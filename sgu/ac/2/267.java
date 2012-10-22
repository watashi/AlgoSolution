// SGU267. Optimist vs. Pessimist 
import java.io.*;
import java.util.*;

class Point {
	double x, y;
	public Point() { }
	public Point(double x, double y) { this.x = x; this.y = y; }
	public Point to(Point p) { return new Point(p.x - x, p.y - y); }
	static final double EPS = 1e-6;
}

public class Solution {
	static StreamTokenizer in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));

	static double nextDouble() throws IOException {
		in.nextToken();
		return in.nval;
	}

	static Point nextPoint() throws IOException {
		Point ret = new Point();
		ret.x = nextDouble();
		ret.y = nextDouble();
		return ret;
	}

	static double xprod(Point a, Point b) {
		return a.x * b.y - b.x * a.y;
	}

	static double dprod(Point a, Point b) {
		return a.x * b.x + a.y * b.y;
	}

	// WA: Points are not in order!!
	static double area(Point[] p) {
		return Math.abs(xprod(p[0].to(p[1]), p[0].to(p[2])));
	}

	static boolean parallel(Point p, Point a, Point b) {
		return Math.abs(xprod(p.to(a), p.to(b))) < Point.EPS;
	}

	public static void main(String[] args) throws IOException {
		int n = (int)nextDouble();
		int m = (int)nextDouble();
		double[] a = new double[n];
		boolean[] b = new boolean[n];
		for (int i = 0; i < n; ++i) {
			Point[] p = new Point[4];
			Point c = new Point(0, 0);
			for (int j = 0; j < 4; ++j) {
				p[j] = nextPoint();
				c.x += p[j].x;
				c.y += p[j].y;
			}
			c.x /= p.length;
			c.y /= p.length;
			Point x = nextPoint();
			Point y = nextPoint();
			a[i] = area(p);
			b[i] = !parallel(c, x, y);
			/*
			1 1
			0 2 6 4 2 0 4 6 3 1 3 5
			8.000 8.000
			*/
			b[i] |= dprod(c.to(x), c.to(y)) < -Point.EPS;
			System.err.println(a[i] + ":" + b[i]);
		}
		
		double ans1 = 0;
		double[] a1 = a.clone();
		for (int i = 0; i < m; ++i) {
			int k = 0;
			for (int j = 0; j < n; ++j) {
				if (a1[j] > a1[k] + Point.EPS || (a1[j] > a1[k] - Point.EPS && b[j])) {
					k = j;
				}
			}
			ans1 += b[k] ? a1[k] : 0;
			a1[k] = -1;
		}
		
		double ans2 = 0;
		double[] a2 = a.clone();
		for (int i = 0; i < m; ++i) {
			int k = 0;
			for (int j = 0; j < n; ++j) {
				if (a2[j] > a2[k] + Point.EPS || (a2[j] > a2[k] - Point.EPS && !b[j])) {
					k = j;
				}
			}
			ans2 += b[k] ? a2[k] : 0;
			a2[k] = -1;
		}

		System.out.printf("%.3f %.3f\n", ans2 / 2, ans1 / 2);
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status:  	Time:  	Memory:
//1078637	19.09.10 16:28	watashi	267 	.JAVA	Accepted 	91 ms	0 kb

