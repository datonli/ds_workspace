package algorithm_java;

import java.util.ArrayList;
import java.util.List;

public class LIS {
	public static void main(String[] args) {
		int[] s = new int[] { 1, 8, 2, 7, 3, 4, 1, 6, 5 };
		List<int[]> l = new ArrayList<int[]>();
//		l = dp(s, l);
		for (int i = 0; i < l.size(); i++) {
			for (int j = 0; j <= l.get(i)[0]; j++)
				System.out.print(l.get(i)[j] + " ");
			System.out.println("");
		}
	}
}
