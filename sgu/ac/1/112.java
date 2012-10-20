// SGU112. ab-ba
/*
112. ab-ba

time limit per test: 0.50 sec.
memory limit per test: 4096 KB

You are given natural numbers a and b. Find ab-ba.

Input

Input file contains numbers a and b (1≤a,b≤100).

Output

Write answer in output file.

Sample Input

2 3

Sample Output

-1

*/

import java.math.*;
import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int a = in.nextInt();
		int b = in.nextInt();
		System.out.println(BigInteger.valueOf(a).pow(b).subtract(BigInteger.valueOf(b).pow(a)));
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//866395	03.07.09 14:58	watashi	112 	.JAVA	Accepted	6 ms	2446 kb


