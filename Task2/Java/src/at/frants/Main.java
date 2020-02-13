package at.frants;

import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.math.BigInteger;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Date;

public class Main {

    public static String pythonTCPServerIP = "192.168.0.5";
    public static int pythonTCPServerPort = 25000;
    public static int localTCPPort = 30001;

    public static void main(String argv[]) throws Exception {
        ServerSocket tcpReceive = new ServerSocket(localTCPPort);
        while (true) {
            Socket connectionSocket = tcpReceive.accept();
            System.out.println("received data: " + new Date());
            InputStream inputStream = connectionSocket.getInputStream();
            readImageFromStream(new BigInteger(inputStream.readNBytes(4)).intValue(), new BigInteger(inputStream.readNBytes(4)).intValue(), connectionSocket.getInputStream());
        }
    }

    private static boolean readImageFromStream(int height, int width, InputStream bufferedInputStream) {
        try {
            byte[] bytes = bufferedInputStream.readAllBytes();
            bufferedInputStream.close();
            System.out.println("Bytes read " + bytes.length + " expected : " + height * width + new Date());
            BufferedImage image = getBufferedImageOfBytes(height, width, bytes);
            System.out.println("BufferedImage converted: " + new Date());
            sendImgToPyhton(image, "bmp");
            saveImage(image);
            return true;
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }
    }

    private static void saveImage(BufferedImage image) throws IOException {
        long timestamp = System.currentTimeMillis();
        File outputFile = new File("frants_img_" + timestamp + ".bmp");
        ImageIO.write(image, "bmp", outputFile);
        System.out.println("Image saved: " + "frants_img_" + timestamp + ".bmp");
    }

    private static BufferedImage getBufferedImageOfBytes(int height, int width, byte[] bytes) {
        BufferedImage image = new BufferedImage(width, height, BufferedImage.TYPE_INT_RGB);
        int origin = 0;
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                image.setRGB(i, j, bytes[origin] != -1 ? Color.BLACK.getRGB() : Color.WHITE.getRGB());
                origin++;
            }
        }
        return image;
    }

    public static void sendImgToPyhton(BufferedImage image, String extension) throws IOException {
        Socket clientSocket = new Socket(pythonTCPServerIP, pythonTCPServerPort);
        ImageIO.write(image, extension, clientSocket.getOutputStream());
        clientSocket.close();
    }
}
