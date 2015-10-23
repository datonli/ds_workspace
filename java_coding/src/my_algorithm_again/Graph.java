package my_algorithm_again;

import java.util.LinkedList;
import java.util.Queue;

class MatrixGraph {
	char V[];
	int E[][];
	int nV, nE;
	static int INF = 65535;
	boolean visited[];

	public MatrixGraph(int MAX) {
		this.V = new char[MAX];
		this.E = new int[MAX][MAX];
		this.visited = new boolean[MAX];
		for (int i = 0; i < MAX; i++) {
			this.V[i] = 0;
			this.visited[i] = false;
			for (int j = 0; j < MAX; j++) {
				if (i == j)
					this.E[i][j] = 0;
				else
					this.E[i][j] = INF;
			}
		}
		this.nV = this.nE = 0;
	}
}

public class Graph {

	public static MatrixGraph createGraph(char v[]) {
		MatrixGraph mg = new MatrixGraph(v.length);
		mg.V = v;
		mg.nV = v.length;
		return mg;
	}

	public static boolean addDirE(MatrixGraph mg, char x, char y,
			int weightValue) {
		int xIndex = 0, yIndex = 0;
		for (int i = 0; i < mg.V.length; i++) {
			if (x == mg.V[i])
				xIndex = i;

			if (y == mg.V[i])
				yIndex = i;
		}

		if (xIndex == yIndex)
			return false;
		mg.E[xIndex][yIndex] = weightValue;
		mg.nE++;
		return true;
	}

	public static boolean addE(MatrixGraph mg, char x, char y, int weightValue) {
		int xIndex = 0, yIndex = 0;
		for (int i = 0; i < mg.V.length; i++) {
			if (x == mg.V[i])
				xIndex = i;

			if (y == mg.V[i])
				yIndex = i;
		}

		if (xIndex == yIndex)
			return false;
		mg.E[xIndex][yIndex] = weightValue;
		mg.E[yIndex][xIndex] = weightValue;
		mg.nE++;
		return true;
	}

	public static void DFSTraverse(MatrixGraph mg) {
		for (int i = 0; i < mg.nV; i++)
			// int i = 1;
			if (!mg.visited[i])
				DFS(mg, i);
	}

	private static void DFS(MatrixGraph mg, int i) {
		mg.visited[i] = true;
		System.out.print(mg.V[i]);
		for (int j = 0; j < mg.nV; j++)
			if (mg.E[i][j] > 0 && mg.E[i][j] < 1000 && !mg.visited[j])
				DFS(mg, j);
	}

	public static void BFSTraverse(MatrixGraph mg) {
		Queue<Integer> q = new LinkedList<Integer>();
		for(int i = 0 ; i < mg.nV; i ++)
			if(!mg.visited[i])
			{
				mg.visited[i] = true;
				System.out.print(mg.V[i] + " ");
				q.add(i);
				while(!q.isEmpty())
				{
					q.remove();
					for(int j = 0 ; j < mg.nV; j ++)
					{
						if(mg.E[i][j] > 0 && mg.E[i][j] < 1000 && !mg.visited[j])
						{
							mg.visited[j] = true;
							System.out.print(mg.V[j] + " ");
							q.add(j);
						}
					}
				}
			}
				
	}

	public static void main(String[] args) {
		char v[] = new char[] { 'A', 'B', 'C', 'D', 'E' };
		MatrixGraph mg = createGraph(v);
		addE(mg, 'B', 'A', 9);
		addE(mg, 'B', 'C', 3);
		addE(mg, 'C', 'A', 2);
		addE(mg, 'A', 'E', 6);
		addE(mg, 'C', 'D', 5);
		addE(mg, 'D', 'E', 1);
		for (int i = 0; i < v.length; i++) {
			for (int j = 0; j < v.length; j++) {
				if (mg.E[i][j] == 65535)
					System.out.print("INF" + " ");
				else
					System.out.print(mg.E[i][j] + " ");
			}
			System.out.println("");
		}
		DFSTraverse(mg);
		System.out.println("");
		for (int i = 0; i < v.length; i++)
			mg.visited[i] = false;
		BFSTraverse(mg);
	}
}
