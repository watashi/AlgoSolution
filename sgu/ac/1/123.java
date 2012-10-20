// SGU123. The sum

/*
123. The sum

time limit per test: 0.50 sec.
memory limit per test: 4096 KB

The Fibonacci sequence of numbers is known: F1 = 1; F2 = 1; Fn+1 = Fn + Fn-1, for n>1. You have to find S - the sum of the first K Fibonacci numbers.

Input

First line contains natural number K (0<K<41).

Output

First line should contain number S.

Sample Input

5

Sample Output

12

Author	: Paul "Stingray" Komkoff, Victor G. Samoilov
Resource	: 5th Southern Subregional Contest. Saratov 2002
Date	: 2002-10-10
*/

import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int k = in.nextInt();
		int a = 1, b = 1, c, s = 0;
		for (int i = 0; i < k; ++i) {
			s += a;
			c = a + b;
			a = b;
			b = c;
		}
		System.out.println(s);
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//865690	30.06.09 06:11	watashi	123 	.JAVA	Accepted	6 ms	1898 kb

