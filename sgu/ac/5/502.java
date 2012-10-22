// SGU502. Digits Permutation

import java.util.*;

public class Solution {
	static final int MOD = 17;

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String n = in.next();
		int[] a = new int[n.length()];
		for (int i = 0; i < a.length; ++i) {
			a[i] = Character.digit(n.charAt(i), 10);
		}
		long[][] dp = new long[1 << a.length][MOD];
		for (int i = 0; i < dp.length; ++i) {
			for (int j = 0; j < dp[i].length; ++j) {
				dp[i][j] = -1;
			}
		}
		dp[0][0] = 0;
		for (int i = 0; i < dp.length; ++i) {
			for (int j = i == 0 ? 0 : 1; j < dp[i].length; ++j) {
				if (dp[i][j] == -1) {
					continue;
				}
				// System.err.println("[" + i + "][" + j + "] = " + dp[i][j]);
				for (int k = 0; k < a.length; ++k) {
					if ((i & (1 << k)) != 0) {
						continue;
					} else {
						dp[i ^ (1 << k)][(j * 10 + a[k]) % MOD] = dp[i][j] * 10 + a[k];
					}
				}
			}
		}
		System.out.println(dp[dp.length - 1][0]);
	}
}

// Wrong answer on test 7 (int => long)
// ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status:  	Time:  	Memory:
// 1039513	08.07.10 14:38	watashi	502 	.JAVA	Accepted 	1153 ms	66367 kb

