import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class P11203 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.nextLine();
		
		while (n-- > 0) {
			String s = sc.nextLine();
			int len = s.length();
			int e_count = 0, m_count = 0, e_index = 0, m_index = 0;
			boolean notValid = false;
			
			for(int i=0; i<len; i++) {
				if(s.charAt(i) == 'M') {
					m_count++;
					m_index = i;
				} else if(s.charAt(i) == 'E') {
					      e_count++;
					      e_index = i;
				} else if(s.charAt(i) != '?') {
					      notValid = true;
					      break;
				}
					
			}
			
			if(e_count > 1 || m_count > 1 || m_index > e_index || m_index == e_index-1 || notValid || s.charAt(0) != '?') {
				System.out.println("no-theorem");
				continue;
			}
			if(m_index + (e_index - 1 - m_index) == len-1-e_index)
				System.out.println("theorem");
			else
				System.out.println("no-theorem");
		}
	}
}
