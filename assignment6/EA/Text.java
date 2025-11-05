
/*
*
*
File Name: Text.java
Assignment: Lab 6 Exercise A&B
*  Completed by: John Zhou
*  Submission Date: Nov 5th, 2025
*/
package EA;

import java.awt.Color;
import java.awt.Graphics;

public class Text implements Component {

	protected String text;
	protected int x;
	protected int y;

	public Text(String text, int x, int y) {
		this.text = text;
		this.x = x;
		this.y = y;
	}

	@Override
	public void draw(Graphics g) {
		Color darkGreen = new Color(0, 128, 0); // Slightly Darker green
		g.setColor(darkGreen);

		//Changing this back to black for part2
		g.drawString(text, x, y);

	}
}