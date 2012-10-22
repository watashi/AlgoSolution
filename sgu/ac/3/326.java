// SGU326. Perspective
import java.util.*;

class Edge {
	int v, c;
	Edge(int v, int c) {
		this.v = v;
		this.c = c;
	}
}

class FlowNetwork {
	int n, m, source, sink;
	Edge[] edge;
	ArrayList<ArrayList<Integer> > e;

	public FlowNetwork(int an, int asource, int asink, int am) {
		n = an;
		m = 0;
		source = asource;
		sink = asink;
		edge = new Edge[am];
		e = new ArrayList<ArrayList<Integer> >(n);
		for (int i = 0; i < n; ++i) {
			e.add(new ArrayList<Integer>());
		}
	}

	void addEdge(int a, int b, int c) {
		edge[m] = new Edge(b, c);
		e.get(a).add(m);
		++m;
		edge[m] = new Edge(a, 0);
		e.get(b).add(m);
		++m;
	}

	int sap() {
		int ret = 0;
		int[] c = new int[n + 1];
		int[] d = new int[n];
		int[] done = new int[n];
		int[] path = new int[n];
		int len = 0;
		c[0] = n;
		path[0] = source;
		while (d[source] != n) {
			int back = path[len];
			if (back == sink) {
				int todo = -1;
				int flow = Integer.MAX_VALUE;
				for (int i = 0; i < len; ++i) {
					Edge arc = edge[e.get(path[i]).get(done[path[i]])];
					if (arc.c < flow) {
						flow = arc.c;
						todo = i;
					}
				}
				for (int i = 0; i < len; ++i) {
					int id = e.get(path[i]).get(done[path[i]]);
					edge[id].c -= flow;
					edge[id ^ 1].c += flow;
				}
				len = todo;
				ret += flow;
			} else {
				while (done[back] < e.get(back).size()) {
					Edge arc = edge[e.get(back).get(done[back])];
					if (d[arc.v] == d[back] - 1 && arc.c > 0) {
						break;
					} else {
						++done[back];
					}
				}
				if (done[back] == e.get(back).size()) {
					if (c[d[back]] == 1) {
						break;	// gap
					} else {
						--c[d[back]];
						d[back] = n;
						for (int i = 0; i < e.get(back).size(); ++i) {
							Edge arc = edge[e.get(back).get(i)];
							if (d[back] > d[arc.v] + 1 && arc.c > 0) {
								d[back] = d[arc.v] + 1;
								done[back] = i;
							}
						}
						++c[d[back]];
						if (back != source) {
							--len;
						}
					}
				} else {
					path[++len] = edge[e.get(back).get(done[back])].v;
				}
			}
		}
		return ret;
	}
}

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[] w = new int[n];
		int[] r = new int[n];
		int[][] a = new int[n][n];
		for (int i = 0; i < n; ++i) {
			w[i] = in.nextInt();
		}
		for (int i = 0; i < n; ++i) {
			r[i] = in.nextInt();
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				a[i][j] = in.nextInt();
			}
		}
		w[0] += r[0];

		int s = 0;
		FlowNetwork fn = new FlowNetwork(n + 1, 0, n, n * (n + 2));
		for (int i = 1; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				w[i] += a[i][j];
				fn.addEdge(i, j, a[i][j]);
			}
			if (w[i] > w[0]) {
				s += w[i] - w[0];
				fn.addEdge(0, i, w[i] - w[0]);
			} else if (w[i] < w[0]) {
				fn.addEdge(i, n, w[0] - w[i]);
			}
		}
		System.out.println(fn.sap() == s ? "YES" : "NO");
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status:  	Time:  	Memory:
//1081922	28.09.10 12:26	watashi	326 	.JAVA	Accepted 	43 ms	0 kb

