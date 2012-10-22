// SGU184. Patties

/*
184. Patties
time limit per test: 0.50 sec.
memory limit per test: 4096 KB
input: standard input
output: standard output



Petya is well-known with his famous cabbage patties. Petya's birthday will come very soon, and he wants to invite as many guests as possible. But the boy wants everybody to try his specialty of the house. That's why he needs to know the number of the patties he can cook using the stocked ingredients. Petya has P grams of flour, M milliliters of milk and C grams of cabbage. He has plenty of other ingredients. Petya knows that he needs K grams of flour, R milliliters of milk and V grams of cabbage to cook one patty. Please, help Petya calculate the maximum number of patties he can cook.

Input
The input file contains integer numbers P, M, C, K, R and V, separated by spaces and/or line breaks (1 <= P, M, C, K, R, V <= 10000).

Output
Output the maximum number of patties Petya can cook.

Sample test(s)

Input

3000 1000 500
30 15 60

Output

8
[submit]
[forum]
Author:	Andrew V. Lazarev
Resource:	ACM International Collegiate Programming Contest 2003-2004
North-Eastern European Region, Southern Subregion
Date:	2003 October, 9
*/

import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int P = in.nextInt();
		int M = in.nextInt();
		int C = in.nextInt();
		int K = in.nextInt();
		int R = in.nextInt();
		int V = in.nextInt();
		System.out.println(Math.min(P / K, Math.min(M / R, C / V)));
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//866390	03.07.09 13:32	watashi	184 	.JAVA	Accepted	19 ms	2222 kb

