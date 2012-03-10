// SGU304. Mars Stomatology
import java.util.*;

public class Solution {
	static class IndexComparator implements Comparator<Integer> {
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

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
		int p = in.nextInt();
		int[] b = new int[m];
		for (int i = 0; i < m; ++i) {
			b[i] = in.nextInt();
		}
		int[] a = new int[n];
		int[] c = new int[n];
		for (int i = 0; i < n; ++i) {
			a[i] = in.nextInt();
			c[i] = in.nextInt();
		}
		
		ArrayList<ArrayList<Integer> > t = new ArrayList<ArrayList<Integer> >(m);
		for (int i = 0; i < m; ++i) {
			t.add(new ArrayList<Integer>());
		}
		for (int i = 0; i < n; ++i) {
			t.get(c[i] - 1).add(i);
		}
		IndexComparator ic = new IndexComparator(a);
		int[][] s = new int[m][];
		for (int i = 0; i < m; ++i) {
			Collections.sort(t.get(i), ic);
			s[i] = new int[t.get(i).size() + 1];
			s[i][0] = b[i];
			for (int j = 1; j < s[i].length; ++j) {
				s[i][j] = s[i][j - 1] + a[t.get(i).get(j - 1)];
			}
			s[i][0] = 0;
		}

		int[][] dp = new int[m + 1][n + 1];
		int[][] pre = new int[m + 1][n + 1];
		for (int i = 0; i <= m; ++i) {
			Arrays.fill(dp[i], Integer.MAX_VALUE / 2);
		}
		dp[0][0] = 0;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < s[i].length; ++j) {
				for (int k = j; k <= n; ++k) {
					if (dp[i + 1][k] > dp[i][k - j] + s[i][j]) {
						dp[i + 1][k] = dp[i][k - j] + s[i][j];
						pre[i + 1][k] = j;
					}
				}
			}
		}

		int k = -1;
		for (int j = n; j >= 0; --j) {
			if (dp[m][j] <= p) {
				k = j;
				break;
			}
		}
		System.out.println(k);
		ArrayList<Integer> ans = new ArrayList<Integer>();
		for (int i = m - 1; i >= 0; --i) {
			for (int j = 0; j < pre[i + 1][k]; ++j) {
				ans.add(t.get(i).get(j));
			}
			k -= pre[i + 1][k];
		}
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

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status:  	Time:  	Memory:
//1081749	27.09.10 18:20	watashi	304 	.JAVA	Accepted 	115 ms	0 kb

