import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class P460 {
	public static void main(String[] args) throws Exception {

		int t = Reader.nextInt();
		while (t-- > 0) {
			int ax = Reader.nextInt();
			int ay = Reader.nextInt();
			int bx = Reader.nextInt();
			int by = Reader.nextInt();

			int cx = Reader.nextInt();
			int cy = Reader.nextInt();
			int dx = Reader.nextInt();
			int dy = Reader.nextInt();

			ax = Math.max(ax, cx);
			bx = Math.min(bx, dx);

			ay = Math.max(ay, cy);
			by = Math.min(by, dy);

			if (ax >= bx || ay >= by)
				System.out.println("No Overlap");
			else
				System.out.printf("%d %d %d %d\n", ax, ay, bx, by);

			if (t > 0)
				System.out.println();

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