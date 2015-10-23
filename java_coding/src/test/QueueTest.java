package test;

import java.util.LinkedList;
import java.util.Queue;

public class QueueTest {
	public static void main(String[] args) {
		// Queue<int> q = new Queue<int>();
		Queue<Integer> q = new LinkedList<Integer>();
		for (int i = 0; i < 8; i++)
			q.add(i);
//		for (int i = 0; i < q.size(); i++)
			System.out.print(q.toString() + " ");
		q.remove();
		System.out.print(q.toString() + " ");
//		for (int i = 0; i < q.size(); i++)
//			System.out.print(q.poll() + " ");
	}
}
