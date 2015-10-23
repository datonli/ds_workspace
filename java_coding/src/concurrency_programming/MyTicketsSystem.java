package concurrency_programming;

public class MyTicketsSystem {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Tickets t = new Tickets(5);
		WindowService ws = new WindowService(t);
		for(int i = 0; i < 3; i ++)
			new Thread(ws).start();
	}

}

class WindowService implements Runnable{
	private Tickets t;
	public WindowService(Tickets t){
		this.t = t;
	}
	public void run(){
		while(!t.isEmpty()){
			t.sell();
			System.out.println("sell information : " + Thread.currentThread().getName() + " sell one ticket,last " + t.getNum() + " tickets!");
		}
//		throw new IllegalArgumentException("Sell off");
	}
}

class Tickets{
	private int num;
	public Tickets(int num){
		this.num= num;
	}
	public int getNum(){
		return this.num;
	}
	public  boolean isEmpty(){
		return 0==num;
	}
	public  void sell(){
		if(0 == num)
			throw new IllegalArgumentException("ticket empty!");
		num--;
	}
}
