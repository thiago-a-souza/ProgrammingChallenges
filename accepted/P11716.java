import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class P11716 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		
		//Scanner in = new Scanner(System.in);
		int T = Integer.parseInt(br.readLine());

		double r;
		int sq;

		
		while(T-- > 0) {
			String s = br.readLine();
			int len = s.length();

			r = Math.sqrt(len);
			sq = (int)r;
		    if( sq - r != 0.0) {
		    	bw.write("INVALID\n");
		    } else {
		    	for(int i=0; i<sq; i++)
		    		for(int j=i, k=0; k<sq; k++, j=j+sq )
		    			bw.write(s.charAt(j));
		    	bw.write("\n");
		    }
				
		}
		br.close();
		bw.flush(); bw.close();

	}
}
