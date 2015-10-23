package basic;

import java.util.Date;
import java.util.Scanner;

public class ReadingInputStream {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.printf("%tc",new Date());
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		System.out.println(n);
		Scanner osc = new Scanner("Testtest");
		int i = 0;
		while(osc.hasNext())
		{
			System.out.print(i++ + " " + osc.next());
		}
	}

}
