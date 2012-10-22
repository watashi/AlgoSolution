// SGU416. Optimal Dartboard
/*
416. Optimal Dartboard
Time limit per test: 2 second(s)
Memory limit: 262144 kilobytes
input: standard
output: standard


A dartboard is a disc divided into segments, with each segment labeled with a distinct positive integer between 1 and . That integer indicates the score for hitting the segment. To make the game more interesting, the arrangement of numbers is chosen in such a way that the risk is maximized. The risk is estimated based on the differences in scores of adjacent segments.

We're studying the following 'double-layered' structure of segments in this problem:



I.e., is always even, and we split the disc into two layers of parts along the circumference. We enumerate the segments in the following manner: the first segment is some outer segment, the second segment is the corresponding inner segment, the third segment is some adjacent outer segment, etc. An example of this enumeration is shown on the picture above.

The total risk is defined as the sum of squared differences between the scores of adjacent segments. If the value assigned to segment is , then the risk is:



(we assume and in this formula).

You are to place the numbers from 1 through into the segments in such a way that the total risk is maximized.

Input
The input file contains an even integer number ().

Output
Output integer numbers: , , , , separated with single spaces. In case there are several possible solutions, output any.

Example(s)

sample input

	

sample output

10

	

2 9 7 4 6 5 3 8 10 1

*/
import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[] a = new int[n];
		int l, r, d, v;
		a[1 - 1] = 1;
		d = 3;
		l = 1;
		r = n + 1;
		v = 1 + 1;
		while (true) {
			l += d;
			if (l >= r) {
				break;
			}
			a[l - 1] = v++;
			d = 4 - d;
			r -= d;
			if (l >= r) {
				break;
			}
			a[r - 1] = v++;
		}
		a[2 - 1] = n;
		d = 1;
		l = 2;
		r = n + 2;
		v = n - 1;
		while (true) {
			l += d;
			if (l >= r) {
				break;
			}
			a[l - 1] = v--;
			d = 4 - d;
			r -= d;
			if (l >= r) {
				break;
			}
			a[r - 1] = v--;
		}
		boolean blank = false;
		for (int ai : a) {
			if (blank) {
				System.out.print(' ');
			} else {
				blank = true;
			}
			System.out.print(ai);
		}
		System.out.println();
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//874732	09.08.09 12:20	watashi	416 	.JAVA	Accepted	7 ms	2094 kb


