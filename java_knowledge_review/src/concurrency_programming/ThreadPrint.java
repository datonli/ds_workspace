package concurrency_programming;

public class ThreadPrint {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Thread t1 = new MultiPrint();
		Thread t2 = new MultiPrint();
		t1.start();
		t2.start();
	}

}

class MultiPrint extends Thread{
	private static int count = 0;
	public void run()
	{
		System.out.println("Count is : " + count );
	}
}
