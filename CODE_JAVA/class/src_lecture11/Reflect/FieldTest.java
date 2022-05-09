package Reflect;
import java.lang.reflect.Field;

public class FieldTest {
    public static void main(String[] args) throws NoSuchFieldException, IllegalAccessException {
        Student Harry = new Student("Harry Potter", 11);
        System.out.println(Harry);
        System.out.println("......................");
        Class StudentClass = Harry.getClass();
        Field f = StudentClass.getDeclaredField("name");
        f.setAccessible(true);
        Object v1 = f.get(Harry);
        System.out.println(v1);
        f.set(Harry,"The boy who lived");
        System.out.println(Harry.getName());
        System.out.println("......................");
        System.out.println(Harry);
    }
}
