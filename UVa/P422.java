import java.util.Scanner;

public class P422 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		
		while (true) {
			
			if (n == 0)
				break;
			in.nextLine();
			String[] words = new String[n];
			for(int i=0; i<n; i++) 
				words[i] = in.nextLine();
			
			while(true) {
				String search = in.nextLine();
				try {
					int tmp = Integer.parseInt(search);
					n = tmp;
					break;
				} catch(Exception e) {
					
				}
				int len = search.length();
				boolean found = false;
				int i=0, j=0, ii=0, jj=0;
				for(i=0; i<n && !found; i++)
					for(j=0; j<n && !found; j++) {
						if(words[i].charAt(j) == search.charAt(0)) {
							boolean tmp = true;
							if(j+len-1 < n) {
								tmp = true;
								for(int k=j, l=0; l<len && tmp; k++, l++)
									if(words[i].charAt(k) != search.charAt(l)) 
										tmp = false;
							    if(tmp) {
							    	found = true;
							    	ii = i; 
							    	jj = j + len - 1; 
							    	continue;
							    }
							}
							if(j + 1 >= len) {
								tmp = true;
								for(int k=j, l=0; l<len && tmp; k--, l++)
									if(words[i].charAt(k) != search.charAt(l))
										tmp = false;
								if(tmp) {
									found = true;
									ii = i;
									jj = j - len + 1;
									continue;
								}
							}
							if(i + len - 1 < n) {
								tmp = true;
								for(int k=i, l=0; l<len && tmp; k++, l++)
									if(words[k].charAt(j) != search.charAt(l))
										tmp = false;
								if(tmp) {
									found = true;
									ii = i + len - 1;
									jj = j;
									continue;
								}
							}
							if(i + 1 >= len) {
								tmp = true;
								for(int k=i, l=0; l<len && tmp; k--, l++)
									if(words[k].charAt(j) != search.charAt(l))
										tmp = false;
								if(tmp) {
									found = true;
									ii = i - len + 1;
									jj = j;
									continue;
								}
							}
						}
					}
				
				if(found)
					System.out.printf("%d,%d %d,%d\n",i, j, ii+1, jj+1);
				else
					System.out.printf("Not found\n");
			}
		}
	}
}
