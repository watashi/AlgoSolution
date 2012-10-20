// SGU299. Triangle
/*
299. Triangle
Time limit per test: 2 second(s)
Memory limit: 65536 kilobytes
input: standard
output: standard


It is well known that three segments can make a triangle if and only if the sum of lengths of any two of them is strictly greater than the length of the third one. Professor Vasechkin has segments. He asked you, if you could find at least one set of three segments among them which can be used by professor to make a triangle.

Input
The first line of the input contains the only integer number (). The following lines contain the length of segments professor has. The length of any segment is the integer number from 1 to .

Output
Write to the output the length of segments requested by the professor — three numbers delimited by spaces. Write three zeros if there are no such three segments.

Example(s)

sample input

	

sample output

7
1
2
6
4
8
100
73

	

8 4 6
*/
import java.math.*;
import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		BigInteger[] a = new BigInteger[n];
		for (int i = 0; i < n; ++i) {
			a[i] = in.nextBigInteger();
		}
		Arrays.sort(a);
		for (int i = n - 1; i >= 2; --i) {
			if (a[i - 2].add(a[i - 1]).compareTo(a[i]) > 0) {
				System.out.println(a[i - 2] + " " + a[i - 1] + " " + a[i]);
				System.exit(0);
			}
		}
		System.out.println("0 0 0");
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//873590	04.08.09 07:31	watashi	299 	.JAVA	Accepted	284 ms	3954 kb
