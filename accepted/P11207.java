import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class P11207 {
	public static void main(String[] args) throws Exception {
		while (true) {
			int N = Reader.nextInt();
			if (N == 0)
				break;
			double max = 0;
			int id = 0;
			for (int i = 0; i < N; i++) {
				int W = Reader.nextInt();
				int H = Reader.nextInt();
				double l = Math.max(W, H);
				double s = Math.min(W, H);
				double tmp = Math.max(Math.min(l / 4.0, s), s / 2.0);
				if (tmp > max) {
					max = tmp;
					id = i + 1;
				}
			}
			System.out.println(id);
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