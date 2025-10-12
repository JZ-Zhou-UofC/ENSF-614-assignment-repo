/*
*
*
File Name: BubbleSorter.java
Assignment: Lab 5 Exercise A
*  Completed by: John Zhou
*  Submission Date: Oct 29th, 2025
*/
import java.util.ArrayList;

public class BubbleSorter<E extends Number & Comparable<E>> implements Sorter<E> {
    @Override
    public void sort(ArrayList<Item<E>> items) {
        int size = items.size();
        for (int i = 0; i < size - 1; i++) {
            boolean swapped = false;
            for (int j = 0; j < size - i - 1; j++) {
                if (items.get(j).getItem().compareTo(items.get(j + 1).getItem()) > 0) {
                    Item<E> temp = items.get(j);
                    items.set(j, items.get(j + 1));
                    items.set(j + 1, temp);
                    swapped = true;
                }
            }
            if (!swapped) break;
        }
    }
}
