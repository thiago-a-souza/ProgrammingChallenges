import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.TreeSet;

public class P10391 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(
				System.out));

		Set<String> words = new HashSet<String>();
		Set<String> ans = new TreeSet<String>();
		List<String> list = new ArrayList<String>();

		String s;

		while ((s = br.readLine()) != null) {
			if (!words.contains(s)) {
				words.add(s);
				list.add(s);
			}
		}
		int sz = list.size();
		int len = 0;
		String tmp;
		for(int i=0; i<sz; i++) {
			tmp = list.get(i);
			len = tmp.length();
			for(int j=1; j<len-1; j++)
				if(words.contains(tmp.substring(0, j))   && words.contains(tmp.substring(j, len)) )
					ans.add(tmp);
		}
			
		for (String ss : ans)
			bw.write(ss + "\n");
		bw.flush();
		bw.close();
		br.close();

	}
}
