// SGU152. Making round
/*
152. Making round
time limit per test: 0.50 sec.
memory limit per test: 4096 KB
input: standard input
output: standard output



Extraordinary things are around us! All citizens of democratic Berland provided election of president and nobody voted "against all candidates". All votes distributed between N candidates. You was charged to write a program to calculate the results of election. You must indicate a part of votes given to each of the candidates. You must write integer numbers, concidering two conditions:
- Total sum of parts must be exactly 100%
- Every part is an integer number and it must be equal to real part, rounded up or down.

Input
There is a natural number N (1<=N<=10000) written in the first line - amount of candidates. Second line contains sequence of non-negative integer numbers A1, A2,..., AN; Ai is amount of votes given to the i-th candidate (Ai<=10000). Numbers of sequence are separated by one or more spaces.

Output
Write sequence of sought parts. Separate numbers by a space. If solution does not exist, write "No solution". If there are several solutions write any of them.

Sample test(s)

Input

2
10 10

Output

50 50
[submit]
[forum]
Author:	Michael R. Mirzayanov
Resource:	Saratov Subregional School Team Contest, 2002
Date:	Spring, 2002
*/
import java.io.*;

public class Solution {
	static int nextInt() throws IOException {
		int ch = -1;
		do {
			ch = System.in.read();
		} while (!Character.isDigit(ch));
		int ret = 0;
		while (Character.isDigit(ch)) {
			ret *= 10;
			ret += Character.digit(ch, 10);
			ch = System.in.read();
		}
		return ret;
	}

	public static void main(String[] args) throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < a.length; ++i) {
			a[i] = nextInt();
		}
		int s = 0;
		for (int ai : a) {
			s += ai;
		}
		int r = 100;
		boolean[] b = new boolean[n];
		for (int i = 0; i < n; ++i) {
			b[i] = (a[i] * 100 % s != 0);
			a[i] = a[i] * 100 / s;
			r -= a[i];
		}
		for (int i = 0; r > 0 && i < n; ++i) {
			if (b[i]) {
				++a[i];
				--r;
			}
		}
		boolean blank = false;
		for (int ai : a) {
			if (blank) {
				System.out.print(' ');
			} else {
				blank = true;
			}
			System.out.print(ai);
		}
		System.out.println();
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//873437	03.08.09 13:34	watashi	152 	.JAVA	Accepted	67 ms	1898 kb

