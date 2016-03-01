import java.util.Arrays;
import java.util.Scanner;
import java.util.TreeSet;

public class P11512 {
	public static void suffix_array(String s) {
		int sz = s.length(), i, k;
		
		
			
		
		TreeSet<String> SA = new TreeSet<String>();
		for (i = 0; i < sz; i++) 
			SA.add(s.substring(i));
		
		String[] v = new String[SA.size()];
		i = 0;
		for (String t : SA) 
			v[i++] = t;
		
		int max = 0, count = 0;
		String ans = "Z";
		
		for (i = 0; i < v.length - 1; i++) {		
			for (int j = i + 1; j < v.length; j++) {
				int min_len = v[i].length();
				if(v[j].length() < min_len)
					min_len = v[j].length();
			    count = 0;
				for(k=0; k<min_len; k++) {
					if(v[i].charAt(k) != v[j].charAt(k))
						break;
					count++;
				}
				if(count == 0)
					break;
				
				if(count > max || (count == max && ans.compareTo(v[i].substring(0,k)) > 0   )) {
					max = count;
					ans = v[i].substring(0,k);
				} 
			}
		}
		
		if(max > 0) {
			count = 0;
			for(i=0; i<v.length; i++)
				if(v[i].startsWith(ans))
					count++;
			System.out.println(ans + " "+count);
		}
		else
			System.out.println("No repetitions found!");

	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		in.nextLine();
		while (n-- > 0) {
			String s = in.nextLine();
			suffix_array(s);
		}

	}
}
