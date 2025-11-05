
/*
*
*
File Name: Decorator.java
Assignment: Lab 6 Exercise A&B
*  Completed by: John Zhou
*  Submission Date: Nov 5th, 2025
*/
package EA;

abstract class Decorator implements Component {

    protected Component cmp;
    protected int x;
    protected int y;
    protected int width;
    public int height;

    public Decorator(Component cmp, int x, int y, int width, int height) {
        this.cmp = cmp;
        this.x = x;
        this.y = y;
        this.width = width;
        this.height = height;
    }
};
