// SGU406. Goggle
/*
406. Goggle
Time limit per test: 2 second(s)
Memory limit: 65536 kilobytes
input: standard
output: standard


Everybody knows search engine Goggle. But only advanced users know that it is possible to search number sequences. You can enter a set of numbers and the search engine will find all sequences which contain it. Goggle developers decided to improve the engine. New feature will help you if you know numbers which shouldn't be in the result. These numbers must be entered with the opposite sign. For example, if somebody enters "5 -3 6", the engine will find all the sequences which contain 5 and 6, but do not contain 3.

Help Goggle developers to implement the feature.

Input
The first line of the input will contain two integer numbers and (, ), where is the number of sequences in Goggle database and is the number of queries. Following lines describe sequences in the Goggle database. The first integer in each line is the length of the sequence (). Next numbers are the sequence elements. All of them are integers between 1 and 100, inclusive. Following lines describe queries. The first integer of each line is the numbers in query (). Next numbers are the sequence elements (). These numbers have different absolute values.

Output
For each query print  — the number of found sequences on a separate line. Each of the next lines should contain found sequence. The relative order of sequences should be preserved (in compliance with the input). The order of numbers in sequences should not change (in compliance with the input). Write sequences in format as they were given in the input.

Example(s)

sample input

	

sample output

3 5
6 1 2 3 1 2 3
4 3 2 4 5
2 4 2
3 1 2 3
2 3 2
3 2 -1 3
2 4 -2
2 4 5

	

1
6 1 2 3 1 2 3
2
6 1 2 3 1 2 3
4 3 2 4 5
1
4 3 2 4 5
0
1
4 3 2 4 5
*/
import java.util.*;

public class Solution {
	static boolean ok(int[] s, int[] b) {
		for (int bi : b) {
			boolean flag = false;
			for (int si : s) {
				if (si == Math.abs(bi)) {
					flag = true;
					break;
				}
			}
			if (bi > 0 && !flag) {
				return false;
			} else if (bi < 0 && flag) {
				return false;
			}
		}
		return true;
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
		int[][] s = new int[n][];
		for (int i = 0; i < n; ++i) {
			int k = in.nextInt();
			s[i] = new int[k];
			for (int j = 0; j < k; ++j) {
				s[i][j] = in.nextInt();
			}
		}
		for (int i = 0; i < m; ++i) {
			int k = in.nextInt();
			int[] b = new int[k];
			for (int j = 0; j < k; ++j) {
				b[j] = in.nextInt();
			}
			ArrayList<Integer> ans = new ArrayList<Integer>();
			for (int j = 0; j < n; ++j) {
				if (ok(s[j], b)) {
					ans.add(j);
				}
			}
			System.out.println(ans.size());
			for (int ansi : ans) {
				System.out.print(s[ansi].length);
				for (int si : s[ansi]) {
					System.out.print(" " + si);
				}
				System.out.println();
			}
		}
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//873638	04.08.09 10:29	watashi	406 	.JAVA	Accepted	30 ms	2422 kb

