// SGU134. Centroid
/*
134. Centroid

time limit per test: 0.50 sec.
memory limit per test: 4096 KB

You are given an undirected connected graph, with N vertices and N-1 edges (a tree). You must find the centroid(s) of the tree.
In order to define the centroid, some integer value will be assosciated to every vertex. Let's consider the vertex k. If we remove the vertex k from the tree (along with its adjacent edges), the remaining graph will have only N-1 vertices and may be composed of more than one connected components. Each of these components is (obviously) a tree. The value associated to vertex k is the largest number of vertices contained by some connected component in the remaining graph, after the removal of vertex k. All the vertices for which the associated value is minimum are considered centroids.

Input

The first line of the input contains the integer number N (1<=N<=16 000). The next N-1 lines will contain two integers, a and b, separated by blanks, meaning that there exists an edge between vertex a and vertex b.

Output

You should print two lines. The first line should contain the minimum value associated to the centroid(s) and the number of centroids. The second line should contain the list of vertices which are centroids, sorted in ascending order.

Sample Input

7
1 2
2 3
2 4
1 5
5 6
6 7

Sample Output

3 1
1

Author	: Mugurel Ionut Andreica
Resource	: SSU::Online Contester Fall Contest #2
Date	: Fall 2002
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

	static ArrayList<ArrayList<Integer> > e;
	static int[] s;
	static ArrayList<Integer> c;
	static int ans;

	static void gao(int v) {
		int max = 0;
		s[v] = 1;
		for (int w : e.get(v)) {
			if (s[w] == 0) {
				gao(w);
				s[v] += s[w];
				max = Math.max(max, s[w]);
			}
		}
		max = Math.max(max, e.size() - s[v]);
		if (max < ans) {
			ans = max;
			c.clear();
			c.add(v);
		} else if (max == ans) {
			c.add(v);
		}
	}
	
	public static void main(String[] args) throws IOException {
		int n = nextInt();
		e = new ArrayList<ArrayList<Integer> >(n);
		s = new int[n];
		c = new ArrayList<Integer>();
		for (int i = 0; i < n; ++i) {
			e.add(new ArrayList<Integer>());
		}
		for (int i = 1; i < n; ++i) {
			int a = nextInt() - 1;
			int b = nextInt() - 1;
			e.get(a).add(b);
			e.get(b).add(a);
		}
		ans = Integer.MAX_VALUE;
		gao(0);
		Collections.sort(c);
		System.out.println(ans + " " + c.size());
		boolean blank = false;
		for (int ci : c) {
			if (blank) {
				System.out.print(' ');
			} else {
				blank = true;
			}
			System.out.print(ci + 1);
		}
		System.out.println();
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//873492	03.08.09 18:02	watashi	134 	.JAVA	Accepted	91 ms	3562 kb

