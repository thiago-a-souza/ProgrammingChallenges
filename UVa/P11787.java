import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashMap;

public class P11787 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(
				System.out));
		int T = Integer.parseInt(br.readLine());
		HashMap<Character, Integer> map = new HashMap<Character, Integer>();
		map.put('B', 0);
		map.put('U', 1);
		map.put('S', 2);
		map.put('P', 3);
		map.put('F', 4);
		map.put('T', 5);
		map.put('M', 6);
		while (T-- > 0) {
			String line = br.readLine();
			int len = line.length();
			int[] vals = new int[len];
			for (int i = 0; i < len; i++)
				vals[i] = map.get(line.charAt(i));

			int[] count = new int[7];
			boolean valid = true;
			for (int i = 0; i < len; i++) {
				count[vals[i]]++;
				if (count[vals[i]] > 9) {
					valid = false;
					break;
				}
			}
			if (!valid) {
				bw.write("error\n");
				continue;
			}
			boolean left = true, right = true;

			for (int i = 0; i < len - 1; i++)
				if (vals[i] > vals[i + 1]) {
					left = false;
					break;
				}
			for (int i = 0; i < len - 1; i++)
				if (vals[i] < vals[i + 1]) {
					right = false;
					break;
				}
			if (!left && !right)
				bw.write("error\n");
			else {
				int ans = 0;
				int i = 0, repetitions = 0;
				while (i < len) {
					int last = vals[i];
					repetitions = 0;
					while (i < len && vals[i] == last) {
						i++;
						repetitions++;
					}
					switch (last) {
					case 0:
						ans += repetitions;
						break;
					case 1:
						ans += (repetitions * 10);
						break;
					case 2:
						ans += (repetitions * 100);
						break;
					case 3:
						ans += (repetitions * 1000);
						break;
					case 4:
						ans += (repetitions * 10000);
						break;
					case 5:
						ans += (repetitions * 100000);
						break;
					case 6:
						ans += (repetitions * 1000000);
						break;
					}
				}
				bw.write(ans + "\n");

			}

			bw.flush();
		}
		bw.close();
		br.close();
	}
}
