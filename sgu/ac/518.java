// SGU518. Kidnapping
import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[][] a = new int[n][n];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				a[i][j] = in.nextInt();
			}
		}

		boolean[] b = new boolean[n];
		b[0] = true;
		int m = in.nextInt();
		for (int k = 0; k < m; ++k) {
			int d = in.nextInt();
			boolean[] c = new boolean[n];
			for (int i = 0; i < n; ++i) {
				if (!b[i]) {
					continue;
				}
				for (int j = 0; j < n; ++j) {
					if (a[i][j] == d) {
						c[j] = true;
					}
				}
			}
			b = c;
		}

		int ans = 0;
		for (boolean bi : b) {
			ans += bi ? 1 : 0;
		}
		System.out.println(ans);
		for (int i = 0; i < b.length; ++i) {
			if (b[i]) {
				if (i > 0) {
					System.out.print(' ');
				}
				System.out.print(i + 1);
			}
		}
		System.out.println();
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//1112531	12.11.10 13:45	watashi	518 	.JAVA	Accepted 	274 ms	0 kb

