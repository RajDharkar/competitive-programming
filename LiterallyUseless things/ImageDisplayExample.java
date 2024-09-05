import java.awt.Graphics;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import javax.imageio.ImageIO;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class ImageDisplayExample {

    public static void main(String[] args) {
        BufferedImage image;  // Declare image as final to use it in the inner class

        try {
            image = ImageIO.read(new File("patriot_poster.png"));
            if (image == null) {
                System.out.println("Image could not be loaded. The file might be corrupted or the format is not supported.");
                return;
            }
        } catch (IOException e) {
            System.out.println("Error loading image: " + e.getMessage());
            return;
        }

        JFrame frame = new JFrame("Image Display Test");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 400);
        frame.add(new JPanel() {
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                g.drawImage(image, 0, 0, this);
            }
        });
        frame.setVisible(true);
    }
}
