// SGU126. Boxes
/*
126. Boxes

time limit per test: 0.50 sec.
memory limit per test: 4096 KB

There are two boxes. There are A balls in the first box, and B balls in the second box (0 < A + B < 2147483648). It is possible to move balls from one box to another. From one box into another one should move as many balls as the other box already contains. You have to determine, whether it is possible to move all balls into one box.

Input

The first line contains two integers A and B, delimited by space.

Output

First line should contain the number N - the number of moves which are required to move all balls into one box, or -1 if it is impossible.

Sample Input

Sample Output

2 6

Sample Output

2

Author	: Victor G. Samoilov, Herman "Smash" Narkaytis
Resource	: 5th Southern Subregional Contest. Saratov 2002
Date	: 2002-10-10
*/

import java.util.*;

class NoSolutionException extends Throwable {
}

// [iimondai]
public class Solution {
	static int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}

	static int solve(int a, int b) throws NoSolutionException {
		int g = gcd(a, b);
		a /= g;
		b /= g;
		if (a < b) {
			return solve(b, a);
		} else if (b == 0) {
			return 0;
		} else if ((a + b) % 2 != 0) {
			throw new NoSolutionException();
		} else {
			a -= b;
			b <<= 1;
			return 1 + solve(a, b);
		}
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int a = in.nextInt();
		int b = in.nextInt();
		try {
			System.out.println(solve(a, b));
		} catch (NoSolutionException e) {
			System.out.println(-1);
		}
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//866764	04.07.09 21:43	watashi	126 	.JAVA	Accepted	6 ms	2254 kb

