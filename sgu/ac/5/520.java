// SGU520. Fire in the Country
import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[] d = new int[n];
		Arrays.fill(d, 1000000000);
		int m = in.nextInt();
		int[] a = new int[m];
		int[] b = new int[m];
		for (int i = 0; i < m; ++i) {
			a[i] = in.nextInt() - 1;
			b[i] = in.nextInt() - 1;
		}

		d[0] = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				d[b[j]] = Math.min(d[b[j]], d[a[j]] + 1);
				d[a[j]] = Math.min(d[a[j]], d[b[j]] + 1);
			}
		}

		boolean[][] f = new boolean[n][n];
		for (int i = n; i >= 0; --i) {
			for (int j = 0; j < m; ++j) {
				if (i < d[b[j]] && !f[i + 1][b[j]]) {	// WA5, WA7, WA10
					f[i][a[j]] = true;
				}
				if (i < d[a[j]] && !f[i + 1][a[j]]) {	// WA .....
					f[i][b[j]] = true;
				}
			}
		}
		System.out.println(f[0][0] ? "Vladimir" : "Nikolay");
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//1112610	12.11.10 15:30	watashi	520 	.JAVA	Accepted 	205 ms	0 kb

