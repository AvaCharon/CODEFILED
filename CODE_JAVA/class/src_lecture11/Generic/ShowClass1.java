package Generic;

public class ShowClass1 implements ShowInterface<String>{
    public void show(String t){
        System.out.println("show:"+t);
    }
}

