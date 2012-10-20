// SGU367. Contest
/*
367. Contest
Time limit per test: 1 second(s)
Memory limit: 65536 kilobytes
input: standard
output: standard


In compliance with the traditional rules of ACM International Collegiate Programming Contest teams are ranked according to the amount solved problems and penalty time. For the purpose of this problem we will define penalty time as a sum of minutes when all problems solved by the team were submitted (thus, let's think that all problems were accepted from the first attempt). For example, if some team solved three problems: on 10-th, 45-th and 123-rd minutes, the penalty time would be 10 + 45 + 123 = 178 minutes.

On one of numerous trainings one famous team was solving old competition it had solved previously. For each problem participants estimated time ti required to solve this problem. Moreover, they defined a set of constraints on problem solving. Each constraint is an ordered pair (a, b), denoting that the problem a must be solved before the problem b (i. e. if the problem b will be solved, than the problem a also must be solved, and must be solved earlier than the problem b). This is due to the fact that the problem a is a subtask of the problem b. Obviously the problem a is easier than the problem b, i. e. ta ≤ tb. The training lasts T minutes.

What is the best performance can show the team? You may assume that the team will not do failed attempts and that they estimated time for solving each problem correctly. Calculate maximal number of problems that they can solve and the corresponding minimal penalty time. Please also determine which problems and in what order the team should solve.

Input
The first line of the input file contains two integer numbers N and T (1 ≤ N ≤ 1000; 1 ≤ T ≤ 109), where N is the number of problems, T is the duration of the training. The second line contains N integer numbers ti (1 ≤ ti ≤ 3500), where ti is the time required to solve i-th problem. The third line contains integer number M (0 ≤ M ≤ 10000) — number of constraints. Each of the next M lines contains one constraint represented by pair of integer numbers ai, bi (1 ≤ ai,bi ≤ N; ai <> bi), denoting that the problem ai must be solved before the problem bi can be solved. It is guaranteed that tai ≤ tbi. All numbers in the input file are integer.

Output
On the first line of the output file print the maximal number of problems that the team can solve and the corresponding minimal penalty time. On the second line print numbers of problems that need to be solved in the order they must be solved. Problems are numbered 1 through N. If there are several solutions, output any of them.

Example(s)

sample input

	

sample output

1 1
1
0

	

1 1
1


sample input

	

sample output

3 10
1 1 1
3
1 2
2 3
3 1

	

0 0


sample input

	

sample output

4 2
1 2 1 2
1
1 3

	

2 3
1 3
*/
import java.util.*;

class IndexComparator implements Comparator<Integer> {
	private final int[] a;

	public IndexComparator(int[] a) {
		this.a = a;
	}

	public int compare(Integer o1, Integer o2) {
		if (a[o1] != a[o2]) {
			return a[o1] < a[o2] ? -1 : 1;
		} else {
			return 0;
		}
	}
}

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int p = 0, q = in.nextInt(), s = 0;
		int[] t = new int[n], d = new int[n];
		ArrayList<ArrayList<Integer> > e = new ArrayList<ArrayList<Integer> >(n);
		for (int i = 0; i < n; ++i) {
			t[i] = in.nextInt();
			e.add(new ArrayList<Integer>());
		}
		int m = in.nextInt();
		for (int i = 0; i < m; ++i) {
			int a = in.nextInt() - 1;
			int b = in.nextInt() - 1;
			e.get(a).add(b);
			++d[b];
		}

		PriorityQueue<Integer> pq = new PriorityQueue<Integer>(n, new IndexComparator(t));
		for (int i = 0; i < n; ++i) {
			if (d[i] == 0) {
				pq.add(i);
			}
		}
		ArrayList<Integer> ans = new ArrayList<Integer>();
		while (!pq.isEmpty() && (p += t[pq.peek()]) <= q) {
			s += p;
			ans.add(pq.peek());
			for (int i : e.get(pq.poll())) {
				if (--d[i] == 0) {
					pq.add(i);
				}
			}
		}

		System.out.println(ans.size() + " " + s);
		boolean blank = false;
		for (int ansi : ans) {
			if (blank) {
				System.out.print(' ');
			} else {
				blank = true;
			}
			System.out.print(ansi + 1);
		}
		System.out.println();
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//887327	15.09.09 16:36	watashi	367 	.JAVA	Accepted	294 ms	0 kb

