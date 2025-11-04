package EAPart2;

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
