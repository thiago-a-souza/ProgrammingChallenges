import java.util.Arrays;
import java.util.Scanner;

public class P11362 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		while (t-- > 0) {
			int n = in.nextInt();
			in.nextLine();
			String[] s = new String[n];
			for (int i = 0; i < n; i++) {
				s[i] = in.nextLine().trim();

			}
			Arrays.sort(s);
			boolean prefix = false;
			int sz = 0;
			for (int i = 0; i < n - 1; i++) {
				sz = s[i].length();
				if (s[i + 1].length() < sz)
					sz = s[i + 1].length();
				prefix = true;
				for (int k = 0; k < sz && prefix; k++)
					if (s[i].charAt(k) != s[i + 1].charAt(k))
						prefix = false;
				if (prefix)
					break;

			}
			if (!prefix)
				System.out.println("YES");
			else
				System.out.println("NO");
		}
	}
}
