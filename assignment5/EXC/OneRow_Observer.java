/*
*
*
File Name: OneRow_Observer.java
Assignment: Lab 5 Exercise C
*  Completed by: John Zhou
*  Submission Date: Oct 29th, 2025
*/
package EXC;

import java.util.ArrayList;

public class OneRow_Observer implements Observer {
    private Subject subject;

    public OneRow_Observer(Subject subject) {
        this.subject = subject;
        subject.attach(this);
    }

    @Override
    public void update(ArrayList<Double> data) {
              System.out.println("\nNotification to one-row Table Observer: Data Changed:");
        display(data);
    }

    private void display(ArrayList<Double> data) {

        for (int index=0; index<data.size();index++) {
            System.out.printf("%-8.2f", data.get(index));
        }
        System.out.println();
    }
}
