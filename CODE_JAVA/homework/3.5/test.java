
public class test {
    static void pong(){
        System.out.println("ha");
    }

    public static void main(String[] args){
        Thread t = new Thread(()->pong());
        t.run();
        System.out.println("heng");

    }
}
