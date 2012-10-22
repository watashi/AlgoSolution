// SGU105. Div 3
/*
105. Div 3

time limit per test: 0.50 sec.
memory limit per test: 4096 KB

There is sequence 1, 12, 123, 1234, ..., 12345678910, ... . Given first N elements of that sequence. You must determine amount of numbers in it that are divisible by 3.

Input

Input contains N (1<=N<=231 - 1).

Output

Write answer to the output.

Sample Input

4

Sample Output

2
*/

import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		--n;
		System.out.println(n / 3 * 2 + n % 3);
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//866769	04.07.09 21:57	watashi	105 	.JAVA	Accepted	6 ms	2206 kb


