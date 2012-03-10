// SGU196. Matrix Multiplication
/*
196. Matrix Multiplication
time limit per test: 0.50 sec.
memory limit per test: 65536 KB
input: standard
output: standard



Let us consider an undirected graph G = <V, E> which has N vertices and M edges. Incidence matrix of this graph is an N × M matrix A = {aij}, such that aij is 1 if i-th vertex is one of the ends of j-th edge and 0 in the other case. Your task is to find the sum of all elements of the matrix ATA where AT is A transposed, i.e. an M × N matrix obtained from A by turning its columns to rows and vice versa.

Input

The first line of the input file contains two integer numbers — N and M (2 le N le 10,000, 1 le M le 100,000). 2M integer numbers follow, forming M pairs, each pair describes one edge of the graph. All edges are different and there are no loops (i.e. edge ends are distinct).

Output

Output the only number — the sum requested.

Sample test(s)

Input

4 4
1 2
1 3
2 3
2 4

Output

18

[submit]
[forum]
Author:	Andrew Stankevich, Georgiy Korneev
Resource:	Petrozavodsk Winter Trainings 2003
Date:	2003-02-06
*/
import java.io.*;

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
		int[] x = new int[n];
		for (int i = 0; i < 2 * m; ++i) {
			int v = nextInt();
			++x[v - 1];
		}
		long ans = 0;
		for (long xi : x) {
			ans += xi * xi;
		}
		System.out.println(ans);
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory: 
//873447	03.08.09 13:51	watashi	196 	.JAVA	Accepted	127 ms	250 kb
