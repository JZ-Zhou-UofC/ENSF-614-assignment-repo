/*
*
*
File Name: FiveRowsTable_Observer.java
Assignment: Lab 5 Exercise C
*  Completed by: John Zhou
*  Submission Date: Oct 29th, 2025
*/
package EXC;

import java.util.ArrayList;

public class FiveRowsTable_Observer implements Observer {
    private Subject subject;

    public FiveRowsTable_Observer(Subject subject) {
        this.subject = subject;
        subject.attach(this);
    }

    @Override
    public void update(ArrayList<Double> data) {
        System.out.println("\nNotification to five-rows Table Observer: Data Changed:");
        display(data);
    }

    private void display(ArrayList<Double> data) {

        int numRows = 5;
  

        for (int row = 0; row < numRows; row++) {
            for (int index = row; index < data.size(); index += numRows) {
                System.out.printf("%-8.2f", data.get(index));
            }
            System.out.println();
        }
    }
}
