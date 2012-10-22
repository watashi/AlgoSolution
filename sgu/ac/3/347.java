// SGU347. Join the Strings
/*
347. Join the Strings
Time limit per test: 2 second(s)
Memory limit: 65536 kilobytes
input: standard
output: standard


His Royal Highness King of Berland Berl XV was a very wise man and had a very accomplished wife, who was aware of the fact, that prominent and outstanding personalities once having written down their names on the pages of glorious History, remain there forever. His Royal Highness King Berl XV experienced an intrinsic, lost nowadays, deep and sincere sense of respect and trust for his beloved spouse. So he decided to acquire a chronicler of his own. Due to the ambiguous nature of misunderstanding and the crying injustice of history to ambiguity, he decided to leave all his royal responsibilities aside and made up his royal mind to find the chronicler, who will make him famous, depicting all his heroic deeds truthfully and gloriously enough.

The King assembled the greatest minds of his kingdom at the Academic Chroniclers Meeting (ACM), as he named it, and decided to test their might. The task was to build the Smallest Lexicographical Concatenation (SLC) out of the given N strings. SLC of N strings s1,..., sN is the lexicographically smallest their concatenation si1 +... + siN, where i1,..., iN is a permutation of integers from 1 through N. It's a great privilege to be a chronicler, so don't miss your chance and don't screw it up! Make the king choose you!

Input
The first line of the input file contains a single integer N (1 ≤ N ≤ 100) indicating the number of strings. The following N lines contain N strings, one string per line. The length of each string is no more than 100 characters. Each string consists only of lowercase Latin letters. There are no any leading or trailing spaces.

Output
Print the SLC of the given N strings to the output file as a single line.

Example(s)

sample input

	

sample output

6
it
looks
like
an
easy
problem

	

aneasyitlikelooksproblem
*/
import java.util.*;

class StringComparator implements Comparator<String> {
	public int compare(String lhs, String rhs) {
		return (lhs + rhs).compareTo(rhs + lhs);
	}
}

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		String[] s = new String[n];
		for (int i = 0; i < n; ++i) {
			s[i] = in.next();
		}
		Arrays.sort(s, new StringComparator());
		for (String si : s) {
			System.out.print(si);
		}
		System.out.println();
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//874953	10.08.09 16:33	watashi	347 	.JAVA	Accepted	65 ms	3194 kb

