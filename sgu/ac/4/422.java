// SGU422. Fast Typing

import java.util.*;

// dp[i] = min{(1-a[i])*(dp[i]+k)+a[i]*(1-a[i+1])*(dp[i+1]+k-1)+..+a[i]*a[i+1]*..*a[n-1]*(dp[n]+0)+(t+k)}
public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		double t = in.nextDouble();
		double[] a = new double[n];
		for (int i = 0; i < n; ++i) {
			a[i] = 1 - in.nextDouble();
		}

		double[] dp = new double[n + 1];
		dp[n] = 0;
		for (int i = n - 1; i >= 0; --i) {
			dp[i] = Double.MAX_VALUE;
			double r = t + 1 + (1 - a[i]);
			double p = a[i];
			for (int j = i + 1; j <= n; ++j) {
				dp[i] = Math.min(dp[i], (r + p * dp[j]) / a[i]);
				if (j < n) {
					r += p * (1 - a[j]) * dp[j] + 1 + (1 - p * a[j]);
					p *= a[j];
				}
			}
		}
		System.out.printf("%.10f\n", dp[0]);
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status:  	Time:  	Memory:
//1048001	27.07.10 12:48	watashi	422 	.JAVA	Accepted 	936 ms	0 kb

