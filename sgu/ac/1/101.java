// SGU101. Domino
/*
101. Domino

time limit per test: 0.50 sec.
memory limit per test: 4096 KB

Dominoes – game played with small, rectangular blocks of wood or other material, each identified by a number of dots, or pips, on its face. The blocks usually are called bones, dominoes, or pieces and sometimes men, stones, or even cards.
The face of each piece is divided, by a line or ridge, into two squares, each of which is marked as would be a pair of dice...

The principle in nearly all modern dominoes games is to match one end of a piece to another that is identically or reciprocally numbered.

ENCYCLOPÆDIA BRITANNICA

Given a set of domino pieces where each side is marked with two digits from 0 to 6. Your task is to arrange pieces in a line such way, that they touch through equal marked sides. It is possible to rotate pieces changing left and right side.

Input

The first line of the input contains a single integer N (1 ≤ N ≤ 100) representing the total number of pieces in the domino set. The following N lines describe pieces. Each piece is represented on a separate line in a form of two digits from 0 to 6 separated by a space.

Output

Write “No solution” if it is impossible to arrange them described way. If it is possible, write any of way. Pieces must be written in left-to-right order. Every of N lines must contains number of current domino piece and sign “+” or “-“ (first means that you not rotate that piece, and second if you rotate it).

Sample Input

5
1 2
2 4
2 4
6 4
2 1

Sample Output

2 -
5 +
1 +
3 +
4 -
*/

import java.util.*;

// [algo] Eulerian Path (Undirected Graph)
public class Solution {
	static int[] a;
	static int[] b;
	static int[] d;
	static ArrayList<LinkedList<Integer> > e;
	static boolean[] f;

	static void floodfill(int v) {
		if (f[v]) {
			return;
		} else {
			f[v] = true;
		}
		for (int ab : e.get(v)) {
			floodfill(v == a[ab] ? b[ab] : a[ab]);
		}
	}

	static void findEulerianPath(int s, int t) {
		if (s == t && d[t] == 0) {
			return;
		} else {
			int ab;
			do {
				ab = e.get(s).pollLast();
			} while (a[ab] == -1);
			int r = (s == a[ab]) ? b[ab] : a[ab];
			String str = (ab + 1) + ((s == a[ab]) ? " -" : " +");
			--d[s];
			--d[r];
			a[ab] = b[ab] = -1;
			findEulerianPath(r, t);
			System.out.println(str);
			while (d[s] > 0) {
				findEulerianPath(s, s);
			}
		}
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		
		a = new int[n];
		b = new int[n];
		d = new int[7];
		e = new ArrayList<LinkedList<Integer> >(7);
		for (int i = 0; i < 7; ++i) {
			e.add(new LinkedList<Integer>());
		}
		f = new boolean[7];
		
		for (int i = 0; i < n; ++i) {
			a[i] = in.nextInt();
			b[i] = in.nextInt();
			e.get(a[i]).add(i);
			e.get(b[i]).add(i);
			++d[a[i]];
			++d[b[i]];
		}

		int s = -1, t = -1;

		floodfill(a[0]);
		for (int i = 0; i < 7; ++i) {
			if (d[i] > 0) {
				if (!f[i]) {
					System.err.println("_1_");
					System.out.println("No solution");
					System.exit(0);
				} else if (d[i] % 2 != 0) {
					if (s == -1) {
						s = i;
						t = -1;
					} else if (t == -1) {
						t = i;
					} else {
						System.err.println("_2_");
						System.out.println("No solution");
						System.exit(0);
					}
				} else if (s == -1 && t == -1) {
					t = i;
				}
			}
		}
		if (s == -1) {
			s = t;
		}
		findEulerianPath(s, t);
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//866793	04.07.09 23:46	watashi	101 	.JAVA	Accepted	19 ms	2570 kb


