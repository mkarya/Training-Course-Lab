
public class Coke implements Item {
	public Packing pack() {
		return new bottle();
	}
	
	public String itemName() {
		return "Coke";
	}
	
	public int prize() {
		return 20;
	}
}
