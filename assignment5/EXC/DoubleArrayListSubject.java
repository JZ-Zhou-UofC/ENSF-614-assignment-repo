package EXC;

import java.util.ArrayList;

public class DoubleArrayListSubject implements Subject {
    private ArrayList<Double> data;
    private ArrayList<Observer> observers;

    public DoubleArrayListSubject() {
        data = new ArrayList<>();
        observers = new ArrayList<>();
    }

    @Override
    public void attach(Observer o) {
        observers.add(o);
        o.update(data);
    }

    @Override
    public void remove(Observer o) {
        observers.remove(o);
    }

    @Override
    public void notifyObservers() {
        for (Observer o : observers) {
            o.update(data);
        }
    }

    public void addData(Double value) {
        data.add(value);
        notifyObservers();
    }

    public void setData(Double value, int index) {
        if (index >= 0 && index < data.size()) {
            data.set(index, value);
            notifyObservers();
        } else {
            System.out.println("Index out of range.");
        }
    }

    public void populate(double[] arr) {
        data.clear();
        for (double v : arr) {
            data.add(v);
        }
        notifyObservers();
    }

    public void display() {
        if (data.isEmpty()) {
            System.out.println("Empty List ...");
        } else {

            System.out.println("default display");
        }
    }
}
