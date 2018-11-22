import java.util.HashSet;
import java.util.Scanner;

public class P263 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while (true) {
			String s = in.nextLine();
			if (s.equals("0"))
				break;
			HashSet<String> nbrs = new HashSet<String>();
			nbrs.add(s);
			int chains = 0;
			System.out.println("Original number was " + s);
			while (true) {
				int[] freq = new int[10];
				int len = s.length();
				for (int i = 0; i < len; i++)
					freq[s.charAt(i) - '0']++;
				String a = "", b = "";
				for (int i = 1; i < 10; i++)
					for (int j = 0; j < freq[i]; j++)
						a = a + i;
				for (int i = 9; i >= 0; i--)
					for (int j = 0; j < freq[i]; j++)
						b = b + i;
				if (a.length() == 0)
					a = "0";
				if (b.length() == 0)
					b = "0";
				Integer x = Integer.parseInt(b) - Integer.parseInt(a);
				System.out.println(b + " - " + a + " = " + x);
				chains++;
				s = x.toString();

				if (nbrs.contains(x.toString()))
					break;
				nbrs.add(s);

			}
			System.out.println("Chain length " + chains);
			System.out.println();
		}

	}
}
