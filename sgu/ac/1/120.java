// SGU120. Archipelago
/*
120. Archipelago

time limit per test: 0.50 sec.
memory limit per test: 4096 KB

Archipelago Ber-Islands consists of N islands that are vertices of equiangular and equilateral N-gon. Islands are clockwise numerated. Coordinates of island N1 are (x1, y1), and island N2 – (x2, y2). Your task is to find coordinates of all N islands.

Input

In the first line of input there are N, N1 and N2 (3£ N£ 150, 1£ N1,N2£N, N1¹N2) separated by spaces. On the next two lines of input there are coordinates of island N1 and N2 (one pair per line) with accuracy 4 digits after decimal point. Each coordinate is more than -2000000 and less than 2000000.

Output

Write N lines with coordinates for every island. Write coordinates in order of island numeration. Write answer with 6 digits after decimal point.

Sample Input

4 1 3
1.0000 0.0000
1.0000 2.0000

Sample Output

1.000000 0.000000
0.000000 1.000000
1.000000 2.000000
2.000000 1.000000

Author	: Michael R. Mirzayanov
Resource	: PhTL #1 Training Contests
Date	: Fall 2001
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
//887867	16.09.09 19:48	watashi	120 	.JAVA	Accepted	69 ms	0 kb
