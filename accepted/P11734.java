import java.util.Scanner;

public class P11734 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		in.nextLine();
		int line = 1;
		while (t-- > 0) {
			String team = in.nextLine();
			String judge = in.nextLine();
			if (team.equals(judge))
				System.out.printf("Case %d: Yes\n", line);
			else {

				String aux = team.replaceAll("\\s+", "");
				if (aux.equals(judge))
					System.out.printf("Case %d: Output Format Error\n", line);
				else
					System.out.printf("Case %d: Wrong Answer\n", line);

			}
			line++;
		}
	}
}
