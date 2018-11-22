import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class P10140 {

	public static void main(String[] args) {
		int i = 0, j = 0;

		while (true) {
			try {
				int L = Reader.nextInt();
				int U = Reader.nextInt();
				int d = U - L + 1;
				int max = (int) Math.sqrt(U);
				boolean flag[] = new boolean[d];
				for (i = 0; i < d; i++)
					flag[i] = true;

				if (L % 2 == 0) {
					if (L == 2)
						i = 2;
					else
						i = 0;
				} else
					i = 1;

				for (; i < d; i += 2)
					flag[i] = false;

				for (i = 3; i <= max; i += 2) {
					if (i > L && !flag[i - L])
						continue;
					if (L < i)
						j = 2 * i;
					else
						j = L - (L % i) + i;
					j -= L;

					for (; j < d; j += i)
						flag[j] = false;

				}

				if (L == 1) {
					flag[0] = false;
					flag[1] = true;
				} else if (L == 0) {
					flag[0] = false;
					flag[1] = false;
					flag[2] = true;
				}

				int mindist = Integer.MAX_VALUE;
				int maxdist = -1;
				int x1 = -1, y1 = -1, x2 = -1, y2 = -1;
				int tmp;

				for (i = 0; i < d; i++) {
					if (flag[i]) {
						tmp = i++;
						while (i < d && !flag[i])
							i++;
						if (i >= d)
							break;
						if (i - tmp < mindist) {
							mindist = i - tmp;
							x1 = tmp + L;
							y1 = i + L;
						}

						if (i - tmp > maxdist) {
							maxdist = i - tmp;
							x2 = tmp + L;
							y2 = i + L;
						}
						i--;

					}
				}

				if (x1 >= 0)
					System.out.printf(
							"%d,%d are closest, %d,%d are most distant.\n", x1,
							y1, x2, y2);
				else
					System.out.printf("There are no adjacent primes.\n");

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