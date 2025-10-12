/*
*
*
File Name: MyVector.java
Assignment: Lab 5 Exercise A
*  Completed by: John Zhou
*  Submission Date: Oct 29th, 2025
*/
import java.util.ArrayList;

public class MyVector<E extends Number & Comparable<E>> {
    private ArrayList<Item<E>> storageM;
    private Sorter<E> sorter;

    public MyVector(int n) {
        storageM = new ArrayList<>(n);
    }

    public MyVector(ArrayList<Item<E>> arr) {
        storageM = new ArrayList<>(arr);
    }

    public void add(Item<E> value) {
        storageM.add(value);
    }

    public void setSortStrategy(Sorter<E> s) {
        this.sorter = s;
    }

    public void performSort() {

       sorter.sort(storageM);
    }

    public void display() {
        for (Item<E> item : storageM) {
            System.out.print(item.getItem() + "  ");
        }
        System.out.println();
    }
}
