package at.frants;

import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.ByteArrayInputStream;
import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.math.BigInteger;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Date;

public class Main {

    public static void main(String argv[]) throws Exception {
        ServerSocket tcpReceive = new ServerSocket(30001);
        // sendImgToPyhton(ImageIO.read(new FileInputStream("photo1.png")), "png");
        //sendImgToPyhton(ImageIO.read(new FileInputStream("frants_img_1580501146336.bmp")), "bmp");
        while (true) {
            Socket connectionSocket = tcpReceive.accept();
            System.out.println("received data: " + new Date());
            InputStream inputStream = connectionSocket.getInputStream();
            int height = new BigInteger(inputStream.readNBytes(4)).intValue();
            int width = new BigInteger(inputStream.readNBytes(4)).intValue();
            int dimension = 0;
           // int dimension = new BigInteger(inputStream.readNBytes(4)).intValue();
            readImageFromStream(height, width, dimension, connectionSocket.getInputStream());
        }
    }

    private static boolean readImageFromStream(int height, int width, int dimension, InputStream bufferedInputStream) {
        try {
            //   byte[] bytes = bufferedInputStream.readNBytes(height * width*dimension);
            byte[] bytes = bufferedInputStream.readAllBytes();

            bufferedInputStream.close();
            BufferedImage img = ImageIO.read(new ByteArrayInputStream(bytes));
            if (img != null) {
                System.out.println("YEAAAH");
            }
            System.out.println("Bytes read " + bytes.length + new Date());
            BufferedImage image = getBufferedImageOfBytes(height, width, dimension, bytes);
            System.out.println("BufferedImage converted: " + new Date());
            sendImgToPyhton(image, "bmp");
            long timestamp = System.currentTimeMillis();
            File outputFile = new File("frants_img_" + timestamp + ".bmp");
            ImageIO.write(image, "bmp", outputFile);
            System.out.println("Image saved: " + "frants_img_" + timestamp + ".bmp");
            return true;
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }

    }

    private static BufferedImage getBufferedImageOfBytes(int height, int width, int dimension, byte[] bytes) {
        if (dimension == 3) {
            BufferedImage image = new BufferedImage(width, height, BufferedImage.TYPE_INT_RGB);
            byte[][][] rgbColors = new byte[width][height][dimension];
            int origin = 0;
            for (int k = 0; k < dimension; k++) {
                for (int i = 0; i < width; i++) {
                    for (int j = 0; j < height; j++) {
                        rgbColors[i][j][k] = bytes[origin++];
                        int rgb = rgbColors[i][j][0];
                        rgb = (rgb << 8) + rgbColors[i][j][1];
                        rgb = (rgb << 8) + rgbColors[i][j][2];
                        image.setRGB(i, j, rgb);
                    }
                }
            }
            return image;
        }else{
            BufferedImage image = new BufferedImage(width, height, BufferedImage.TYPE_INT_RGB);
            int origin = 0;
                for (int i = 0; i < width; i++) {
                    for (int j = 0; j < height; j++) {
                        image.setRGB(i, j,  bytes[origin] != -1 ?  Color.BLACK.getRGB() : Color.WHITE.getRGB());
                        origin++;
                    }

            }
            return image;
        }


    }

    public static void sendImgToPyhton(BufferedImage image, String extension) throws IOException {
        Socket clientSocket = new Socket("192.168.0.5", 25000);
        ImageIO.write(image, extension, clientSocket.getOutputStream());
        clientSocket.close();

    }
}
