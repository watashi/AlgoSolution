// SGU519. 3D City Model
import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
		int s = 0;
		int[][] a = new int[n][m];
		for (int i = 0; i < n; ++i) {
			String l = in.next();
			for (int j = 0; j < m; ++j) {
				a[i][j] = Character.digit(l.charAt(j), 10);
				if (a[i][j] == 0) {
					continue;
				}
				s += a[i][j] * 4 + 2;
				if (i > 0) {
					s -= 2 * Math.min(a[i - 1][j], a[i][j]);
				}
				if (j > 0) {
					s -= 2 * Math.min(a[i][j - 1], a[i][j]);
				}
			}
		}
		System.out.println(s);
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//1112414	12.11.10 11:47	watashi	519 	.JAVA	Accepted 	64 ms	0 kb

