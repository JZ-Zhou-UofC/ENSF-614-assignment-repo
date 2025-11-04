package EA;

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Stroke;

public class ColouredFrameDecorator extends Decorator {
    protected int thickness;

    public ColouredFrameDecorator(Component cmp, int x, int y, int width, int height, int thickness) {
           super(cmp, x, y, width, height);
            this.thickness = thickness;
    };

    @Override
    public void draw(Graphics g) {
        cmp.draw(g);
        Graphics2D g2d = (Graphics2D) g;
        Stroke oldStroke = g2d.getStroke();
        Color oldColor = g2d.getColor();

        g2d.getColor();
        g2d.setStroke(new BasicStroke(thickness));
        g2d.setColor(Color.red);
        g2d.drawRect(x, y, width, height);
        g2d.setStroke(oldStroke);
        g2d.setColor(oldColor);

    }
}
