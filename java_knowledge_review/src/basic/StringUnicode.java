package basic;

public class StringUnicode {

	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String s = "Java\u2122";
		System.out.println(s);
		String os = s;
		os = os.substring(0,3);
		System.out.println(s);
		os = s;
		
		
		/**
		 *  notion:
		 *  "==" stands for the same address if it's used to object comparation.
		 *  "equals" represent for the same value used to object comparation,even they aren't the same address.
		 */
		
		if(os.equals(s))
			System.out.println("equal");
		if(os == s)
			System.out.println("==");
		String ns = new String(s);
		if(ns.equals(s))
			System.out.println("equal");
		if(ns == s)
			System.out.println("==");
		
		/**
		 *  understand the object pool 
		 *  when initial an instance, JVM will find in the object pool if same instance is existed.
		 *  If yes,it will refer to that instance directly.That causes the same address thing happend.
		 */
		String oos = "Java\u2122";
		if(oos == s)
			System.out.println("Same address! Reference to object pool 's same instance!");
		else
			System.out.println("Different address!");
		
		
		
	}

}
