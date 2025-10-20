/*
*
*
File Name: Subject.java
Assignment: Lab 5 Exercise C
*  Completed by: John Zhou
*  Submission Date: Oct 29th, 2025
*/
package EXC;
public interface Subject {
    void attach(Observer o);
    void remove(Observer o);
    void notifyObservers();
}
