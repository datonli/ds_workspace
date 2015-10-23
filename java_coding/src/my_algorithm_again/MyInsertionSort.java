package my_algorithm_again;

public class MyInsertionSort {
	public static void main(String[] args) {
		int[] a = new int[] { 0, 12, 40, 20, 15, 32, 1, 4, 3 };
		insertionSort(a);
		for (int i = 0; i < a.length; i++)
			System.out.print(a[i] + " ");

	}

	private static void insertionSort(int[] a) {
		for (int i = 1; i < a.length; i++) {
			int v = a[i];
			int j = i - 1;
			for (; j >= 0; j--) {
				if (a[j] > v)
					a[j + 1] = a[j];
				else
					break;
			}
			a[j + 1] = v;
		}
	}
}
