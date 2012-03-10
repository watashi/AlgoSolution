// SGU523. Elevator

import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int f = in.nextInt();
		int[] e = new int[n];
		boolean[] b = new boolean[128];
		for (int i = 0; i < n; ++i) {
			e[i] = in.nextInt();
			b[e[i]] = true;
		}

		boolean blank = false;
		for (int i = 0; i < n; ++i) {
			if (!b[e[i]]) {
				continue;
			}
			int d = (e[i] > f ? 1 : -1);
			do {
				f += d;
				if (b[f]) {
					if (blank) {
						System.out.print(' ');
					} else {
						blank = true;
					}
					System.out.print(f);
					b[f] = false;
				}
			} while (f != e[i]);
		}
		System.out.println();
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//1112428	12.11.10 11:56	watashi	523 	.JAVA	Accepted 	64 ms	0 kb
