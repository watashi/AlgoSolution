// SGU213. Strong Defence
/*
213. Strong Defence
time limit per test: 2 sec.
memory limit per test: 65536 KB
input: standard
output: standard



The Chief of the Galactic Empire has recently received some bad news from his spies. The Dark Lord is preparing to attack the Empire. His fleet of spaceships is ready for the first hyperjump.

It is well known that travelling in space is very simple. You just start from some star and make a series of hyperjumps to other stars. You can only jump from one star to another if they are connected with a special hyperjump tunnel, which is bidirectional, thus allowing to make a jump from one star that it connects to another. Of course, the tunnels are designed in such a way that there is the way to get from each star to any other one.

However, there is the way to block the hyperjump — to do this one must put a special battleship in the corresponding hypertunnel.

Of course, the Chief would like to block all hyperpaths from the star where the headquaters of the Dark Lord are located to the star where the capital of the Galactic Empire is. The resources of the Empire are almost unbounded, so it is easy to create as many battleships as needed. Unfortunately, there is one problem.

Each hyperjump blocking battleship must have a special crystal on board which allows him to stay in the hyperspace. There is a number of types of such crystals. The problem is that there is the way to destroy all battleships carrying some particular type of crystal.

Although it is known, that for each crystal type there is the way to destroy battleships powered by this crystal, there is hope that not all of those are known to Dark Lord engineers. So the Chief would like to use blocking ships in such a way that the following conditions are satisfied:


    * for each crystal type, if all ships with other crystal types are destroyed, battle ships with this crystal type block hypertunnels in such a way, that there is no path from Dark Lord's star to Empire Capital star;
    * the number of different crystal types used in ships is maximal possible;
    * no two ships block the same hypertunnel.


You may consider that there is the unlimited number of crystal types available and crystals of each type available.

Input

The first line of the input file contains N — the number of stars in the Galaxy(2 ≤ N ≤ 400), M -- the number of tunnels, S and T — numbers of stars where Dark Lord headquaters and Empire Capital are located respectively (S ≠ T).

Next M lines contain two integer numbers each — the numbers of the stars the corresponding tunnel connects. No tunnel connects a star to itself, no two stars are connected with more than one tunnel.


Output

First output L — the number of crystal types used. After that output L lines, for each crystal type output first Ki — the number of battleships with this crystal used, and then Ki numbers, identifying the hypertunnels blocked by the corresponding battleship. The tunnels are numbered starting from 1, as they are given in the input file.

Sample test(s)

Input

4 4 1 4
1 2
1 3
2 4
3 4

Output

2
2 1 2
2 3 4
[submit]
[forum]
Author:	Andrew Stankevich
Resource:	Petrozavodsk Summer Trainings 2003
Date:	2003-08-30
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
		int s = nextInt() - 1;
		int t = nextInt() - 1;
		int[][] e = new int[n][n];
		for (int i = 0; i < m; ++i) {
			int a = nextInt() - 1;
			int b = nextInt() - 1;
			e[a][b] = e[b][a] = i + 1;
		}
		int[] d = new int[n];
		Arrays.fill(d, -1);
		int[] q = new int[n];
		q[0] = s;
		d[s] = 0;
		for (int begin = 0, end = 1; begin < end; ++begin) {
			int i = q[begin];
			for (int j = 0; j < n; ++j) {
				if (d[j] == -1 && e[i][j] > 0) {
					d[j] = d[i] + 1;
					q[end++] = j;
				}
			}
		}
		ArrayList<ArrayList<Integer> > ans = new ArrayList<ArrayList<Integer> >(d[t]);
		for (int i = 0; i < d[t]; ++i) {
			ans.add(new ArrayList<Integer>());
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (e[i][j] > 0 && d[i] < d[t] && d[j] == d[i] + 1) {
					ans.get(d[i]).add(e[i][j]);
				}
			}
		}
		System.out.println(ans.size());
		for (ArrayList<Integer> i : ans) {
			System.out.print(i.size());
			for (int j : i) {
				System.out.print(" " + j);
			}
			System.out.println();
		}
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//875273	11.08.09 18:46	watashi	213 	.JAVA	Accepted	35 ms	2346 kb
