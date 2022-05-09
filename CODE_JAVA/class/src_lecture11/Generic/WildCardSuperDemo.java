package Generic;

import java.util.ArrayList;

public class WildCardSuperDemo {
    public static void printAllObject(ArrayList<? super Double> list) {
        for (Object object : list) {
            System.out.println(object);
        }
    }
    public static void main(String[] args) {
        ArrayList<Number> list1 = new ArrayList<>();
        list1.add(7);
        printAllObject(list1);

        ArrayList<Object> list2 = new ArrayList<>();
        list2.add("Java");
        printAllObject(list2);
    }
}

