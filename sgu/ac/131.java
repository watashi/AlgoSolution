// SGU131. Hardwood floor

import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int m = in.nextInt();
		int n = in.nextInt();
		long[] ans = new long[1 << n];
		ans[0] = 1;
		for (int i = 0; i < m; ++i) {
			long[][] dp = new long[n + 1][1 << n];
			dp[0] = ans;
			for (int j = 0; j < n; ++j) {
				for (int k = 0; k < (1 << n); ++k) {
				//	if (dp[j][k] > 0) {
				//		System.out.println(j + "," + k + ": " + dp[j][k]);
				//	}
				//	if (j == n) {
				//		continue;
				//	}
					if ((k & (1 << j)) == 0) {
						dp[j + 1][k ^ (1 << j)] += dp[j][k]; // X,X
						if (j + 1 < n && (k & (1 << j + 1)) == 0) {
							dp[j + 2][k] += dp[j][k]; // XX
							dp[j + 2][k ^ (1 << j)] += dp[j][k]; // XX,X_
							dp[j + 2][k ^ (2 << j)] += dp[j][k]; // XX,_X
							if (j + 2 < n && (k & (1 << j + 2)) == 0) {
								dp[j + 3][k ^ (3 << j)] += dp[j][k]; // X@@,XX_
								dp[j + 3][k ^ (7 << j)] += dp[j][k]; // X@@,XX@
							}
						}
						if (j > 0 && (k & (1 << j - 1)) == 0) {
							dp[j + 1][k ^ (3 << j - 1)] += dp[j][k]; // .X,XX
						}
						if (j + 1 < n && (k & (1 << j + 1)) != 0) {
							dp[j + 2][k ^ (1 << j)] += dp[j][k]; // X.,XX
						}
					} else {
						dp[j + 1][k ^ (1 << j)] += dp[j][k];	//
					}
				}
			}
			ans = dp[n];
		}
		System.out.println(ans[0]);
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status:  	Time:  	Memory:
//1076137	14.09.10 17:24	watashi	131 	.JAVA	Accepted 	19 ms	0 kb

