// SGU205. Quantization Problem
/*
205. Quantization Problem
time limit per test: 2 sec.
memory limit per test: 65536 KB
input: standard
output: standard



When entering some analog data into a computer, this information must be quantized. Quantization transforms each measured value x to some other value l(x) selected from the predefined set L of levels. Sometimes to reduce the influence of the levels set to the information, the group of levels sets Li is used. The number of levels sets is usually chosen to be the power of 2.

When using the number of levels sets, some additional information should be used to specify which set was used for each quantization. However, providing this information may be too expensive — the better solution would be to choose more levels and use one set. To avoid the specification of the quantization set, the following technique is used. Suppose that n values x1, x2, ..., xn are to be quantized and the group of m=2p levels sets Li, i=0, ..., m-1; each of size s=2q is used to quantize it. After quantization xj is replaced with some number lj = in Lf(j). Instead of sending lj, its ordinal number in Lf(j) is usually sent, let kj be the ordinal number of lj in Lf(j) (levels are numbered starting with 0). Take p least significant bits of kj and say that the number kj & (2p-1) is the number of the levels set that will be used for next quantization, that is f(j+1) = kj & (2p-1).

Since the least significant bits of kj are usually distributed quite randomly, the sets used for quantization change often and weakly depend on values of quantized data, thus this technique provides the good way to perform the quantization.

Usually to perform the quantization the closest to the value level of the levels set is chosen. However, using the technique described, sometimes it pays off to choose not the optimal level, but some other one, the ordinal number of which has other least significant bits, thus choosing another levels set for next measure and providing better approximation of quantized values in the future. Let us call the deviation of quantization the value of sum(j=1.. n, |xj - lj|). Your task is given measures and levels sets to choose quantized value for each measure in such a way, that the deviation of quantization is minimal possible.

The first value is always quantized using set L0.

Input
The first line of the input file contains n (1 ≤ n ≤ 1000). The second line contains n integer numbers xi ranging from 1 to 106. The next line contains m and s (1 ≤ m ≤ 128, m ≤ s ≤ 128). Next m lines contain s integer numbers each — levels of the quantization sets given in increasing order for each set, all levels satisfy 1 ≤ level ≤ 106.

Output
First output the minimal possible deviation of the quantization. Then output n integer numbers in range from 0 to s - 1. For each input value output the number of the level in the corresponding levels set (kj) used for this number to achieve the quantization required.

Sample test(s)

Input

3
8 8 19
2 4
5 10 15 20
3 7 13 17

Output

5
1 1 3
[submit]
[forum]
Author:	Andrew Stankevich
Resource:	Petrozavodsk Summer Trainings 2003
Date:	2003-08-23
*/
import java.util.*;

public class Solution {
	public static int binarySearch(int[] a, int key) {
		int index = Arrays.binarySearch(a, key);
		if (index < 0) {
			index = -index - 1;
			if (index == a.length || (index > 0 && a[index] - key > key - a[index - 1])) {
				--index;
			}
		}
		return index;
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[] x = new int[n];
		for (int i = 0; i < n; ++i) {
			x[i] = in.nextInt();
		}
		int m = in.nextInt();
		int s = in.nextInt();
		int mask = m - 1;
		int[][] l = new int[m][s];
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < s; ++j) {
				l[i][j] = in.nextInt();
			}
		}
		int[][] dp = new int[n][m];
		int[][] pd = new int[n][m];
		for (int[] ar : dp) {
			Arrays.fill(ar, Integer.MAX_VALUE);
		}
		for (int j = 0; j < m; ++j) {
			int index = binarySearch(l[j], x[n - 1]);
			dp[n - 1][j] = Math.abs(l[j][index] - x[n - 1]);
			pd[n - 1][j] = index;
		}
		for (int i = n - 2; i >= 0; --i) {
			for (int j = 0; j < m; ++j) {
				int p = binarySearch(l[j], x[i]);
				int f = Math.max(p - (m - 1), 0);
				int t = Math.min(p + (m - 1), s - 1);
				for (int k = f; k <= t; ++k) {
					if (dp[i][j] > dp[i + 1][k & mask] + Math.abs(l[j][k] - x[i])) {
						dp[i][j] = dp[i + 1][k & mask] + Math.abs(l[j][k] - x[i]);
						pd[i][j] = k;
					}
				}
			}
		}
		System.out.println(dp[0][0]);
		int q = 0;
		for (int i = 0; i < n; ++i) {
			if (i > 0) {
				System.out.print(' ');
			}
			System.out.print(pd[i][q]);
			q = pd[i][q] & mask;
		}
		System.out.println();
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//873774	04.08.09 20:22	watashi	205 	.JAVA	Accepted	840 ms	4318 kb
