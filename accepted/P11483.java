import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;


public class P11483 {
public static void main(String[] args) throws Exception {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(
			System.out));
	int line = 1;
	while(true) {
		int n = Integer.parseInt(br.readLine());
		if(n == 0)
			break;
		bw.write("Case "+line+":\n"); line++;
		bw.write("#include<string.h>\n#include<stdio.h>\nint main()\n{\n");
		for(int i=0; i<n; i++) {
			String s = br.readLine();
			int len = s.length();
			if(len == 0) {
				i--;
				continue;
			}
			bw.write("printf(\"");
			for(int j=0; j<len; j++) {
				if(s.charAt(j) == '\"') 
					bw.write("\\\"");
				else if(s.charAt(j) == '\\') 
					    bw.write("\\\\");
				else bw.write(s.charAt(j));
			}				
			bw.write("\\n\");\n");
			
		}
		bw.write("printf(\"\\n\");\nreturn 0;\n}\n");
		
	}
	bw.flush();
	bw.close();
	br.close();
	
	
}
}
