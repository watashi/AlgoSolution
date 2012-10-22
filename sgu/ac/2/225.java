// SGU225. Little Knights
/*
225. Little Knights
time limit per test: 0.50 sec.
memory limit per test: 65536 KB
input: standard
output: standard



	
Oh no, here it comes again
Can't remember when we came so close to love before
Hold on, good things never last
Nothing's in the past, it always seems to come again
Again and again and again

...

Bloodied angels fast descending
Moving on a never-bending light
Phantom figures free forever
Out of shadows, shining ever-bright

Neon Knights!

Black Sabbath, "Neon Knights"


The knight is the piece in the game of chess. The knight moves the following way: first he moves 2 squares in horizontal or vertical direction and then 1 square in the perpendicular direction. Figures on the way of knight do not interfere with its movement. Two knights are in the attacking position if they can move to each other's cells.

Input

The input file contains two integers n (1 ≤ n ≤ 10) and k (0 ≤ k ≤ n2).

Output

Print a line containing the total number of ways one can put k knights on a chessboard of size n × n so that no two of them are in the attacking positions.

Sample test(s)

Input

Test #1

3 2

Test #2

4 4

Output

Test #1

28

Test #2

412
[submit]
[forum]
Author:	Andrew Stankevich
Resource:	Little Chess Pieces Series, SPb IFMO 2003-2004 Authumn Training Sessions
Date:	2003-10-11
*/

/*
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
		OneBitCount obc = new OneBitCount(1 << 10);
		for (int n = 1; n <= 10; ++n) {
			int m = 1 << n;
			ArrayList<Integer> mask = new ArrayList<Integer>();
			ArrayList<ArrayList<Integer> > x = new ArrayList<ArrayList<Integer> >(m);
			for (int i = 0; i < m; ++i) {
				ArrayList<Integer> xi = new ArrayList<Integer>();
				for (int j = 0; j < m; ++j) {
					if ((i & (j << 2)) == 0 && (i & (j >> 2)) == 0) {
						xi.add(j);
						mask.add((i << n) ^ j);
					}
				}
				x.add(xi);
			}
			ArrayList<ArrayList<Integer> > e = new ArrayList<ArrayList<Integer> >(mask.size());
			for (int maski : mask) {
				ArrayList<Integer> ei = new ArrayList<Integer>();
				int i = maski >> n;
				int j = maski & (m - 1);
				for (int k : x.get(j)) {
					if ((i & (k << 1)) == 0 && (i & (k >> 1)) == 0) {
						ei.add(Collections.binarySearch(mask, (j << n) ^ k));
					}
				}
				e.add(ei);
			}

			long[][] cur = new long[n * n + 1][mask.size()];
			cur[0][0] = 1L;
			for (int i = 0; i < n; ++i) {
				long[][] pre = cur;
				cur = new long[n * n + 1][mask.size()];
				for (int j = 0; j < cur.length; ++j) {
					for (int mi = 0; mi < mask.size(); ++mi) {
						if (pre[j][mi] == 0L) {
							continue;
						}
						for (int mj : e.get(mi)) {
							cur[j + obc.get(mask.get(mj) & (m - 1))][mj] += pre[j][mi];
						}
					}
				}
			}
			long[] ans = new long[n * n + 1];
			for (int i = 0; i < cur.length; ++i) {
				for (long curi : cur[i]) {
					ans[i] += curi;
				}
			}
			System.out.print("new long[]{");
			for (long ansi : ans) {
				System.out.print(ansi + "L, ");
			}
			System.out.println("},");
		}
	}
}
*/

/*
watashi@watashi-pc:~/ac/sgu$ time java -Xms256m -Xmx1024m Solution 
new long[]{1L, 1L, },
new long[]{1L, 4L, 6L, 4L, 1L, },
new long[]{1L, 9L, 28L, 36L, 18L, 2L, 0L, 0L, 0L, 0L, },
new long[]{1L, 16L, 96L, 276L, 412L, 340L, 170L, 48L, 6L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, },
new long[]{1L, 25L, 252L, 1360L, 4436L, 9386L, 13384L, 12996L, 8526L, 3679L, 994L, 158L, 15L, 1L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, },
new long[]{1L, 36L, 550L, 4752L, 26133L, 97580L, 257318L, 491140L, 688946L, 716804L, 556274L, 323476L, 141969L, 47684L, 12488L, 2560L, 393L, 40L, 2L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, },
new long[]{1L, 49L, 1056L, 13340L, 111066L, 649476L, 2774728L, 8891854L, 21773953L, 41310504L, 61412928L, 72304650L, 68233368L, 52400729L, 33376132L, 18001362L, 8363763L, 3374053L, 1178064L, 351592L, 87913L, 17910L, 2858L, 336L, 26L, 1L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, },
new long[]{1L, 64L, 1848L, 32084L, 376560L, 3184708L, 20202298L, 98796304L, 379978716L, 1167053680L, 2897726604L, 5876860140L, 9825415557L, 13660238780L, 15932672964L, 15737653004L, 13304668385L, 9742722088L, 6260518246L, 3574590840L, 1830733371L, 844203844L, 349524138L, 128874944L, 41833846L, 11792736L, 2840224L, 572432L, 93840L, 12004L, 1122L, 68L, 2L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, },
new long[]{1L, 81L, 3016L, 68796L, 1080942L, 12472084L, 110018552L, 762775440L, 4241252429L, 19206532478L, 71707869632L, 222946143752L, 582155146204L, 1286247689414L, 2421159140764L, 3908273840366L, 5446391581062L, 6599640204257L, 7010436668992L, 6589213734278L, 5537849837497L, 4207779106033L, 2920161348852L, 1865346129716L, 1101125592067L, 600730512987L, 302041066250L, 139345014744L, 58692638521L, 22451454400L, 7755194754L, 2403337080L, 663103709L, 161373907L, 34237130L, 6238414L, 957145L, 120334L, 11914L, 872L, 42L, 1L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, },
new long[]{1L, 100L, 4662L, 135040L, 2732909L, 41199404L, 481719518L, 4491423916L, 34075586550L, 213628255072L, 1120204619108L, 4961681221524L, 18715619717199L, 60541371615660L, 168976761361446L, 409191804533576L, 864172675710439L, 1599730843649564L, 2609262108838924L, 3770687313420780L, 4857550050070531L, 5616928666465104L, 5874943705896600L, 5604501518609804L, 4917655076255841L, 3999855946779732L, 3034690618677388L, 2156485957257040L, 1437827591264317L, 899278231344296L, 526753407546620L, 288274613750624L, 146990556682887L, 69626509814580L, 30542906352994L, 12366448408056L, 4604442057431L, 1569983914256L, 487876545370L, 137395261280L, 34831261750L, 7884855000L, 1578162590L, 275861904L, 41455966L, 5246412L, 543534L, 44244L, 2652L, 104L, 2L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, },

real	0m17.469s
user	0m13.421s
sys	0m0.584s
*/

import java.util.*;

public class Solution {
	static long[][] ans = new long[][]{
			new long[]{0L, },
			new long[]{1L, 1L, },
			new long[]{1L, 4L, 6L, 4L, 1L, },
			new long[]{1L, 9L, 28L, 36L, 18L, 2L, 0L, 0L, 0L, 0L, },
			new long[]{1L, 16L, 96L, 276L, 412L, 340L, 170L, 48L, 6L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, },
			new long[]{1L, 25L, 252L, 1360L, 4436L, 9386L, 13384L, 12996L, 8526L, 3679L, 994L, 158L, 15L, 1L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, },
			new long[]{1L, 36L, 550L, 4752L, 26133L, 97580L, 257318L, 491140L, 688946L, 716804L, 556274L, 323476L, 141969L, 47684L, 12488L, 2560L, 393L, 40L, 2L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, },
			new long[]{1L, 49L, 1056L, 13340L, 111066L, 649476L, 2774728L, 8891854L, 21773953L, 41310504L, 61412928L, 72304650L, 68233368L, 52400729L, 33376132L, 18001362L, 8363763L, 3374053L, 1178064L, 351592L, 87913L, 17910L, 2858L, 336L, 26L, 1L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, },
			new long[]{1L, 64L, 1848L, 32084L, 376560L, 3184708L, 20202298L, 98796304L, 379978716L, 1167053680L, 2897726604L, 5876860140L, 9825415557L, 13660238780L, 15932672964L, 15737653004L, 13304668385L, 9742722088L, 6260518246L, 3574590840L, 1830733371L, 844203844L, 349524138L, 128874944L, 41833846L, 11792736L, 2840224L, 572432L, 93840L, 12004L, 1122L, 68L, 2L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, },
			new long[]{1L, 81L, 3016L, 68796L, 1080942L, 12472084L, 110018552L, 762775440L, 4241252429L, 19206532478L, 71707869632L, 222946143752L, 582155146204L, 1286247689414L, 2421159140764L, 3908273840366L, 5446391581062L, 6599640204257L, 7010436668992L, 6589213734278L, 5537849837497L, 4207779106033L, 2920161348852L, 1865346129716L, 1101125592067L, 600730512987L, 302041066250L, 139345014744L, 58692638521L, 22451454400L, 7755194754L, 2403337080L, 663103709L, 161373907L, 34237130L, 6238414L, 957145L, 120334L, 11914L, 872L, 42L, 1L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, },
			new long[]{1L, 100L, 4662L, 135040L, 2732909L, 41199404L, 481719518L, 4491423916L, 34075586550L, 213628255072L, 1120204619108L, 4961681221524L, 18715619717199L, 60541371615660L, 168976761361446L, 409191804533576L, 864172675710439L, 1599730843649564L, 2609262108838924L, 3770687313420780L, 4857550050070531L, 5616928666465104L, 5874943705896600L, 5604501518609804L, 4917655076255841L, 3999855946779732L, 3034690618677388L, 2156485957257040L, 1437827591264317L, 899278231344296L, 526753407546620L, 288274613750624L, 146990556682887L, 69626509814580L, 30542906352994L, 12366448408056L, 4604442057431L, 1569983914256L, 487876545370L, 137395261280L, 34831261750L, 7884855000L, 1578162590L, 275861904L, 41455966L, 5246412L, 543534L, 44244L, 2652L, 104L, 2L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, },
	};

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int k = in.nextInt();
		System.out.println(ans[n][k]);
	}
};
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//874626	08.08.09 20:41	watashi	225 	.JAVA	Accepted	21 ms	2090 kb

