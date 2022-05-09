import java.lang.reflect.Field;

public class Test {
    public static void main(String[] args)throws NoSuchFieldException, IllegalAccessException{
        Disney disney = new Disney();
        Class disneyClass = disney.getClass();
        Field field = disneyClass.getDeclaredField("name");
        field.setAccessible(true);
        field.set("Mickey Mouse","Donald Duck");
        System.out.println(disney.getName());
    }
}

class Disney{
    private String name = "Mickey Mouse";

    public String getName(){
        return name;
    }
}