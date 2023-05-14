import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class MinecraftLauncher extends JFrame {

    public MinecraftLauncher() {
        super("Minecraft Launcher");
        setSize(500, 500);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        
        // Add UI components here
        
        setVisible(true);
    }

    public static void main(String[] args) {
        new MinecraftLauncher();
    }
}
