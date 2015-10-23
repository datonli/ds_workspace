package test;

public class TestBreak {
	public static void main(String[] args)
	{
		for(int i = 0 ; i < 5; i ++)
		{
			for(int j = 0; j <5; j ++)
			{
				if(j == 3)
					break;
				System.out.print(j + " ");
			}
			System.out.println("");
			System.out.println(i + " ");
		}
	}
}
