import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class P531 {
	private static int[][] table;
	private static String[] a, b;
	private static List<String> ans;
	private static void printPath(int i, int j) {
		if(i == 0 || j == 0)
			return;
		if(a[i-1].equals(b[j-1])) {
			printPath(i-1, j-1);
			ans.add(a[i-1]);
			//System.out.print(a[i-1]+" ");
		} else if(table[i-1][j] <= table[i][j-1])
			      printPath(i, j-1);
		else printPath(i-1,j);
			
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while (in.hasNextLine()) {
			String s1 = "";
			String s2 = "";
			while (true) {
				String tmp = in.nextLine();
				if (tmp.equals("#"))
					break;
				s1 = s1 + " " + tmp;
			}

			while (true) {
				String tmp = in.nextLine();
				if (tmp.equals("#"))
					break;
				s2 = s2 + " " + tmp;
			}
		//	System.out.println("==>"+s1);System.out.println("==>"+s2);
			s1 = s1.trim();
			s2 = s2.trim();
		    a = s1.split("\\s+");
			b = s2.split("\\s+");
			
			int m = a.length;
			int n = b.length;
			table = new int[m+1][n+1];
			for(int i=1; i<m+1; i++)
				for(int j=1; j<n+1; j++) {
					if(a[i-1].equals(b[j-1]))
						table[i][j] = table[i-1][j-1] + 1;
					else
						table[i][j] = Math.max(table[i][j-1], table[i-1][j]);
				}			
			ans = new ArrayList<String>();
			printPath(m, n);
			int sz = ans.size();
			for(int i=0; i<sz; i++)
				if(i<sz-1)
				  System.out.print(ans.get(i)+" ");
				else
					System.out.print(ans.get(i));
			System.out.println();
					 
		}
	}
}
