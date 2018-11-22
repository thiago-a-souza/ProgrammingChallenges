import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class P10115 {
	private static int[] a;
	private static int m;
	private static String P;

	public static void calculatePrefix(String prefix) {
		int i = 0, j = -1;
		P = prefix;
		m = P.length();

		a = new int[m + 1];
		a[0] = -1;

		while (i < m) {
			while (j >= 0 && P.charAt(i) != P.charAt(j))
				j = a[j];
			i++;
			j++;
			a[i] = j;
		}
	}

	public static int KMP(String S) {
		int i = 0, j = 0;
		int n = S.length();
		while (i < n) {
			while (j >= 0 && S.charAt(i) != P.charAt(j))
				j = a[j];
			j++;
			i++;
			if (j == m)
				return i - m;

		}
		return -1;
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(
				System.out));
		while (true) {
			int n = Integer.parseInt(br.readLine());
			if (n == 0)
				break;
			String[] search = new String[n];
			String[] replace = new String[n];
			for (int i = 0; i < n; i++) {
				search[i] = br.readLine();
				replace[i] = br.readLine();
			}
			String text = br.readLine();
			int index = 0;
			calculatePrefix(search[0]);
			while (index < n) {
				int start = KMP(text);
				if (start >= 0) {
					text = text.substring(0, start)
							+ replace[index]
							+ text.substring(start + search[index].length(),
									text.length());
				} else if(index + 1 < n)
					calculatePrefix(search[++index]);
				else break;

			}
			bw.write(text+"\n");
			

		}
		bw.flush();
		bw.close();
	}
}
