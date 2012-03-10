// SGU206. Roads
/*
206. Roads
time limit per test: 2 sec.
memory limit per test: 65536 KB
input: standard
output: standard



The kingdom of Farland has N cities connected by M roads. Some roads are paved with stones, others are just country roads. Since paving the road is quite expensive, the roads to be paved were chosen in such a way that for any two cities there is exactly one way to get from one city to another passing only the stoned roads.

The kingdom has a very strong bureaucracy so each road has its own ordinal number ranging from 1 to M: the stoned roads have numbers from 1 to N-1 and other roads have numbers from N to M. Each road requires some money for support, i-th road requires ci coins per year to keep it intact. Recently the king has decided to save some money and keep financing only some roads. Since he wants his people to be able to get from any city to any other, he decided to keep supporting some roads in such a way, that there is still a path between any two cities.

It might seem to you that keeping the stoned roads would be the good idea, however the king did not think so. Since he did not like to travel, he did not know the difference between traveling by a stoned road and travelling by a muddy road. Thus he ordered you to bring him the costs of maintaining the roads so that he could order his wizard to choose the roads to keep in such a way that the total cost of maintaining them would be minimal.

Being the minister of communications of Farland, you want to help your people to keep the stoned roads. To do this you want to fake the costs of maintaining the roads in your report to the king. That is, you want to provide for each road the fake cost of its maintaining di in such a way, that stoned roads form the set of roads the king would keep. However, to lower the chance of being caught, you want the value of sum(i = 1..M, |ci-di|) to be as small as possible.

You know that the king's wizard is not a complete fool, so if there is the way to choose the minimal set of roads to be the set of the stoned roads, he would do it, so ties are allowed.

Input
The first line of the input file contains N and M (2 ≤ N ≤ 60, N-1 ≤ M ≤ 400). Next M lines contain three integer numbers ai, bi and ci each — the numbers of the cities the road connects (1 ≤ ai ≤ N, 1 ≤ bi ≤ N, ai ≠ bi) and the cost of maintaining it (1 ≤ ci ≤ 10 000).

Output
Output M lines — for each road output di that should be reported to be its maintainance cost so that he king would choose first N-1 roads to be the roads to keep and the specified sum is minimal possible.

Sample test(s)

Input

4 5
4 1 7
2 1 5
3 4 4
4 2 5
1 3 1

Output

4
5
4
5
4
[submit]
[forum]
Author:	Andrew Stankevich
Resource:	Petrozavodsk Summer Trainings 2003
Date:	2003-08-23 
*/
import java.util.*;

class Matching {
	// nu <= nv
	public static int kuhnMunkres(int nu, int nv, int[][] w, int[] u, int[] v, int[] mu, int[] mv) {
		for (int i = 0; i < nu; ++i) {
			u[i] = Integer.MIN_VALUE;
			for (int uu : w[i]) {
				u[i] = Math.max(u[i], uu);
			}
		}
		for (int j = 0; j < nv; ++j) {
			v[j] = 0;
		}
		mu = new int[nu];	// null
		Arrays.fill(mu, -1);
		mv = new int[nv];	// null
		Arrays.fill(mv, -1);

		int[] q = new int[nu];
		int[] p = new int[nv];

		for (int i = 0; i < nu; ++i) {
			Arrays.fill(p, -1);
			q[0] = i;
			int t = 1;
BFS:
			for (int s = 0; s < t; ++s) {
				int k = q[s];
				for (int j = 0; j < nv; ++j) {
					if (p[j] == -1 && u[k] + v[j] == w[k][j]) {
						if (mv[j] == -1) {
							int x = k, y = j, z;
							while(true) {
								z = mu[x];
								mu[x] = y;
								mv[y] = x;
								if (z == -1) {
									break;
								} else {
									x = p[z];
									y = z;
								}
							}
							break BFS;
						} else {
							q[t++] = mv[j];
							p[j] = k;
						}
					}
				}
			}
			if (mu[i] != -1) {
				continue;
			} else {
				--i; // !
			}
			int e = Integer.MAX_VALUE;
			for (int j = 0; j < nv; ++j) {
				if (p[j] != -1) {	// Y - T
					continue;
				}
				for (int s = 0; s < t; ++s) {	// S
					e = Math.min(e, u[q[s]] + v[j] - w[q[s]][j]);
				}
			}
			for (int j = 0; j < nv; ++j) {
				if (p[j] != -1) {
					v[j] += e;
				}
			}
			for (int s = 0; s < t; ++s) {
				u[q[s]] -= e;
			}
		}
		int ret = 0;
		for (int i : u) {
			ret += i;
		}
		for (int i : v) {
			ret += i;
		}
		return ret;
	}
}

public class Solution {
	static final int INF = Integer.MAX_VALUE / 2;
	static int t, d;
	static int[] c, q;
	static int[][] ab, w;
	static boolean[] mark;
	static ArrayList<ArrayList<Integer> > e;

	static void dfs(int p) {
		mark[p] = true;
		q[t++] = p;
		if (t >= 3 && ab[q[0]][q[t - 1]] != -1) {
			int y = ab[q[0]][q[t - 1]];
			for (int i = 1; i < t; ++i) {
				int x = ab[q[i - 1]][q[i]];
				w[x][y] = Math.max(w[x][y], c[x] - c[y + d]);
			}
		}
		for (int v : e.get(p)) {
			if (!mark[v]) {
				dfs(v);
			}
		}
		--t;
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
		d = n - 1;
		e = new ArrayList<ArrayList<Integer> >(n);
		for (int i = 0; i < n; ++i) {
			e.add(new ArrayList<Integer>());
		}
		ab = new int[n][n];
		for (int[] ar : ab) {
			Arrays.fill(ar, -1);
		}
		c = new int[m];
		for (int i = 0; i < m; ++i) {
			int a = in.nextInt() - 1;
			int b = in.nextInt() - 1;
			ab[a][b] = ab[b][a] = (i < d) ? i : (i - d);
			c[i] = in.nextInt();
			if (i < d) {
				e.get(a).add(b);
				e.get(b).add(a);
			}
		}

		q = new int[n];
		w = new int[n - 1][m - d];
		for (int[] ar : w) {
			Arrays.fill(ar, 0);
		}
		mark = new boolean[n];
		for (int i = 0; i < n; ++i) {
			Arrays.fill(mark, false);
			t = 0;
			dfs(i);
		}

		if (m - d < d) {
			int[][] ww = w;
			w = new int[m - d][d];
			for (int i = 0; i < w.length; ++i) {
				for (int j = 0; j < w[i].length; ++j) {
					w[i][j] = ww[j][i];
				}
			}
		}
		int[] u = new int[w.length];
		int[] v = new int[m - w.length]; // w[0].length -> RE
		Matching.kuhnMunkres(u.length, v.length, w, u, v, new int[u.length], new int[v.length]);
		if (m - d < d) {
			int[] swap;
			swap = u;
			u = v;
			v = swap;
		}
		for (int i = 0; i < u.length; ++i) {
			System.out.println(c[i] - u[i]);
		}
		for (int i = 0; i < v.length; ++i) {
			System.out.println(c[i + d] + v[i]);
		}
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//887918	16.09.09 22:55	watashi	206 	.JAVA	Accepted	119 ms	0 kb

