import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class P620 {
	private static String s;
	private static int len;

	public static boolean check(int start, int end){
		if(start == end)
		  return ((s.charAt(start) == 'A') ? true : false);

		if(end - start >= 2 && s.charAt(end - 1) == 'A' && s.charAt(end) == 'B')
			return (check(start, end - 2) ? true : false);

		if (end - start >= 2 && s.charAt(start) == 'B' && s.charAt(end) == 'A')
			return (check(start + 1, end - 1) ? true : false);

		return false;
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int t = Integer.parseInt(br.readLine());
		while (t-- > 0) {
			s = br.readLine();
			len = s.length();

			if (len == 1) {
				if (s.equals("A"))
					bw.write("SIMPLE\n");
				else
					bw.write("MUTANT\n");
			} else if (len % 2 == 0) {
				bw.write("MUTANT\n");
			} else {
				if (!check(0, len - 1))
					bw.write("MUTANT\n");
				else if (s.charAt(len - 1) == 'B')
					bw.write("FULLY-GROWN\n");
				else if (s.charAt(len - 1) == 'A')
					bw.write("MUTAGENIC\n");
				

			}
		}
		bw.flush();
		bw.close();
	}
}
