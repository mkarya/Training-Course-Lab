import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class showMealOption {
	BufferedReader bo = new BufferedReader(new InputStreamReader(System.in));
	
	public int showOption() throws NumberFormatException, IOException {
		System.out.println("to select Chicken Burger type ------- 1");
		System.out.println("to select Coke           type ------- 2");
		System.out.println("to select Veg Burger     type ------- 3");
		System.out.println("to select  type ------- 1");
		return Integer.parseInt(bo.readLine());
	}
}
