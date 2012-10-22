// SGU197. Nice Patterns Strike Back
/*
197. Nice Patterns Strike Back
time limit per test: 2 sec.
memory limit per test: 65536 KB
input: standard
output: standard



You might have noticed that there is the new fashion among rich people to have their yards tiled with black and white tiles, forming a pattern. The company Broken Tiles is well known as the best tiling company in our region. It provides the widest choices of nice patterns to tile your yard with. The pattern is nice if there is no square of size 2 × 2, such that all tiles in it have the same color. So patterns on the figure 1 are nice, while patterns on the figure 2 are not.





The president of the company wonders whether the variety of nice patterns he can provide to the clients is large enough. Thus he asks you to find out the number of nice patterns that can be used to tile the yard of size N × M. Now he is interested in the long term estimation, so he suggests N ≤ 10100. However, he does not like big numbers, so he asks you to find the answer modulo P.

Input

The input file contains three integer numbers: N (1 ≤ N ≤ 10100), M (1 ≤ M ≤ 5) and P (1 ≤ P ≤ 10000).

Output

Write the number of nice patterns of size N × M modulo P to the output file.

Sample test(s)

Input


Test #1

2 2 5

Test #2

3 3 23

Output


Test #1

4

Test #2

0


[submit]
[forum]
Author:	Andrew Stankevich
Resource:	Petrozavodsk Winter Trainings 2003
Date:	2003-02-06 
*/
import java.math.*;
import java.util.*;

public class Solution {
	static int[][] mul(int n, int m, int[][] a, int[][] b) {
		int[][] ret = new int[n][n];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				long s = 0;
				for (int k = 0; k < n; ++k) {
					s += a[i][k] * b[k][j];
				}
				ret[i][j] = (int)(s % m);
			}
		}
		return ret;
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		BigInteger n = in.nextBigInteger().subtract(BigInteger.ONE);
		int m = in.nextInt();
		int p = in.nextInt();
		int mm = 1 << m;
		int[][] a = new int[mm][mm];
		for (int i = 0; i < mm; ++i) {
			for (int j = i; j < mm; ++j) {
				int mask = (i ^ (i >> 1)) | (j ^ (j >> 1)) | (i ^ j);
				if ((mask & ((mm >> 1) - 1)) == ((mm >> 1) - 1)) {
					a[i][j] = a[j][i] = 1;
				}
			}
		}
		int[][] c = new int[mm][mm];
		for (int i = 0; i < mm; ++i) {
			c[i][i] = 1;
		}
		for (int i = 0; i < n.bitLength(); ++i) {
			if (n.testBit(i)) {
				c = mul(mm, p, c, a);
			}
			a = mul(mm, p, a, a);
		}
		long ans = 0;
		for (int i = 0; i < mm; ++i) {
			for (int j = 0; j < mm; ++j) {
				ans += c[i][j];
			}
		}
		System.out.println(ans % p);
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//873713	04.08.09 17:07	watashi	197 	.JAVA	Accepted	139 ms	3286 kb
