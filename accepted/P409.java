import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class P409 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int line = 1;
		while (in.hasNextInt()) {
			int K = in.nextInt();
			int E = in.nextInt();
			in.nextLine();
			Set<String> keywords = new HashSet<String>();
			for (int i = 0; i < K; i++)
				keywords.add(in.nextLine().toLowerCase());
			String[] excuses = new String[E];
			int[] count = new int[E];
			int max = 0;
			for (int i = 0; i < E; i++) {
				excuses[i] = in.nextLine();
				String search = excuses[i].toLowerCase();
				int len = search.length();
				for (int index = 0; index < len; index++) {
					if (search.charAt(index) >= 'a'
							&& search.charAt(index) <= 'z') {
						int end = index;
						while (end < len && search.charAt(end) >= 'a'
								&& search.charAt(end) <= 'z')
							end++;
						if (keywords.contains(search.substring(index, end))) {
							count[i]++;
							if (count[i] > max)
								max = count[i];
						}
						index = end;
					}
				}
			}
			System.out.printf("Excuse Set #%d\n", line++);
			for (int i = 0; i < E; i++)
				if (count[i] == max)
					System.out.println(excuses[i]);
			System.out.println();
		}
	}
}
