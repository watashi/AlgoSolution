// SGU144. Meeting
/*
144. Meeting

time limit per test: 0.50 sec.
memory limit per test: 4096 KB

Two of the three members of the winning team of one of the ACM regional contests are going to meet in order to train for the upcoming World Finals. They decided that they will meet sometime between X o'clock and Y o'clock. Because they never get anywhere on time (they were late even on the day of the regional contest), they did not set an exact time when they will meet. However, they decided that the one who gets first at the meeting point will not wait more than Z minutes for the other one (they calculated that, if the other one will not come within Z minutes from the arrival of the first of them, then it is very probable that he will not show up at all).
Knowing that, in the end, both of them will show up at some time between X o'clock and Y o'clock (not necessarily after an integer number of minutes), compute which is the probability that they will actually meet.

Input

The input will contain 2 integer numbers X and Y (0<=X<Y<=24) and one real number Z ( 0 < Z <= 60*(Y-X) ).

Output

You should output the required probability with 7 decimal digits (rounded according to the 8th decimal digit).

Sample Input

11 12 20.0

Sample Output

0.5555556

Author	: Mugurel Ionut Andreica
Resource	: SSU::Online Contester Fall Contest #2
Date	: Fall 2002
*/

/*
beginfig(1440);
u=1in;
draw (0,0)--(u,0)--(u,u)--(0,u)--cycle;
fill (0,0)--(.382u,0)--(u,.618u)--(u,u)--(.618u,u)--(0,.382u)--cycle withcolor .618 green;
label.bot("a", (.5u,0));
label.lft("b", (0,.5u));
endfig;
*/

import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int x = in.nextInt();
		int y = in.nextInt();
		double z = in.nextDouble();
		double a = 60 * (y - x);
		double r = (a - z) / a;
		System.out.printf("%.8f\n", 1 - r * r);
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//865693	30.06.09 06:36	watashi	144 	.JAVA	Accepted	30 ms	2370 kb

