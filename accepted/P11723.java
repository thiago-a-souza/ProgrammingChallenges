import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class P11723 {
	public static void main(String[] args) throws Exception {
		int R, N;
		int line = 1;
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(
				System.out));

		while (true) {
			R = Reader.nextInt();
			N = Reader.nextInt();
			if (R == 0 && N == 0)
				break;

			int count = N;
			if (count >= R) {
				bw.write("Case " + line + ": 0\n");

			} else {
				int ans = (int) Math.ceil((double) (R - N) / N);
				if (ans > 26)
					bw.write("Case " + line + ": impossible\n");
				else
					bw.write("Case " + line + ": " + ans + "\n");

			}
			bw.flush();

			line++;
		}
		bw.close();

	}
}
