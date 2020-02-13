#!/usr/bin/env python3

import numpy as np
import socket
import cv2
import sknw
from skimage.morphology import skeletonize
from skimage.measure import approximate_polygon
import networkx as nx
import matplotlib

matplotlib.use('TkAgg')
import matplotlib.pyplot as plt
from simplification.cutil import simplify_coords, simplify_coords_vw, simplify_coords_vwp
import json
import socket

#NUMBA_DISABLE_JIT 1 
TCP_IP = '0.0.0.0'
TCP_PORT = 25000
ROBOT_IP = 'localhost'
ROBOT_PORT = 11223
last = 90  # start position; 0 - looking east, 90 - looking south, -90 - looking north, 180 - looking west
factor = 150  # how many cm is the image width
BUFFER_SIZE = 20  # Normally 1024, but we want fast response


def getAngle(A, B, last=0):
    unadjusted_angle = int(round(np.arctan2(B[1] - A[1], B[0] - A[0]) * 180 / np.pi))
    turn = unadjusted_angle - last
    return turn, unadjusted_angle


def getJsonPath(a, width):
    out = []
    last_int = last
    for i in range(len(a) - 1):
        angle, last_int = getAngle(a[i], a[i + 1], last_int)
        dist = np.sqrt(np.square(a[i + 1][1] - a[i][1]) + np.square(a[i + 1][0] - a[i][0])) * (factor / width)

        tmp = dict()
        tmp['step'] = i
        tmp['angle'] = angle
        tmp['dist'] = dist
        out.append(tmp)
    return json.dumps(out, indent=4)


def doImage(img):
    grayscaled = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    grayscaled = cv2.GaussianBlur(grayscaled, (5, 5), 0)
    retval, threshold = cv2.threshold(grayscaled, 10, 255, cv2.THRESH_BINARY_INV + cv2.THRESH_OTSU)
    retval, threshold2 = cv2.threshold(threshold, 10, 255, cv2.THRESH_BINARY_INV)
    threshold2[threshold2 == 255] = 1

    # Skeletonize the Thresholded Image
    skel = skeletonize(threshold2.astype(bool)).astype(np.uint16)
    fig, axes = plt.subplots(nrows=1, ncols=3, figsize=(8, 4),
                             sharex=True, sharey=True)

    ax = axes.ravel()
    ax[0].imshow(threshold2, cmap=plt.cm.gray)
    ax[0].axis('off')
    ax[0].set_title('original', fontsize=20)

    ax[1].imshow(skel, cmap=plt.cm.gray)
    ax[1].axis('off')
    ax[1].set_title('skeleton', fontsize=20)

    fig.tight_layout()
    # Build Graph from skeleton
    graph = sknw.build_sknw(skel, multi=False)
    G = nx.Graph(graph)
    shpath = nx.shortest_path(G, source=0, target=len(G) - 1)
    if len(shpath) == 2:
        G.remove_edge(shpath[0], shpath[1])
    # plt.imshow(img, cmap='gray')
    ax[2].imshow(grayscaled, cmap=plt.cm.gray)
    ax[2].axis('off')
    ax[2].set_title('shortest path', fontsize=20)

    # Draw Node by 'o'
    node, nodes = graph._node, graph.nodes()
    ps = np.array([node[i]['o'] for i in nodes])
    try:

        one_path = nx.shortest_path(G, source=0, target=len(G) - 1)
        print('Shortest Path = ', one_path)
        my_path = []
        for sp in one_path:
            my_path.append(ps[sp])

        full_line = []

        for source, target in zip(one_path, one_path[1:]):
            #    continue
            polyline = G[source][target]['pts']
            simplified = simplify_coords(polyline, 0.2)
            ax[2].plot(simplified[:, 1], simplified[:, 0], 'blue')

            ## Find the "corner point":
            tolerance = 5
            simple_polyline = approximate_polygon(simplified, tolerance)
            # ax[2].plot(simple_polyline[1:-1, 1], simple_polyline[1:-1, 0], '.m')
            full_line.extend(simple_polyline[:-1])

        full_line.append(simple_polyline[-1])  # add the last point
        full_line = np.array(full_line)  # convert to an array
        print([(sub[1], sub[0]) for sub in full_line])
        jsonString = getJsonPath([(sub[1], sub[0]) for sub in full_line], img.shape[1])
        print(jsonString)
        sendJsonToCar(jsonString)
        # print('2nd', second)
        ax[2].plot(full_line[:, 1], full_line[:, 0], '.r')
    except Exception as e:
        print(e)
        pass

    plt.show()


def sendJsonToCar(jsonString):
    # send json string to robot
    socketForCar = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    socketForCar.connect((ROBOT_IP, ROBOT_PORT))
    socketForCar.sendall(jsonString.encode())
    socketForCar.close()


s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((TCP_IP, TCP_PORT))
s.listen(1)

print("Waiting for picture on port", TCP_PORT)

while True:
    conn, addr = s.accept()
    print('Connection address:', addr)
    picture = b''
    while 1:
        data = conn.recv(BUFFER_SIZE)
        if not data: break
        picture += data
    conn.close()
    data2 = np.frombuffer(picture, dtype='uint8')

    decimg = cv2.imdecode(data2, 1)
    doImage(decimg)
    print('Waiting for new image...')
