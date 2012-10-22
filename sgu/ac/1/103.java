// SGU103. Traffic Lights
/*
103. Traffic Lights
Time limit per test: 0.50 second(s)
Memory limit: 4096 kilobytes
input: standard
output: standard


# In the city of Dingilville the traffic is arranged in an unusual way. There are junctions and roads connecting the junctions. There is at most one road between any two different junctions. There is no road connecting a junction to itself. Travel time for a road is the same for both directions. At every junction there is a single traffic light that is either blue or purple at any moment. The color of each light alternates periodically: blue for certain duration and then purple for another duration. Traffic is permitted to travel down the road between any two junctions, if and only if the lights at both junctions are the same color at the moment of departing from one junction for the other. If a vehicle arrives at a junction just at the moment the lights switch it must consider the new colors of lights. Vehicles are allowed to wait at the junctions. You are given the city map which shows: the travel times for all roads (integers)
# the durations of the two colors at each junction (integers)
# and the initial color of the light and the remaining time (integer) for this color to change at each junction.

Your task is to find a path which takes the minimum time from a given source junction to a given destination junction for a vehicle when the traffic starts. In case more than one such path exists you are required to report only one of them.

Input
The first line contains two numbers: The id-number of the source junction and the id-number of the destination junction. The second line contains two numbers: N, M. The following N lines contain information on N junctions. The (i+2)'th line of the input file holds information about the junction i : Ci, riC, tiB, tiP where Ci is either B for blue or P for purple, indicating the initial color of the light at the junction i. Finally, the next M lines contain information on M roads. Each line is of the form: i, j, lij where i and j are the id-numbers of the junctions which are connected by this road. 2 ≤ N ≤ 300 where N is the number of junctions. The junctions are identified by integers 1 through N. These numbers are called id-numbers. 1 ≤ M ≤ 14000 where M is the number of roads. 1 ≤ lij ≤ 100 where lij is the time required to move from junction i to j using the road that connects i and j. 1 ≤ tiC ≤ 100 where tiC is the duration of the color c for the light at the junction i. The index c is either 'B' for blue or 'P' for purple. 1 ≤ riC ≤ tiC where riC is the remaining time for the initial color c at junction i.

Output
If a path exists:
# The first line will contain the time taken by a minimum-time path from the source junction to the destination junction.
# Second line will contain the list of junctions that construct the minimum-time path you have found. You have to write the junctions to the output file in the order of travelling. Therefore the first integer in this line must be the id-number of the source junction and the last one the id-number of the destination junction.

If a path does not exist:
# A single line containing only the integer 0.

Example(s)

sample input

	

sample output

1 4
4 5
B 2 16 99
P 6 32 13
P 2 87 4
P 38 96 49
1 2 4
1 3 40
2 3 75
2 4 76
3 4 77

	

127
1 2 4




Online Contester Team © 2002 - 2009. All rights reserved.
*/
import java.util.*;

public class Solution {
	static int[] r;
	static int[] tb;
	static int[] tp;
	static int[] ts;

	// [core]
	static int getTime(int a, int b, int c) {
		int ra = (r[a] + c) % ts[a];
		int rb = (r[b] + c) % ts[b];
		if (!((ra < tb[a]) ^ (rb < tb[b]))) {
			return c;
		} else if (!(ra < tb[a])) {
			return getTime(b, a, c);
		} else if (tb[a] - ra != ts[b] - rb) {
			return c + Math.min(tb[a] - ra, ts[b] - rb);
		} else if (tp[a] != tb[b]) {
			return c + (tb[a] - ra) + Math.min(tp[a], tb[b]);
		} else if (tb[a] != tp[b]) {
			return c + (ts[a] - ra) + Math.min(tb[a], tp[b]);
		} else {
			return -1;
		}
	}

	public static void main(String[] args) {
		/* input */
		Scanner in = new Scanner(System.in);
		int s = in.nextInt() - 1;
		int t = in.nextInt() - 1;
		int n = in.nextInt();
		int m = in.nextInt();
		r = new int[n];
		tb = new int[n];
		tp = new int[n];
		ts = new int[n];
		for (int i = 0; i < n; ++i) {
			String c = in.next();
			r[i] = in.nextInt();
			tb[i] = in.nextInt();
			tp[i] = in.nextInt();
			ts[i] = tb[i] + tp[i];
			if (c.equals("B")) {
				r[i] = tb[i] - r[i];
			} else if (c.equals("P")) {
				r[i] = tb[i] + tp[i] - r[i];
			}
		}
		int[][] l = new int[n][n];
		for (int k = 0; k < m; ++k) {
			int i = in.nextInt() - 1;
			int j = in.nextInt() - 1;
			l[i][j] = l[j][i] = in.nextInt();
		}
		/* solve */
		boolean[] mark = new boolean[n];
		int[] mind = new int[n];
		int[] prev = new int[n];
		Arrays.fill(mind, Integer.MAX_VALUE);
		mind[s] = 0;
		prev[s] = -1;
		for (int i = 0; i < n; ++i) {
			int k = -1;
			for (int j = 0; j < n; ++j) {
				if (!mark[j] && (k == -1 || mind[j] < mind[k])) {
					k = j;
				}
			}
			mark[k] = true;
			if (mind[k] == Integer.MAX_VALUE) {
				continue;
			}
			for (int j = 0; j < n; ++j) {
				if (l[k][j] == 0) {
					continue;
				}
				int at = getTime(k, j, mind[k]);
				if (at != -1 && at + l[k][j] < mind[j]) {
					mind[j] = at + l[k][j];
					prev[j] = k;
				}
			}
		}
		/* output */
		if (mind[t] == Integer.MAX_VALUE) {
			System.out.println(0);
		} else {
			System.out.println(mind[t]);
			Stack<Integer> stack = new Stack<Integer>();
			int k = t;
			do {
				stack.push(k + 1);
				k = prev[k];
			} while (k != -1);
			do {
				System.out.print(stack.pop());
				System.out.print(stack.isEmpty() ? '\n' : ' ');
			} while (!stack.isEmpty());
		}
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//866943	05.07.09 14:35	watashi	103 	.JAVA	Accepted	236 ms	3838 kb


