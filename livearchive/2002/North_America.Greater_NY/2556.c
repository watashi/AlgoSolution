#include <stdio.h>
int main()
{
	int i, j;
	double win, lose, tie, sum, dp[21][203];

	for (j = 0; j < 203; j++)
		dp[0][j] = 0;
	dp[0][100] = 1;
	printf("Round   A wins    B wins    Tie\n");
	for(i = 1; i <= 20; i++){
		win = lose = tie = sum = 0;
		for(j = 0; j < 3; j++)
			dp[i][j] = 0;
		for(j = 3; j < 200; j++){
			dp[i][j] = dp[i - 1][j - 3] + 2 * dp[i - 1][j - 2] + 4 * dp[i - 1][j - 1] +
				6 * dp[i - 1][j] + 2 * dp[i - 1][j + 1] + dp[i - 1][j + 3];
			sum += dp[i][j];
			if(j < 100) win += dp[i][j];
			else if(j == 100) tie = dp[i][j];
			else lose += dp[i][j];
		}
		for(j = 200; j < 203; j++)
			dp[i][j] = 0;
		printf("%5d %9.4lf%%%9.4lf%%%9.4lf%%\n", i, 100.0 * lose / sum, 100.0 * win / sum, 100.0 * tie / sum);
	}

	return 0;
}

/* # 		Problem 	Verdict 	Language 	Run Time 	Submission Date */
/* 805963 	2556 	Four Quarters 	Accepted 	ANSI C 	0.008 	2011-05-23 16:09:09 */
/*
id => 1174331
pid => 2556
pname => Four Quarters
status => Accepted
lang => ANSI C
time => 0.006
date => 2012-12-14 17:58:28
*/
