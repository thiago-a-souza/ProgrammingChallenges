import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class P11834 {
	public static void main(String[] args) throws Exception {
		while(true) {
			int L = Reader.nextInt();
			int C = Reader.nextInt();
			int R1 = Reader.nextInt();
			int R2 = Reader.nextInt();
			if(L == 0 && C == 0 && R1 == 0 && R2 == 0)
				break;
			if(R1*2 > L || R1*2 > C || R2*2 > L || R2*2 > C)
				System.out.println("N");
			else {
				double w = L - (R1+R2);
				double h = C - (R1+R2);
				double sq = Math.sqrt(w*w + h*h);
				if(sq >= (double)(R1+R2))
					System.out.println("S");
				else
					System.out.println("N");
			}
			
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

}