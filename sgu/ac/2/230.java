// SGU230. Weighings
/*
230. Weighings
time limit per test: 0.50 sec.
memory limit per test: 4096 KB
input: standard
output: standard



There are N types of coins in Berland country. Values of the types are 1 burl, 2 burls, ..., N burls. The weight of i-burles coin is i grams. N coins (one of each type) are placed in N matchlog boxes, one coin in each box. A number of weighings was done on the cup-scales.
You are to write a program which should find such assignment of coins to boxes, that would not conflict with the weighings. It is possible that scales are broken and such assignment doesn't exist.

Input
The first line of the input consists of two integers N and M (1 <= N <= 100, 1 <= M <= 10000), where N is the amount of types, and M is the amount of weighings. Next M lines consist of pairs P, Q (1 <= P, Q <= N), each line means that the P-th box lighter than the Q-th.

Output
Write "No solution" if it is impossible to find such assignment. In opposite case, write N numbers, where the K-th number means the type of coin in K-th box, for example A, means that there is A-burles coin in the K-th box. Output sequence must be a permutation of numbers from 1 to N.

Sample test(s)

Input

3 2
2 1
1 3

Output

2 1 3
[submit]
[forum]
Author:	Michael R. Mirzayanov
Resource:	---
Date:	---
*/
// [algo]Topological Sort

import java.io.*;

public class Solution {
	static int nextInt() throws IOException {
		int ch = -1;
		do {
			ch = System.in.read();
		} while (!Character.isDigit(ch));
		int ret = 0;
		while (Character.isDigit(ch)) {
			ret *= 10;
			ret += Character.digit(ch, 10);
			ch = System.in.read();
		}
		return ret;
	}

	public static void main(String[] args) throws IOException {
		int n = nextInt();
		int m = nextInt();
		int[][] a = new int[n][n];
		int[] d = new int[n];
		for (int i = 0; i < m; ++i) {
			int x = nextInt() - 1;
			int y = nextInt() - 1;
			++a[x][y];
			++d[y];
		}
		int[] queue = new int[n];
		int p = 0, q = 0;
		for (int i = 0; i < n; ++i) {
			if (d[i] == 0) {
				queue[q++] = i;
			}
		}
		while (p < q) {
			for (int i = 0; i < n; ++i) {
				if (d[i] > 0) {
					d[i] -= a[queue[p]][i];
					if (d[i] == 0) {
						queue[q++] = i;
					}
				}
			}
			++p;
		}
		if (q == n) {
			int[] ans = new int[n];
			for (int i = 0; i < n; ++i) {	// ~~
				ans[queue[i]] = i + 1;
			}
			for (int i = 0; i < n; ++i) {
				System.out.print(ans[i] + (i == n - 1 ? "\n" : " "));
			}
		} else {
			System.out.println("No solution");
		}
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//873503	03.08.09 20:19	watashi	230 	.JAVA	Accepted	19 ms	366 kb
//873502	03.08.09 20:12	watashi	230 	.JAVA	Wrong answer on test 2	0 ms	190 kb

