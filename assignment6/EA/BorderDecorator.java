package EA;

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Stroke;
import java.awt.geom.Rectangle2D;

public class BorderDecorator extends Decorator {

    public BorderDecorator(Component cmp, int x, int y, int width, int height) {
        super(cmp, x, y, width, height);
    };

    @Override
    public void draw(Graphics g) {

        cmp.draw(g);
        Graphics2D g2d = (Graphics2D) g;
        Stroke oldStroke = g2d.getStroke();
        Color oldColor = g2d.getColor();

        Stroke dashed = new BasicStroke(3, BasicStroke.CAP_BUTT,
                BasicStroke.JOIN_BEVEL, 0, new float[] { 9 }, 0);

        g2d.setStroke(dashed);
        g2d.setColor(Color.BLACK);
        g2d.draw(new Rectangle2D.Float(x, y, width, height));

        g2d.setStroke(oldStroke);
        g2d.setColor(oldColor);
    }

}
