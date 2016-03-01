import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class P10551 {
	public static void main(String[] args) throws Exception {
		while (true) {
			int b = Reader.nextInt();
			if (b == 0)
				break;
			String nbr = Reader.next();
			BigInteger base = new BigInteger(new Integer(b).toString());
			BigInteger big = new BigInteger(nbr, b);
			BigInteger m = new BigInteger(Reader.next(), b);

			big = big.mod(m);
			String ans = "";
			while (!big.equals(BigInteger.ZERO)) {
				ans = big.mod(base).toString() + ans;
				big = big.divide(base);
			}
			if (ans.length() >= 1)
				System.out.println(ans);
			else
				System.out.println("0");
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