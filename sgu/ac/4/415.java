// SGU415. Necessary Coins
/*
415. Necessary Coins
Time limit per test: 4 second(s)
Memory limit: 262144 kilobytes
input: standard
output: standard


Vasya has been on vacation on Mars. He's a big fan of foreign coins, and thus has collected exactly one martian coin of each denomination, for a total of coins: martian dollars, martian dollars, etc, martian dollars. Unfortunately, he couldn't stand ordering the Pan Galactic Gargle Blaster at the Starport, and has to pay for it — it costs martian dollars. Vasya is wondering which of his coins are absolutely necessary to do so (i.e., he is forced to abandon them). They don't offer change at the Starport Mars.

Input
The input file contains two integer numbers and (, ), followed by distinct integer numbers ().

Output
On the first line of output, print the amount of denominations of coins that appear in any subset that sums to martian dollars. On the second line of output, print the denominations themselves, in any order, separated with single spaces. It is guaranteed that there exists at least one way to pay martian dollars with the given coins.

Example(s)

sample input

	

sample output

5 18
1 2 3 5 10

	

2
5 10
*/
import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int x = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; ++i) {
			a[i] = in.nextInt();
		}
		ArrayList<Integer> ans = new ArrayList<Integer>();
		for (int i = 0; i < n; ++i) {
			boolean[] b = new boolean[x + 1];
			b[0] = true;
			for (int j = 0; !b[x] && j < n; ++j) {
				if (i == j) {
					continue;
				}
				for (int k = x; k >= a[j]; --k) {
					b[k] |= b[k - a[j]];
				}
			}
			if (!b[x]) {
				ans.add(a[i]);
			}
		}
		System.out.println(ans.size());
		boolean blank = false;
		for (int ansi : ans) {
			if (blank) {
				System.out.print(' ');
			} else {
				blank = true;
			}
			System.out.print(ansi);
		}
		System.out.println();
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//874731	09.08.09 11:55	watashi	415 	.JAVA	Accepted	1486 ms	2986 kb
