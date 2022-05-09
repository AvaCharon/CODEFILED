
class User {
    private String name;
    public User(){

    }

    public void setName(String name)
    {
        name = name;
    }

    public String getName(){
        return name;
    }
}

public class UserTest{
    public static void main(String[] args){
        User user = new User();
        user.setName("zhangsan");
        System.out.println(user.getName());
    }
}
