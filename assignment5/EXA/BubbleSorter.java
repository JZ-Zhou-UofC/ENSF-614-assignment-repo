public class BubbleSorter<E extends Number & Comparable<E>> implements SortStrategy<E> {

    @Override
    public void sort(Item<E>[] items, int size) {
        boolean swapped;

        for (int i = 0; i < size - 1; i++) {
            swapped = false;

            for (int j = 0; j < size - i - 1; j++) {
                if (items[j].getItem().compareTo(items[j + 1].getItem()) > 0) {
                    Item<E> temp = items[j];
                    items[j] = items[j + 1];
                    items[j + 1] = temp;
                    swapped = true;
                }
            }

            if (!swapped)
                break;
        }
    }
}
