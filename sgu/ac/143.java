// SGU143. Long Live the Queen
/*
143. Long Live the Queen

time limit per test: 0.50 sec.
memory limit per test: 4096 KB

The Queen of Byteland is very loved by her people. In order to show her their love, the Bytelanders have decided to conquer a new country which will be named according to the queen's name. This new country contains N towns. The towns are connected by bidirectional roads and there is exactly ONE path between any two towns, walking on the country's roads. For each town, the profit it brings to the owner is known. Although the Bytelanders love their queen very much, they don't want to conquer all the N towns for her. They will be satisfied with a non-empty subset of these towns, with the following 2 properties: there exists a path from every town in the subset to every other town in the subset walking only through towns in the subset and the profit of the subset is maximum. The profit of a subset of the N towns is equal to the sum of the profits of the towns which belong to the subset. Your task is to find the maximum profit the Bytelanders may get.

Input

The first line of input will contain the number of towns N (1<=N<=16 000). The second line will contain N integers: the profits for each town, from 1 to N. Each profit is an integer number between -1000 and 1000. The next N-1 lines describe the roads: each line contains 2 integer numbers a and b, separated by blanks, denoting two different towns between which there exists a road.

Output

The output should contain one integer number: the maximum profit the Bytelanders may get.

Sample Input

5
-1 1 3 1 -1
4 1
1 3
1 2
4 5

Sample Output

4

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
		} while (Character.isWhitespace(ch));
		boolean negative = (ch == '-');
		if (negative) {
			ch = System.in.read();
		}
		int ret = 0;
		while (Character.isDigit(ch)) {
			ret *= 10;
			ret += Character.digit(ch, 10);
			ch = System.in.read();
		}
		return negative ? -ret : ret;
	}

	static ArrayList<ArrayList<Integer> > e;
	static int[] s;
	static ArrayList<Integer> c;
	static int ans;

	static void gao(int v, int p) {
		for (int w : e.get(v)) {
			if (w != p) {
				gao(w, v);
				s[v] += Math.max(0, s[w]);
			}
		}
		ans = Math.max(ans, s[v]);
	}
	
	public static void main(String[] args) throws IOException {
		int n = nextInt();
		e = new ArrayList<ArrayList<Integer> >(n);
		s = new int[n];
		c = new ArrayList<Integer>();
		for (int i = 0; i < n; ++i) {
			e.add(new ArrayList<Integer>());
			s[i] = nextInt();
		}
		for (int i = 1; i < n; ++i) {
			int a = nextInt() - 1;
			int b = nextInt() - 1;
			e.get(a).add(b);
			e.get(b).add(a);
		}
		ans = Integer.MIN_VALUE;
		gao(0, -1);
		System.out.println(ans);
	}
}

// a non-empty subset => WA2

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//873497	03.08.09 18:14	watashi	143 	.JAVA	Accepted	79 ms	2842 kb
//873496	03.08.09 18:12	watashi	143 	.JAVA	Wrong answer on test 2	0 ms	258 kb

