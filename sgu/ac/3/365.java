// SGU365. Ships of the Desert
/*
365. Ships of the Desert
Time limit per test: 1 second(s)
Memory limit: 65536 kilobytes
input: standard
output: standard


During one of his trips Vasya went to Egypt. He needed to cross the desert. This is pretty easy to do because of caravans furrowing the desert. The only thing Vasya needed was to buy a ticket. Inhabitants told Vasya that he should buy peculiar ticket to get a lot of luck in his life. Vasya found out that peculiar ticket is so-called ticket-dromedary (named after the dromedary camels that are crossing the desert). Ticket can be called dromedary if digits in its number are going in non-descending order and then in non-ascending order (length of any digit group may equals to zero). Vasya has interesting question: how many tickets-dromedaries exist with number consisting of exactly S digits?

Input
The first line of the input file contains S (1 ≤ S ≤ 20) — amount of digits in the ticket number. Ticket number may have leading zeroes.

Output
Print amount of tickets-dromedaries with exactly S digits.

Example(s)

sample input

	

sample output

1

	

10


sample input

	

sample output

3

	

715

*/
import java.util.*;

public class Solution {
	static final int MAXS = 20;
	static long[] ans;

	static {
		ans = new long[MAXS + 1];
		long[][] dp = new long[MAXS + 1][11];
		Arrays.fill(dp[0], 1);
		for (int i = 1; i <= MAXS; ++i) {
			for (int j = 1; j <= 10; ++j) {
				dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
			}
		}
		for (int i = 1; i <= MAXS; ++i) {
			for (int j = 0; j <= 9; ++j) {
				for (int k = 0; k < i; ++k) {
					ans[i] += dp[k][j + 1] * dp[i - 1 - k][j];
				}
			}
		}
	}
		
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int s = in.nextInt();
		System.out.println(ans[s]);
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//874939	10.08.09 14:13	watashi	375 	.JAVA	Accepted	25 ms	2054 kb
