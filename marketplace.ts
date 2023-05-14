import java.util.ArrayList;

public class MinecraftMarketplace {
    private ArrayList<String> items;

    public MinecraftMarketplace() {
        items = new ArrayList<String>();
    }

    public void addItem(String item) {
        items.add(item);
    }

    public void removeItem(String item) {
        items.remove(item);
    }

    public void displayItems() {
        System.out.println("Items in the Minecraft marketplace:");
        for (String item : items) {
            System.out.println("- " + item);
        }
    }
}
