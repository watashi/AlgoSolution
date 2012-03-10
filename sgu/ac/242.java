// SGU242. Student's Morning
/*
242. Student's Morning
time limit per test: 1 sec.
memory limit per test: 6144 KB
input: standard
output: standard



One Monday morning after some very fun party N students woke up at the flat of one of them. Notice that it was a Monday morning and every student of that party needs to be in his university this day. But nobody wants to go to his university alone (there were students from different universities). So, they decided to select from all universities only K of them to visit. Every selected university must be visited by at least two of the students. Every student has his own preference list of universities. It means, if some university is in list of some student's preferred universities, this student can go to this university with some non-empty company of students. Notice, that some of students can stay at the flat and continue drinking "juices" and playing "games". For example, student Shokman was to stay home (due to failed exam) with foreign student Chokman, who remained home because of runny nose.
In that problem there are no preferences between students, because if they have very fun party that already means that everyone of them prefers anybody from this company.

More formally, your task is, given numbers of students, selected universities and preference list of every student, to decide whether it is possible to visit all universities by at least two of students or no, and if it is possible you must output for each university numbers of students, which have to go to it in one company. One student can't be in more than one company.

Input
First line of input file contains two numbers N and K (0<=K<=N<=200). Next N lines contain preference lists of each student. Every preference list is started by number of preferred universities followed by numbers of these universities.

Output
First line of output file must contain word "YES" (without quotes), if it possible to visit all universities, satisfying rules of that task or word "NO" (also without quotes) when it is impossible. In case of positive answer next K lines must contain lists of students, who are going to corresponding university. First number in list of students must be a number of students in the list, followed by numbers of these students.

Sample test(s)

Input

Test #1
4 2
1 1
2 1 2
1 2
2 1 2

Test #2
3 2
2 1 2
2 1 2
2 1 2

Output

Test #1
YES
2 1 2
2 3 4

Test #2
NO
[submit]
[forum]
Author:	Alexey Preobrajensky
Resource:	---
Date:	October, 2003 
*/
import java.io.*;
import java.util.*;

public class Solution {
	// [algo] hungary BipartiteMaximumMatching
	// [module] hungary
	public static int hungary(int nu, int nv, int[][] e, int[] mu, int[] mv) {
		Arrays.fill(mu, -1);
		Arrays.fill(mv, -1);
		int[] q = new int[nu];
		int[] p = new int[nv];
		int ret = 0;
		for (int i = 0; i < nu; ++i) {
			Arrays.fill(p, -1);
			q[0] = i;
BFS:
			for (int begin = 0, end = 1; begin < end; ++begin) {
				int u = q[begin];
				for (int v : e[u]) {
					if (p[v] == -1) {
						p[v] = u;
						if (mv[v] == -1) {
							int t = v;
							while (t != -1) {
								u = p[t];
								v = t;
								t = mu[u];
								mu[u] = v;
								mv[v] = u;
							}
							++ret;
							break BFS;
						} else {
							q[end++] = mv[v];
						}
					}
				}
			}
		}
		return ret;
	}

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
		int k = nextInt();
		int[][] e = new int[n][];
		for (int i = 0; i < n; ++i) {
			int m = nextInt();
			int[] ei = new int[m << 1];
			for (int j = 0; j < m; ++j) {
				ei[j] = (nextInt() - 1) << 1;
				ei[m + j] = ei[j] ^ 1;
			}
			e[i] = ei;
		}
		int[] mv = new int[k << 1];
		if (hungary(n, k << 1, e, new int[n], mv) == 2 * k) {
			System.out.println("YES");
			for (int i = 0; i < k; ++i) {
				System.out.println("2 " + (mv[i << 1] + 1) + " " + (mv[(i << 1) ^ 1] + 1));
			}
		} else {
			System.out.println("NO");
		}
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//874635	08.08.09 20:52	watashi	242 	.JAVA	Accepted	7 ms	430 kb
