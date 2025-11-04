package EAPart2;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;

public class ColouredGlassDecorator extends Decorator {

    public ColouredGlassDecorator(Component cmp, int x, int y, int width, int height) {
        super(cmp, x, y, width, height);
    }

    @Override
    public void draw(Graphics g) {
        // Draw wrapped component first
        cmp.draw(g);

        Graphics2D g2d = (Graphics2D) g;

        // Save old color
        Color oldColor = g2d.getColor();

        // Set translucent green color (RGBA: 0, 255, 0, alpha)
        Color translucentGreen = new Color(0, 255, 0, 100); // alpha 0-255
        g2d.setColor(translucentGreen);

        // Fill rectangle over the component
        g2d.fillRect(x, y, width, height);

        // Restore old color
        g2d.setColor(oldColor);
    }
}
