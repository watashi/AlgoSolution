// SGU124. Broken line
/*
124. Broken line

time limit per test: 0.50 sec.
memory limit per test: 4096 KB

There is a closed broken line on a plane with sides parallel to coordinate axes, without self-crossings and self-contacts. The broken line consists of K segments. You have to determine, whether a given point with coordinates (X0,Y0) is inside this closed broken line, outside or belongs to the broken line.

Input

The first line contains integer K (4 Ј K Ј 10000) - the number of broken line segments. Each of the following N lines contains coordinates of the beginning and end points of the segments (4 integer xi1,yi1,xi2,yi2; all numbers in a range from -10000 up to 10000 inclusive). Number separate by a space. The segments are given in random order. Last line contains 2 integers X0 and Y0 - the coordinates of the given point delimited by a space. (Numbers X0, Y0 in a range from -10000 up to 10000 inclusive).

Output

The first line should contain:

INSIDE - if the point is inside closed broken line,

OUTSIDE - if the point is outside,

BORDER - if the point belongs to broken line.

Sample Input

4
0 0 0 3
3 3 3 0
0 3 3 3
3 0 0 0
2 2

Sample Output

INSIDE

Author	: Alex Y. Suslov, Sergey V. Mironov
Resource	: 5th Southern Subregional Contest. Saratov 2002
Date	: 2002-10-10

*/
import java.io.*;

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
		int[] x1 = new int[n], y1 = new int[n], x2 = new int[n], y2 = new int[n];
		for (int i = 0; i < n; ++i) {
			x1[i] = nextInt();
			y1[i] = nextInt();
			x2[i] = nextInt();
			y2[i] = nextInt();
		}
		int x0 = nextInt();
		int y0 = nextInt();
		int xx = 0, yy = 0;
		for (int i = 0; i < n; ++i) {
			if ((x1[i] <= x0 && x0 <= x2[i] || x2[i] <= x0 && x0 <= x1[i]) &&
					(y1[i] <= y0 && y0 <= y2[i] || y2[i] <= y0 && y0 <= y1[i])) {
				System.out.println("BORDER");
				System.exit(0);
			} else if (x1[i] == x2[i] && x0 < x1[i] &&
					(y1[i] <= y0 && y0 < y2[i] || y2[i] <= y0 && y0 < y1[i])) {
				++xx;
			} else if (y1[i] == y2[i] && y0 < y1[i] &&
					(x1[i] <= x0 && x0 < x2[i] || x2[i] <= x0 && x0 < x1[i])) {
				++yy;
			}
		}
		if (xx % 2 != 0 && yy % 2 != 0) {
			System.out.println("INSIDE");
		} else {
			System.out.println("OUTSIDE");
		}
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//873500	03.08.09 18:53	watashi	124 	.JAVA	Accepted	19 ms	566 kb
//873499	03.08.09 18:50	watashi	124 	.JAVA	Wrong answer on test 10	0 ms	190 kb
//873498	03.08.09 18:31	watashi	124 	.JAVA	Wrong answer on test 3	0 ms	186 kb

