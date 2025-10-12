public interface SortStrategy<E extends Number & Comparable<E>> {
    void sort(Item<E>[] items, int size);
}
