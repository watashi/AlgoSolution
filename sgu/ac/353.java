// SGU353. Billing
/*
353. Billing
Time limit per test: 2 second(s)
Memory limit: 65536 kilobytes
input: standard
output: standard


A girl named Kate has a contract with the Berland only cell phone operator BTS. Her tariff plan is called "Very Profitable" and all Kate can do is to make phone calls. All incoming calls are free. The outgoing calls are billed in the following way: at the very beginning of the call Kate's account is charged p1 cents for the first k1 seconds of the call. Each of the next k2 seconds costs p2 cents. And all remaining time costs p3 cents per second. The account is always billed instantly at the end of each second. If the account balance becomes non-positive, the call is automatically dropped.

Kate has put N cents to her account and she is going to talk with her very good friend. Kate would like to know what is the maximum number of seconds she can talk during a single call.

If N < p1, Kate does not have enough money to establish the call.

Input
The input contains 6 integer numbers N, k1, k2, p1, p2, p3, (0≤ N≤ 1000000; 1≤ k1,k2≤ 1000000; 1≤ p1, p2, p3≤ 1000000).

Output
Write to the output just one integer number — the maximum number of seconds Kate can talk.

Example(s)

sample input

	

sample output

20 3 3 3 4 2

	

9


sample input

	

sample output

3 15 3 5 2 3

	

0


sample input

	

sample output

1 1 1 1 3 1

	

1


sample input

	

sample output

2 1 1 1 3 1

	

2

*/
import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		long n = in.nextInt();
		long k1 = in.nextInt();
		long k2 = in.nextInt();
		long p1 = in.nextInt();
		long p2 = in.nextInt();
		long p3 = in.nextInt();
		long ans = 0;
		if (n >= p1) {
			ans += k1;
			n -= p1;
			if (n >= p2 * k2) {
				ans += k2;
				n -= p2 * k2;
				ans += (n + p3 - 1) / p3;
			} else {
				ans += (n + p2 - 1) / p2;
			}
		}
		System.out.println(ans);
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//874960	10.08.09 17:08	watashi	353 	.JAVA	Accepted	35 ms	2082 kb
//874956	10.08.09 16:56	watashi	353 	.JAVA	Wrong answer on test 26	15 ms	2086 kb
