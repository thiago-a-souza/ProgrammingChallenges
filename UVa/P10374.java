import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class P10374 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		while (t-- > 0) {
			int cand = in.nextInt();
			in.nextLine();
			int index = 1;
			Map<String, Integer> position = new HashMap<String, Integer>();
			Map<String, String> candParty = new HashMap<String, String>();
			for (int i = 0; i < cand; i++) {
				String name = in.nextLine();
				String party = in.nextLine();
				position.put(name, index++);
				candParty.put(name, party);
			}
			int[] votes = new int[cand + 10];
			int v = in.nextInt();
			int max = 0;
			in.nextLine();
			String winner = "";
			for (int i = 0; i < v; i++) {
				String c = in.nextLine();
				if (!position.containsKey(c))
					continue;
				int idx = position.get(c);
				votes[idx]++;
				if (votes[idx] > max) {
					max = votes[idx];
					winner = candParty.get(c);
				}
			}
			int count = 0;
			for (int i = 1; i <= cand; i++) {
				if (votes[i] == max) {
					count++;
					if (count > 1)
						break;
				}
			}
			if (count <= 1)
				System.out.println(winner);
			else
				System.out.println("tie");

			if (t > 0)
				System.out.println();
		}
	}
}
