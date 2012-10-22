// SGU195. New Year Bonus Grant
/*
195. New Year Bonus Grant
time limit per test: 4 sec.
memory limit per test: 65536 KB
input: standard
output: standard



All programmers of Mocrosoft software company are organized in a strict subordination hierarchy. Every programmer has exactly one chief, except Bill Hates who is also the head of the company and has no chief.

Due to the celebration of the new 2003 year, chief accountant of Mocrosoft decided to pay a New Year Bonus Grant of 1000 dollars to some programmers. However being extremely concerned of the company wealth she would like to designate the least possible amount of money for these grants. On the other hand she didn't want to be accused of being too greedy or of giving preferences to some programmers. To do this, she developed the following scheme of grants appointment:


    * Each programmer may either assign a grant to one of his subordinates or have a grant assigned to him by his chief or none of the above.
    * No programmer can simultaneously receive a grant and assign a grant to one of his subordinates.
    * No programmer can assign a grant to more than one of his subordinates



The scheme seemed to be designed perfectly — nobody would like to assign a grant to anybody since in this case he himself would not receive money. But programmers somehow discovered the plan of chief accountant and decided to make a trick to get the most money possible and share them fairly afterwards. The idea was to make such grant assignments that the total amount of grant money received is maximum possible.

You were selected to write the program which will find the optimal grants appointment.

Input

The first line of the input file contains integer N — the number of programmers in Mocrosoft company (2 ≤ N ≤ 500 000). Each programmer is assigned his unique identifier — integer number ranging from 1 to N. Bill Hates has number 1 and each programmer has the number greater then the number of his chief. The second line of the input file contains N-1 integers, i-th of which being the number of the chief of the worker whose number is (i + 1).

Output

On the first line of the output file print the maximum possible amount of money workers can get. On the second line output the numbers of programmers that will receive grant in ascending order.

Sample test(s)

Input

4
1 1 2

Output

2000
3 4

[submit]
[forum]
Author:	Andrew Stankevich
Resource:	Petrozavodsk Winter Trainings 2003
Date:	2003-02-06
*/
import java.io.*;
import java.util.*;

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
		int[] c = new int[n];
		int[] p = new int[n];
		p[0] = 0;
		c[0] = 1;
		for (int i = 1; i < n; ++i) {
			p[i] = nextInt() - 1;
			++c[p[i]];
		}
		int[] queue = new int[n];
		int s = 0, q = 0;
		for (int i = 0; i < n; ++i) {
			if (c[i] == 0) {
				queue[q++] = i;
			}
		}
		int[] b = new int[n];
		int ans = 0;
		while (s < q) {
			int v = queue[s++];
			if (b[v] == 0 && b[p[v]] == 0) {
				b[v] = 1;
				b[p[v]] = -1;
				++ans;
			}
			if (--c[p[v]] == 0) {
				queue[q++] = p[v];
			}
		}
		boolean blank = false;
		System.out.println(ans * 1000);
		for (int i = 0; i < n; ++i) {
			if (b[i] == 1) {
				if (blank) {
					System.out.print(' ');
				} else {
					blank = true;
				}
				System.out.print(i + 1);
			}
		}
		System.out.println();
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//873702	04.08.09 16:36	watashi	195 	.JAVA	Accepted	1685 ms	13206 kb

