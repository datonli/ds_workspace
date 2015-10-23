package concurrency_programming;

import java.util.ArrayList;
import java.util.List;

public class MessageSystem {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MessageQueue queue = new MessageQueue(5);
		new Producer(queue).start();
		new Producer(queue).start();
		new Consumer(queue).start();
		new Producer(queue).start();
		new Consumer(queue).start();
		
	}

}

class MessageQueue{
	private int bufferSize;
	private List<String> buffer = new ArrayList<String>();
	public MessageQueue(int bufferSize)
	{
		if(bufferSize <= 0)
			throw new IllegalArgumentException("Size is illegal!");
		this.bufferSize = bufferSize;
	}
	
	public synchronized boolean isFull(){
		return buffer.size() == bufferSize;
	}
	
	public synchronized boolean isEmpty(){
		return buffer.isEmpty();
	}
	
	public synchronized void put(String message){
		while(isFull())
		{
			System.out.println("Queue is full");
			try{
				//set current thread to wait
				wait();
			}catch(InterruptedException ex){
				//do something to wake me up
			}
		}
		buffer.add(message);
		System.out.println("Queue receives message " + message + " !");
		notifyAll();
	}
	
	public synchronized String get(){
		String message = null;
		while(isEmpty()){
			System.out.println("There is no message in queue.");
			try{
				wait();
			}catch (InterruptedException ex){
				
			}
		}
		message = buffer.remove(0);
		notifyAll();
		return message;
	}
}

class Producer extends Thread{
	private static int count = 0;
	private MessageQueue queue = null;
	public Producer(MessageQueue queue){
		this.queue = queue;
	}
	public void run()
	{
		for(int i = 0; i < 10; i ++){
			queue.put(generateMessage());
		}
	}
	private synchronized String generateMessage(){
		String msg = "MSG#"+count;
		count ++;
		return msg;
	}
}

class Consumer extends Thread{
	private MessageQueue queue = null;
	public Consumer (MessageQueue queue){
		this.queue = queue;
	}
	public void run(){
		for(int i = 0; i < 10; i ++)
		{
			System.out.println("Consumer downloads " + queue.get() + " from the queue.") ;
			
		}
		
	}
}

