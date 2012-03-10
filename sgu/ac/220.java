// SGU220. Little Bishops
/*
220. Little Bishops
time limit per test: 1 sec.
memory limit per test: 65536 KB
input: standard
output: standard




A bishop is a piece used in the game of chess which is played on a board of square grids. A bishop can only move diagonally from its current position and two bishops attack each other if one is on the path of the other.

Given two numbers n and k, your job is to determine the number of ways one can put k bishops on an n × n chessboard so that no two of them are in attacking positions.

Input

The input file contains two integers n (1 ≤ n ≤ 10) and k (0 ≤ k ≤ n2).

Output

Print a line containing the total number of ways one can put the given number of bishops on a chessboard of the given size so that no two of them are in attacking positions.

Sample test(s)

Input

Test #1

4 4

Test #2

8 6

Output

Test #1

260

Test #2

5599888
[submit]
[forum]
Author:	Folklore, Andrew Stankevich
Resource:	Little Chess Pieces Series, SPb IFMO 2003-2004 Authumn Training Sessions
Date:	2003-09-27 
*/
// the same as 221
import java.math.*;
import java.util.*;

public class Solution {
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
		int[] odd = new int[n];
		for (int i = 0; i < odd.length; ++i) {
			odd[i] = i / 2 * 2 + 1;
		}
		BigInteger[] ans1 = gao(odd);
		int[] even = new int[n - 1];
		for (int i = 0; i < even.length; ++i) {
			even[i] = i / 2 * 2 + 2;
		}
		BigInteger[] ans2 = gao(even);
		BigInteger ans = BigInteger.ZERO;
		for (int i = Math.max(0, k - (ans2.length - 1)); i < ans1.length && i <= k; ++i) {
			ans = ans.add(ans1[i].multiply(ans2[k - i]));
		}
		System.out.println(ans);
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//874623	08.08.09 20:37	watashi	220 	.JAVA	Accepted	7 ms	2286 kb

