package my_algorithm_again;

import java.util.ArrayList;
import java.util.List;

public class LIS {

	static int MAX = 20;

	public static List<int[]> dp(int[] s, List<int[]> l) {
		if (l.isEmpty()) {
			int[] q = new int[MAX];
			for(int k = 0; k < q.length ; k ++)
				q[k] = 0;
			q[0] = 1;
			q[1] = s[0];
			l.add(q);
		}
		for (int top = 1; top < s.length; top++) {
			boolean flag = false;
			for (int i = 0; i < l.size(); i++) {
				if (s[top] >= l.get(i)[l.get(i)[0]]) {
					l.get(i)[++l.get(i)[0]] = s[top];
//					l.get(i)[0]++;
					flag = true;
				}
			}
			if (flag == false) {
				int[] p = new int[MAX];
				for(int k = 0; k < p.length ; k ++)
					p[k] = 0;
				p[0] = 1;
				p[1] = s[top];
				l.add(p);
			}
			flag = false;

		}

		return l;
	}

	public static void main(String[] args) {
		int[] s = new int[] { 1, 8, 2, 7, 3, 4, 1, 6, 5 };
		List<int[]> l = new ArrayList<int[]>();
		l = dp(s, l);
		for (int i = 0; i < l.size(); i++) {
			for (int j = 0; j <= l.get(i)[0]; j++)
				System.out.print(l.get(i)[j] + " ");
			System.out.println("");
		}
	}

}
