// SGU369. Game
/*
369. Game
Time limit per test: 4 second(s)
Memory limit: 65536 kilobytes
input: standard
output: standard


Vasya loves his new game which is played on an infinite rectangular grid where K cells are initially black, all other cells are white. The move of the game is to find three black cells which are vertices of some rectangle with sides parallel to coordinate axis such that the fourth vertex of the rectangle is white. In this case you need to paint the fourth vertex black. Vasya asks you to write a program which calculates the number of black cells in the end of the game, i.e. when no more moves can be made.

Input
The first line contains an integer K (0 ≤ K≤ 2·105). The next K lines contain two integers each — coordinates of black cells Xi and Yi (-109 ≤ Xi, Yi ≤ 109).

Output
Output the answer to the task.

Example(s)

sample input

	

sample output

3
1 1
1 2
2 2

	

4


sample input

	

sample output

5
0 0
1 0
0 1
1 2
2 1

	

9
*/
import java.io.*;
import java.util.*;

class DijointSet {
	int[] p, s;

	DijointSet(int n) {
		p = new int[n];
		s = new int[n];
		for (int i = 0; i < n; ++i) {
			p[i] = i;
			s[i] = 1;
		}
	}

	int root(int i) {
		return p[i] == i ? i : (p[i] = root(p[i]));
	}

	boolean isFriend(int i, int j) {
		return root(i) == root(j);
	}

	void setFriend(int i, int j) {
		i = root(i);
		j = root(j);
		if (i != j) {
			s[i] += s[j];
			s[j] = 0;
			p[j] = i;
		}
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

	static int gao(ArrayList<Integer> a) {
		int ret = 0, p = 0;
		Collections.sort(a);
		for (int ai : a) {
			if (ret == 0 || ai != p) {
				++ret;
				p = ai;
			}
		}
		return ret;
	}

	public static void main(String[] args) throws IOException {
		int n = nextInt();
		int[] x = new int[n], y = new int[n];
		for (int i = 0; i < n; ++i) {
			x[i] = nextInt();
			y[i] = nextInt();
		}
		int[] xx = x.clone(), yy = y.clone();
		Arrays.sort(xx);
		Arrays.sort(yy);
		ArrayList<ArrayList<Integer> > a = new ArrayList<ArrayList<Integer> >(n);
		for (int i = 0; i < n; ++i) {
			a.add(new ArrayList<Integer>());
		}
		int[] yx = new int[n];
		Arrays.fill(yx, -1);
		DijointSet ds = new DijointSet(n);
		for (int i = 0; i < n; ++i) {
			int tx = Arrays.binarySearch(xx, x[i]);
			int ty = Arrays.binarySearch(yy, y[i]);
			a.get(tx).add(ty);
			if (yx[ty] == -1) {
				yx[ty] = tx;
			} else {
				ds.setFriend(yx[ty], tx);
			}
		}
		for (int i = 0; i < n; ++i) {
			if (ds.root(i) != i) {
				a.get(ds.root(i)).addAll(a.get(i));
				a.get(i).clear();
			}
		}
		long ans = 0;
		for (int i = 0; i < n; ++i) {
			if (!a.get(i).isEmpty()) {
				ans += 1L * gao(a.get(i)) * ds.s[i];
			}
		}
		System.out.println(ans);
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//887331	15.09.09 17:02	watashi	369 	.JAVA	Accepted	1793 ms	40775 kb


