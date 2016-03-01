import java.util.Scanner;

public class P11839 {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);

		char[] c = { 'A', 'B', 'C', 'D', 'E' };

		while (true) {
			int n = in.nextInt();
			if (n == 0)
				break;
			for (int x = 0; x < n; x++) {
				int ans = -1;
				int tmp = 0;
				boolean valid = true;

				for (int i = 0; i < 5; i++) {
					tmp = in.nextInt();
					if (tmp <= 127) {
						if (ans < 0)
							ans = i;
						else
							valid = false;
					}
				}
				if (valid && ans >= 0)
					System.out.printf(c[ans] + "\n");
				else
					System.out.printf("*\n");

			}
		}

	}
}
