// SGU136. Erasing Edges
/*
136. Erasing Edges

time limit per test: 0.50 sec.
memory limit per test: 4096 KB

Little Johnny painted on a sheet of paper a polygon with N vertices. Then, for every edge of the polygon, he drew the middle point of the edge. After that, he went to school. When he came back, he found out that his brother had erased the polygon (both the edges and the vertices). The only thing left were the middle points of the edges of the polygon. Help Johnny redraw his polygon.

Input

The first line of the input contains the integer number N (3<=N<=10 000). Then, N lines will follow, each of them containing 2 real numbers, separated by blanks: xi and yi. (xi,yi) are the coordinates of the middle point of the edge #i. The coordinates will be given with at most 3 decimal places.

Output

Print a line containing the word "YES", if the polygon can be redrawn, or "NO", if there exists no polygon having the given coordinates for the middle points of its edges. If the answer is "YES", then you should print N more lines, each of them containing two real numbers, separated by a blank, representing the X and Y coordinates of the vetices of the polygon. The coordinates should be printed with at least 3 decimal places. You should output the cordinates for vertex #1 first, for vertex #2 second and so on.. In order to decide which vertex of the polygon is #1,#2,..,#N, you should know that for every 1<=i<=N-1, edge #i connects the vertices labeled i and i+1. Edge #N connects the vertices N and 1.

Hint

The polygon may contain self-intersections. Although in many geometric problems, self-intersections only make things more difficult, in this case, they make things a lot easier.

Sample Input #1

4
0 0
2 0
2 2
0 2

Sample Output #1

YES
-1.000 1.000
1.000 -1.000
3.000 1.000
1.000 3.000

Sample Input #2

4
0 0
2 0
2 2
1 3

Sample Output #2

NO

Author	: Mugurel Ionut Andreica
Resource	: SSU::Online Contester Fall Contest #2
Date	: Fall 2002
*/
import java.io.*;

public class Solution {
	public static void main(String[] args) throws IOException {
		StreamTokenizer in = new StreamTokenizer(
				new BufferedReader(new InputStreamReader(System.in)));
		in.nextToken();
		int n = (int)(in.nval + .5);
		double[] x = new double[n], y = new double[n];
		double sx = 0, sy = 0;
		for (int i = 0; i < n; ++i) {
			in.nextToken();
			x[i] = in.nval;
			in.nextToken();
			y[i] = in.nval;
			if (i % 2 == 0) {
				sx += x[i];
				sy += y[i];
			} else {
				sx -= x[i];
				sy -= y[i];
			}
		}
		if (n % 2 == 0 && (Math.abs(sx) > 1e-6 || Math.abs(sy) > 1e-6)) {
			System.out.println("NO");
		} else {
			System.out.println("YES");
			for (int i = 0; i < n; ++i) {
				System.out.printf("%.3f %.3f\n", sx, sy);
				sx = 2 * x[i] - sx;
				sy = 2 * y[i] - sy;
			}
		}
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//874112	05.08.09 16:08	watashi	136 	.JAVA	Accepted	453 ms	3370 kb

