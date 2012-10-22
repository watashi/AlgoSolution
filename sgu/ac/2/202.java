// SGU202. The Towers of Hanoi Revisited
/*
202. The Towers of Hanoi Revisited
time limit per test: 2 sec.
memory limit per test: 65536 KB
input: standard
output: standard



You all must know the puzzle named ``The Towers of Hanoi''. The puzzle has three pegs and N discs of different radii, initially all disks are located on the first peg, ordered by their radii - the largest at the bottom, the mallest at the top. In a turn you may take the topmost disc from any peg and move it to another peg, the only rule says that you may not place the disc atop any smaller disk. The problem is to move all disks to the last peg making the smallest possible number of moves.

There is the legend that somewhere in Tibet there is a monastery where monks tirelessly move disks from peg to peg solving the puzzle for 64 discs. The legend says that when they finish, the end of the world would come.

Since it is well known that to solve the puzzle you need to make 2N-1 moves, a small calculation shows that the world seems to be a quite safe place for a while.

However, recent archeologists discoveries have shown that the things can be a bit worse. The manuscript found in Tibet mountains says that the puzzle the monks are solving has not 3 but M pegs. This is the problem, because when increasing the number of pegs, the number of moves needed to move all discs from the first peg to the last one following the rules described, decreases dramatically.

Calculate how many moves one needs to move N discs from the first peg to the last one when the puzzle has M pegs and provide the scenario for moving the discs.

Input
Input file contains N and M (1 ≤ N ≤ 64, 4 ≤ M ≤ 65).

Output
On the first line output L - the number of moves needed to solve the puzzle. Next L lines must contain the moves themselves. For each move print the line of the form

move <disc-radius> from <source-peg> to <target-peg>

if the disc is moved to the empty peg or

move <disc-radius> from <source-peg> to <target-peg> atop <target-top-disc-radius>

if the disc is moved atop some other disc.

Disc radii are integer numbers from 1 to N, pegs are numbered from 1 to M.

Sample test(s)

Input

5 4

Output

13
move 1 from 1 to 3
move 2 from 1 to 2
move 1 from 3 to 2 atop 2
move 3 from 1 to 4
move 4 from 1 to 3
move 3 from 4 to 3 atop 4
move 5 from 1 to 4
move 3 from 3 to 1
move 4 from 3 to 4 atop 5
move 3 from 1 to 4 atop 4
move 1 from 2 to 1
move 2 from 2 to 4 atop 3
move 1 from 1 to 4 atop 2
[submit]
[forum]
Author:	Andrew Stankevich
Resource:	Petrozavodsk Summer Trainings 2003
Date:	2003-08-23
*/
import java.util.*;

class Hanoi {
	static final int MAX = 66;
	static final long INF = 1234567890987654321L;
	static final long[][] dp;
	static final int[][] pre;

	static {
		dp = new long[MAX][MAX];
		pre = new int[MAX][MAX];
		for (int i = 0; i < MAX; ++i) {
			Arrays.fill(dp[i], INF);
		}
		for (int j = 1; j < MAX; ++j) {
			dp[1][j] = 1L;
		}
		for (int i = 2; i < MAX; ++i) {
			for (int j = 3; j < MAX; ++j) {
				for (int k = 1; k < i; ++k) {
					if (dp[i][j] > dp[i - k][j - 1] + 2 * dp[k][j]) {
						dp[i][j] = dp[i - k][j - 1] + 2 * dp[k][j];
						pre[i][j] = k;
					}
				}
			}
		}
	}

	private int n, m;
	private boolean[] b;
	private ArrayList<LinkedList<Integer> > s;

	public Hanoi(int n, int m) {
		// m >= 4
		this.n = n;
		this.m = m;
		b = new boolean[m];
		s = new ArrayList<LinkedList<Integer> >(m);
		for (int i = 0; i < m; ++i) {
			s.add(new LinkedList<Integer>());
		}
	}

	public long moves() {
		return dp[n][m];
	}

	private void move(int an, int am, int f, int t) {
		if (an == 1) {
			int e = s.get(f).pollFirst();
			String str = "move " + (e + 1) + " from " + (f + 1) + " to " + (t + 1);
			if (!s.get(t).isEmpty()) {
				str += " atop " + (s.get(t).getFirst() + 1);
			}
			System.out.println(str);
			s.get(t).addFirst(e);
		} else {
			int p = pre[an][am];
			int q = -1;
			for (int i = 0; i < b.length; ++i) {
				if (i != f && i != t && !b[i]) {
					q = i;
					break;
				}
			}			
			move(p, am, f, q);
			b[q] = true;
			move(an - p, am - 1, f, t);
			b[q] = false;
			move(p, am, q, t);
		}
	}

	public void print() {
		Arrays.fill(b, false);
		for (LinkedList list : s) {
			list.clear();
		}
		for (int i = 0; i < n; ++i) {
			s.get(0).addLast(i);
		}
		move(n, m, 0, m - 1);
	}
}

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
		Hanoi h = new Hanoi(n, m);
		System.out.println(h.moves());
		h.print();
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//873771	04.08.09 20:16	watashi	202 	.JAVA	Accepted	272 ms	3658 kb
