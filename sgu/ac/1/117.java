// SGU117. Counting
/*
117. Counting

time limit per test: 0.50 sec.
memory limit per test: 4096 KB

Find amount of numbers for given sequence of integer numbers such that after raising them to the M-th power they will be divided by K.

Input

Input consists of two lines. There are three integer numbers N, M, K (0<N, M, K<10001) on the first line. There are N positive integer numbers − given sequence (each number is not more than 10001) − on the second line.

Output

Write answer for given task.

Sample Input

4 2 50
9 10 11 12

Sample Output

1

Author	: Michael R. Mirzayanov
Resource	: PhTL #1 Training Contests
Date	: Fall 2001
*/

import java.util.*;

class ModMath {
	final int MOD;

	ModMath(int mod) {
		MOD = mod;
	}

	int pow(int a, long b) {
		long y = 1 % MOD;
		long x = a % MOD;
		while (b > 0) {
			if ((b & 1) != 0) {
				y = (y * x) % MOD;
			}
			x = (x * x) % MOD;
			b >>= 1;
		}
		return (int)y;
	}
}

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
		int k = in.nextInt();
		ModMath calc = new ModMath(k);
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			int x = in.nextInt();
			if (calc.pow(x, m) == 0) {
				++ans;
			}
		}
		System.out.println(ans);
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//866411	03.07.09 16:39	watashi	117 	.JAVA	Accepted	103 ms	3182 kb


