// SGU169. Numbers
/*

169. Numbers
time limit per test: 0.50 sec.
memory limit per test: 4096 KB
input: standard
output: standard



Let us call P(n) - the product of all digits of number n (in decimal notation).
For example, P(1243)=1*2*4*3=24; P(198501243)=0.
Let us call n to be a good number, if (p(n)<>0) and (n mod P(n)=0).
Let us call n to be a perfect number, if both n and n+1 are good numbers.

You are to write a program, which, given the number K, counts all such
numbers n that n is perfect and n contains exactly K digits in decimal notation.

Input
Only one number K (1<=K<=1000000) is written in input.

Output
Output the total number of perfect k-digit numbers.

Sample test(s)

Input

1

Output

8
[submit]
[forum]
Author:	All-Russian mathematical olympiad jury
Resource:	District mathematical olympiad, 8th form
Date:	
*/

import java.util.*;

public class Solution {
	// gcd(n, n + 1) == 1 && n % p(n)=0
	// => gcd(p(n), p(n + 1)) = 1
	// => n =~ m/1*[1-8]/
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int k = in.nextInt();
		int ans = 0;
		// _k = 0 1 2 3 ...
		--k;
		// %1 = 0 0 .
		if (k % 1 == 0) { ++ans; }
		// %2 = 0 0 .
		if (k % 3 == 0) { ++ans; }
		// %3 = 0 1 2 0 .
		if (k == 0) { ++ans; }
		// %4 = 0 2 2 x
		if (k == 0) { ++ans; }
		// %5 = 0 0 .
		if (k % 3 == 0) { ++ans; }
		// %6 = 0 4 2 0 .
		if (k % 6 == 0) { ++ans; }
		// %7 = 0 3 5 4 1 6 0 .
		if (k == 0) { ++ans; }
		// %8 = 0 2 6 6 x
		if (k == 0) { ++ans; }
		// %9 = 0 1 2 3 4 5 6 7 8 9 0 .
		System.out.println(ans);
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//866725	04.07.09 19:24	watashi	169 	.JAVA	Accepted	6 ms	2210 kb


