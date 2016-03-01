import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class P920 {
	public static void main(String[] args) throws Exception {
		int C = Reader.nextInt();
		while (C-- > 0) {
			int N = Reader.nextInt();
			Point[] p = new Point[N];
			for (int i = 0; i < N; i++) {
				p[i] = new Point();
				p[i].x = Reader.nextInt();
				p[i].y = Reader.nextInt();
			}
			Arrays.sort(p);
			//int lastx = p[N - 1].x;
			int lasty = p[N - 1].y;
			double dist = 0.0;

			for (int i = N - 2; i >= 0; i--) {
				if (p[i].y > lasty) {
					double M = ((double)(p[i].y - p[i+1].y))/((double)(p[i].x - p[i+1].x));
					double X = ((double)(lasty - p[i].y + M*p[i].x))/M;
					dist += Math.sqrt((X -p[i].x)*(X -p[i].x) + (p[i].y - lasty)*(p[i].y - lasty)); 
					lasty = p[i].y;
				}
			}
			System.out.printf("%.2f\n",dist);

		}
	}
}

class Point implements Comparable<Point> {
	int x, y;

	@Override
	public int compareTo(Point o) {
		return this.x - o.x;
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