// SGU207. Robbers
/*
207. Robbers
time limit per test: 2 sec.
memory limit per test: 65536 KB
input: standard
output: standard



N robbers have robbed the bank. As the result of their crime they chanced to get M golden coins. Before the robbery the band has made an agreement that after the robbery i-th gangster would get Xi/Y of all money gained. However, it turned out that M may be not divisible by Y.

The problem which now should be solved by robbers is what to do with the coins. They would like to share them fairly. Let us suppose that i-th robber would get Ki coins. In this case unfairness of this fact is |Xi/Y-Ki/M|. The total unfairness is the sum of all particular unfairnesses. Your task as the leader of the gang is to spread money among robbers in such a way that the total unfairness is minimized.

Input
The first line of the input file contains numbers N, M and Y (1 ≤ N ≤ 1000, 1 ≤ M, Y ≤ 10000). N integer numbers follow - Xi (1 ≤ Xi ≤ 10000, sum of all Xi is Y).

Output
Output N integer numbers — Ki (sum of all Ki must be M), so that the total unfairness is minimal.

Sample test(s)

Input

3 10 4
1 1 2

Output

2 3 5
[submit]
[forum]
Author:	Andrew Stankevich
Resource:	Petrozavodsk Summer Trainings 2003
Date:	2003-08-23
*/
import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		long m = in.nextLong();
		long y = in.nextLong();
		long[] x = new long[n];
		for (int i = 0; i < n; ++i) {
			x[i] = in.nextLong();
		}
		long[] k = new long[n];
		long[] d = new long[n];
		long r = m;
		for (int i = 0; i < n; ++i) {
			k[i] = x[i] * m / y;
			r -= k[i];
			d[i] = (2 * k[i] + 1) * y - 2 * x[i] * m;
			d[i] = (d[i] << 10) ^ i;
		}
		Arrays.sort(d);
		for (int i = 0; i < r; ++i) {
			k[(int)(d[i] & 1023L)]++;
		}
		for (int i = 0; i < n; ++i) {
			System.out.print(k[i]);
			System.out.print(i == n - 1 ? '\n' : ' ');
		}
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//873919	05.08.09 09:02	watashi	207 	.JAVA	Accepted	79 ms	3438 kb

