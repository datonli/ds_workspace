package my_algorithm;

public class MyHeapSort {
	public void HeapBottomUp(int[] a, int start, int end) {
		int k = 0, v = 0, n = end;
		for (int i = n / 2; i >= start; i--) {
			k = i;
			v = a[k];
			boolean heap = false;
			while (!heap && 2 * k <= n) {
				int j = 2 * k;
				if (j < n)
					if (a[j] < a[j + 1])
						j = j + 1;
				if (v >= a[j])
					heap = true;
				else {
					a[k] = a[j];
					k = j;
				}
			}
			a[k] = v;
		}
	}

	public static void main(String[] args) {
		int[] a = new int[] { 0, 1, 3, 2,8,5 };
		MyHeapSort mhs = new MyHeapSort();
		mhs.HeapBottomUp(a, 1, a.length - 1);
		for (int i = 0; i < a.length; i++)
			System.out.print(a[i] + ",");
		System.out.println("");
		mhs.swap(a, 3, 0);
		mhs.HeapBottomUp(a, 1, a.length - 1);
		for (int i = 0; i < a.length; i++)
			System.out.print(a[i] + ",");
	}

	public void swap(int[] a, int i, int j) {
		int tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}
}
