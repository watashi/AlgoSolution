// SGU140. Integer Sequences 
import java.util.*;

public class Solution {
	static int[] gcd(int a, int b) {
		if (b == 0) {
			return new int[]{a, 1, 0};
		} else {
			int[] g = gcd(b, a % b);
			return new int[]{g[0], g[2], g[1] - a / b * g[2]};
		}
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int p = in.nextInt();
		int b = in.nextInt();
		int[] a = new int[n + 1];
		for (int i = 0; i < n; ++i) {
			a[i] = in.nextInt();
		}
		a[n] = p;
		int[][] g = new int[n + 1][];
		g[0] = new int[]{a[0], 0, 1};
		for (int i = 1; i <= n; ++i) {
			g[i] = gcd(g[i - 1][0], a[i]);
		}
		
		if (b % g[n][0] != 0) {
			System.out.println("NO");
			return;
		} else {
			System.out.println("YES");
			b /= g[n][0];
		}

		int[] x = new int[n + 1];
		for (int i = n; i > 0; --i) {
//			System.err.printf("[%d] %d %d %d\n", i, b, g[i][1], g[i][2]);
			x[i] = (b * g[i][2] % p + p) % p;
			b = b * g[i][1] % p;
		}
		x[0] = (b + p) % p;

		for (int i = 0; i < n; ++i) {
			System.out.print(x[i] + (i == n - 1 ? "\n" : " "));
		}
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status:  	Time:  	Memory:
//1079411	21.09.10 09:11	watashi	140 	.JAVA	Accepted 	30 ms	0 kb
