import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class P325 {
	public static void main(String[] args) {
		Pattern p1 = Pattern.compile("(\\+|\\-)?([0-9]+\\.[0-9]+)");
		Pattern p2 = Pattern
				.compile("(\\+|\\-)?[0-9]+(\\.?[0-9]+)?(E|e)(\\+|\\-)?[0-9]+");

		Scanner in = new Scanner(System.in);
		while (true) {
			String s = in.nextLine();
			int len = s.length();
			if (len == 1 && s.charAt(0) == '*')
				break;
			s = s.trim();
			Matcher m1 = p1.matcher(s);
			Matcher m2 = p2.matcher(s);
			if (m1.find() && m1.hitEnd() && m1.start() == 0)
				System.out.println(s + " is legal.");
			else if (m2.find() && m2.hitEnd() && m2.start() == 0)
				System.out.println(s + " is legal.");
			else
				System.out.println(s + " is illegal.");

		}
	}
}
