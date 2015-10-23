package basic;

/**
 * Viarables auto-initialization mechanism:
 * 1) class 's field will default initial
 * 2) viarables in methods will alarm error like : "The local variable n2 may not have been initialized " 
 * @author Daniel Li
 *
 */
public class ViarablesInitialization {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		TestClass tc = new TestClass();
		System.out.println(tc.n1);
	}

}


class TestClass{
	int n1;
	public void t()
	{
		int n2 = 0;
		System.out.println(n2);
	}
}