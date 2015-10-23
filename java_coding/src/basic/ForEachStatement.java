package basic;

public class ForEachStatement {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] a = new int[20];
		for( int ea : a)
			ea = 1;
		System.out.println(a[18]);	
		for(int i = 0;i < a.length; i ++)
			a[i] = i;
		for(int ea : a)
			System.out.println(ea);
		
	}

}
