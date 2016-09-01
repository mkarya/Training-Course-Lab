
public abstract class Burger implements Item{
	public Packing pack() {
		return new Wrapper();
	}
	
}
