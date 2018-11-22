import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class P10393 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		boolean finger[] = new boolean[11];
		Map<Character, Integer> m = new HashMap<Character, Integer>();
		
		m.put('q', 1); m.put('a', 1); m.put('z', 1);
		m.put('w', 2); m.put('s', 2); m.put('x', 2);
		m.put('e', 3); m.put('d', 3); m.put('c', 3);
		m.put('r', 4); m.put('f', 4); m.put('v', 4); m.put('t', 4); m.put('g', 4); m.put('b', 4);
		m.put('y', 7); m.put('h', 7); m.put('n', 7); m.put('u', 7); m.put('j', 7); m.put('m', 7);
		m.put('i', 8); m.put('k', 8); m.put(',', 8);
		m.put('o', 9); m.put('l', 9); m.put('.', 9);
		m.put('p', 10); m.put(';',10 ); m.put('/',10 );
		
		
		
		while(in.hasNextInt()) {
			int F = in.nextInt();
			int N = in.nextInt();
		//	System.out.println(F+" => ");
			for(int i=0; i<11; i++)
				finger[i] = true;
			
			for(int i=0; i<F; i++)
				finger[in.nextInt()] = false;
			
			in.nextLine();
			String[] words = new String[N];
			boolean[] ans = new boolean[N];
			int max_size = 0;
	        for(int i=0; i<N; i++) {
	        	words[i] = in.nextLine();
	        	//System.out.println("word ="+words[i]);
	        	boolean canType = true;
	        	int len = words[i].length();
	        	for(int j=0; j<len; j++) {
	        	//	System.out.println("===> "+m.get(words[i].charAt(j)));
	        		if(!finger[m.get(words[i].charAt(j))]) {
	        			canType = false;
	        			break;
	        		}
	        	}
	        	if(canType && len >= max_size) {
	        		max_size = len;
	        		ans[i] = true;
	        	}
	        }
	        Set<String> s = new TreeSet<String>();
	        for(int i=0; i<N; i++)
	        	if(ans[i] && words[i].length() == max_size) {
	        		s.add(words[i]);
	        	}
	        System.out.printf("%d\n",s.size());
	        for(String str : s)
	        	System.out.println(str);
	        
	        
				
			
		}
	}
}
