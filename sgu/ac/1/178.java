// SGU178. Golden chain
/*
178. Golden chain
time limit per test: 0.50 sec.
memory limit per test: 4096 KB
input: standard
output: standard



Peter arrived to the city and stayed in the hotel. He has no money but few day's later (maximum N days) he will receive a lot of money. And so he has a golden chain with N links. Peter must pay one link everyday, but he can pay more and take change by some of his links paid before.
When he receives money he will get his chain out of pawn. Peter likes his chain and he wants to break minimal number of links. Help him!
For example, if N=5, he must break one link (the second). After it his chain will consist of 3 parts with lengths 1, 1 and 3.
At the first day he will pay one link, at the second - one link too. Now he have one part consists of three connected links. At the third day he will pay 3-linked part and take two separated links (as change) back. On the fourth and fifth day he will pay one link.
You may assume that Peter can choose the way to get change.

Input
Input contains one integer number N (1<=N<=10^16).

Output
In output file you must write one integer number (number of the broken links).

Sample test(s)

Input

9

Output

2
[submit]
[forum]
Author:	Vasiliy Astakhov
Resource:	Saratov ST team Spring Contest #1
Date:	18.05.2003
*/
import java.util.*;

public class Solution {
	static long[] max;

	static {
		max = new long[55];
		for (int i = 0; i < max.length; ++i) {
			max[i] = (i + 1) * (1L << (i + 1)) - 1;
			System.err.println(i + " " + max[i]);
		}
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		long n = in.nextLong();
		for (int i = 0; i < max.length; ++i) {
			if (n <= max[i]) {
				System.out.println(i);
				break;
			}
		}
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//874005	05.08.09 12:42	watashi	178 	.JAVA	Accepted	19 ms	2234 kb

