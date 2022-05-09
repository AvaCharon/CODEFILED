import javax.swing.JFrame;
import java.awt.*;
public class SimpleFrameTest {
    public static void main(String[] args){
        EventQueue.invokeLater(()->
        {
            var frame = new SimpleFrame();
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame.setVisible(true);
        });
    }
}
