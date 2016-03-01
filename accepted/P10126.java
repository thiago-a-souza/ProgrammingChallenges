import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashMap;
import java.util.Set;
import java.util.TreeSet;

public class P10126 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(
				System.out));

		String line;
		boolean first = true;
		while ((line = br.readLine()) != null) {
			int freq;

			try {
				freq = Integer.parseInt(line);
			} catch (Exception e) {
				continue;
			}
			HashMap<String, Integer> map = new HashMap<String, Integer>();
			while (true) {
				line = br.readLine();
				if (line == null || line.equals("EndOfText"))
					break;

				line = line.toLowerCase() + ".";
				int i = 0, start = -1;
				int len = line.length();
				while (i < len) {
					if (line.charAt(i) >= 'a' && line.charAt(i) <= 'z') {
						if (start < 0)
							start = i;
					} else {
						if (start >= 0) {
							String tmp = line.substring(start, i);
							if (map.containsKey(tmp))
								map.put(tmp, map.get(tmp) + 1);
							else
								map.put(tmp, 1);
						}
						start = -1;
					}
					i++;
				}
			}
			Set<String> set = map.keySet();
			TreeSet<String> ans = new TreeSet<String>();
			if (first)
				first = false;
			else
				bw.write("\n");
			for (String s : set)
				if (map.get(s) == freq)
					ans.add(s);
			if (ans.size() > 0) {
				for (String s : ans)
					bw.write(s + "\n");
			} else {
				bw.write("There is no such word.\n");
			}
			bw.flush();

		}
		bw.close();
		br.close();

	}
}
