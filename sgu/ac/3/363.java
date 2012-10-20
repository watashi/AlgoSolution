// SGU363. Baggage Room
/*
363. Baggage Room
Time limit per test: 1 second(s)
Memory limit: 65536 kilobytes
input: standard
output: standard


Schoolboys Vasya and Pete travel a lot. They use baggage rooms really often. Baggage room has M windows, numbered 1 through M. When a lot of people come, there are big queues in front of windows. Newly come person stands in the queue with the least number of people. If there are several such queues than he or she chooses queue to the window with lowest number. When the queue is chosen, the decision will not further change. When next person comes to the window, he or she spends some time near the window to take or get his stuff, pay money, etc. (let's call it servicing time). This time is specific to each person and doesn't depend on the window. During this time the person is counted as standing in the queue. If new person come in the moment when one or several peoplehave just proceeded to their windows, he or she waits first until these people will leave their queues and then he or she chooses the queue to stand in. Vasya and Pet e wonder when each particular person will leave the queue. Please help them.

Input
The first line of the input file contains two integer numbers N, M (1 ≤ N ≤ 100; 1 ≤ M ≤ 100), where N - number of people, M - number of windows in the baggage room. Next N lines contain pairs of integer numbers ki, ti (1 ≤ ki ≤ 1000; 1 ≤ ti ≤ 100), where ki - time moment, when ith person came, ti - servicing time of ith person. Persons are listed in order of increase of ki.

Output
Print N lines. Print in the ith line two numbers - number of the queue, that would be chosen by ith person and moment of the time, when he or she will leave the queue.

Example(s)

sample input

	

sample output

5 2
1 2
3 4
4 1
5 2
6 1

	

1 3
1 7
2 5
2 7
1 8
*/
import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
		ArrayList<ArrayDeque<Integer> > a = new ArrayList<ArrayDeque<Integer> >(m);
		int[] t = new int[m];
		for (int i = 0; i < m; ++i) {
			a.add(new ArrayDeque<Integer>());
		}
		int[] x = new int[n], y = new int[n];

		for (int i = 0; i < n; ++i) {
			x[i] = in.nextInt();
			y[i] = in.nextInt();
			int k = 0;
			for (int j = 0; j < m; ++j) {
				while (!a.get(j).isEmpty() && t[j] + y[a.get(j).getFirst()] <= x[i]) {
					t[j] = (y[a.get(j).pollFirst()] += t[j]);
				}
				if (a.get(j).isEmpty()) {
					t[j] = Math.max(t[j], x[i]);
					k = j;
					break;
				} else if (a.get(j).size() < a.get(k).size()) {
					k = j;
				}
			}
			x[i] = k + 1;
			a.get(k).addLast(i);
		}
		for (int i = 0; i < m; ++i) {
			while (!a.get(i).isEmpty()) {
				t[i] = (y[a.get(i).pollFirst()] += t[i]);
			}
		}

		for (int i = 0; i < n; ++i) {
			System.out.println(x[i] + " " + y[i]);
		}
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//887547	16.09.09 09:32	watashi	363 	.JAVA	Accepted	69 ms	0 kb

