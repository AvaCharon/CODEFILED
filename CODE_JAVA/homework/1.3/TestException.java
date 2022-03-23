
public class TestException {
    public static void main(String[] args){
        try{
            System.out.println("Outside try");
            //throw new Exception();
        }
        catch(Exception e){
            System.err.println("An exception was thrown.");
            throw e;
        }
    }   
}
