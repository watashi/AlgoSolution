// SGU174. Walls
/*
174. Walls
time limit per test: 3 sec.
memory limit per test: 32768 KB
input: standard
output: standard



People of country T-land lived on the big plain many years ago. It is happened so that they started to quarrel, so they began to build walls to separate from each other.
One day they realized that walls surround some part of the country. Your task is to determine which wall was build first to surround a part of the T-land.

Input
The first line of input contains one number M (1<=M<=200000) - number of walls. Each of the following M lines contains four integer numbers: Cartesian coordinates of two ends of each wall. Walls are rectilinear segments with positive length, two walls can cross only by ends, and walls can't coincide. All coordinates do not exceed 10^9 by its absolute values.

Output
Write the answer in the single line of output. If all the walls leave the territory opened, write 0.

Sample test(s)

Input

4
0 0 1 0
0 1 0 0
1 0 0 1
2 2 5 7

Output

3
[submit]
[forum]
Author:	Dmitry Orlov
Resource:	Saratov ST team Spring Contest #1
Date:	18.05.2003
*/
import java.io.*;
import java.util.*;

// [algo]DijointSet
class DijointSet {
	int[] p;

	DijointSet(int n) {
		p = new int[n];
		for (int i = 0; i < n; ++i) {
			p[i] = i;
		}
	}

	int root(int i) {
		return p[i] == i ? i : (p[i] = root(p[i]));
	}

	boolean isFriend(int i, int j) {
		return root(i) == root(j);
	}

	void setFriend(int i, int j) {
		p[root(i)] = root(j);
	}
}

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

	public static void main(String[] args) throws IOException {
		int n = nextInt();
		DijointSet ds = new DijointSet(2 * n);
		HashMap<Long, Integer> mp = new HashMap<Long, Integer>();
		int x, y;
		long a, b;
		for (int i = 0; i < n; ++i) {
			x = nextInt();
			y = nextInt();
			a = ((long)x << 32) ^ y;
			x = nextInt();
			y = nextInt();
			b = ((long)x << 32) ^ y;
			if (mp.containsKey(a)) {
				x = mp.get(a);
			} else {
				x = mp.size();
				mp.put(a, x);
			}
			if (mp.containsKey(b)) {
				y = mp.get(b);
			} else {
				y = mp.size();
				mp.put(b, y);
			}
			if (ds.isFriend(x, y)) {
				System.out.println(i + 1);
				return;
			} else {
				ds.setFriend(x, y);
			}
		}
		System.out.println(0);
	}
}
// ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
// 871673	23.07.09 18:14	watashi	174 	.JAVA	Accepted	1275 ms	23238 kb

