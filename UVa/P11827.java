import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class P11827 {
	public static int gcd(int a, int b) {
		if (b == 0)
			return a;
		return gcd(b, a % b);
	}

	public static void main(String[] args) throws Exception {
		int n = Reader.nextInt();
		while (n-- > 0) {

			String[] s = Reader.nextLine().split("\\s+");
			int len = s.length;
			int nbr[] = new int[len];
			for (int i = 0; i < len; i++)
				nbr[i] = Integer.parseInt(s[i]);

			int max = -1, tmp = 0;
			for (int i = 0; i < len - 1; i++)
				for (int j = i + 1; j < len; j++) {
					tmp = gcd(nbr[i], nbr[j]);
					if (tmp > max)
						max = tmp;
				}
			System.out.println(max);

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