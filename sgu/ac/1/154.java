// SGU154. Factorial
/*
154. Factorial
time limit per test: 0.50 sec.
memory limit per test: 4096 KB
input: standard input
output: standard output



You task is to find minimal natural number N, so that N! contains exactly Q zeroes on the trail in decimal notation. As you know N! = 1*2*...*N. For example, 5! = 120, 120 contains one zero on the trail.

Input
One number Q written in the input (0<=Q<=10^8).

Output
Write "No solution", if there is no such number N, and N otherwise.

Sample test(s)

Input

2

Output

10
Author:	Andrew V. Lazarev
Resource:	Saratov Subregional School Team Contest, 2002
Date:	Spring, 2002
*/

import java.util.*;

public class Solution {
	static int factZeros(int n) {
		int ret = 0;
		while (n > 0) {
			n /= 5;
			ret += n;
		}
		return ret;
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int q = in.nextInt();
		int l = 1/* (Wrong answer on test 3) if (0) */, r = 5 * q;
		while (l < r) {
			int mid = (l + r) >> 1;
			if (factZeros(mid) < q) {
				l = mid + 1;
			} else {
				r = mid;
			}
		}
		if (factZeros(l) == q) {
			System.out.println(l);
		} else {
			System.out.println("No solution");
		}
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//865697	30.06.09 06:48	watashi	154 	.JAVA	Accepted	6 ms	1890 kb

