// SGU218. Unstable Systems
/*
218. Unstable Systems
time limit per test: 8 sec.
memory limit per test: 65536 KB
input: standard
output: standard



Of course you know that some operating systems are not stable. Sasha learnt it only few days ago. Now there are very bad days of his life. He is an adminstrator of the network of n computers with different versions of such systems. Each computer is a workstation which is usually used to run a single program. But the programs often crash with a message "The system is busy or unstable" Sasha has determined some unsafety value corresponding to the frequency of program crash for each program on each workstation (the larger values correspond to more often crashes). Now he plans to arrange programs in such a way that the maximal unsafety value of all workstations will become minimal possible (because crashes slow down all the work!). Help him!

Input

The first line of the input file contains the number of workstations n (1 ≤ n ≤ 500) which is equal to number of programs. The next n lines contain n numbers each — j-th number of i-th line contains the unsafety value for a program j on i-th computer. All numbers do not exceed 106 by their absolute values.

Output

Write the maximal unsafety value on the first line. Then output n lines each corresponding to one program in format "i j" — i-th computer must run j-th program.

Sample test(s)

Input

2
1 3
4 5

Output

4
1 2
2 1
[submit]
[forum]
Author:	Andrew Stankevich, Andrew Lopatin
Resource:	Petrozavodsk Summer Trainings 2003
Date:	2003-08-31 
*/
import java.io.*;
import java.util.*;

public class Solution {
	// [algo] hungary BipartiteMaximumMatching
	// [module] hungary
	public static int hungary(int nu, int nv, boolean[][] e, int[] mu, int[] mv) {
		Arrays.fill(mu, -1);
		Arrays.fill(mv, -1);
		int[] q = new int[nu];
		int[] p = new int[nv];
		int ret = 0;
		for (int i = 0; i < nu; ++i) {
			Arrays.fill(p, -1);
			q[0] = i;
BFS:
			for (int begin = 0, end = 1; begin < end; ++begin) {
				int u = q[begin];
				for (int v = 0; v < nv; ++v) {
					if (!e[u][v]) {
						continue;
					}
					if (p[v] == -1) {
						p[v] = u;
						if (mv[v] == -1) {
							int t = v;
							while (t != -1) {
								u = p[t];
								v = t;
								t = mu[u];
								mu[u] = v;
								mv[v] = u;
							}
							++ret;
							break BFS;
						} else {
							q[end++] = mv[v];
						}
					}
				}
			}
		}
		return ret;
	}

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

	static int floor(int a, int b) {
		if (b < 0) {
			return floor(-a, -b);
		} else if (a < 0) {
			return -ceil(-a, b);
		} else {
			return a / b;
		}
	}

	static int ceil(int a, int b) {
		if (b < 0) {
			return ceil(-a, -b);
		} else if (a < 0) {
			return -floor(-a, b);
		} else {
			return (a + b - 1) / b;
		}
	}

	public static void main(String[] args) throws IOException {
		int n = nextInt();
		int[][] w = new int[n][n];
		boolean[][] b = new boolean[n][n];
		int l = Integer.MAX_VALUE, r = Integer.MIN_VALUE;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				w[i][j] = nextInt();
				l = Math.min(l, w[i][j]);
				r = Math.max(r, w[i][j]);
			}
		}
		int[] mu = new int[n], mv = new int[n];
		while (l < r) {
			int m = floor(l + r, 2);
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					b[i][j] = (w[i][j] <= m);
				}
			}
			if (hungary(n, n, b, mu, mv) == n) {
				r = m;
			} else {
				l = m + 1;
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				b[i][j] = (w[i][j] <= r);
			}
		}
		hungary(n, n, b, mu, mv);
		System.out.println(r);
		for (int i = 0; i < n; ++i) {
			System.out.println((i + 1) + " " + (mu[i] + 1));
		}
	}
}

// negative number => WA6
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//875280	11.08.09 19:12	watashi	218 	.JAVA	Accepted	295 ms	2286 kb

