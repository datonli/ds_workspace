package basic;

/**
 * understand the object's method which all object have:
 * 1)clone and finalize both are protected , if want to use it , should over-write it as public first
 * 2) clone comes from Cloneable(interface)
 * 3) finalize overload directly
 * @author Daniel Li
 *
 */
public class DeepCopy {

	public static void main(String[] args) throws Throwable {
		// TODO Auto-generated method stub
		Object o;
		Sample s = new Sample();
		s.finalize();
		int[] a = new int[]{1,2,3};
		int[] b = a.clone();
		if(a.equals(b))
			System.out.println("equals");
		if(a == b)
			System.out.println("==");
	}
}


class Sample implements Cloneable{
	int num;
	String s ;
	public Sample(){
		
	}
	
	public native void test();
	
	public void finalize() throws Throwable{
		super.finalize();
	}
	
	public Sample clone() throws CloneNotSupportedException 
	{
		return (Sample)super.clone();
	}
}