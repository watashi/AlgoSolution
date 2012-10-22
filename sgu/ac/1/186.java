// SGU186. The Chain
/*
186. The Chain
time limit per test: 0.50 sec.
memory limit per test: 4096 KB
input: standard input
output: standard output



Smith has N chains. Each chain is the sequence of successively connected links. The length of each chain is known: the first chain contains L1 links, the second - L2, ..., the last one - LN.
He can make a following series of actions in a minute:
1. to unchain one link
2. to remove or to put into the unchained link some other links of any chain
3. to chain the link
Your task is to determine the minimum time which will take the smith to connect all the chains in one line, i.e. the chain will look like a chain made up of successively connected links.

Input
The first line contains natural number N<=100. The second line contains L1, L2, ..., LN (1<=Li<=100, for all i = 1..N).

Output
Output the only integer number - the solution to the problem.

Sample test(s)

Input

2
3 4

Output

1
[submit]
[forum]
Author:	Michael R. Mirzayanov
Resource:	ACM International Collegiate Programming Contest 2003-2004
North-Eastern European Region, Southern Subregion
Date:	2003 October, 9 
*/
import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < a.length; ++i) {
			a[i] = in.nextInt();
		}
		Arrays.sort(a);
		int t = 0;
		for (int i = 0, r = n - 1; i < a.length && r > 0; ++i) {
			t += Math.min(a[i], r);
			r -= Math.min(a[i] + 1, r);
		}
		System.out.println(t);
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//873457	03.08.09 14:19	watashi	186 	.JAVA	Accepted	19 ms	2306 kb

