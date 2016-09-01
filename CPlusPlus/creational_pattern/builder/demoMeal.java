import java.io.IOException;
import java.util.ArrayList;

public class demoMeal {
	public ArrayList<Item> meal = new ArrayList<Item>();
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		showMealOption so = new showMealOption();
		demoMeal dm = new demoMeal();
		int kk = 1;
		while( kk != 0) {
			try {
				kk = so.showOption();
			} catch (NumberFormatException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			switch (kk) {
				case 1:
					dm.meal.add(new ChickenBurger());
					break;
				case 2:
					dm.meal.add(new Coke());
					break;
				case 3:
					dm.meal.add(new VegBurger());
					break;
			}			
		}
		 int prize = 0;
		 for (Item it: dm.meal) {
			 System.out.println(it.itemName());
			 prize += it.prize();
		 }
		 
		 System.out.println("total cost of meal :" + Integer.toString(prize));
		 return;
	}
	
}
	

