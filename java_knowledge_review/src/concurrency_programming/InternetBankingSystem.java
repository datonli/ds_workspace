package concurrency_programming;

public class InternetBankingSystem {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Account accountObject = new Account(100);
		new Thread(new DesopitThread(accountObject,20)).start();
		new Thread(new DesopitThread(accountObject,50)).start();
		new Thread(new WithdrawThread(accountObject,10)).start();
		new Thread(new WithdrawThread(accountObject,90)).start();
	}

}


class Account {
	private double balance = 0;
	public Account(double balance)
	{
		this.balance = balance;
	}
	public synchronized void deposit(double amount){
		if(amount < 0)
			throw new IllegalArgumentException("Can't deposit.");
		this.balance += amount;
		System.out.println("Deposit " + amount + " in thread " + 
					+ Thread.currentThread().getId() + ", balance is " + this.balance);
		
	}
	public synchronized void withdraw(double amount ){
		if(amount < 0 || amount > this.balance)
			throw new IllegalArgumentException("Can't withdraw!");
		this.balance -= amount;
		System.out.println("withdraw " + amount + " in thread " + 
				+ Thread.currentThread().getId() + ", balance is " + this.balance);
	}
}

class WithdrawThread implements Runnable{
	private Account account;
	private double amount;
	public WithdrawThread(Account account,double amount)
	{
		this.account = account;
		this.amount = amount;
	}
	public void run()
	{
		account.withdraw(amount);
	}
}

class DesopitThread implements Runnable{
	private Account account;
	private double amount;
	public DesopitThread(Account account,double amount)
	{
		this.account = account;
		this.amount = amount;
	}
	public void run()
	{
		account.deposit(amount);
	}
}