// SGU185. Two shortest 

import java.io.*;
import java.util.*;

class ShorestPath {
	static final int INF = Integer.MAX_VALUE >> 2;
	int n;
	int[][] d;

	ShorestPath(int n) {
		this.n = n;
		d = new int[n][n];
		for (int[] di : d) {
			Arrays.fill(di, INF);
		}
	}

	void addEdge(int x, int y, int z) {
		d[x][y] = d[y][x] = Math.min(d[x][y], z);
	}

	int[] dijkstra(int s) {
		boolean[] mark = new boolean[n];
		int[] ret = new int[n];
		Arrays.fill(ret, INF);
		ret[s] = 0;
		for (int i = 0; i < n; ++i) {
			s = -1;
			for (int j = 0; j < n; ++j) {
				if (!mark[j] && (s == -1 || ret[j] < ret[s])) {
					s = j;
				}
			}
			mark[s] = true;
			for (int j = 0; j < n; ++j) {
				if (!mark[j] && ret[j] > ret[s] + d[s][j]) {
					ret[j] = ret[s] + d[s][j];
				}
			}
		}
		return ret;
	}
}

class FlowNetwork {
	int n, source, sink;
	int[][] c;
	int[][] f;
	
	FlowNetwork(int n, int source, int sink) {
		this.n = n;
		this.source = source;
		this.sink = sink;
		c = new int[n][n];
		f = new int[n][n];
	}

	void addEdge(int x, int y, int z) {
		c[x][y] += z;
	}

	boolean[] mark;

	boolean augment(int v) {
		if (v == sink) {
			return true;
		} else {
			mark[v] = true;
			for (int i = 0; i < n; ++i) {
				if (!mark[i] && (c[v][i] - f[v][i] > 0 || f[i][v] > 0) && augment(i)) {
					if (f[i][v] > 0) {
						--f[i][v];
					} else {
						++f[v][i];
					}
					return true;
				}
			}
			return false;
		}
	}

	int maxFlow() {
		int ret = -1;
		do {
			++ret;
			mark = new boolean[n];
		} while (augment(source));
		return ret;
	}
}

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

	static void gao(FlowNetwork fn, int v) {
		if (v == fn.sink) {
			System.out.println(v + 1);
		} else {
			System.out.print((v + 1) + " ");
			for (int i = 0; i < fn.n; ++i) {
				if (fn.f[v][i] > 0) {
					--fn.f[v][i];
					gao(fn, i);
					break;
				}
			}
		}
	}

	public static void main(String[] args) throws IOException {
		int n = nextInt();
		int m = nextInt();
		ShorestPath sp = new ShorestPath(n);
		for (int i = 0; i < m; ++i) {
			int x = nextInt() - 1;
			int y = nextInt() - 1;
			int z = nextInt();
			sp.addEdge(x, y, z);
		}
		int[] ds = sp.dijkstra(0);
		int[] dt = sp.dijkstra(n - 1);
		
		FlowNetwork fn = new FlowNetwork(n, 0, n - 1);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (ds[i] + sp.d[i][j] + dt[j] == dt[0]) {
					fn.addEdge(i, j, 1);
				}
			}
		}
		if (fn.maxFlow() < 2) {
			System.out.println("No solution");
		} else {
			for (int i = 0; i < 2; ++i) {
				gao(fn, fn.source);
			}
		}
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status:  	Time:  	Memory:
//1078742	19.09.10 20:31	watashi	185 	.JAVA	Accepted 	333 ms	0 kb

