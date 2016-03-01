import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class P10198 {
	public static void main(String args[]) {
		int n;
		Scanner sc = new Scanner(System.in);
		BigInteger d0 = new BigInteger("0");
		List<BigInteger> ans = new ArrayList<BigInteger>();
		ans.add(new BigInteger("0"));
		ans.add(new BigInteger("2"));
		ans.add(new BigInteger("5"));
		ans.add(new BigInteger("13"));

		for (int i = 4; i <= 1000; i++)
			ans.add(ans.get(i - 3).add(ans.get(i - 2))
					.add(ans.get(i - 1).multiply(new BigInteger("2"))));
		while (sc.hasNext()) {
			n = sc.nextInt();
			System.out.println(ans.get(n));
		}

	}
}
