// SGU508. Black-white balls

import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int l1 = in.nextInt();
		int l2 = in.nextInt();
		int q = in.nextInt();

		long[][] c = new long[n + 1][n + 1];
		for (int i = 0; i <= n; ++i) {
			c[i][0] = c[i][i] = 1;
			for (int j = 1; j < i; ++j) {
				c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
			}
		}
		long[] p = new long[n + 1];
		long s = 0;
		for (int i = 0; i <= n; ++i) {
			p[i] = c[i][l1] * c[n - i][l2];
			s += p[i];
		}
		s = (q * s + 99) / 100;

		int a = 0, b = n;
		for (int i = 0; i <= n; ++i) {
			long t = p[i];
			int j = i;
			while (t < s && j < n) {
				t += p[++j];
			}
			if (t >= s && j - i < b - a) {
				a = i;
				b = j;
			}
		}
	
		System.out.println(a + " " + b);
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status:  	Time:  	Memory:
//1039562	08.07.10 16:53	watashi	508 	.JAVA	Accepted 	19 ms	0 kb

