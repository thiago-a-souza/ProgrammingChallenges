import java.util.Scanner;

public class P12243 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while (true) {
			String s = in.nextLine();
			if (s.equals("*"))
				break;
			String[] tokens = s.toLowerCase().split("\\s+");
			boolean ans = true;
			for (int i = 1; i < tokens.length && ans; i++) {
				if (tokens[i].charAt(0) != tokens[0].charAt(0))
					ans = false;
			}
			if (ans)
				System.out.println("Y");
			else
				System.out.println("N");
		}
	}
}
