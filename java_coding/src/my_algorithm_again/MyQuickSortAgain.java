package my_algorithm_again;

public class MyQuickSortAgain {
	public static void quickSort(int[] a, int p, int q) {
		if (p < q) {
			int s = Parition(a, p, q);
			quickSort(a, p, s - 1);
			quickSort(a, s + 1, q);
		}
	}

	private static int Parition(int[] a, int p, int q) {
		int x = a[p];
		int i = p;
		int j = p + 1;
		for (; j <= q; j++) {
			if (a[j] <= x) {
				i++;
				swap(a, i, j);
			}
		}
		swap(a, i, p);
		return i;
	}

	private static void swap(int[] a, int i, int j) {
		int tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}

	public static int binarySearch(int[] a , int l,int r,int K)
	{
		while(l<=r)
		{
			int m = (l+r)/2;
			if(a[m] == K)
				return m;
			else if(a[m] > K)
				r = m -1;
			else
				l = m + 1;
		}
		return -1;
	}
	
	public static void main(String[] args) {
		int[] a = new int[] { 0, 12, 40, 20, 15, 32, 1, 4, 3 };
		quickSort(a, 0, a.length - 1);
		for (int i = 0; i < a.length; i++)
			System.out.print(a[i] + " ");
		
		System.out.println("\n" + binarySearch(a,0,a.length-1,4));
	}
}
