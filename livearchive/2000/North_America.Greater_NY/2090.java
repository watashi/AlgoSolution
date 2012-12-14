import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
	private static final int ROOT = 0;
	private static final int SIZE = 1024;
	private ArrayList<ArrayList<Integer> > e;
	private int[] map;
	private int depth, size;
	private int[] m, c, u, d;

	public Main() {
		size = 0;
		map = new int[SIZE];
		Arrays.fill(map, -1);
		e = new ArrayList<ArrayList<Integer> >();
	}

	private int get(int x) {
		if (map[x] == -1) {
			map[x] = size++;
			e.add(new ArrayList<Integer>());
		}
		return map[x];
	}

	public void add(int a, int b) {
		a = get(a);
		b = get(b);
		e.get(a).add(b);
		e.get(b).add(a);
	}

	private void dfs(int p, int f) {
		d[p] = depth;
		u[p] = depth;
		m[p] = 1;
		++depth;
		for (int i : e.get(p)) {
			if (i == f) {
				continue;
			}
			if (m[i] == 1) {
				u[p] = Math.min(u[p], d[i]);
			} else if (m[i] == 0) {
				dfs(i, p);
				u[p] = Math.min(u[p], u[i]);
				if (p == ROOT) {
					++c[ROOT];
				} else if (u[i] >= d[p]) {
					++c[p];
				}
			}
		}
		--depth;
		m[p] = 2;
	}

	private void gao() {
		// !assert! connected
		m = new int[size];
		c = new int[size];
		u = new int[size];
		d = new int[size];
		depth = 0;
		Arrays.fill(m, 0);
		Arrays.fill(c, 1);
		c[ROOT] = 0;
		dfs(ROOT, -1);
	}

	public void solve() {
		boolean zero = true;

		gao();
		for (int i = 0; i < map.length; ++i) {
			if (map[i] != -1 && c[map[i]] > 1) {
				zero = false;
				System.out.println("  SPF node " + i +
						" leaves " + c[map[i]] + " subnets");
			}
		}
		if (zero) {
			System.out.println("  No SPF nodes");
		}
	}

	// static
	private static int buffer = -1;

	public static int nextInt() throws IOException {
		int ret = 0;

		while (!Character.isDigit(buffer)) {
			buffer = System.in.read();
		}
		do {
			ret *= 10;
			ret += Character.digit(buffer, 10);
			buffer = System.in.read();
		} while (Character.isDigit(buffer));

		return ret;
	}	

	public static void main(String[] args) throws IOException {
		int x = 0, ri = 0;

		while ((x = nextInt()) != 0) {
			Main solution = new Main();
			do {
				solution.add(x, nextInt());
			} while ((x = nextInt()) != 0);
			if (ri > 0) {
				System.out.println();
			}
			System.out.println("Network #" + (++ri));
			solution.solve();
		}
	}
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//805919 	2090 	SPF 	Accepted 	JAVA 	0.216 	2011-05-23 15:12:17
/*
id => 1174129
pid => 2090
pname => SPF
status => Accepted
lang => JAVA
time => 0.166
date => 2012-12-14 17:28:01
*/
