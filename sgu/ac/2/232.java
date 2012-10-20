// SGU232. Infinite Fraction
/*
232. Infinite Fraction
time limit per test: 1 sec.
memory limit per test: 4096 KB
input: standard
output: standard



You are given integer numbers N and K and an array D[0..N-1] of decimal digits (0<=D[i]<=9, D[i] is an integer).
Consider an array A of real numbers, such that integer part of A[i] is equal to zero, and fractional part is an infinite decimal fraction with digits D[[(i + 0K) mod N], D[(i + 1K) mod N], D[(i + 2K) mod N] and so on.
For example, for N = 3, K = 2 and D = '194':

A[1] = 0.1491491491...
A[2] = 0.9149149149...
A[3] = 0.4914914914...

You are to find an element of array A with the greatest value and output first N digits of its fractional part.

Input
The first line contains integer numbers N and K (1<=N<=150000; 0<=K<=10^9). The second line contains an array of digits D, given without spaces.

Output
You are to output exactly N characters to the output file, according to the task.

Sample test(s)

Input

Test #1
3 2
194

Test #2
2 1
57

Test #3
4 1
0000

Output

Test #1
914

Test #2
75

Test #3
0000
[submit]
[forum]
Author:	Antony Popovich
Resource:	---
Date:	October, 2003
*/

// O(n)
// 字符串最小表示

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

	static int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}

	// [algo] minString
	// [module] minString
	public static int maxP(int n, byte[] a) {
		int i = 0, j = 1;
		// double str
		while (i < n && j < n) {
			int k = 0;
			while (k < n && a[i + k] == a[j + k]) {
				++k;
			}
			if (a[i + k] < a[j + k]) {
				i += k + 1;
			} else if (a[i + k] > a[j + k]) {
				j += k + 1;
			} else {	// k == n
				break;
			}
			if (i == j) {
				++j;
			}
		}
		return Math.min(i, j);
	}

	public static void main(String[] args) throws IOException {
		int n = nextInt();
		int k = nextInt() % n;
		byte[] s = new byte[n];
		int ch = System.in.read();	// \n @.@ \r\n => WA1
		while (Character.isWhitespace(ch)) {
			ch = System.in.read();
		}
		s[0] = (byte)ch;
		System.in.read(s, 1, s.length - 1);

		int g = gcd(n, k);
		int len = n / gcd(n, k);
		byte[] buf = new byte[2 * len];
		byte[] ans = new byte[len];

		for (int i = 0; i < g; ++i) {
			if (s[i] == 0) {
				continue;
			}
			for (int j = 0, p = i; j < len; ++j, p = (p + k) % n) {
				buf[j] = buf[len + j] = s[p];
			}
			int off = maxP(len, buf);
			for (int j = 0; j < len; ++j) {
				if (ans[j] < buf[off + j]) {
					while (j < len) {
						ans[j] = buf[off + j];
						++j;
					}
				} else if (ans[j] > buf[off + j]) {
					break;
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			s[i] = ans[i % len];
		}
		System.out.write(s);
		System.out.println();
	}
}

// Scanner | BufferedReader + String => MLE4

// ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status:  	Time:  	Memory:
// 1078645	19.09.10 16:40	watashi	232 	.JAVA	Accepted 	0 ms	0 kb

