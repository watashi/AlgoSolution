// SGU260. Puzzle 
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

	static boolean[] gauss(int n, boolean[][] _a, boolean[] _b) {
		boolean[][] a = new boolean[_a.length][];
		for (int i = 0; i < a.length; ++i) {
			a[i] = _a[i].clone();
		}
		boolean[] b = _b.clone();
		int[] p = new int[n];
		for (int i = 0; i < n; ++i) {
			p[i] = i;
		}

		for (int k = 0; k < n; ++k) {
			// find one
			int ii = -1, jj = -1;
			for (int i = k; i < n && ii == -1; ++i) {
				for (int j = k; j < n && jj == -1; ++j) {
					if (a[i][j]) {
						ii = i;
						jj = j;
					}
				}
			}
			if (ii == -1) {
				break;
			}
			boolean tmp;
			int swp;		
			// swap row
			for (int j = k; j < n; ++j) {
				tmp = a[k][j];
				a[k][j] = a[ii][j];
				a[ii][j] = tmp;
			}
			tmp = b[k];
			b[k] = b[ii];
			b[ii] = tmp;
			// swap column
			for (int i = 0; i < n; ++i) {
				tmp = a[i][k];
				a[i][k] = a[i][jj];
				a[i][jj] = tmp;
			}
			swp = p[k];
			p[k] = p[jj];
			p[jj] = swp;
			// elismate
			for (int i = 0; i < n; ++i) {
				if (i != k && a[i][k]) {
					for (int j = k; j < n; ++j) {
						a[i][j] ^= a[k][j];
					}
					b[i] ^= b[k];
				}
			}
		}

		for (int i = 0; i < n; ++i) {
			if (!a[i][i] && b[i]) {
				return null;
			}
		}

		boolean[] x = new boolean[n];
		for (int i = 0; i < n; ++i) {
			x[p[i]] = b[i];
		}
		return x;
	}

	static void print(boolean[] x) {
		ArrayList<Integer> ans = new ArrayList<Integer>();
		for (int i = 0; i < x.length; ++i) {
			if (x[i]) {
				ans.add(i + 1);
			}
		}
		System.out.println(ans.size());
		for (int i = 0; i < ans.size(); ++i) {
			if (i > 0) {
				System.out.print(' ');
			}
			System.out.print(ans.get(i));
		}
		System.out.println();
	}

	public static void main(String[] args) throws IOException {
		int n = nextInt();
		boolean[][] a = new boolean[n][n];
		boolean[] b = new boolean[n];
		for (int i = 0; i < n; ++i) {
			int m = nextInt();
			for (int j = 0; j < m; ++j) {
				a[nextInt() - 1][i] = true;	// WA1
			}
		}
		for (int i = 0; i < n; ++i) {
			b[i] = (nextInt() == 0);
		}

		boolean[] x;
		if ((x = gauss(n, a, b)) != null) {
			print(x);
			return;
		}

		for (int i = 0; i < n; ++i) {
			b[i] = !b[i];
		}
		if ((x = gauss(n, a, b)) != null) {
			print(x);
			return;
		}

		System.out.println(-1);
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status:  	Time:  	Memory:
//1079183	20.09.10 18:48	watashi	260 	.JAVA	Accepted 	115 ms	0 kb

