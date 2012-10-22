// SGU190. Dominoes
/*
190. Dominoes
time limit per test: 0.50 sec.
memory limit per test: 4096 KB
input: standard input
output: standard output



There is a NxN squared chessboard (1<=N<=40). P squares were removed from the chessboard (0<=P<N*N). It is necessary to find out whether it is possible to cover the remaining part of the chessboard with dominoes dice (each die is 2x1 squares sized). Each die should lie on two neighboring squares exactly. No two dice can cover one and the same square. Your task is to find the covering, if it exists.

Input
The first line contains two integer numbers N and P separated by a space. Each of the following P lines contains a pair of numbers separated by a space - coordinates of the removed square (1<=Xi, Yi<=N). The bottom left square has the coordinates (1, 1), the bottom right square - (N, 1).

Output
If the covering exists, output "Yes" to the first line and "No" in the opposite case. If the first answer was positive, then output to the second line integer number Nh - the number of horizontally placed dice. Each of the following Nh lines should contain two integers - the coordinates of the left square covered by a corresponding die. Output to the next line Nv - the number of vertically placed dice. And the following Nv lines should contain the coordinates of the bottom square covered by a corresponding die.

Sample test(s)

Input

4 10
1 3
1 2
1 1
2 1
3 1
4 1
3 2
4 2
3 3
4 3

Output

Yes
2
1 4
3 4
1
2 2
[submit]
[forum]
Author:	Michael R. Mirzayanov
Resource:	ACM International Collegiate Programming Contest 2003-2004
North-Eastern European Region, Southern Subregion
Date:	2003 October, 9
*/
import java.util.*;

public class Solution {
	// [algo] hungary BipartiteMaximumMatching
	// [module] hungary
	public static int hungary(int nu, int nv, ArrayList<ArrayList<Integer> > e, int[] mu, int[] mv) {
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
				for (int v : e.get(u)) {
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

	static final int[] dx = new int[]{1, 0, -1, 0};
	static final int[] dy = new int[]{0, 1, 0, -1};

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int p = in.nextInt();
		boolean[][] board = new boolean[n][n];
		for (int i = 0; i < p; ++i) {
			int x = in.nextInt() - 1;
			int y = in.nextInt() - 1;
			board[x][y] = true;
		}
		ArrayList<ArrayList<Integer> > e = new ArrayList<ArrayList<Integer> >(n * n);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				e.add(new ArrayList<Integer>());
				if (board[i][j] || (i + j) % 2 != 0) {
					continue;
				}
				for (int k = 0; k < 4; ++k) {
					try {
						if (!board[i + dx[k]][j + dy[k]]) {
							e.get(i * n + j).add((i + dx[k]) * n + (j + dy[k]));
						}
					} catch (ArrayIndexOutOfBoundsException dump) {
					}
				}
			}
		}
		int[] mu = new int[n * n], mv = new int[n * n];
		if (2 * hungary(n * n, n * n, e, mu, mv) != n * n - p) {
			System.out.println("No");
		} else {
			ArrayList<String> ans1 = new ArrayList<String>(), ans2 = new ArrayList<String>();
			for (int i = 0; i < mu.length; ++i) {
				if (mu[i] == -1) {
					continue;
				}
				int x1 = i / n, y1 = i % n, x2 = mu[i] / n, y2 = mu[i] % n;
				if (x1 == x2) {
					ans2.add((x1 + 1) + " " + (Math.min(y1, y2) + 1));
				} else if (y1 == y2) {
					ans1.add((Math.min(x1, x2) + 1) + " " + (y1 + 1));
				}
			}
			System.out.println("Yes");
			System.out.println(ans1.size());
			for (String ans : ans1) {
				System.out.println(ans);
			}
			System.out.println(ans2.size());
			for (String ans : ans2) {
				System.out.println(ans);
			}
		}
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//874029	05.08.09 13:34	watashi	190 	.JAVA	Accepted	91 ms	3518 kb
