package Generic;

public class ShowClass2<T> implements ShowInterface<T>{
    public void show(T t){
        System.out.println("show:"+t);
    }
}
