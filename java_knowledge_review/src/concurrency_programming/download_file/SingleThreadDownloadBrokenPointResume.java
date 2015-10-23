package concurrency_programming.download_file;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.io.RandomAccessFile;
import java.net.HttpURLConnection;
import java.net.URL;

public class SingleThreadDownloadBrokenPointResume {

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
			
			osf.seek(start);
			
			HttpURLConnection http = (HttpURLConnection) url.openConnection();
			http.setRequestProperty("User-Agent","NetFox"); 
			http.setRequestProperty("RANGE", "bytes="+start+"-");
			long len = http.getContentLengthLong();
			System.out.println("File total length : " + len);
			System.out.println("Starting download from " + start);
			
			InputStream is = http.getInputStream();
			byte[] b = new byte[1024];
			int i ;
			long l = 0;
			while((i = is.read(b, 0, b.length)) != -1 && l < len)
			{
				osf.write(b, 0, i);
				l += i;
			}
			
			is.close();
			osf.close();
			http.disconnect();
			
			System.out.println("Download complete!");
			
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}
