// SGU179. Brackets light
/*
179. Brackets light
time limit per test: 0.50 sec.
memory limit per test: 131072 KB
input: standard
output: standard



There is a correct brackets sequence. It's length doesn't exceed 10000 symbols.
Your task is to find next (in lexicographic order) correct brackets sequence with the same length. You may assume that '(' < ')'.

Input
The first line of the input contains correct brackets sequence. There are only '(' and ')' symbols in the input.

Output
Write sought sequence in the single line of the output or 'No solution' if solution doesn't exist.

Sample test(s)

Input

(())()

Output

()(())
[submit]
[forum]
Author:	Stanislav Angelyuk
Resource:	Saratov ST team Spring Contest #1
Date:	18.05.2003
*/
import java.util.*;

public class Solution {
	static String next(String str) {
		char[] s = str.toCharArray();
		int l = 0, r = 0, p = s.length - 1;
		while (p >= 0) {
			if (s[p] == '(') {
				if (l + 1 <= r - 1) {
					break;
				}
				++l;
			} else if (s[p] == ')') {
				++r;
			}
			--p;
		}
		if (p < 0) {
			return null;
		} else {
			++l;
			--r;
			s[p++] = ')';
		}
		Arrays.fill(s, p, p + l, '(');
		Arrays.fill(s, p + l, s.length, ')');
		return new String(s);
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String cur = in.next();
		String ans = next(cur);
		System.out.println(ans == null ? "No solution" : ans);
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//873659	04.08.09 12:55	watashi	179 	.JAVA	Accepted	19 ms	2574 kb
//873657	04.08.09 12:42	watashi	179 	.JAVA	Wrong answer on test 3	0 ms	2142 kb
//873656	04.08.09 12:24	watashi	179 	.JAVA	Wrong answer on test 5	6 ms	2142 kb
