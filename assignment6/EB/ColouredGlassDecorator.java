
/*
*
*
File Name: ColouredGlassDecorator.java
Assignment: Lab 6 Exercise A&B
*  Completed by: John Zhou
*  Submission Date: Nov 5th, 2025
*/
package EB;

import java.awt.AlphaComposite;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;

public class ColouredGlassDecorator extends Decorator {

    public ColouredGlassDecorator(Component cmp, int x, int y, int width, int height) {
        super(cmp, x, y, width, height);
    }

    @Override
    public void draw(Graphics g) {

        cmp.draw(g);

        Graphics2D g2d = (Graphics2D) g;


        Color oldColor = g2d.getColor();

        g2d.setColor(Color.green);
        g2d.setComposite(AlphaComposite.getInstance(AlphaComposite.SRC_OVER, 1 *
                0.1f));

        g2d.fillRect(x, y, width, height);


        g2d.setColor(oldColor);
    }
}
