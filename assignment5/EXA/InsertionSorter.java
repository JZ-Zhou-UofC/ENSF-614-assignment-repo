public class InsertionSorter<E extends Number & Comparable<E>> implements SortStrategy<E> {

    @Override
    public void sort(Item<E>[] items, int size) {
        for (int i = 1; i < size ; i++) {
            Item<E> key = items[i];
            int j = i - 1;

            while (j >= 0 && items[j].getItem().compareTo(key.getItem())>0) {
                items[j + 1] = items[j];
                j--;
            }
            items[j + 1] = key;
        }

    }
}
