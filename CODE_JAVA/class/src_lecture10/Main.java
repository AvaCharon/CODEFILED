public class Main {
    public static void main(String[] args) {
        new Thread1().start();
        new Thread(new Thread2()).start();

        Runnable r=()->{
            System.out.println("New Thread3");
        };
        new Thread(r).start();
    }
}

class Thread1 extends Thread {
    @Override
    public void run() {
        System.out.println("New thread1");
    }
}

class Thread2 implements Runnable {
    @Override
    public void run() {
        System.out.println("New thread2");
    }
}


//public class Main {
//    public static void main(String[] args) {
//        System.out.println("main start...");
//        Thread t = new Thread() {
//            public void run() {
//                System.out.println("thread run...");
//                System.out.println("thread end.");
//            }
//        };
//        t.start();
//        System.out.println("main end...");
//    }
//}
