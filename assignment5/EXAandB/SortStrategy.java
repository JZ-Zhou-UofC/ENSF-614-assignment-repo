/*
*
*
File Name: SortStrategy.java
Assignment: Lab 5 Exercise A
*  Completed by: John Zhou
*  Submission Date: Oct 29th, 2025
*/
public interface SortStrategy<E extends Number & Comparable<E>> {
   void sort(Item<E>[] var1, int var2);
}
