// SGU168. Matrix
/*
168. Matrix
time limit per test: 2.25 sec.
memory limit per test: 16000 KB
input: standard
output: standard



You are given N*M matrix A. You are to find such matrix B, that B[i,j]=min{ A[x,y] : (y>=j) and (x>=i+j-y) }

Input
On the first line of the input there are two integer numbers, N and M (1<=N,M<=1000). Then matrix A follows: next N lines contains M integers each (not greater than 32000 by absolute value). The j-th number on then i-th of this lines is A[i,j].

Output
Write matrix B in the same format as matrix A, but without N and M.

Sample test(s)

Input

3 3
1 2 3
4 5 6
7 8 9

Output

1 2 3
2 3 6
3 6 9

Author:	NNSU #2 team
Resource:	
Date:	
*/
import java.io.*;

public class Solution {
	static int nextInt() throws IOException {
		int ch = -1;
		do {
			ch = System.in.read();
		} while (Character.isWhitespace(ch));
		boolean negative = (ch == '-');
		if (negative) {
			ch = System.in.read();
		}
		int ret = 0;
		while (Character.isDigit(ch)) {
			ret *= 10;
			ret += Character.digit(ch, 10);
			ch = System.in.read();
		}
		return negative ? -ret : ret;
	}

	public static void main(String[] args) throws IOException {
		int n = nextInt();
		int m = nextInt();
		int[][] a = new int[n][m];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				a[i][j] = nextInt();
			}
		}
		for (int j = m - 1; j >= 0; --j) {
			for (int i = n - 1; i >= 0; --i) {
				if (i != n - 1) {
					a[i][j] = Math.min(a[i][j], a[i + 1][j]);
				}
				if (j != m - 1) {
					if (i != 0) {
						a[i][j] = Math.min(a[i][j], a[i - 1][j + 1]);
					} else {
						a[i][j] = Math.min(a[i][j], a[i][j + 1]);
					}
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			StringBuilder buf = new StringBuilder();
			for (int j = 0; j < m; ++j) {
				buf.append(a[i][j]);
				buf.append(((j == m - 1) ? '\n' : ' '));
			}
			System.out.print(buf);
		}
	}
}

// n=1 m>1 ... => WA3
// System.out.print => TLE8

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//873403	03.08.09 10:20	watashi	168 	.JAVA	Accepted	1226 ms	5774 kb

