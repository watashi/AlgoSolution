// SGU441. Set Division
/*
441. Set Division
Time limit per test: 4 second(s)
Memory limit: 262144 kilobytes
input: standard
output: standard


Ruslan has friends. And all of them have birthday tomorrow. He has bought different photo albums yesterday, and wants to present these photo albums to his friends. Of course, he can't give less than 1 photo album to anybody. Your task is to calculate how many possible ways is there to do it.

All photo albums are different. Two distributions are considered the same if they differ only by order of albums in the gifts or by the persons receiving gifts.

Input
In the only line of the input there are two numbers separated by a space — , .

Output
Output should contain one number — the number of possible ways to distribute the albums modulo .

Example(s)

sample input

	

sample output

3 2 

	

3

*/

import java.util.*;

public class Solution {
	static final int MOD = 2007;

	static int[][] mul(int n, int a[][], int b[][]) {
		int[][] c =  new int[n][n];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				for (int k = 0; k < n; ++k) {
					c[i][j] += a[i][k] * b[k][j];
				}
				c[i][j] %= MOD;
			}
		}
		return c;
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int k = in.nextInt();
		int[][] a = new int[k + 1][k + 1];
		for (int i = 0; i <= k; ++i) {
			if (i > 0) {
				a[i][i - 1] = 1;
			}
			a[i][i] = i;
		}
		int[][] b = new int[k + 1][k + 1];
		for (int i = 0; i <= k; ++i) {
			b[i][i] = 1;
		}
		while (n > 0) {
			if ((n & 1) != 0) {
				b = mul(k + 1, b, a);
			}
			a = mul(k + 1, a, a);
			n >>= 1;
		}
		System.out.println(b[k][0]);
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//874707	09.08.09 10:57	watashi	441 	.JAVA	Accepted	21 ms	2134 kb
