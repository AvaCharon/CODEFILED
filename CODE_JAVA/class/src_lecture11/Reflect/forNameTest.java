package Reflect;
public class forNameTest {
    public static void main(String[] args) throws ClassNotFoundException {
        String className = "Reflect.Student";
        Class cl1 = Class.forName(className); //Class.forName
        System.out.println(cl1);
        Class cl2 = Student.class; //T.class
       // Class cl2 = int.class; //T.class
        System.out.println(cl2);
    }
}
