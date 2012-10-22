// SGU172. eXam
/*
172. eXam
time limit per test: 0.50 sec.
memory limit per test: 4096 KB
input: standard
output: standard



In Russia school pupils must do some exams before leaving school. Among others, they must do two "selective" exams. This means that school provides a list of available subjects; each pupil selects two different subjects from this list and is going to do this exams. According to rules, pupil isn't allowed to do both exams at the same day, so the school must schedule the exams, i.e. provide some days when pupils will be able to do exams.

One school does not want to warn teachers too much. They want to schedule all the exams into two days in such way that exams on some subjects are on the first day, and exams on all other (and only on them) are on second. You are to write a program, which will determine, if it is possible to schedule exams in this way so that all pupils will be able to do all their selected exams.

Input
On the first line of input there are two integers N and M (1<=N<=200, 1<=M<=30000) - the number of available subjects and the number of pupils. Then M lines follows; on i-th of them there are two integers - the numbers of exams, which were selected by i-th pupil. Exams are numerated from 1 to N.

Output
If the solution exists, write on the first line of output only one word "yes". On the second line write the total number of exams, which must be held on first day, and on the third line - the numbers of subjects of this exams. If there exist several solutions, output any. If no solution exists, write to output only one word "no".

Sample test(s)

Input

4 4
1 2
3 4
2 4
1 3

Output

yes
2
1 4
[submit]
[forum]
Author:	NNSU#2 team
Resource:	Lazurny olympiad in informatics
Date:	July-August 2002
*/
// 判断一个图是否是二分图（贪心着色）

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
		int m = nextInt();
		boolean[][] a = new boolean[n][n];
		for (int i = 0; i < m; ++i) {
			int x = nextInt() - 1;
			int y = nextInt() - 1;
			a[x][y] = a[y][x] = true;
		}
		int[] tag = new int[n];
		int[] queue = new int[n];
		int count = 0;
		for (int i = 0; i < n; ++i) {
			if (tag[i] != 0) {
				if (tag[i] == -1) {
					++count;
				}
				continue;
			}
			tag[i] = 1;
			queue[0] = i;
			for (int p = 0, q = 1; p < q; ++p) {
				int v = queue[p];
				for (int j = 0; j < n; ++j) {
					if (a[v][j]) {
						if (tag[j] == 0) {
							tag[j] = -tag[v];
							queue[q++] = j;
						} else if (tag[j] == tag[v]) {
							System.out.println("no");
							return;
						}
					}
				}
			}
		}
		System.out.println("yes");
		System.out.println(count);
		boolean blank = false;
		for (int i = 0; i < n; ++i) {
			if (tag[i] == -1) {
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
// ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
// 871675	23.07.09 18:33	watashi	172 	.JAVA	Accepted	6 ms	590 kb

