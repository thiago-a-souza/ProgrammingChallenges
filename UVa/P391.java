import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class P391 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(
				System.out));
		boolean comments = false;
		while (true) {
			String s = br.readLine();
			if (s == null)
				break;
			int len = s.length();
		//	System.out.println("line="+s);
			for (int i = 0; i < len; i++) {
			//	System.out.println("comments="+comments +" "+(!(i+1 < len && s.charAt(i) == '\\' && s.charAt(i) == '*')) );
				if(i + 1 < len && s.charAt(i) == '\\' && s.charAt(i+1) == '*') {
					comments = !comments;
					i++;
				} else if (comments && !(i+1 < len && s.charAt(i) == '\\' && s.charAt(i) == '*')) {
					//System.out.println("i="+i);
					bw.write(s.charAt(i));
				} else if (s.charAt(i) == '\\') { 
					if (i + 1 < len	&& (s.charAt(i + 1) == 'b' || s.charAt(i + 1) == 'i')) {
						i++;
					} else if (i + 1 < len && s.charAt(i + 1) == '\\') {
						bw.write("\\");
						i++;
					} else if (i + 1 < len && s.charAt(i + 1) == 's') {
						i += 2;
						if (i < len && s.charAt(i) >= '0' && s.charAt(i) <= '9') {
							while (i < len && s.charAt(i) >= '0' && s.charAt(i) <= '9')
							 	   i++;
							if (i < len && s.charAt(i) == '.') {
								i++;
								while (i < len && s.charAt(i) >= '0' && s.charAt(i) <= '9')
									   i++;
							}
						} else if (i < len && s.charAt(i) == '.') {
							       i++;
							       boolean flg = false;
							       while (i < len && s.charAt(i) >= '0'	&& s.charAt(i) <= '9') {
								          i++;
								          flg = true;
							       }
							       if(!flg)
							    	   bw.write(".");
						}
						i--;

					}
				} else
					bw.write(s.charAt(i));
			}
			bw.write("\n");
			bw.flush();
		}
		bw.close();
		
		
		
	}
}
