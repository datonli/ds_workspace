package algorithm_java;

import java.util.Arrays;

public class PackageProblem {
	/**
	 * @param value
	 *            ��ֵ
	 * @param weight
	 *            ����
	 * @param capicity
	 *            ��������
	 * @param m
	 *            ��ʾֻ��w[i],w[i+1]...w[n]��Щ��Ʒʱ,��������Ϊjʱ������ֵ
	 */
	public static void knapsack(int[] value, int[] weight, int capicity,
			int[][] m) {
		int n = value.length - 1;
		int jMax = Math.min(weight[n] - 1, capicity);
		for (int j = 0; j <= jMax; j++)
			m[n][j] = 0; // ��w[n]>j �� m[n][j]=0
		for (int j = weight[n]; j <= capicity; j++)
			m[n][j] = value[n]; // ��w[n]<=j ��m[n][j]=v[n]
		for (int i = n - 1; i >= 1; i--) {
			jMax = Math.min(weight[i] - 1, capicity);
			for (int k = 0; k <= jMax; k++)
				m[i][k] = m[i + 1][k];
			for (int h = weight[i]; h <= capicity; h++) {
				m[i][h] = Math.max(m[i + 1][h], m[i + 1][h - weight[i]]
						+ value[i]);
			}
			showArray(m);
		}
		m[0][capicity] = m[1][capicity];
		if (capicity >= weight[0])
			m[0][capicity] = Math.max(m[0][capicity],
					m[1][capicity - weight[0]] + value[0]);
		System.out.println("bestw =" + m[0][capicity]);
	}

	public static void showArray(int[][] m) {
		for (int[] a : m) {
			System.out.println(Arrays.toString(a));
		}
		System.out.println("-------------------------------------------");
	}

	public static void traceback(int[][] m, int[] w, int c, int[] x) {// ��������ֵ������Ž�
		int n = w.length - 1;
		for (int i = 0; i < n; i++)
			if (m[i][c] == m[i + 1][c])
				x[i] = 0;
			else {
				x[i] = 1;
				c -= w[i];
			}
		x[n] = (m[n][c] > 0) ? 1 : 0;
	}

	public static void main(String[] args) {
		int[] ww = { 2, 1, 3, 2 };
		int[] vv = { 12, 10, 20, 15 };
		int[][] mm = new int[4][13];
		int MaxWeight = 5;
		knapsack(vv, ww, MaxWeight, mm);
		int[] xx = new int[ww.length];
		traceback(mm, ww, 12, xx);
		for (int i = 0; i < xx.length; i++)
			System.out.println(xx[i]);
	}
}
