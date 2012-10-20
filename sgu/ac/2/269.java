// SGU269. Rooks
/*
269. Rooks
time limit per test: 1 sec.
memory limit per test: 65536 KB
input: standard
output: standard



Let's define a board as a finite subset of infinite chessboard cells. The (b_1, b_2, ..., b_n) board is the board with n left-aligned rows. The i-th line consists of b_i sequential cells. For example, (1, 4, 3, 5) board looks as follows:

 
 	 	 	 
 	 	 
 	 	 	 	 


The rook can be placed on any cell of the board. The rooks disposition is called peaceful if and only if no two rooks stay on the same vertical or horizontal line (no matter if all cells between them belong to the (b_1, b_2, ..., b_n) board or not).
Your task is to find a number of peaceful dispositions of k rooks for the (b_1, b_2, ..., b_n) board.

Input
The first line of the input file contains two integer numbers n and k (1 <= n, k <= 250). The second line contains n space-delimited numbers (b_1, b_2, ..., b_n) (1 <= b_i <= 250, i=1..n).

Output
Write to the output single integer -- number of different peaceful rooks dispositions on the given board.

Sample test(s)

Input

Test #1
2 2
2 3

Test #2
3 3
2 1 2

Output

Test #1
4

Test #2
0
[submit]
[forum]
Author:	Michael R. Mirzayanov
Resource:	ACM ICPC 2004-2005, NEERC, Southern Subregional Contest
Date:	Saratov, October 7, 2004 
*/
import java.math.*;
import java.util.*;

public class Solution {
	// (from sgu221)
	static BigInteger[] gao(int[] a) {
		BigInteger[] ret = new BigInteger[a.length + 1];
		ret[0] = BigInteger.ONE;
		for (int i = 0; i < a.length; ++i) {
			ret[i + 1] = BigInteger.ZERO;
			for (int j = i; j >= 0; --j) {
				if (a[i] > j) {
					ret[j + 1] = ret[j + 1].add(ret[j].multiply(BigInteger.valueOf(a[i] - j)));
				}
			}
		}
		return ret;
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int k = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; ++i) {
			a[i] = in.nextInt();
		}
		Arrays.sort(a);
		BigInteger[] ans = gao(a);
		System.out.println(k >= ans.length ? BigInteger.ZERO : ans[k]);
	}
}
// k==ans.length => RE3
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//874630	08.08.09 20:48	watashi	269 	.JAVA	Accepted	74 ms	3282 kb
