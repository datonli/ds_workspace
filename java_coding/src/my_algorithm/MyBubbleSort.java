package my_algorithm;

public class MyBubbleSort {
	
	public static void swap(int[] a,int i, int j)
	{
		int tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}
	
	public void bubbleSort(int[] a)
	{
		for(int i = 1;i < a.length; i ++)
			for(int j = a.length-2;j >= i; j --)
			{
				if(a[j] > a[j+1])
					swap(a,j,j+1);
			}
	}
	
	
//	a[]的第一位a[0]用来存储些其他额外信息
	public static void main(String[] args)
	{
		int[] a = new int[]{6,4,6,2,7,12,3};
		MyBubbleSort mbs = new MyBubbleSort();
		mbs.bubbleSort(a);
		for(int i = 0; i < a.length; i++)
			System.out.print(a[i] + " ");
	}
}
