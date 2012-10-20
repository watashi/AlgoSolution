// SGU139. Help Needed!
/*
139. Help Needed!

time limit per test: 0.50 sec.
memory limit per test: 4096 KB

Little Johnny likes puzzles a lot! Just a few days ago, he found out about the 'traditional' 4x4 puzzle. For this puzzle, you have all the numbers from 0 to 15 arranged in 4 rows and 4 columns. You are allowed to switch two adjacent elements (horizontally or vertically), only if one of them has the value 0. The purpose of the puzzle is to reach the following final state:

                             1  2  3  4
                             5  6  7  8
                             9 10 11 12
                            13 14 15  0

Given the initial state of the puzzle, you have to decide whether there exists a sequence of moves which brings the puzzle into the final state.

Input

The input will consist of  4 lines, each of them containing 4 integers, describing the initial state of the puzzle.

Output

For every initial state, you should print "YES" if the final state can be reached after several moves or "NO", if such a thing is impossible.

Sample Input #1

1 2 3 4
5 6 7 8
9 10 11 0
13 14 15 12

Sample Output #1

YES

Sample Input #2

2 1 3 4
5 6 7 8
9 10 11 12
0 13 14 15

Sample Output #2

NO

Author	: Mugurel Ionut Andreica
Resource	: SSU::Online Contester Fall Contest #2
Date	: Fall 2002

*/
import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int num;
		int[] a = new int[16];
		int dis = 0;
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				num = in.nextInt() - 1;
				if (num == -1) {
					num = 15;
				} else {
					dis += Math.abs(num / 4 - i) + Math.abs(num % 4 - j);
				}
				a[i * 4 + j] = num;
			}
		}
		int inv = 0;
		for (int i = 0; i < 16; ++i) {
			for (int j = 0; j < i; ++j) {
				if (a[i] < a[j]) {
					++inv;
				}
			}
		}
		System.err.println(dis + " " + inv);
		System.out.println(((dis & 1) ^ (inv & 1)) == 0 ? "YES" : "NO");
	}
}
// ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
// 871681	23.07.09 18:50	watashi	139 	.JAVA	Accepted	19 ms	2274 kb

