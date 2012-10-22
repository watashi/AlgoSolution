// SGU310. Hippopotamus
import java.util.*;

public class Solution {
	static int[] ones;

	static {
		ones = new int[1 << 16];
		ones[0] = 0;
		for (int i = 1; i < ones.length; ++i) {
			ones[i] = ones[i >> 1] + (i & 1);
		}
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
		int k = in.nextInt();
		if (n < m) {
			System.out.println(1 << n);
		} else {
			long[] dp = new long[1 << m];
			for (int j = 0; j < dp.length; ++j) {
				dp[j] = ones[j] >= k ? 1 : 0;
			}
			for (int i = m; i < n; ++i) {
				long[] pre = dp;
				dp = new long[1 << m];
				for (int j = 0; j < pre.length; ++j) {
					dp[j >> 1] += pre[j];
					dp[(j >> 1) | (1 << m - 1)] += pre[j];
				}
				for (int j = 0; j < dp.length; ++j) {
					if (ones[j] < k) {
						dp[j] = 0;
					}
				}
			}
			long ans = 0;
			for (long dpi : dp) {
				ans += dpi;
			}
			System.out.println(ans);
		}
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status:  	Time:  	Memory:
//1081677	27.09.10 12:57	watashi	310 	.JAVA	Accepted 	176 ms	0 kb

