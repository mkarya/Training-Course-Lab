import java.util.ArrayList;

public class MealBuilder {
	private ArrayList<Item> item = new ArrayList<Item>();
	
	public void addItem(Item itemType) {
		item.add(itemType);
	}
	
	public void showItem() {
		if (item.isEmpty() == true)  {
			System.out.println("please add item to meal");
		}
		else {
			System.out.println("Item Name" + "       " + "Item Prize");
			for (Item it : item ) {
				System.out.print(it.itemName() + "       " + it.prize());
			}
		}
	}
	
	public int getMealPrize() {
		int prize = 0;
		for (Item it : item) {
			prize = prize + it.prize();
		}
		return prize;
	}
}
