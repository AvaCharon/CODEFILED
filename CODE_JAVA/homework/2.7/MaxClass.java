public class MaxClass {
    
    public int max(int data1,int data2){
        return data1>data2?data1:data2;
    }

    public int max(int data1,int data2,int data3){
        return this.max(this.max(data1, data2), this.max(data3, data2));
    }

    public static void main(String[] args){
        MaxClass maxClass=new MaxClass();
        System.out.println(maxClass.max(10,100));
        System.out.println(maxClass.max(10,100,1000));
        return;
    }
}
