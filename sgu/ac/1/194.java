// SGU194. Reactor Cooling
/*
194. Reactor Cooling
time limit per test: ? sec.
memory limit per test: ? KB
input: standard
output: standard



The terrorist group leaded by a well known international terrorist Ben Bladen is buliding a nuclear reactor to produce plutonium for the nuclear bomb they are planning to create. Being the wicked computer genius of this group, you are responsible for developing the cooling system for the reactor.

The cooling system of the reactor consists of the number of pipes that special cooling liquid flows by. Pipes are connected at special points, called nodes, each pipe has the starting node and the end point. The liquid must flow by the pipe from its start point to its end point and not in the opposite direction.

Let the nodes be numbered from 1 to N. The cooling system must be designed so that the liquid is circulating by the pipes and the amount of the liquid coming to each node (in the unit of time) is equal to the amount of liquid leaving the node. That is, if we designate the amount of liquid going by the pipe from i-th node to j-th as fij, (put fij = 0 if there is no pipe from node i to node j), for each i the following condition must hold:


sum(j=1..N, fij) = sum(j=1..N, fji)


Each pipe has some finite capacity, therefore for each i and j connected by the pipe must be fij ≤ cij where cij is the capacity of the pipe. To provide sufficient cooling, the amount of the liquid flowing by the pipe going from i-th to j-th nodes must be at least lij, thus it must be fij ≥ lij.

Given cij and lij for all pipes, find the amount fij, satisfying the conditions specified above.

Input

The first line of the input file contains the number N (1 ≤ N ≤ 200) - the number of nodes and and M — the number of pipes. The following M lines contain four integer number each - i, j, lij and cij each. There is at most one pipe connecting any two nodes and 0 ≤ lij ≤ cij ≤ 105 for all pipes. No pipe connects a node to itself. If there is a pipe from i-th node to j-th, there is no pipe from j-th node to i-th.

Output

On the first line of the output file print YES if there is the way to carry out reactor cooling and NO if there is none. In the first case M integers must follow, k-th number being the amount of liquid flowing by the k-th pipe. Pipes are numbered as they are given in the input file.

Sample test(s)

Input

Test #1

4 6
1 2 1 2
2 3 1 2
3 4 1 2
4 1 1 2
1 3 1 2
4 2 1 2

Test #2

4 6
1 2 1 3
2 3 1 3
3 4 1 3
4 1 1 3
1 3 1 3
4 2 1 3

Output

Test #1

NO

Test #2

YES
1
2
3
2
1
1

[submit]
[forum]
Author:	Andrew Stankevich
Resource:	Petrozavodsk Winter Trainings 2003
Date:	2003-02-06
*/
import java.util.*;

// [algo] feasible flow
// [module] limit flow
// [module] sap gap

class NoSuchFlowException extends Throwable {
}

class Edge {
	int v, c;
	Edge(int v, int c) {
		this.v = v;
		this.c = c;
	}
}

class FeasibleFlow {
	int n, m, source, sink;
	int[] diff;
	Edge[] edge;
	ArrayList<ArrayList<Integer> > e;

	public FeasibleFlow(int an, int am) {
		n = an + 2;
		m = 0;
		source = an;
		sink = an + 1;
		diff = new int[an];
		edge = new Edge[2 * (an + am)];
		e = new ArrayList<ArrayList<Integer> >(n);
		for (int i = 0; i < n; ++i) {
			e.add(new ArrayList<Integer>());
		}
	}

	void _addEdge(int a, int b, int c) {
		edge[m] = new Edge(b, c);
		e.get(a).add(m);
		++m;
		edge[m] = new Edge(a, 0);
		e.get(b).add(m);
		++m;
	}

	public void addEdge(int a, int b, int l, int u) {
		diff[a] += l;
		diff[b] -= l;
		_addEdge(a, b, u - l);
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

	public void gao() throws NoSuchFlowException {
		int flow = 0;
		for (int i = 0; i < diff.length; ++i) {
			if (diff[i] >= 0) {
				_addEdge(i, sink, diff[i]);
				flow += diff[i];
			} else {
				_addEdge(source, i, -diff[i]);
			}
		}
		if (sap() != flow) {
			throw new NoSuchFlowException();
		}
	}
}

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
		FeasibleFlow ff = new FeasibleFlow(n, m);
		int[] ans = new int[m];
		for (int i = 0; i < m; ++i) {
			int a = in.nextInt() - 1;
			int b = in.nextInt() - 1;
			int l = in.nextInt();
			int u = in.nextInt();
			ff.addEdge(a, b, l, u);
			ans[i] = l;
		}
		try {
			ff.gao();
			System.out.println("YES");
			for (int i = 0; i < ans.length; ++i) {
				ans[i] += ff.edge[(i << 1) ^ 1].c;
				System.out.println(ans[i]);
			}
		} catch (NoSuchFlowException e) {
			System.out.println("NO");
		}
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//873694	04.08.09 16:02	watashi	194 	.JAVA	Accepted	513 ms	5174 kb

