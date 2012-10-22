// SGU180. Inversions
/*
180. Inversions
time limit per test: 0.50 sec.
memory limit per test: 4096 KB
input: standard
output: standard



There are N integers (1<=N<=65537) A1, A2,.. AN (0<=Ai<=10^9). You need to find amount of such pairs (i, j) that 1<=i<j<=N and A[i]>A[j].

Input
The first line of the input contains the number N. The second line contains N numbers A1...AN.

Output
Write amount of such pairs.

Sample test(s)

Input

5
2 3 1 5 4

Output

3
[submit]
[forum]
Author:	Stanislav Angelyuk
Resource:	Saratov ST team Spring Contest #1
Date:	18.05.2003
*/
import java.io.*;
import java.util.*;

public class Solution {
	static int nextInt() throws IOException {
		int ch = -1;
		do {
			ch = System.in.read();
		} while (!Character.isDigit(ch));
		int ret = 0;
		while (Character.isDigit(ch)) {
			ret *= 10;
			ret += Character.digit(ch, 10);
			ch = System.in.read();
		}
		return ret;
	}

	// [algo]merge sort
	// [algo]inversions
	// [algo]inversion number
	public static long inversion(int[] a) {
		if (a.length == 1) {
			return 0L;
		} else {
			int n = a.length / 2;
			int[] x = Arrays.copyOfRange(a, 0, n), y = Arrays.copyOfRange(a, n, a.length);
			long ret = inversion(x) + inversion(y);
			for (int i = 0, j = 0; i + j < a.length; ) {
				if (j == y.length || (i < x.length && x[i] <= y[j])) {
					a[i + j] = x[i];
					++i;
					ret += j;
				} else {
					a[i + j] = y[j];
					++j;
				}
			}
			return ret;
		}
	}

	public static void main(String[] args) throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; ++i) {
			a[i] = nextInt();
		}
		System.out.println(inversion(a));
	}
}

// ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
// 871684	23.07.09 19:19	watashi	180 	.JAVA	Accepted	139 ms	2426 kb


