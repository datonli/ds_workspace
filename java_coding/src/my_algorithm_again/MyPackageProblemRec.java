package my_algorithm_again;

import java.util.Stack;

public class MyPackageProblemRec {
	static int W;
	static int[] weight;
    static int[] value;
	static int[][] V;

	public static void main(String[] args) {
		value = new int[] { 12, 10, 20, 15 };
        weight = new int[] { 2, 1, 3, 2 };
        W = 5;
		V = new int[value.length + 1][W + 1];
		Stack<int[]> path = new Stack<int[]>();
		
		
		for(int i = 1; i <= 4; i ++)
			for(int j = 1; j <= 5; j ++)
			{
				if(j >= weight[i-1])
//					V[i][j] = Math.max(V[i-1][j], value[i-1] + V[i-1][j-weight[i-1]]);
				{
					if(V[i-1][j] >= value[i-1] + V[i-1][j-weight[i-1]])
					{
						V[i][j] = V[i-1][j];
						path.add(new int[]{i-1,j});
					}
					else
					{
						V[i][j] = value[i-1] + V[i-1][j-weight[i-1]];
						path.add(new int[]{i-1,j-weight[i-1]});
					}
				}
				else
				{
					V[i][j] = V[i-1][j];
					path.add(new int[]{i-1,j});
				}
			}
		
		for(int i = 0; i < V.length; i ++)
		{
			for(int j = 0; j < V[0].length; j ++)
				System.out.print(V[i][j] + " ");
			System.out.println("");
		}
		System.out.println(V[4][5]);
		for(int i = 0; i < path.size(); i ++)
		{
			System.out.println("( "+ (path.get(i)[0]+1) + " , " + (path.get(i)[1]+1) + " )");
		}
		
	}
	
}
