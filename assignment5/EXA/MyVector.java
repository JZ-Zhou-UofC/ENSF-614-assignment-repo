
public class MyVector<E extends Number & Comparable<E>> {
    private Item<E>[] items;
    private int count = 0;
    private int capacity =0;
    private SortStrategy<E> sortStrategy;

    public MyVector(int cap) {

        items = (Item<E>[]) new Item[cap] ;
        this.capacity=cap;
    }

    public void add(Item<E> item) {
          if (count < capacity) {
            items[count] = item;
            count++;
        } else {
            System.out.println("Vector is full!");
        }}

    public void display() {
        for (int i = 0; i < count; i++) {
            System.out.print(items[i].getItem() + "  ");
        }
        System.out.println();
    }

    public void setSortStrategy(SortStrategy<E> strategy) {
        this.sortStrategy = strategy;
    }

    public void performSort() {
        if (sortStrategy != null)
            sortStrategy.sort(items, count);
    }
}
