import java.math.BigInteger;
import java.util.Scanner;

public class P10213 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		for(int i=0; i<n; i++) {
			Integer v = sc.nextInt();
			//F(N) = ( N * (N-1) * (N*N-5*N+18) / 24 ) + 1
			
			BigInteger ans = new BigInteger(v.toString());
			BigInteger b1 = new BigInteger(Integer.valueOf(v-1).toString());

			ans = ans.multiply(b1);
			
			BigInteger b2 = new BigInteger(v.toString());
			b2 = b2.multiply(b2);
			b2 = b2.add(new BigInteger("18"));
			
			BigInteger b3 = new BigInteger(v.toString());
			b3 = b3.multiply(new BigInteger("5"));

			b2 = b2.subtract(b3);
			ans = ans.multiply(b2);
			ans = ans.divide(new BigInteger("24"));
			ans = ans.add(new BigInteger("1"));
			System.out.println(ans);
			
		}
	}
}
