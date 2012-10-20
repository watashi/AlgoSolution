// SGU223. Little Kings
/*
223. Little Kings
time limit per test: 2 sec.
memory limit per test: 65536 KB
input: standard
output: standard



After solving nice problems about bishops and rooks, Petya decided that he would like to learn to play chess. He started to learn the rules and found out that the most important piece in the game is the king.

The king can move to any adjacent cell (there are up to eight such cells). Thus, two kings are in the attacking position, if they are located on the adjacent cells.

Of course, the first thing Petya wants to know is the number of ways one can position k kings on a chessboard of size n × n so that no two of them are in the attacking position. Help him!

Input

The input file contains two integers n (1 ≤ n ≤ 10) and k (0 ≤ k ≤ n2).

Output

Print a line containing the total number of ways one can put the given number of kings on a chessboard of the given size so that no two of them are in attacking positions.

Sample test(s)

Input

Test #1

3 2

Test #2

4 4

Output

Test #1

16

Test #2

79
[submit]
[forum]
Author:	Andrew Stankevich
Resource:	Little Chess Pieces Series, SPb IFMO 2003-2004 Authumn Training Sessions
Date:	2003-10-04 
*/
import java.math.*;
import java.util.*;

class OneBitCount {
	int[] a;

	public OneBitCount(int n) {
		a = new int[n];
		a[0] = 0;
		for (int i = 1; i < a.length; ++i) {
			a[i] = a[i >> 1] + (i & 1);
		}
	}

	public int get(int i) {
		return a[i];
	}
}

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int k = in.nextInt();
		int mm = 1 << n;
		ArrayList<Integer> mask = new ArrayList<Integer>();
		for (int i = 0; i < mm; ++i) {
			if ((i & (i << 1)) == 0 && (i & (i >> 1)) == 0) {
				mask.add(i);
			}
		}
		ArrayList<ArrayList<Integer> > e = new ArrayList<ArrayList<Integer> >(mask.size());
		for (int i = 0; i < mask.size(); ++i) {
			ArrayList<Integer> ei = new ArrayList<Integer>();
			for (int j = 0; j < mask.size(); ++j) {
				if ((mask.get(i) & mask.get(j)) == 0 &&
					(mask.get(i) & (mask.get(j) << 1)) == 0 &&
					(mask.get(i) & (mask.get(j) >> 1)) == 0) {
					ei.add(j);
				}
			}
			e.add(ei);
		}
		OneBitCount obc = new OneBitCount(mm);
		BigInteger[][] cur = new BigInteger[k + 1][mask.size()];
		cur[0][0] = BigInteger.ONE;
		for (int i = 0; i < n; ++i) {
			BigInteger[][] pre = cur;
			cur = new BigInteger[k + 1][mask.size()];
			for (int j = 0; j <= k; ++j) {
				for (int mi = 0; mi < mask.size(); ++mi) {
					if (pre[j][mi] == null) {
						continue;
					}
					for (int mj : e.get(mi)) {
						int jj = j + obc.get(mask.get(mj));
						if (jj > k) {
							continue;
						} else if (cur[jj][mj] == null) {
							cur[jj][mj] = pre[j][mi];
						} else {
							cur[jj][mj] = cur[jj][mj].add(pre[j][mi]);
						}
					}
				}
			}
		}
		BigInteger ans = BigInteger.ZERO;
		for (BigInteger curi : cur[k]) {
			if (curi != null) {
				ans = ans.add(curi);
			}
		}
		System.out.println(ans);
	}
}

// long就够了

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//874619	08.08.09 20:29	watashi	223 	.JAVA	Accepted	74 ms	4506 kb


