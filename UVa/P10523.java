import java.math.BigInteger;
import java.util.*;

public class P10523 {
	public static void main(String args[]) {
		Integer n, a;
		Scanner sc = new Scanner(System.in);
		while (sc.hasNext()) {
			n = sc.nextInt();
			a = sc.nextInt();

			BigInteger ans = new BigInteger("0");
			BigInteger val = new BigInteger(a.toString());			
			for(Integer i=1; i<=n; i++){
				ans = ans.add(val.multiply(new BigInteger(i.toString())));
				val = val.multiply(new BigInteger(a.toString()));
			}
			System.out.println(ans);
			
		}

	}
}
