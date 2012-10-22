// SGU198. Get Out!
/*
198. Get Out!
time limit per test: 2 sec.
memory limit per test: 65536 KB
input: standard
output: standard



Captain Faraway on his famous circular ship Kolobok is lost among the islands of the archipelago that he has just discovered. Now he wonders whether he can get out of there. Help him!

All islands in the archipelago can be composed of pieces that have circular form. You are given the map of archipelago and the position of captain. Find out whether captain can get out of there, i.e. can get as far from the point he is in the beginning as he likes.

Input

The first line contains N — the number of circular island parts (1 ≤ N ≤ 300). N lines follow, each containing xi, yi, ri — coordinates of center and radius of the i-th circle. All coordinates and radii are real. Objects may overlap with each other in arbitrary way. All objects are considered solid.

The last line of the input file contains three real numbers — coordinates of the center of Kolobok and its radius.

You may consider Kolobok to be the perfect circle and that it is in the free area in the beginning. Kolobok can move along any trajectory and is so strong that he can even touch islands, but no nonzero part of island must intersect Kolobok during his motion. You may assume that making calculations with the precision of 10-6 is satisfactory.

Output

Output YES if Kolobok can leave archipelago and NO if it cannot.

Sample test(s)

Input


Test #1

7
2 2 1.1
-2 2 1.1
2 -2 1.0
-2 -2 1.0
2 -5 1.0
0 -8 1.0
-2 -6 1.0
0 0 1

Test #2

5
2 2 1.1
-2 2 1.1
2 -2 1.0
-2 -2 1.0
0 -3 0.01
0 0 1

Output


Test #1

YES

Test #2

NO


[submit]
[forum]
Author:	Andrew Stankevich
Resource:	Petrozavodsk Winter Trainings 2003
Date:	2003-02-06 
*/
import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		double[] x = new double[n], y = new double[n], r = new double[n], d = new double[n];
		for (int i = 0; i < n; ++i) {
			x[i] = in.nextDouble();
			y[i] = in.nextDouble();
			r[i] = in.nextDouble();
		}
		double x0 = in.nextDouble();
		double y0 = in.nextDouble();
		double r0 = in.nextDouble();
		double[][] w = new double[n][n];
		for (int i = 0; i < n; ++i) {
			x[i] -= x0;
			y[i] -= y0;
			r[i] += r0;
			d[i] = Math.hypot(x[i], y[i]);
			w[i][i] = 0;
			for (int j = 0; j < i; ++j) {
				if (r[i] + r[j] > Math.hypot(x[i] - x[j], y[i] - y[j]) + 1e-6) {
					double a = Math.acos(Math.max(-1.0, Math.min(1.0,	// WA12
							(x[i] * x[j] + y[i] * y[j]) / (d[i] * d[j]))));
					boolean b = (x[i] * y[j] - x[j] * y[i] >= 0);
					w[i][j] = b ? a : -a;
					w[j][i] = b ? -a : a;
				} else {
					w[i][j] = w[j][i] = 1e100;
				}
			}
		}
		// floyd => WA17
		double[] v = new double[n];
		for (int k = 0; k < n; ++k) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					v[j] = Math.min(v[j], v[i] + w[i][j]);
				}
			}
		}
		boolean flag = true;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (v[j] > v[i] + w[i][j] + 1e-6) {
					flag = false;
				}
			}
		}
		System.out.println(flag ? "YES" : "NO");
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//873756	04.08.09 18:53	watashi	198 	.JAVA	Accepted	779 ms	4274 kb

