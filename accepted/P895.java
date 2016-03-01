import java.util.Scanner;

public class P895 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while(in.hasNextLine()) {
			int[][] dic = new int[1001][30];
			int rows = 0;
			while(true) {
				String s = in.nextLine();
				if(s.equals("#"))
					break;
			    int sz = s.length();
			    for(int i=0; i<sz; i++) 
			    	dic[rows][s.charAt(i) - 'a']++;
				rows++;
			}
			
			while(true) {
				String s = in.nextLine();
				if(s.equals("#"))
					break;
				int sz = s.length();				
				
				int[] freq = new int[30];
				for(int i=0; i<sz; i++)
					if(s.charAt(i) >= 'a' && s.charAt(i) <= 'z')
						freq[s.charAt(i) - 'a']++;
								
				int words = 0;
				for(int i=0; i<rows; i++) {
					boolean fits = true;
					for(int j=0; j<30 && fits; j++) {
						if(dic[i][j] > freq[j])
							fits = false;
					}
				    if(fits) 
				    	words++;
				}
				System.out.println(words);
			}
		}
	}
}
