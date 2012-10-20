// SGU370. Rifleman
/*
370. Rifleman
Time limit per test: 4 second(s)
Memory limit: 65536 kilobytes
input: standard
output: standard


Petya is a rifleman. He is located in the leftmost bottom cell of the rectangular field N×M, all other cells of the field are occupied by enemies. Petya and his enemies are points and they are located in the centers of the corresponding cells. Petya has a power supersecret weapon Ber-9875 which destroys all enemies along a straight line. Your task is to calculate the minimum number of shots to do this.

Input
The first line of the input contains two integers N and M (1≤ N, M≤ 106).

Output
Output file must contain the minimum number of shots.

Example(s)

sample input

	

sample output

3 4

	

7


sample input

	

sample output

2 10

	

11
*/
import java.util.*;

public class Solution {
	static long gao(int p, ArrayList<Integer> a, long s) {
		if (p == a.size() || s == 0) {
			return s;
		} else {
			return gao(p + 1, a, s) + gao(p + 1, a, -s / a.get(p));
		}
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
		int[] a = new int[n];
		long ans = 0;
		if (m > 1) {
			++ans;
		}
		if (n > 1) {
			ans += m;
		}
		--m;
		for (int i = 2; i < n; ++i) {
			if (a[i] == 0) {
				for (int j = i; j < n; j += i) {
					a[j] = i;
				}
			}
			ArrayList<Integer> b = new ArrayList<Integer>();
			int x = i, p = a[i];
			while (x > 1) {
				b.add(p);
				do {
					x /= p;
				} while (a[x] == p);
				p = a[x];
			}
			ans += gao(0, b, m);
		}
		System.out.println(ans);
	}
}

/*
WA2:
1 1
0
*/

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//887323	15.09.09 16:10	watashi	370 	.JAVA	Accepted	1419 ms	0 kb


