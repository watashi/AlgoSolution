// SGU175. Encoding
/*
175. Encoding
time limit per test: 0.50 sec.
memory limit per test: 4096 KB
input: standard
output: standard



Let phi(W) is the result of encoding for algorithm:
1. If the length of W is 1 then phi(W) is W;
2. Let coded word is W = w1w2...wN and K = N / 2 (rounded down);
3. phi(W) = phi(wNwN-1...wK+1) + phi(wKwK-1...w1).
For example, phi('Ok') = 'kO', phi('abcd') = 'cdab'.
Your task is to find position of letter wq in encoded word phi(W).

Input
Given integers N, q (1 <= N <= 10^9; 1<= q <= N), where N is the length of word W.

Output
Write position of letter wq in encoded word phi(W).

Sample test(s)

Input

9 4

Output

8
[submit]
[forum]
Author:	Michael R. Mirzayanov
Resource:	Saratov ST team Spring Contest #1
Date:	18.05.2003
*/

import java.util.*;

public class Solution {
	static int gao(int n, int q) {
		if (n == 1) {
			return 1;
		} else {
			int k = n / 2;
			if (q <= k) {
				return n - k + gao(k, k + 1 - q);
			} else {
				return gao(n - k, n + 1 - q);
			}
		}
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int q = in.nextInt();
		System.out.println(gao(n, q));
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//865986	01.07.09 10:49	watashi	175 	.JAVA	Accepted	19 ms	2218 kb

