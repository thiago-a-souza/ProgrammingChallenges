import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class P10892 {
	public static long gcd(long a, long b) {
		if (b == 0)
			return a;
		return gcd(b, a % b);
	}
	
	public static long lcm(long a, long b) {
	     return (a/gcd(a,b))*b;
	}

	public static void main(String[] args) throws Exception {
		while (true) {
			int n = Reader.nextInt();
			if (n == 0)
				break;

			int limit = (int) Math.sqrt(n);
			List<Integer> list = new ArrayList<Integer>();
			
			for (int m = 1; m <= limit; m++) {
				if (n % m == 0) {
					list.add(m);
					if( m!= n/m)
						list.add(n/m);
				}
			}
			
			
			int ans = 0;
			for(int i=0; i<list.size(); i++)
				for(int j=i; j<list.size(); j++)
					if(lcm(list.get(i), list.get(j) ) == n)
						ans++;
		    System.out.println(n+" "+ans);
			

		}
	}
}

class Reader {
	static BufferedReader reader;
	static StringTokenizer tokenizer;

	static {
		reader = new BufferedReader(new InputStreamReader(System.in));
		tokenizer = new StringTokenizer("");
	}

	static String next() throws IOException {
		while (!tokenizer.hasMoreTokens()) {
			String line = reader.readLine();
			if (line == null)
				return null;
			tokenizer = new StringTokenizer(line);
		}
		return tokenizer.nextToken();
	}

	static int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	static String nextLine() throws IOException {
		return reader.readLine();
	}

}