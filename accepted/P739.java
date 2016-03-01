import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashMap;
import java.util.Scanner;

public class P739 {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		// BufferedReader br = new BufferedReader(new
		// InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(
				System.out));

		bw.write("         NAME                     SOUNDEX CODE\n");
		HashMap<Character, Integer> dic = new HashMap<Character, Integer>();
		dic.put('A', 0);
		dic.put('E', 0);
		dic.put('I', 0);
		dic.put('O', 0);
		dic.put('U', 0);
		dic.put('Y', 0);
		dic.put('W', 0);
		dic.put('H', 0);
		dic.put('B', 1);
		dic.put('P', 1);
		dic.put('F', 1);
		dic.put('V', 1);
		dic.put('C', 2);
		dic.put('S', 2);
		dic.put('K', 2);
		dic.put('G', 2);
		dic.put('J', 2);
		dic.put('Q', 2);
		dic.put('X', 2);
		dic.put('Z', 2);
		dic.put('D', 3);
		dic.put('T', 3);
		dic.put('L', 4);
		dic.put('M', 5);
		dic.put('N', 5);
		dic.put('R', 6);

		while (in.hasNextLine()) {
			String s = in.nextLine();
			s = s.trim();
			int len = s.length();
			bw.write("         " + s);
			for (int i = 0; i < 25 - len; i++)
				bw.write(" ");
			bw.write(s.charAt(0));
			int[] codes = new int[3];
			int index = 0;
			int curr = 0, last = 0;
			for (int i = 1; i < len && index < 3; i++) {
				// if(!dic.containsKey(s.charAt(i)))
				// continue;
				curr = dic.get(s.charAt(i));
				last = dic.get(s.charAt(i - 1));
				if (curr == 0 || curr == last)
					continue;
				codes[index++] = curr;
			}
			for (int i = 0; i < 3; i++)
				bw.write(""+codes[i]);
			bw.write("\n");
		}
		bw.write("                   END OF OUTPUT\n");
		bw.flush();
		bw.close();

	}
}
