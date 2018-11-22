import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class P1225 {
	public static void main(String[] args) throws Exception {
		int N = Reader.nextInt();
		while (N-- > 0) {
			int val = Reader.nextInt();
			int ans[] = new int[10];
			for (int i = 1; i <= val; i++) {
				Integer tmp = i;
				String str = tmp.toString();
				int len = str.length();
				for (int j = 0; j < len; j++)
					ans[(int) (str.charAt(j) - '0')]++;
			}
			for (int i = 0; i < 9; i++)
				System.out.print(ans[i] + " ");
			System.out.println(ans[9]);

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