/*
*
*
File Name: InsertionSorter.java
Assignment: Lab 5  B
*  Completed by: John Zhou
*  Submission Date: Oct 29th, 2025
*/
import java.util.ArrayList;

public class InsertionSorter<E extends Number & Comparable<E>> implements Sorter<E> {

    @Override
    public void sort(ArrayList<Item<E>> items) {
        int size = items.size();
        for (int i = 1; i < size; i++) {
            Item<E> key = items.get(i);
            int j = i - 1;

            while (j >= 0 && items.get(j).getItem().compareTo(key.getItem()) > 0) {
                items.set(j + 1, items.get(j));
                j--;
            }
            items.set(j + 1, key);
        }
    }
}
