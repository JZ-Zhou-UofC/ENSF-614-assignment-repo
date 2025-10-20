/*
*
*
File Name: ThreeColumnTable_Observer.java
Assignment: Lab 5 Exercise C
*  Completed by: John Zhou
*  Submission Date: Oct 29th, 2025
*/
package EXC;

import java.util.ArrayList;

public class ThreeColumnTable_Observer implements Observer {
    private Subject subject;

    public ThreeColumnTable_Observer(Subject subject) {
        this.subject = subject;
        subject.attach(this);
    }

    @Override
    public void update(ArrayList<Double> data) {
        System.out.println("\nNotification to three-Column Table Observer: Data Changed:");
        display(data);
    }

    private void display(ArrayList<Double> data) {

        for (int i = 0; i < data.size(); i++) {
            System.out.printf("%-8.2f", data.get(i));
            if ((i + 1) % 3 == 0) System.out.println();
        }
        System.out.println();
    }
}
