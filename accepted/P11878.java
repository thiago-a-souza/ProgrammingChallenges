import java.util.Scanner;

public class P11878 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int correct = 0;
		while(sc.hasNextLine()) {
			String s = sc.nextLine();
			//System.out.println("==> "+s);
			int op_idx = -1, eq_idx = 0, len;
			len = s.length();
			for(int i=0; i<len; i++) {
				if(op_idx < 0 && (s.charAt(i) == '+' || s.charAt(i) == '-'))
					op_idx = i;
				else if(op_idx > 0 && s.charAt(i) == '=') {
					     eq_idx = i;
					     break;
				}
			}
			
			if(s.charAt(len-1) != '?') {
			   int a = Integer.parseInt(s.substring(0, op_idx));
			   int b = Integer.parseInt(s.substring(op_idx+1, eq_idx));
			   int c = Integer.parseInt(s.substring(eq_idx+1,len));
			   if(s.charAt(op_idx) == '+' && a + b == c ) 
					   correct++;
			   else if(s.charAt(op_idx) == '-' && a - b == c)
				       correct++;
			   
			}
		}
		System.out.println(correct);

	}
}
