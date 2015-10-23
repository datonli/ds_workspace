package basic;

/**
 * Testing what happend when parent's class has a private method?
 * child's method cannot use directly!
 * But it can still be used by "super.XXX" which "super" means parent's class and "XXX" is a public method invoking private method! 
 * @author Daniel Li
 *
 */
public class PrivateMethodInheritance {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		SubClass p = new SubClass();
		p.sInvokeA();
		p.invokeA();
	}

}

class SuperClass{
	private void A(){
		System.out.println("SuperClass's A method");
	}
	
	public void invokeA(){
		A();
	}
	
}


class SubClass extends SuperClass{
	public void sInvokeA(){
//		super.A();
	}
}
