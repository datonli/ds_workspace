package concurrency_programming;

public class RunnablePrint {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Money money = new Money(10);
		MultiPrint2 mp2 = new MultiPrint2(money);
		Thread t1 = new Thread(mp2);
		Thread t2 = new Thread(mp2);
		t2.start();
		t1.start();
	}

}


class Money{
	int count;
	public Money(int count)
	{
		this.count  = count;
	}
	
}

class MultiPrint2 implements Runnable{
	
	private  int count ;
	public MultiPrint2(Money money)
	{
		this.count = money.count;
	}
	public void run()
	{
		System.out.println(Thread.currentThread().getName() + " : count is " + getCount());
	}
	private synchronized int getCount()
	{
		return count ++;
	}
}