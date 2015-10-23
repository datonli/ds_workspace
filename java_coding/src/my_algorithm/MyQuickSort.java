package my_algorithm;

public class MyQuickSort {

	// static int[] a;

	public static void main(String[] args) {
		int[] a = new int[] { 0, 12, 40, 20, 15, 32, 1, 4, 3 };
		quickSort(a, 0, a.length - 1);
		for (int i = 0; i < a.length; i++)
			System.out.print(a[i] + " ");
	}

	public static void quickSort(int[] a, int start, int end) {
		int s = 0;
		if (start < end) {
			s = Partition(a, start, end);
			quickSort(a, start, s - 1);
			quickSort(a, s + 1, end);
		}

	}

	private static int Partition(int[] a, int start, int end) {
		int p = a[start], i = start, j = end;
		while (i < j) {
			while (a[j] >= p && i < j)
				j--;
			swap(a, i, j);
			while (a[i] <= p && i < j)
				i++;
			swap(a, i, j);
		}
		return i;
	}

	private static void swap(int[] a, int i, int j) {
		int tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}

}
