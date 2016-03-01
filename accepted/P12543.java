import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class P12543 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(
				System.out));
		
		int max = 0, start = -1;
		String ans = "";
		while(true) {
			String line = br.readLine();
			if(line == null)
				break;
			
			
			int len = line.length();
			int i = 0;
			
			while(i < len) {
				 if(i + 5 < len && line.charAt(i) == 'E' && line.charAt(i+1) == '-' &&
					line.charAt(i+2) == 'N' && line.charAt(i+3) == '-' && line.charAt(i+4) == 'D')
					 break;
				 if((line.charAt(i) >= 'a' && line.charAt(i) <= 'z') ||
					(line.charAt(i) >= 'A' && line.charAt(i) <= 'Z') || line.charAt(i) == '-') {
					 if(start < 0)
						 start = i;
				 } else {
					 if(start >= 0 && i - start > max) {
						 max = i - start;
						 ans = line.substring(start,i);
					 }
					 start = -1;
				 }
				 i++;
			}
		}
		bw.write(ans.toLowerCase());
		bw.write("\n");
		bw.flush();
		bw.close();

	}
}
