// SGU374. Save Vasya
/*
374. Save Vasya
Time limit per test: 6 second(s)
Memory limit: 65536 kilobytes
input: standard
output: standard


Vasya has huge problems. He needs to take polynomial ax + b, then calculate its k-th power and evaluate the sum of its coefficients. Your task is to help him.

Input
The first line of the input contains three integers a, b and k (1 ≤ a, b≤ 100, 1≤ k≤ 20).

Output
The first line must contain the sum of coefficients of the resulting polynomial.

Example(s)

sample input

	

sample output

1 2 2

	

9
*/
import java.math.*;
import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int a = in.nextInt();
		int b = in.nextInt();
		int k = in.nextInt();
		System.out.println(BigInteger.valueOf(a + b).pow(k));
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//874929	10.08.09 13:51	watashi	374 	.JAVA	Accepted	25 ms	2266 kb
