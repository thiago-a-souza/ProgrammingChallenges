import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class P10814 {
	public static void main(String[] args) throws Exception {
		int n = Reader.nextInt();
		while (n-- > 0) {
			BigInteger a = new BigInteger(Reader.next());
			Reader.next();
			BigInteger b = new BigInteger(Reader.next());
			BigInteger gcd = a.gcd(b);
			System.out.println(a.divide(gcd) + " / " + b.divide(gcd));
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