interface Student{
    void printMessage();
}


public class College implements Student {
    private int id;
    private String name;

    @Override
    public void printMessage() {
        System.out.println(id + name);
    }
}
