import java.util.Scanner;

public class P455 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		in.nextLine();
		while (t-- > 0) {
			in.nextLine();
			String s = in.nextLine();

			int sz = s.length();

			boolean ans = false;
			for (int l = 1; l <= sz / 2; l++) {
				if ((sz / l) * l != sz)
					continue;
				boolean b = true;
				for (int j = 0, k = 0; j < sz && b; j++, k = ((k + 1) % l)) {
					if (s.charAt(j) != s.charAt(k))
						b = false;
				}
				if (b) {
					ans = true;
					System.out.println(l);
					break;
				}
			}
			if (!ans)
				System.out.println(sz);
			if (t > 0)
				System.out.println("");
		}

	}
}
