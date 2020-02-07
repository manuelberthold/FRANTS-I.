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

TCP_IP = '0.0.0.0'
TCP_PORT = 25000
BUFFER_SIZE = 20  # Normally 1024, but we want fast response


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
        path = nx.shortest_path(G, source=0, target=len(G) - 1)
        path_edges = zip(path, path[1:])
        # nx.draw_networkx_nodes(G,pos,nodelist=path,node_color='r')
        # nx.draw_networkx_edges(G,pos,edgelist=path_edges,edge_color='g',width=5)
        # plt.axis('equal')

        ##Show Output
        ##plt.show()
        # plt.draw()
        #print(ps)
        #print('Number of Element = ', len(ps))
        #print('Number of Step = ', nx.shortest_path_length(G, source=0, target=len(G) - 1))
        #print('Path Edges = ', path_edges)
        one_path = nx.shortest_path(G, source=0, target=len(G) - 1)
        print('Shortest Path = ', one_path)
        my_path = []
        for sp in one_path:
            my_path.append(ps[sp])

        # print(sp, ps[sp])
        my_path_arr = np.asarray(my_path)
        #print(my_path_arr)
        #ax[2].plot(my_path_arr[:, 1], my_path_arr[:, 0], 'g.')

        full_line = []
        for source, target in zip(one_path, one_path[1:]):
            #    continue
            polyline = G[source][target]['pts']
            #if source == 7:
                #print('siebener:')
                #print(polyline.dtype)
            simplified = simplify_coords(polyline, 0.2)
                #print("ramer", simplified)
                #print("ramer", ramerdouglas(np.array([[0,0], [0,1], [0,5], [0,10],[5,10],[10,10]]), 0.2))
            # draw shortest path lines
            #ax[2].plot(polyline[:, 1], polyline[:, 0], 'blue')
            ax[2].plot(simplified[:, 1], simplified[:, 0], 'blue')
            #print("s:", source)
            #print(G._node[source]['pts'])
            #print("t:", target)
            #print(G._node[target]['pts'])
            ##print(polyline[:, 0])

            ## Find the "corner point":
            tolerance = 5
            simple_polyline = approximate_polygon(simplified, tolerance)
            #ax[2].plot(simple_polyline[1:-1, 1], simple_polyline[1:-1, 0], '.m')
            full_line.extend(simple_polyline[:-1])

        full_line.append(simple_polyline[-1])  # add the last point
        full_line = np.array(full_line)  # convert to an array
        print([(sub[1], sub[0]) for sub in full_line])
        ax[2].plot(full_line[:, 1], full_line[:, 0], '.r')
        # for C in nx.connected_component_subgraphs(G):
        #    print('Length of Path = ',nx.average_shortest_path_length(C))
    except Exception as e:
        print(e)
        # print(ps[0])
        # print(ps[140])
        pass

    #print('nodes[0]',G[0])
    plt.show()


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
        #print("received data:", data)
        picture += data
        #conn.send(data)  # echo
    conn.close()
    data2 = np.frombuffer(picture, dtype='uint8')

    decimg=cv2.imdecode(data2,1)
    doImage(decimg)
    #cv2.imshow('SERVER',decimg)
    #cv2.waitKey(0)
    #cv2.destroyAllWindows()
    print('Waiting for new image...')


