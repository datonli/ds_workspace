package concurrency_programming;

public class CalculatorThread {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		for(int i = 0; i < 10; i ++)
		{
			new Thread(new Calculator(i)).start();
		}
	}
}

class Calculator implements Runnable{
	private int num;
	public Calculator(int num)
	{
		this.num = num;
	}
	
	public void run()
	{
		for(int i = 0;i < 10; i ++)
			System.out.printf("%s : %d * %d = %d\n",Thread.currentThread().getName(),num,i,num*i);
	}
}