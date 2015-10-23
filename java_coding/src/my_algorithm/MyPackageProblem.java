package my_algorithm;

public class MyPackageProblem {

	static int W;
	static int[] weight;
    static int[] value;
	static int[][] V;

	public static void main(String[] args) {
		value = new int[] { 12, 10, 20, 15 };
        weight = new int[] { 2, 1, 3, 2 };
        W = 5;
		V = new int[value.length + 1][W + 1];

		for (int i = 1; i < V.length; i++)
			for (int j = 1; j < W + 1; j++) {
				V[i][j] = -1;
			}
		System.out.println(MFKnapsack(value.length, W));
	}


	public static int MFKnapsack(int i, int j) {
		int v = 0;
		if(V[i][j] < 0)
		{
			if(j < weight[i-1])
				v = MFKnapsack(i-1, j);
			else
			{
				v = Math.max(MFKnapsack(i-1, j), MFKnapsack(i-1, j-weight[i-1]) + value[i-1]);
				V[i][j] = v;
			}
		}
		return V[i][j];
	}
	


}
