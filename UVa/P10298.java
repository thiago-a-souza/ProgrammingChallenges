import java.util.Scanner;

public class P10298 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int sz = 0, len = 0;
		while (true) {
			String str = in.nextLine();
			len = str.length();
			if (len == 1 && str.equals("."))
				break;

			boolean found = false;
			for (sz = 1; sz < len; sz++) {
				if (str.charAt(sz) != str.charAt(0) || len % sz != 0)
					continue;
				boolean b = true;
				for (int i = sz, j = 0; i < len && b; i++, j = (j + 1) % sz)
					if (str.charAt(i) != str.charAt(j))
						b = false;
				if (b) {
					found = true;
					break;
				}
			}
			if (found)
				System.out.printf("%d\n", len / sz);
			else
				System.out.println("1");

		}
	}
}
