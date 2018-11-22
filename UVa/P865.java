import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashMap;

public class P865 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(
				System.out));
		int T = Integer.parseInt(br.readLine());
		br.readLine();
		while (T-- > 0) {
			String a = br.readLine();
			String b = br.readLine();

			HashMap<Character, Character> map = new HashMap<Character, Character>();
			int len = a.length();

			for (int i = 0; i < len; i++) {
				map.put(a.charAt(i), b.charAt(i));
			}
			bw.write(b + "\n");
			bw.write(a + "\n");
			while (true) {
				String line = br.readLine();
				if (line == null || line.length() == 0)
					break;
				len = line.length();
				for (int i = 0; i < len; i++) {
					if (map.containsKey(line.charAt(i)))
						bw.write(map.get(line.charAt(i)));
					else
						bw.write(line.charAt(i));
				}
				bw.write("\n");
			}
			if (T > 0)
				bw.write("\n");
			bw.flush();
		}
		bw.close();
		br.close();
	}
}
