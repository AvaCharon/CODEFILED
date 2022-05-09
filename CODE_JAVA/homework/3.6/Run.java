public class Run {
    public static void main(String[] args){
        Runnable tortoiseRunnable = ()->{
            try{       
                int dis=0;
                while(dis<20)
                {
                    if(dis!=0&&dis%5==0){
                        System.out.println("乌龟开始休息1秒");
                        Thread.sleep(1000);
                    }
                    Thread.sleep(1000);
                    System.out.println("乌龟跑了1米");
                    dis++;
                }   
                System.out.println("乌龟跑到了终点！");
            }catch(InterruptedException e){
                e.printStackTrace();
            }
        };

        Runnable rabbitRunnable =()->{
            try{    
                int dis=0;   
                while(dis<20)
                {
                    if(dis!=0&&dis%5==0){
                        System.out.println("兔子开始休息10秒");
                        Thread.sleep(10000);
                    }
                    Thread.sleep(200);
                    System.out.println("兔子跑了1米");
                    dis++;
                }   
                System.out.println("兔子跑到了终点！");
            }catch(InterruptedException e){
                e.printStackTrace();
            }
        };

        new Thread(rabbitRunnable).start();
        new Thread(tortoiseRunnable).start();
    }
}

// public class Run {
//     public static void main(String[] args){
//         Runnable tortoiseRunnable = ()->{
//             try{       
//                 int dis=0;
//                 while(dis<20)
//                 {
//                     if(dis!=0&&dis%5==0){
//                         System.out.println("tortoise rest for 1 second");
//                         Thread.sleep(1000);
//                     }
//                     Thread.sleep(1000);
//                     System.out.println("tortoise has run 1 meter");
//                     dis++;
//                 }   
//                 System.out.println("tortoise has arrived at the final!");
//             }catch(InterruptedException e){
//                 e.printStackTrace();
//             }
//         };

//         Runnable rabbitRunnable =()->{
//             try{    
//                 int dis=0;   
//                 while(dis<20)
//                 {
//                     if(dis!=0&&dis%5==0){
//                         System.out.println("rabbit rest for 10 seconds");
//                         Thread.sleep(10000);
//                     }
//                     Thread.sleep(200);
//                     System.out.println("rabbit has run 1 meter");
//                     dis++;
//                 }   
//                 System.out.println("rabbit has arrived at the final!");
//             }catch(InterruptedException e){
//                 e.printStackTrace();
//             }
//         };

//         new Thread(rabbitRunnable).start();
//         new Thread(tortoiseRunnable).start();
//     }
// }