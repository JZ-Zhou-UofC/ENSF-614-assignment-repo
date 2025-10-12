/*
*
*
File Name: SelectionSorter.java
Assignment: Lab 5 Exercise B
*  Completed by: John Zhou
*  Submission Date: Oct 29th, 2025
*/
import java.util.ArrayList;

public class SelectionSorter<E extends Number & Comparable<E>> implements Sorter<E> {

    @Override
    public void sort(ArrayList<Item<E>> items) {
        int size = items.size();

        for (int i = 0; i < size - 1; i++) {
            int minIndex = i;

            // Find the index of the minimum element in the unsorted portion
            for (int j = i + 1; j < size; j++) {
                if (items.get(j).getItem().compareTo(items.get(minIndex).getItem()) < 0) {
                    minIndex = j;
                }
            }

            // Swap the found minimum with the first element of unsorted portion
            if (minIndex != i) {
                Item<E> temp = items.get(i);
                items.set(i, items.get(minIndex));
                items.set(minIndex, temp);
            }
        }
    }
}
