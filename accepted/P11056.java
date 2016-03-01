import java.util.Arrays;
import java.util.Scanner;

public class P11056 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while (in.hasNextInt()) {
			int n = in.nextInt();
			in.nextLine();
			Racer[] racers = new Racer[n];

			for (int i = 0; i < n; i++) {
				String s = in.nextLine();
				String[] token = s.split("\\s+");
				racers[i] = new Racer(token[0], Integer.parseInt(token[2]),
						Integer.parseInt(token[4]), Integer.parseInt(token[6]));
			//	System.out.println(token[0] + " " + token[2] + " " + token[4]);
			}
			Arrays.sort(racers);
			int len = racers.length;
			for (int i = 0, j = 1; i < len; i += 2, j++) {
				System.out.println("Row " + j);
				System.out.println(racers[i]);
				if (i + 1 < len)
					System.out.println(racers[i + 1]);
			}
			System.out.println("");

		}

	}

}

class Racer implements Comparable {
	private String name;
	private int min, sec, ms;

	public Racer(String name, int min, int sec, int ms) {
		this.name = name;
		this.min = min;
		this.sec = sec;
		this.ms = ms;
	}

	@Override
	public int compareTo(Object o) {
		Racer that = (Racer) o;
		if (this.min < that.min)
			return -1;
		if (this.min > that.min)
			return 1;
		if (this.sec < that.sec)
			return -1;
		if (this.sec > that.sec)
			return 1;
		if (this.ms < that.ms)
			return -1;
		if (this.ms > that.ms)
			return 1;
		return name.toUpperCase().compareTo(that.name.toUpperCase());
	}

	@Override
	public String toString() {
		return name;
	}
}
