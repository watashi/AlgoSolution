// SGU106. The equation
/*
106. The equation

time limit per test: 0.50 sec.
memory limit per test: 4096 KB

There is an equation ax + by + c = 0. Given a,b,c,x1,x2,y1,y2 you must determine, how many integer roots of this equation are satisfy to the following conditions : x1<=x<=x2,   y1<=y<=y2. Integer root of this equation is a pair of integer numbers (x,y).

Input

Input contains integer numbers a,b,c,x1,x2,y1,y2 delimited by spaces and line breaks. All numbers are not greater than 108 by absolute value.

Output

Write answer to the output.

Sample Input

1 1 -3
0 4
0 4

Sample Output

4

*/

import java.util.*;

public class Solution {
	// [alog] extendedGreatestCommonDivider extGcd
	// 可以处理负数
	static long[] extGcd(long a, long b) {
		if (b == 0) {
			return new long[]{1, 0, a};
		} else {
			long[] ret = extGcd(b, a % b);
			long x = ret[0], y = ret[1];
			ret[0] = y;
			ret[1] = x - y * (a / b);
			return ret;
		}
	}

	// [util] floor
	static long floor(long a, long b) {
		if (b < 0) {
			return floor(-a, -b);
		} else if (a < 0) {
			return -ceil(-a, b);
		} else {
			return a / b;
		}
	}

	// [util] ceil
	static long ceil(long a, long b) {
		if (b < 0) {
			return ceil(-a, -b);
		} else if (a < 0) {
			return -floor(-a, b);
		} else {
			return (a + b - 1) / b;
		}
	}

	// [ , )
	static long[] gao(long b, long k, long l, long r) {
		if (k < 0) {
			return gao(-b - 1, -k, -r, -l);
		} else {
			return new long[]{ceil(l - b, k), ceil(r - b, k)};
		}
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		long a = in.nextLong();
		long b = in.nextLong();
		long c = in.nextLong();
		long x1 = in.nextLong();
		long x2 = in.nextLong() + 1;
		long y1 = in.nextLong();
		long y2 = in.nextLong() + 1;

		long[] g = extGcd(a, b);
		if (a == 0 && b == 0) {
			System.out.println(c == 0 ? (x2 - x1) * (y2 - y1) : 0);
		} else if (a == 0) {
			System.out.println(c % b == 0 && y1 <= -c / b && -c / b < y2 ? (x2 - x1) : 0);
		} else if (b == 0) {
			System.out.println(c % a == 0 && x1 <= -c / a && -c / a < x2 ? (y2 - y1) : 0);
		} else if (c % g[2] != 0) {
			System.out.println(0);
		} else {
			long[] tx = gao(g[0] * (-c / g[2]), b / g[2], x1, x2);
			long[] ty = gao(g[1] * (-c / g[2]), - (a / g[2]), y1, y2);
			System.out.println(Math.max(0, Math.min(tx[1], ty[1]) - Math.max(tx[0], ty[0])));
		}
	}
}

//->1y<- zan

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//866971	05.07.09 15:53	watashi	106 	.JAVA	Accepted	6 ms	2218 kb

