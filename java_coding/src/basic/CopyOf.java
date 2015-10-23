package basic;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class CopyOf {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		List<String> a = new ArrayList<String>();
		a.add("A");
		a.add("B");
		
//		reference copy
//		== is true and equal is true, because they point to same address 
		List<String> b = a;
//		a and b are just the address!
		if(b.equals(a))
			System.out.println("a equals b");
		
//		value copy
//		two methods:  1) CopyOf, implements by themselves ; 2) new a another object and copy every build-in type value.
//		c and d have same value but not the same address
		int[] c = new int[]{1,2,3,4};
		int[] d = Arrays.copyOf(c, c.length);
		
		for(int cv : c)
			System.out.print(cv + " ");
		System.out.println();
		
		for(int dv : d)
			System.out.print(dv + " ");
		System.out.println();
		
		if(d.equals(c))
			System.out.println("Same value");
		
//		let look around what "clone" do
		int[] e = c.clone();
		if(e == c)
			System.out.println("Same Address");
//		using "equal" to an object is always wrong.Because it's comparing the address just like below : 
//		e is just stand for an address.Of course they are different.
		if(e.equals(c))
			System.out.println("Same value");
		
		for ( int ev : e)
			System.out.print(ev + " ");
		
	} 

}
