// SGU226. Colored graph
/*
226. Colored graph
time limit per test: 0.50 sec.
memory limit per test: 4096 KB
input: standard
output: standard



You are given an oriented graph. Each edge of the graph is colored in one of the three colors. Your task is to find the length of the shortest path from the first vertex to the N-th. Note that any two successive edges in the path can't have the same color.

Input
The first line of the input file consists of two integers N and M (2 <= N <= 200; 0 <= M <= N*N). Next M lines contain descriptions of the edges. Each edge description is a list of three integers X, Y, C (1 <= X, Y <= N, 1 <= C <= 3), where X is the starting vertex of the edge, Y is the finishing vertex and C is the color of the edge.

Output
Output the length of the shortest path between the first and the N-th vertexes. Output "-1" if the path doesn't exist.

Sample test(s)

Input


Test #1
4 4
1 2 1
2 3 2
3 4 3
2 4 1

Test #2
3 2
1 2 1
2 3 1

Output


Test #1
3

Test #2
-1
[submit]
[forum]
Author:	---
Resource:	---
Date:	---
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

	public static void main(String[] args) throws IOException {
		int n = nextInt();
		int m = nextInt();
		int s = 3 * n;
		ArrayList<ArrayList<Integer> > e = new ArrayList<ArrayList<Integer> >(s + 2);
		for (int i = 0; i < s + 2; ++i) {
			e.add(new ArrayList<Integer>());
		}
		for (int i = 0; i < 3; ++i) {
			e.get(s).add(i);
			e.get((n - 1) * 3 + i).add(s + 1);
		}
		for (int i = 0; i < m; ++i) {
			int a = nextInt() - 1;
			int b = nextInt() - 1;
			int c = nextInt() - 1;
			a = a * 3 + c;
			for (int j = 0; j < 3; ++j) {
				if (j != c) {
					e.get(a).add(b * 3 + j);
				}
			}
		}
		int[] d = new int[s + 2];
		Arrays.fill(d, -1);
		d[s] = 0;
		int[] q = new int[s + 2];
		q[0] = s;
		for (int begin = 0, end = 1; begin < end; ++begin) {
			for (int v : e.get(q[begin])) {
				if (d[v] == -1) {
					d[v] = d[q[begin]] + 1;
					q[end++] = v;
				}
			}
		}
		System.out.println(d[s + 1] == -1 ? -1 : d[s + 1] - 2);
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//874625	08.08.09 20:39	watashi	226 	.JAVA	Accepted	47 ms	1710 kb

