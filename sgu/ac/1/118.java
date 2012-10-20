// SGU118. Digital Root
/*
118. Digital Root

time limit per test: 0.50 sec.
memory limit per test: 4096 KB

Let f(n) be a sum of digits for positive integer n. If f(n) is one-digit number then it is a digital root for n and otherwise digital root of n is equal to digital root of f(n). For example, digital root of 987 is 6. Your task is to find digital root for expression A1*A2*…*AN + A1*A2*…*AN-1 + … + A1*A2 + A1.

Input

Input file consists of few test cases. There is K (1<=K<=5) in the first line of input. Each test case is a line. Positive integer number N is written on the first place of test case (N<=1000). After it there are N positive integer numbers (sequence A). Each of this numbers is non-negative and not more than 109.

Output

Write one line for every test case. On each line write digital root for given expression.

Sample Input

1
3 2 3 4

Sample Output

5

Author	: Michael R. Mirzayanov
Resource	: PhTL #1 Training Contests
Date	: Fall 2001
*/

import java.math.*;
import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int re = in.nextInt();
		for (int ri = 1; ri <= re; ++ri) {
			int n = in.nextInt();
			int[] a = new int[n];
			for (int i = 0; i < n; ++i) {
				a[i] = in.nextInt();
			}
			BigInteger x = BigInteger.ONE;
			for (int i = n - 1; i >= 0; --i) {
				x = x.multiply(BigInteger.valueOf(a[i]));
				x = x.add(BigInteger.ONE);
			}
			x = x.subtract(BigInteger.ONE);
			char[] d = x.toString().toCharArray();
			int s = 0;
			for (char digit : d) {
				s += Character.digit(digit, 10);
			}
			while (s >= 10) {
				int ss = 0;
				while (s > 0) {
					ss += s % 10;
					s /= 10;
				}
				s = ss;
			}
			System.out.println(s);
		}
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//866415	03.07.09 16:48	watashi	118 	.JAVA	Accepted	417 ms	3538 kb


