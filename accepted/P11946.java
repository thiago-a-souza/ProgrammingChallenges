import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class P11946 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(
				System.out));
		int T = Integer.parseInt(br.readLine());
		int len;
		while (T-- > 0) {
			while (true) {
				String line = br.readLine();

				if (line == null || line.length() == 0)
					break;
				len = line.length();

				for (int i = 0; i < len; i++) {
					if (line.charAt(i) >= '0' && line.charAt(i) <= '9') {
						switch (line.charAt(i)) {
						case '0':
							bw.write("O");
							break;
						case '1':
							bw.write("I");
							break;
						case '2':
							bw.write("Z");
							break;
						case '3':
							bw.write("E");
							break;
						case '4':
							bw.write("A");
							break;
						case '5':
							bw.write("S");
							break;
						case '6':
							bw.write("G");
							break;
						case '7':
							bw.write("T");
							break;
						case '8':
							bw.write("B");
							break;
						case '9':
							bw.write("P");
							break;
						}
					} else
						bw.write(line.charAt(i));
				}
				bw.write("\n");
				bw.flush();
			}
			if (T > 0)
				bw.write("\n");
		}
		bw.close();
		br.close();
	}
}
