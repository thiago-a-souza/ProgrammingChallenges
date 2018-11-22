import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class P787 {
	public static void main(String[] args) throws Exception {
		int n;
		Integer aux;
		BigInteger v[] = new BigInteger[105];
		while (true) {
			try {
				n = 0;
				while (true) {
					aux = Reader.nextInt();
					if (aux == -999999)
						break;
					v[n++] = new BigInteger(aux.toString());
				}

				// /////////////
				BigInteger max = new BigInteger("-999999999");
				for (int i = 0; i < n; i++) {
					BigInteger tmp = new BigInteger("1");
					for (int j = i; j < n; j++) {
						tmp = tmp.multiply(v[j]);
						//tmp = tmp * v[j];
						if(tmp.compareTo(max) == 1)
							max = tmp;
					}
				}
				System.out.println(max);
				// /////////////

			} catch (Exception e) {
				break;
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

	static String nextLine() throws IOException {
		return reader.readLine();
	}

}

