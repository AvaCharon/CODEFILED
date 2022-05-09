#单例模式实例（个人学习记录）

#单例模式有5种实现方式：饿汉、懒汉、双重校验锁、静态内部类和枚举
'''
#饿汉
类加载的时候就创建了实例
优点：类加载的时候创建一次实例，避免了多线程同步问题

缺点：即使单例没被用到也会创建，浪费内存

public class Singleton {
    private static Singleton instance = new Singleton();
    private Singleton() { }
    public static Singleton getInstance() {
        return instance; 
    }
}

#饿汉-变种
public class Singleton {
    private static Singleton instance = null;
    static {
        instance = new Singleton();
    }
    private Singleton() { }
    public static Singleton getInstance() {
        return this.instance; 
    }
}

#懒汉-（非线程安全）
优点:需要时才去创建
缺点:没有考虑线程安全问题,多个线程并发调用getInstance,可能会创建多个实例

public class Singleton {
    private static Singleton instance = null;
    private Singleton() { }
    public static Singleton getInstance() {
          if (instance == null) {
                instance = new Singleton();
          }
        return instance;
    }
}

#懒汉-（线程安全）
缺点:性能问题,添加了synchronized的函数比一般方法慢得多,若多次调用getInstance,则累积的性能损耗特别大。

public class Singleton {
    private static Singleton instance = null;
    private Singleton() { }
    public static Synchronized Singleton getInstance() {
          if (instance == null) {
                instance = new Singleton();
          }
        return instance;
    }
}
'''


#双重检查锁定(DCL,即 double-checked locking)
'''
public class Singleton {  
    private volatile static Singleton singleton;  
    private Singleton (){}  
    public static Singleton getSingleton() {  
    if (singleton == null) {  
        synchronized (Singleton.class) {  
        if (singleton == null) {  
            singleton = new Singleton();  
        }  
        }  
    }  
    return singleton;  
    }  
}
'''




'''
#当一个变量被volatile修饰时,会拥有两个特性:

#1 保证了不同线程对该变量操作的内存可见性.(当一个线程修改了变量,其他使用次变量的线程可以立即知道这一修改).
#2 禁止了指令重排序.
'''