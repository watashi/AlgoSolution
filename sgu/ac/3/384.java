// SGU384. Country
/*
384. Country
Time limit per test: 5 second(s)
Memory limit: 262144 kilobytes
input: standard
output: standard


Once upon a time in a faraway kingdom there was a very wise King. This King wanted to improve the road system of the country. For the purposes of this problem the road system can be considered as an undirected graph without loops and parallel edges (the vertices of this graph correspond to the cities and the edges correspond to the roads). The King was fond of mathematics, so he reformed the road system of the kingdom in the following mathematical way: for each two distinct cities there was exactly one common neighbour (any city is not neighbour of itself). The road reform was successful, but with the lapse of time some roads were destroyed. The government of the kingdom wants to know the distances between cities at any moment of time. Your task is to help the government with this problem.

Input
The first line of the input contains two integer numbers and  — the number of cities and the number of roads immediately after the reform (). The next lines describe the roads of the kingdom. Each of these lines contains two integer numbers and  — -based indices of cities connected by this road. The following lines describe queries of the government and information about road destruction. If the line describes a destruction of the road, it will be formatted as "DELETE ", where is -based index of the road. Otherwise it will be formated as "LENGTH ", where and are -based indices of cities. The queries will appear in the input till the end of the file. The total number of queries doesn't exceed .

Output
For each " " query output the answer on the separate line, or if there's no way to travel from one city to another.

Example(s)

sample input

	

sample output

3 3
1 2
2 3
3 1
LENGTH 1 2
DELETE 1
LENGTH 1 2
LENGTH 2 3
DELETE 3
LENGTH 1 2

	

1
2
1
-1

*/
import java.io.*;

public class Solution {
	public static void main(String[] args) throws IOException {
		StreamTokenizer in = new StreamTokenizer(
				new BufferedReader(new InputStreamReader(System.in)));
		in.nextToken();
		int n = (int)in.nval;
		in.nextToken();
		int m = (int)in.nval;
		int[] x = new int[m];
		int[] y = new int[m];
		int[] z = new int[n];
		for (int i = 0; i < m; ++i) {
			in.nextToken();
			x[i] = (int)in.nval - 1;
			in.nextToken();
			y[i] = (int)in.nval - 1;
			++z[x[i]];
			++z[y[i]];
		}
		int root = 0;
		for (int i = 1; i < n; ++i) {
			if (z[i] > z[root]) {
				root = i;
			}
		}
		z[root] = -1;
		for (int i = 0; i < m; ++i) {
			if (x[i] != root && y[i] != root) {
				z[x[i]] = y[i];
				z[y[i]] = x[i];
			}
		}
		boolean[] b = new boolean[n];
		
		while (in.nextToken() != StreamTokenizer.TT_EOF) {
			if (in.sval.charAt(0) == 'D') {
				in.nextToken();
				int id = (int)in.nval - 1;
				if (x[id] == root) {
					b[y[id]] = true;
				} else if (y[id] == root) {
					b[x[id]] = true;
				} else {
					z[x[id]] = z[y[id]] = -1;
				}
			} else {
				in.nextToken();
				int s = (int)in.nval - 1;
				in.nextToken();
				int t = (int)in.nval - 1;
				if (s == t) {
					System.out.println(0);
				} else if (s == root || t == root) {
					t = s + t - root;
					if (!b[t]) {
						System.out.println(1);
					} else if (z[t] != -1 && !b[z[t]]) {
						System.out.println(2);
					} else {
						System.out.println(-1);
					}
				} else if (z[s] == t && z[t] == s) {
					System.out.println(1);
				} else {
					int d = 0;
					if (!b[s]) {
						++d;
					} else if (z[s] != -1 && !b[z[s]]) {
						d += 2;
					} else {
						d -= 10;
					}
					if (!b[t]) {
						++d;
					} else if (z[t] != -1 && !b[z[t]]) {
						d += 2;
					} else {
						d -= 10;
					}
					System.out.println(d < 0 ? -1 : d);
				}
			}
		}
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//887356	15.09.09 17:41	watashi	384 	.JAVA	Accepted	1081 ms	0 kb


