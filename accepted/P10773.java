import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class P10773 {
	public static void main(String[] args) throws Exception {
		int T = Reader.nextInt();
		int line = 1;
	//	System.out.println("T="+T);
		while (T-- > 0) {
			double d = Reader.nextDouble();
			double v = Reader.nextDouble();
			double u = Reader.nextDouble();
			//System.out.println("d="+d+ " v="+v+" u="+u);

			if (u == 0 || v >= u || v == 0)
				System.out.printf("Case %d: can't determine\n", line);
			else {
				double t1 = d / u;
				double t2 = d / Math.sqrt(u * u - v * v);
				System.out.printf("Case %d: %.3f\n", line, Math.abs(t1 - t2));
			}
			line++;
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