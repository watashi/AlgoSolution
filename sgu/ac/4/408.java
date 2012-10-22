// SGU408. Game with points
/*
408. Game with points
Time limit per test: 2 second(s)
Memory limit: 65536 kilobytes
input: standard
output: standard
# Recently Petya has discovered new game with points. Rules of the game are quite simple. First, there is only one point with coordinates . Then Petya have to draw another points. Points must be drawn consequently and each new point must be connected with exactly one of the previous points by a segment. Let's decribe the game process more formally. At the -th step Petya chooses the position of the point (not necessarily with integer coordinates). Than he chooses one of the previously drawn points in order to connect it with the point . Lets call this point . The following conditions must be held: Point must not coincide with any of the previous points.
# Point must not lie on the previously drawn segments.
# Segment must not have common points with previously drawn segments, except possibly the point .
# Segment must not cover any of the previous points, except the point .
# Length of the segment must not exceed 1. After drawing each point Petya computes two values.
# The largest number of segments which share a common point.
# The largest euclid distance between some pair of points. After each step Petya gains the score which is equal to the product of these values. Find out which is the maximal score Petya can gain after the whole game.
Input
Input contains single integer number ().
Output
Output the maximal score that Petya can gain. Your answer must be accurate up to .
Example(s)

sample input

	

sample output

2

	

5.000


sample input

	

sample output

4

	

20.000

*/

// 1 2*2 2*3 3*3 3*4 4*4

import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int s = (n > 0 ? 1 : 0);	// n = 0 => WA3
		for (int i = 2; i <= n; ++i) {
			s += (i / 2 + 1) * ((i + 1) / 2 + 1);
		}
		System.out.println(s);
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//874704	09.08.09 10:36	watashi	408 	.JAVA	Accepted	7 ms	2074 kb


