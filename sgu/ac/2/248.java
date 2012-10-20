// SGU248. Integer Linear Programming 
import java.util.*;

public class Solution {
	static long[] gcd(long a, long b) {
		if (b == 0) {
			return new long[]{a, 1, 0};
		} else {
			long[] g = gcd(b, a % b);
			return new long[]{g[0], g[2], g[1] - a / b * g[2]};
		}
	}

	// ax + by = v && gcd(a, b) = 1 && 0 < a <= b
	static long gao(long a, long b, long x, long y) {
		long d = (x >= 0 ? x / b : -((-x + b - 1) / b));
		x -= d * b;
		y += d * a;
		return y >= 0 ? x + y : -1;
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		long[] a = new long[n];
		for (int i = 0; i < a.length; ++i) {
			a[i] = in.nextLong();
		}
		Arrays.sort(a);
		long b = in.nextLong();

		if (n == 1) {
			System.out.println(b % a[0] == 0 ? b / a[0] : -1);
		} else if (n == 2) {
			long[] g = gcd(a[0], a[1]);
			if (b % g[0] != 0) {
				System.out.println(-1);
			} else {
				a[0] /= g[0];
				a[1] /= g[0];
				b /= g[0];
				System.out.println(gao(a[0], a[1], g[1] * b, g[2] * b));
			}
		} else {
			long ans = -1;
			long[] g = gcd(a[0], a[1]);
			a[0] /= g[0];
			a[1] /= g[0];
			for (long i = 0; b >= 0; ++i) {
				if (b % g[0] == 0) {
					long tmp = gao(a[0], a[1], g[1] * b / g[0], g[2] * b / g[0]);
					if (tmp != -1 && (ans == -1 || tmp + i < ans)) {	// WA21
						ans = tmp + i;
					}
				}
				b -= a[2];
			}
			System.out.println(ans);
		}
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status:  	Time:  	Memory:
//1081517	26.09.10 17:38	watashi	248 	.JAVA	Accepted 	30 ms	0 kb

