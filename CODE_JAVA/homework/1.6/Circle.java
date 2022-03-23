public class Circle {

    public static final double PI = 3.14159;

    public double radius;

    
    public Circle(){
        radius = 1;
    };

    public Circle(double r){
        this.radius = r;
    };


    public double length(){
        return 2*radius*PI;
    }    


    public double area(){
        return radius*radius*PI;
    }
    

    public static void main(String[] args){
        Circle c = new Circle(5.0);
        System.out.printf("The length of the circle is : %.5f ,and the area is : %.5f",c.length(),c.area());
    }
}