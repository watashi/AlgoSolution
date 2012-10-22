// SGU130. Circle
/*
130. Circle

time limit per test: 0.50 sec.
memory limit per test: 4096 KB

On a circle border there are 2k different points A1, A2, ..., A2k, located contiguously. These points connect k chords so that each of points A1, A2, ..., A2k is the end point of one chord. Chords divide the circle into parts. You have to find N - the number of different ways to connect the points so that the circle is broken into minimal possible amount of parts P.

Input

The first line contains the integer k (1 <= k <= 30).

Output

The first line should contain two numbers N and P delimited by space.

Sample Input

2

Sample Output

2 3

Author	: Natalia L. Andreeva, Alex Y. Suslov, Alexander S. Ivanov
Resource	: 5th Southern Subregional Contest. Saratov 2002
Date	: 2002-10-10
*/

import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int k = in.nextInt();
		long[] dp = new long[k + 1];
		dp[0] = 1;
		for (int i = 1; i <= k; ++i) {
			for (int j = 0; j < i; ++j) {
				dp[i] += dp[j] * dp[i - 1 - j];
			}
		}
		System.out.println(dp[k] + " " + (k + 1));
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//866718	04.07.09 18:46	watashi	130 	.JAVA	Accepted	6 ms	2214 kb


