package Generic;

import java.util.ArrayList;

public class WildCardExtendsDemo {
    public static void printAllObject(ArrayList<? extends Number> list) {
        for (Object object : list) {
            System.out.println(object);
        }
    }
    public static void main(String[] args) {
        ArrayList<Double> list1 = new ArrayList<>();
        list1.add(1.23);
        printAllObject(list1);

        ArrayList<Integer> list2 = new ArrayList<>();
        list2.add(7);
        printAllObject(list2);
    }
}

