// SGU228. Archipelago
/*
228. Archipelago
time limit per test: 0.50 sec.
memory limit per test: 4096 KB
input: standard
output: standard



Ber-islands Archipelago consists of N islands and has a form of regular N-gon. Islands are numbered in a clockwise order. Coordinates of the N1-th island are (X1, Y1), and of the N2-th island are - (X2, Y2). You are to write a program which will find coordinates of all islands.

Input
The input contains three integers N, N1, N2 (3<=N<=150, 1<=N1,N2<=N, N1<>N2). The following two pairs of real numbers are coordinates of N1-th and N2-th islands. All absolute values of coordinates do not exceed 10^6. All numbers separated by white spaces.

Output
Output coordinates of the islands in order of numeration on separate lines. The computed coordinates should be exact to six digits after the decimal point.

Sample test(s)

Input

4 1 3
1.0000 0.0000
1.0000 2.0000

Output

1.000000 0.000000
0.000000 1.000000
1.000000 2.000000
2.000000 1.000000
[submit]
[forum]
Author:	Michael R. Mirzayanov
Resource:	---
Date:	--
*/

import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int n1 = in.nextInt() - 1;
		int n2 = (in.nextInt() - 1 - n1 + n) % n;
		double x1 = in.nextDouble();
		double y1 = in.nextDouble();
		double x2 = in.nextDouble() - x1;
		double y2 = in.nextDouble() - y1;
		double[] x = new double[n], y = new double[n];
		double a = 2 * Math.PI / n;
		for (int i = 0; i < n; ++i) {
			x[i] = Math.cos(-i * a) - 1;
			y[i] = Math.sin(-i * a) - 0;
		}
		double r = Math.hypot(x2, y2) / Math.hypot(x[n2], y[n2]);
		double d = Math.atan2(y2, x2) - Math.atan2(y[n2], x[n2]);
		double[][] t = new double[][]{
			new double[]{Math.cos(d) * r, -Math.sin(d) * r},
			new double[]{Math.sin(d) * r, Math.cos(d) * r}
		};
	//	System.out.println(r + " " + d);
	//	System.out.println(x1 + " " + y1);
		for (int i = 0; i < n; ++i) {
			double xx = x1 + t[0][0] * x[i] + t[0][1] * y[i];
			double yy = y1 + t[1][0] * x[i] + t[1][1] * y[i];
			x[i] = xx;
			y[i] = yy;
		}
		for (int i = n - n1; i < n; ++i) {
			System.out.printf("%.6f %.6f\n", x[i], y[i]);
		}
		for (int i = 0; i < n - n1; ++i) {
			System.out.printf("%.6f %.6f\n", x[i], y[i]);
		}
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//886972	14.09.09 15:24	watashi	228 	.JAVA	Accepted	82 ms	0 kb


