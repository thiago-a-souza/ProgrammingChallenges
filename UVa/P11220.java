import java.util.Scanner;

public class P11220 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		int line = 1;
		in.nextLine();
		in.nextLine();
		while (T-- > 0) {
			System.out.printf("Case #%d:\n", line++);
			while (true) {
				if (!in.hasNextLine())
					break;
				String s = in.nextLine();
				// System.out.println("=>"+s);
				int len = s.length();
				if (len == 0)
					break;
				String[] tokens = s.split("\\s+");
				int pos = 0;
				for (int i = 0; i < tokens.length; i++)
					if (tokens[i].length() >= pos + 1)
						System.out.print(tokens[i].charAt(pos++));
				System.out.println();

			}
			if (T > 0)
				System.out.println();
		}
	}
}
