import java.util.Scanner;

public class P644 {
	public static final int MAX = 100000;

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String[] v = new String[MAX];
		int[] length = new int[MAX];
		int sz;
		int line = 1;

		while (true) {

			sz = 0;
			while (true) {
				v[sz] = in.nextLine();
				length[sz] = v[sz].length();
				if (length[sz] == 1 && v[sz].equals("9"))
					break;

				sz++;
			}
			boolean decodable = true;
			for (int i = 0; i < sz && decodable; i++)
				for (int j = i + 1; j < sz && decodable; j++) {
					if (length[j] >= length[i]) {
						boolean b = true;
						for (int k = 0; k < length[i] && b; k++)
							if (v[i].charAt(k) != v[j].charAt(k))
								b = false;
						if (b)
							decodable = false;

					} else {
						boolean b = true;
						for(int k=0; k<length[j] && b; k++)
							if(v[i].charAt(k) != v[j].charAt(k))
								b = false;
						if (b)
							decodable = false;
					}

				}
			if (decodable)
				System.out.printf("Set %d is immediately decodable\n", line++);
			else
				System.out.printf("Set %d is not immediately decodable\n",
						line++);

			if (!in.hasNextLine())
				break;
		}

	}
}
