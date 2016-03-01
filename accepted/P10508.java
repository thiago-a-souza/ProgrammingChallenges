import java.util.Scanner;

public class P10508 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while (in.hasNextInt()) {
			int n = in.nextInt();
			int sz = in.nextInt();
			String[] s = new String[n];
			in.nextLine();
			for (int i = 0; i < n; i++)
				s[i] = in.nextLine();
			String[] ans = new String[n];
			ans[0] = s[0];
			for(int i=1; i<n; i++) {
				int diffs = 0;
				for(int j=0; j<sz; j++)
					if(s[0].charAt(j) != s[i].charAt(j))
						diffs++;
				ans[diffs] = s[i];
			}
			for(int i=0; i<n; i++)
				System.out.println(ans[i]);

		}
	}
}
