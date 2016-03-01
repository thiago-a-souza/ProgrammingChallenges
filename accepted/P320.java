import java.util.Scanner;

public class P320 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		int line = 1;
		while (t-- > 0) {
			int col = in.nextInt();
			int row = 31 - in.nextInt();

			boolean[][] grid = new boolean[33][33];
			in.nextLine();
			String path = in.nextLine();
			int sz = path.length();
			if (path.charAt(0) == 'E')
				grid[++row][col] = true;
			else if (path.charAt(0) == 'W')
				grid[row][col] = true;
			else if (path.charAt(0) == 'N')
				grid[row][col] = true;
			else if (path.charAt(0) == 'S')
				grid[++row][--col] = true;
			for (int i = 1; i < sz; i++) {
				if (path.charAt(i) == '.')
					break;

				if (path.charAt(i) == 'E') {
					if (path.charAt(i - 1) == 'E')
						grid[row][++col] = true;
					else if (path.charAt(i - 1) == 'N')
						grid[--row][++col] = true;
					else if (path.charAt(i - 1) == 'S')
						grid[++row][++col] = true;

					if (i + 2 < sz && path.charAt(i + 1) == 'S'
							&& path.charAt(i + 2) == 'W')
						i += 2;
					else if (i + 1 < sz && path.charAt(i + 1) == 'S')
						i++;

				} else if (path.charAt(i) == 'N') {
					if (path.charAt(i - 1) == 'N')
						grid[--row][col] = true;
					else if (path.charAt(i - 1) == 'E')
						grid[--row][++col] = true;

					if (i + 2 < sz && path.charAt(i + 1) == 'E'
							&& path.charAt(i + 2) == 'S')
						i += 2;
					else if (i + 1 < sz && path.charAt(i + 1) == 'E')
						i++;
				} else if (path.charAt(i) == 'W') {
					if (path.charAt(i - 1) == 'W')
						grid[row][--col] = true;
					else if (path.charAt(i - 1) == 'N')
						grid[--row][--col] = true;

					if (i + 2 < sz && path.charAt(i + 1) == 'N'
							&& path.charAt(i + 2) == 'E')
						i += 2;
					else if (i + 1 < sz && path.charAt(i + 1) == 'N')
						i++;
				} else if (path.charAt(i) == 'S') {
					if (path.charAt(i - 1) == 'S')
						grid[++row][col] = true;
					else if (path.charAt(i - 1) == 'W')
						grid[++row][--col] = true;
					else if (path.charAt(i - 1) == 'E')
						grid[++row][++col] = true;
					if (i + 2 < sz && path.charAt(i + 1) == 'W'
							&& path.charAt(i + 2) == 'N')
						i += 2;
					else if (i + 1 < sz && path.charAt(i + 1) == 'W')
						i++;

				}

			}

			System.out.printf("Bitmap #%d\n", line++);
			for (int ii = 0; ii < 32; ii++) {
				for (int jj = 0; jj < 32; jj++) {
					if (grid[ii][jj])
						System.out.print("X");
					else
						System.out.print(".");
				}
				System.out.println("");
			}
			System.out.printf("\n");

		}

	}
}
