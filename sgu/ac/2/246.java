// SGU246. Black & White
/*
246. Black & White
time limit per test: 2 sec.
memory limit per test: 65536 KB
input: standard
output: standard



Consider a necklace made of 2N-1 black and white beads, K of which are black. Necklace is called "beautiful" if it is possible to choose two black beads (not necessarily different) in such a way that one of two necklace parts strictly between them contains exactly N beads.
For example, if N=4 and K=3, necklace "WBWBWBW" is beautiful, and necklace "BBWWBWW" is not.
You need to find minimal K for which every necklace of 2N-1 beads is beatiful.

Input
The first line of input contains odd integer number 2N-1 (5<=2N-1<=2^31-1).

Output
Output minimal K for which every necklace of 2N-1 beads is beatiful.

Sample test(s)

Input

Test #1
5

Test #2
7

Output

Test #1
3

Test #2
4
[submit]
[forum]
Author:	Alexey Preobrajensky
Resource:	Petrozavodsk Summer Training Sessions 2004
Date:	August 25, 2004 
*/

// n%3==2 gcd(n+1, 2n-1)=3 ans=(2n-1)/3/2*3+1
// n%3!=2 gcd(n+1, 2n-1)=1 ans=(2n-1)/2+1

import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		long n = (in.nextLong() + 1) / 2;
		if (n % 3 == 2) {	// WA7
			System.out.println(n - 1);
		} else {
			System.out.println(n);
		}
	}
}
// 2^31-1 => WA48

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//873511	03.08.09 20:55	watashi	246 	.JAVA	Accepted	19 ms	2218 kb

