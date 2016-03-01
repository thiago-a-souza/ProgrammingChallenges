import java.util.Scanner;

public class P10800 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		char[][] graph = new char[200][200];
		int line = 1;
		in.nextLine();
		while (n-- > 0) {
			String s = in.nextLine();
			int len = s.length();
			//char[][] graph = new char[200][200];

			for(int i=0; i<200; i++) 
				for(int j=0; j<200; j++)
					graph[i][j] = ' ';
			int min_row = 100, max_row = 100, last_row = 100;
			
			if (s.charAt(0) == 'C')
				graph[100][0] = '_';
			else if(s.charAt(0) == 'R')
				    graph[100][0] = '/';
			else graph[100][0] = '\\';
				
			for (int j = 1; j < len; j++) {
				char a = s.charAt(j - 1);
				char b = s.charAt(j);
				if (a == 'C') {
					if (b == 'C')
						graph[last_row][j] = '_';
					else if (b == 'R')
						graph[last_row][j] = '/';
					else if (b == 'F')
						graph[++last_row][j] = '\\';
				} else if (a == 'R') {
					if (b == 'C')
						graph[--last_row][j] = '_';
					else if (b == 'R')
						graph[--last_row][j] = '/';
					else if (b == 'F')
						graph[last_row][j] = '\\';
				} else if (a == 'F') {
					if (b == 'C')
						graph[last_row][j] = '_';
					else if (b == 'R')
						graph[last_row][j] = '/';
					else if (b == 'F')
						graph[++last_row][j] = '\\';
				}
				if (last_row < min_row)
					min_row = last_row;
				if (last_row > max_row)
					max_row = last_row;
			}
			System.out.printf("Case #%d:\n",line++);
			for (int i = min_row; i <= max_row; i++) {
				System.out.printf("| ");
				for (int j = 0; j < len; j++) {
					//System.out.printf("%c", graph[i][j]);
					if(graph[i][j] != ' ')
						System.out.printf("%c", graph[i][j]);
					else {
						boolean b = false;
						for(int k=j+1; k<len; k++)
							if(graph[i][k] != ' ') {
								b = true;
								break;
							}
						if(b)
						  System.out.printf(" ");
								
					}
						
				}
				System.out.printf("\n");
			}
			System.out.printf("+-");
			for(int i=0; i<=len; i++)
				System.out.printf("-");
			System.out.printf("\n\n");
		}
	}
}
