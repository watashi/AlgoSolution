import java.util.*;

public class Flags {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		long[][] dp = new long[n + 1][2];
		
		dp[1][0] = 2; // red or white
		dp[1][1] = 0; // blue
		for (int i = 2; i <= n; i++) {
			dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
			dp[i][1] = dp[i - 1][0];
		}

		System.out.println(dp[n][0]);
	}
}
/*
id => 4678073
date => 03:46:5516 Dec 2012
user => watashi
pname => Flags
lang => Java
status => Accepted
testid => 
time => 0.078
mem => 1 442 KB
pid => 1225
*/
