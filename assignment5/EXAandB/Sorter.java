/*
*
*
File Name: Sorter.java
Assignment: Lab 5 Exercise A
*  Completed by: John Zhou
*  Submission Date: Oct 29th, 2025
*/
import java.util.ArrayList;

public interface Sorter<E extends Number & Comparable<E>> {
    void sort(ArrayList<Item<E>> items);
}
