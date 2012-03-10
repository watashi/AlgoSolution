// SGU193. Chinese Girls' Amusement
/*
193. Chinese Girls' Amusement
time limit per test: 2 sec.
memory limit per test: 65536 KB
input: standard
output: standard



You must have heard that the Chinese culture is quite different from that of Europe or Russia. So some Chinese habits seem quite unusual or even weird to us.

So it is known that there is one popular game of Chinese girls. N girls stand forming a circle and throw a ball to each other. First girl holding a ball throws it to the K-th girl on her left (1 ≤ K ≤ N/2). That girl catches the ball and in turn throws it to the K-th girl on her left, and so on. So the ball is passed from one girl to another until it comes back to the first girl. If for example N = 7 and K = 3, the girls receive the ball in the following order: 1, 4, 7, 3, 6, 2, 5, 1.

To make the game even more interesting the girls want to choose K as large as possible, but they want one condition to hold: each girl must own the ball during the game.

Input

Input file contains one integer number N (3 ≤ N ≤ 102000) - the number of Chinese girls taking part in the game.

Output

Output the only number - K that they should choose.

Sample test(s)

Input

Test #1
7

Test #2
6


Output

Test #1
3

Test #2
1

[submit]
[forum]
Author:	Alexander Maximov, Andrew Stankevich
Resource:	Petrozavodsk Winter Trainings 2003
Date:	2003-02-06 
*/
import java.math.*;
import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		BigInteger n = in.nextBigInteger();
		if (n.testBit(0)) {
			n = n.shiftRight(1);
		} else {
			n = n.shiftRight(2).shiftLeft(1).subtract(BigInteger.ONE);
		}
		System.out.println(n);
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//873670	04.08.09 13:56	watashi	193 	.JAVA	Accepted	19 ms	2542 kb
