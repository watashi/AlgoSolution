// SGU210. Beloved Sons
/*
210. Beloved Sons
time limit per test: 2 sec.
memory limit per test: 65536 KB
input: standard
output: standard



Once upon a time there lived a king and he had N sons. And the king wanted to marry his beloved sons on the girls that they did love. So one day the king asked his sons to come to his room and tell him whom do they love.

But the sons of the king were all young men so they could not tell exactly whom they did love. Instead of that they just told him the names of the girls that seemed beautiful to them, but since they were all different, their choices of beautiful girls also did not match exactly.

The king was wise. He did write down the information that the children have provided him with and called you, his main wizard.

"I want all my kids to be happy, you know," he told you, "but since it might be impossible, I want at least some of them to marry the girl they like. So please, prepare the marriage list."

Suddenly you recalled that not so long ago the king told you about each of his sons, so you knew how much he loves him. So you decided to please the king and make such a marriage list that the king would be most happy. You know that the happiness of the king will be proportional to the square root of the sum of the squares of his love to the sons that would marry the girls they like.

So, go on, make a list to maximize the king's happiness.

Input

The first line of the input file contains N — the number of king's sons (1 ≤ N ≤ 400). The second line contains N integer numbers Ai ranging from 1 to 1000 — the measures of king's love to each of his sons.

Next N lines contain lists of king's sons' preferences — first Ki — the number of the girls the i-th son of the king likes, and then Ki integer numbers — the girls he likes (all potentially beautiful girls in the kingdom were numbered from 1 to N, you know, beautiful girls were rare in those days).

Output

Output N numbers — for each son output the number of the beautiful girl he must marry or 0 if he must not marry the girl he likes.

Denote the set of sons that marry a girl they like by L, then you must maximize the value of

sqrt( sum(i from L, Ai2) )


Sample test(s)

Input

4
1 3 2 4
4 1 2 3 4
2 1 4
2 1 4
2 1 4

Output

2 1 0 4
[submit]
[forum]
Author:	Andrew Stankevich
Resource:	Petrozavodsk Summer Trainings 2003
Date:	2003-08-30
*/
import java.util.*;

public class Solution {
	// [algo] hungary BipartiteMaximumMatching
	// [module] hungary
	public static int hungary(int nu, int nv, int[][] e, int[] mu, int[] mv) {
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
				for (int v : e[u]) {
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

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; ++i) {
			a[i] = in.nextInt();
			a[i] = (a[i] << 10) ^ i;
		}
		int[] o = new int[n];
		Arrays.sort(a);
		for (int i = 0; i < n; ++i) {
			o[a[n - 1 - i] & 1023] = i;
		}
		int[][] e = new int[n][];
		for (int i : o) {
			int k = in.nextInt();
			e[i] = new int[k];
			for (int j = 0; j < k; ++j) {
				e[i][j] = in.nextInt() - 1;
			}
		}
		int[] mu = new int[n];
		hungary(n, n, e, mu, new int[n]);
		for (int i = 0; i < n; ++i) {
			System.out.print(mu[o[i]] + 1);
			System.out.print(i == n - 1 ? '\n' : ' ');
		}
	}
}

// IndexComparator < => WA16
// IndexComparator > => WA18
// IndexComparator bug? spj bug?

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//874055	05.08.09 14:51	watashi	210 	.JAVA	Accepted	755 ms	4098 kb
