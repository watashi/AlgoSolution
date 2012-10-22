// SGU107. 987654321 problem
/*
107. 987654321 problem

time limit per test: 0.75 sec.
memory limit per test: 4096 KB

For given number N you must output amount of N-digit numbers, such, that last digits of their square is equal to 987654321.

Input

Input contains integer number N (1<=N<=106)

Output

Write answer to the output.

Sample Input

8

Sample Output

0
*/

/*
111111111
611111111
380642361
880642361
119357639
619357639
388888889
888888889
*/

import java.util.*;

public class Solution {
	public static void main(String[] args) {
		int t = 1, n = 987654321, m, k;
		ArrayList<Integer> x = new ArrayList<Integer>();
		x.add(0);
		while (t < n) {
			m = t * 10;
			k = n % m;
			ArrayList<Integer> y = new ArrayList<Integer>();
			for (int z : x) {
				for (int i = 0; i < 10; ++i) {
					if (((long)z * (long)z) % m == k) {
						y.add(z);
					}
					z += t;
				}
			}
			t = m;
			x = y;
		}
		int[] ans = new int[10];
		for (Integer z : x) {
			++ans[z.toString().length()];
		}
		
		Scanner in = new Scanner(System.in);
		int d = in.nextInt();
		if (d <= 9) {
			System.out.println(ans[d]);
		} else {
			System.out.print(ans[9] * 9);
			/* Time Limit Exceeded on test 18
			for (int i = 10; i < d; ++i) {
				System.out.print('0');
			}
			*/
			/* Memory Limit Exceeded on test 18
			char[] str = new char[d - 10];
			Arrays.fill(str, '0');
			System.out.println(new String(str));
			*/
			char[] chr = new char[4096];
			Arrays.fill(chr, '0');
			String str = new String(chr);
			d -= 10;
			while (d > 4096) {
				System.out.print(str);
				d -= 4096;
			}
			while (d > 0) {
				System.out.print('0');
				--d;
			}
			System.out.println();
		}
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//866449	03.07.09 17:37	watashi	107 	.JAVA	Accepted	43 ms	2814 kb


