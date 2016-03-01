import java.util.HashMap;
import java.util.Scanner;

public class P11385 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int[] fib = {0, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 
				832040, 1346269, 2178309, 3524578, 5702887, 9227465, 14930352, 24157817, 39088169, 63245986, 102334155, 165580141, 267914296, 433494437, 701408733, 1134903170, 1836311903};
		HashMap<Integer, Integer> m = new HashMap<Integer, Integer>();
		for(int i=1; i<fib.length; i++)
			m.put(fib[i], i);
		           
			
		char[] output = new char[200];
		int t = in.nextInt();
		while(t-- > 0) {
			int n = in.nextInt();
			int[] codes = new int[n];
			for(int i=0; i<n; i++)
				codes[i] = in.nextInt();
			in.nextLine();
			String msg = in.nextLine();
			for(int i=0; i<200; i++)
				output[i] = ' ';
			int len = msg.length();
			int max = -1, index = 0 , tmp = 0;
			for(int i=0; i<n; i++) {
				tmp = m.get(codes[i]);
				if(tmp > max)
					max = tmp;
				while(index < len && !(msg.charAt(index) >= 'A' && msg.charAt(index) <= 'Z'))
					   index++;
				output[tmp] = msg.charAt(index);
				index++;
			}
			
			for(int i=1; i<=max; i++)
				System.out.printf("%c",output[i]);
			System.out.printf("\n");
		
		
		}

	}
}
