import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class P11909 {
	public static void main(String[] args) {
		while (true) {
			try {
				int L = Reader.nextInt();
				int W = Reader.nextInt();
				int H = Reader.nextInt();
				int theta = Reader.nextInt();

				double rad = (Math.PI * theta) / 180.0;

				if (theta == 0)
					System.out.printf("%.3f mL\n", (double) L * W * H);
				else if (theta == 90)
					System.out.println("0.000 mL");
				else if (L * Math.tan(rad) <= H) {
					double volTot = L * W * H;
					double X = Math.tan(rad) * L;
					double volTri = X * L * W / 2.0;
					System.out.printf("%.3f mL\n", volTot - volTri);
				} else {
					double X = H / Math.tan(rad);
					double volTri = X * H * W / 2.0;
					System.out.printf("%.3f mL\n", volTri);
				}

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

}