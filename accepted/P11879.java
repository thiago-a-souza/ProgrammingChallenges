import java.math.BigInteger;
import java.util.Scanner;

public class P11879 {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);

		while (true) {

			String nbr = in.nextLine();
			int len = nbr.length();

			if (nbr.equals("0"))
				break;

			if (len < 5) {
				Integer val = Integer.parseInt(nbr);
				if (val % 17 == 0)
					System.out.println("1");
				else
					System.out.println("0");
				continue;
			}

			BigInteger b1 = new BigInteger(nbr.substring(0, len - 1));

			BigInteger b2 = new BigInteger(nbr.substring(len - 1, len))
					.multiply(new BigInteger("5"));
			b1 = b1.subtract(b2);
			b1 = b1.mod(new BigInteger("17"));
			if (b1.equals(new BigInteger("0")))
				System.out.println("1");
			else
				System.out.println("0");

		}

	}
}
