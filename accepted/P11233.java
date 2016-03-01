import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class P11233 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int L = in.nextInt();
		int N = in.nextInt();
		Map<String, String> irregular = new HashMap<String, String>();
		in.nextLine();
		for (int i = 0; i < L; i++) {
			String[] s = in.nextLine().split("\\s+");
			// System.out.println("==>" + s[0] + " =>" + s[1]);
			irregular.put(s[0], s[1]);
		}

		for (int i = 0; i < N; i++) {
			String s = in.nextLine();
			//System.out.println("===> "+s);
			int sz = s.length();
			if (irregular.containsKey(s)) {
				System.out.println(irregular.get(s));
			} else {
				if (s.endsWith("o") || s.endsWith("s") || s.endsWith("ch")
						|| s.endsWith("sh") || s.endsWith("x"))
					System.out.println(s + "es");
				else if (s.endsWith("y") && sz - 2 >= 0
						&& s.charAt(sz - 2) != 'a' && s.charAt(sz - 2) != 'e'
						&& s.charAt(sz - 2) != 'i' && s.charAt(sz - 2) != 'o'
						&& s.charAt(sz - 2) != 'u')
					System.out.println(s.substring(0, sz - 1) + "ies");
				else
					System.out.println(s + "s");
			}
		}

	}
}
