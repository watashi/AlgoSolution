// SGU181. X-Sequence
/*
181. X-Sequence
time limit per test: 0.50 sec.
memory limit per test: 4096 KB
input: standard
output: standard



Let {xi} be the infinite sequence of integers:
1) x0 = A;
2) xi = (alpha * xi-1^2 + beta * xi-1 + gamma) mod M, for i >= 1.
Your task is to find xk if you know A, alpha, beta, gamma, M and k.

Input
Given A (1 <= A <= 10000), alpha (0 <= alpha <= 100), beta (0 <= beta <= 100), gamma (0 <= gamma <= 100), M (1 <= M <= 1000), k (0 <= k <= 10^9). All numbers are integer.

Output
Write xk.

Sample test(s)

Input

1 1 1 1 10 1

Output

3
[submit]
[forum]
Author:	Michael R. Mirzayanov
Resource:	Saratov ST team Spring Contest #1
Date:	18.05.2003
*/

import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int A = in.nextInt();
		int alpha = in.nextInt();
		int beta = in.nextInt();
		int gamma = in.nextInt();
		int M = in.nextInt();
		int k = in.nextInt();
		if (k == 0) {
			System.out.println(A);
			return;
		}
		int[] x = new int[M];
		int begin = -1, end = -1;
		x[0] = A % M;
GAO:
		for (int i = 1; ; ++i) {
			x[i] = ((alpha * x[i - 1] + beta) * x[i - 1] + gamma) % M;
			for (int j = 0; j < i; ++j) {
				if (x[i] == x[j]) {
					begin = j;
					end = i;
					break GAO;
				}
			}
		}
		if (k > begin) {
			k = begin + (k - begin) % (end - begin);
		}
		System.out.println(x[k]);
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//865985	01.07.09 10:34	watashi	181 	.JAVA	Accepted	6 ms	2226 kb


