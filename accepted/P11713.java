import java.util.Scanner;

public class P11713 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		in.nextLine();
		while(n-- > 0) {
			String a = in.nextLine();
			int sza = a.length();
			
			String b = in.nextLine();
			int szb = b.length();
			if(sza != szb) {
				System.out.println("No");
			} else {
				boolean found = true;
				for(int i=0; i<sza && found; i++) {
					if(a.charAt(i) != b.charAt(i)) {
						if(!((a.charAt(i) == 'a' || a.charAt(i) == 'e' || a.charAt(i) == 'i' || a.charAt(i) == 'o' || a.charAt(i) == 'u') &&
						   (b.charAt(i) == 'a' || b.charAt(i) == 'e' || b.charAt(i) == 'i' || b.charAt(i) == 'o' || b.charAt(i) == 'u')	)) {
							found = false;
							break;
						}
							
					}
				}
				if(found)
					System.out.println("Yes");
				else
					System.out.println("No");
			}
			
		}
	}
}
