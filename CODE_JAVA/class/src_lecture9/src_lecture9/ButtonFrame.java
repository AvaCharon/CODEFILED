
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
public class ButtonFrame extends JFrame {
    private JPanel buttonPanel;
    private static final int DEFAULT_WIDTH = 300;
    private static final int DEFAULT_HEIGHT = 200;

    public ButtonFrame() {
        setSize(DEFAULT_WIDTH, DEFAULT_HEIGHT);
        var YellowButton = new JButton("Yel");
        var BlueButton = new JButton("Blu");
        var RedButton = new JButton("Rd");

        buttonPanel = new JPanel();
        buttonPanel.add(YellowButton);
        buttonPanel.add(BlueButton);
        buttonPanel.add(RedButton);
        add(buttonPanel);
        var YellowAction = new ColorAction(Color.YELLOW);
        var BlueAction = new ColorAction(Color.BLUE);
        var RedAction = new ColorAction(Color.RED);
        YellowButton.addActionListener(YellowAction);
        BlueButton.addActionListener(BlueAction);
        RedButton.addActionListener(RedAction);
    }

    private class ColorAction implements ActionListener {
        private Color backgroundColor;

        public ColorAction(Color C) {
            backgroundColor = C;
        }

        public void actionPerformed(ActionEvent event) {
            buttonPanel.setBackground(backgroundColor);
        }
    }
}

