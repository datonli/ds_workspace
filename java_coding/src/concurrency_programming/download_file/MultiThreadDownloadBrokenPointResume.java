package concurrency_programming.download_file;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.io.RandomAccessFile;
import java.net.HttpURLConnection;
import java.net.URL;

public class MultiThreadDownloadBrokenPointResume {
	
	private static String urlt = "https://www.python.org/ftp/python/3.4.3/python-3.4.3.msi";
	private static String filePath = "D:\\python-3.4.3.msi"; 
	
	public static void main(String[] args) {
		try {
			URL url = new URL(urlt);
			
			File f = new File(filePath);
			RandomAccessFile osf = new RandomAccessFile(f, "rw");
			
			long start = 0;
			if(f.exists())
			{
				start = f.length();
			}
			
			HttpURLConnection http = (HttpURLConnection) url.openConnection();
			long allLen = http.getContentLengthLong();
			System.out.println("Whole file length : " + allLen);
			System.out.println("Start from " + start);
			int tn = 4;
			long nLen = allLen-start;
			long eLen = nLen/tn;
			long bn;
			
			for(int i = 0; i < tn; i ++)
			{
				if((tn-1) == i)
					bn = nLen - (tn-1)*eLen;
				else
					bn = eLen;
				new Thread(new DownloadThreadBrokenPointResume(filePath,urlt,i*eLen,bn)).start();
			}
			
			
			osf.close();
			http.disconnect();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
	}

}


class DownloadThreadBrokenPointResume implements Runnable{

	private long len;
	private long start;
	private String urlt;
	private String filePath;
	public DownloadThreadBrokenPointResume(String filePath,String urlt,long start,long eLen){
		this.filePath = filePath;
		this.urlt = urlt;
		len = eLen;
		this.start = start;
	}
	
	@Override
	public void run() {
		try {
			System.out.println(Thread.currentThread().getName() + " download begin ...");
			URL url = new URL(urlt);
			HttpURLConnection http = (HttpURLConnection) url.openConnection();
			http.setRequestProperty("User-Agent","NetFox"); 
			http.setRequestProperty("RANGE", "bytes="+start+"-"+(start+len));
			
			
			File f = new File(filePath);
			RandomAccessFile osf = new RandomAccessFile(f, "rw");
			osf.seek(start);
			
			
			InputStream is = http.getInputStream();
			byte b[] = new byte[1024];
			long l = 0;
			int i;
			while((i = is.read(b, 0, b.length)) != -1 && l < len){
				osf.write(b, 0, i);
				l += i;
			}
			
			is.close();
			osf.close();
			http.disconnect();
			System.out.println(Thread.currentThread().getName() + " download complete!");
		} catch (IOException e) {
			
			e.printStackTrace();
		}
		
	}
	
}






