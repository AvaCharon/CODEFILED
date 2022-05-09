public class DeadLock {
    public static String bluekey = "蓝色钥匙";
    public static String redkey = "红色钥匙";
    public static void main(String[] args) {
        PerA la = new PerA();
        new Thread(la).start();
        PerB lb = new PerB();
        new Thread(lb).start();
    }
}
class PerA implements Runnable{
    public void run() {
        try {
            System.out.println( " PerA: 我有蓝色钥匙请给我红色钥匙");
            while(true){
                synchronized (DeadLock.bluekey) {
                    System.out.println(" PerA 锁住 蓝色钥匙");
                    Thread.sleep(3000); // 此处等待是给B能锁住机会
                    synchronized (DeadLock.redkey) {
                        System.out.println(" PerA 开门");
                        Thread.sleep(60 * 1000); // 为测试，占用了就不放
                    }
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
class PerB implements Runnable{
    public void run() {
        try {
            System.out.println(" PerB： 我有红色钥匙请给我蓝色钥匙");
            while(true){
                synchronized (DeadLock.redkey) {
                    System.out.println(" PerB 锁住 红色钥匙");
                    Thread.sleep(3000); // 此处等待是给A能锁住机会
                    synchronized (DeadLock.bluekey) {
                        System.out.println(" PerB 开门");
                        Thread.sleep(60 * 1000); // 为测试，占用了就不放
                    }
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}