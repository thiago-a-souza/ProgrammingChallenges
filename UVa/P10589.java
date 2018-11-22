import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class P10589 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(
				System.out));
		while (true) {
			String[] token = br.readLine().split("\\s+");
			int N = 0, A = 0;
			if (!token[0].contains("^")) {
				N = Integer.parseInt(token[0]);
				A = Integer.parseInt(token[1]);
			} else {
				int tmp = Integer.parseInt(token[0].substring(token[0].indexOf("^")+1));
				N = 1;
				for(int i=0; i<tmp; i++)
					N = N*10;
				A = Integer.parseInt(token[1]);
			}

			
			if (N == 0 && A == 0)
				break;

			double x, y;
			int M = 0;

			for (int i = 0; i < N; i++) {
				token = br.readLine().split("\\s+");
				x = Double.parseDouble(token[0]);
				y = Double.parseDouble(token[1]);

				boolean b1 = (x * x + y * y <= ((double) (A * A)));
				boolean b2 = ((x - (double) A) * (x - (double) A) + y * y <= ((double) (A * A)));
				boolean b3 = ((x - (double) A) * (x - (double) A)
						+ (y - (double) A) * (y - (double) A) <= ((double) (A * A)));
				boolean b4 = x * x + (y - (double) A) * (y - (double) A) <= ((double) (A * A));

				if (b1 && b2 && b3 && b4)
					M++;
			}
			System.out.printf("%.5f\n",(double)((double)M*A*A)/((double)N));

		}
	}
}
