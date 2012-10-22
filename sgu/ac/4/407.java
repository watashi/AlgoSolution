// SGU407. Number of Paths in the Empire
/*
407. Number of Paths in the Empire
Time limit per test: 2 second(s)
Memory limit: 65536 kilobytes
input: standard
output: standard
During the period of Tsam dynasty ruling people rarely fought against each other and their neighbours, because they just could not afford themselves such a waste of time. The matter for it is that they were entirely absorbed with solving various problems which were connected with trade, craft, agriculture and other spheres of human activity. In a wide list of problems the ones of tax collection stand out. As one of such problems was posed by Emperor himself, it was of great importance. The problem was to count the number of different paths consisting of exactly roads. Every path should have started and ended in the capital of Empire. Paths were supposed to cover the same towns and roads any times, moreover they could cover the capital several times. Now you are to solve this problem given information about Empire: there were country towns situated at the foot of a hill, they formed a circle at the bottom, and the capital was on the top of the hill. The capital was connected to all other towns, and each country town was also connected to other two neighbouring country towns both to the left and to the right. Pic. 1 Empire comprising the capital (index 0) and four country towns (indices 1 — 4).
Input
The only line of input file contains two integers and (, ).
Output
Output the answer without leading zeros.
Example(s)

sample input

	

sample output

4 3

	

8


sample input

	

sample output

3 4

	

21


Commentary to the first sample test. There are 8 paths in the Empire. 0-1-2-0, 0-2-3-0, 0-3-4-0, 0-4-1-0, 0-2-1-0, 0-3-2-0, 0-4-3-0, 0-1-4-0. 
*/

import java.math.*;
import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
		BigInteger k = BigInteger.valueOf(n);
		BigInteger c = BigInteger.ONE;
		BigInteger nc = BigInteger.ZERO;
		for (int i = 0; i < m; ++i) {
			BigInteger t = c;
			c = nc;
			nc = nc.shiftLeft(1).add(t.multiply(k));
		}
		System.out.println(c);
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//874728	09.08.09 11:42	watashi	407 	.JAVA	Accepted	194 ms	3514 kb

