package my_algorithm;

public class MyEmergeSort {
	
	static int[] tr2 = new int[10];
	public void MergeSort(int[] a) {
		MSort(a, a, 1, a.length - 1);
	}

	private void MSort(int[] a, int[] tr1, int i, int j) {
		int m;
//		int[] tr2 ;
		if (i == j)
			tr1[i] = a[i];
		else {
			m = (i + j) / 2;
			MSort(a, tr2, i, m);
			MSort(a, tr2, m + 1, j);
			Merge(tr2, tr1, i, m, j);
		}
	}

	private void Merge(int[] tr22, int[] tr1, int i, int m, int n) {
		int p, q, k;
		for (p = m + 1, k = i; i <= m && p <= n; k++) {
			if (tr22[k] < tr22[p])
				tr1[k] = tr22[i++];
			else
				tr1[k] = tr22[p++];
		}

		if (k <= m) {
			for (q = 0; q <= m - k; q++)
				tr1[k + q] = tr22[k + q];
		}
		if (p <= n) {
			for (q = 0; q <= n - p; q++)
				tr1[k + q] = tr22[k + q];
		}
		for (int f = 0; f < tr1.length; f++)
			System.out.print(tr1[f] + ",");
		System.out.println("");
	}

	public static void main(String[] args) {
		int[] a = new int[] {10,12, 1, 4, 7, 2, 3, 11 };
		
		MyEmergeSort mes = new MyEmergeSort();
//		mes.Merge(a, tr2, 0, 2, 5);
		 mes.MergeSort(a);
		for (int i = 0; i < tr2.length; i++)
			System.out.print(tr2[i] + ",");

	}
}
