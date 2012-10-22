// SGU199. Beautiful People
/*
199. Beautiful People
time limit per test: 2 sec.
memory limit per test: 65536 KB
input: standard
output: standard



The most prestigious sports club in one city has exactly N members. Each of its members is strong and beautiful. More precisely, i-th member of this club (members being numbered by the time they entered the club) has strength Si and beauty Bi . Since this is a very prestigious club, its members are very rich and therefore extraordinary people, so they often extremely hate each other. Strictly speaking, i-th member of the club Mr X hates j-th member of the club Mr Y if Si ≤ Sj and Bi ≥ Bj or if Si ≥ Sj and Bi ≤ Bj (if both properties of Mr X are greater then corresponding properties of Mr Y, he doesn't even notice him, on the other hand, if both of his properties are less, he respects Mr Y very much).

To celebrate a new 2003 year, the administration of the club is planning to organize a party. However they are afraid that if two people who hate each other would simultaneouly attend the party, after a drink or two they would start a fight. So no two people who hate each other should be invited. On the other hand, to keep the club presti≥ at the apropriate level, administration wants to invite as many people as possible.

Being the only one among administration who is not afraid of touching a computer, you are to write a program which would find out whom to invite to the party.

Input

The first line of the input file contains integer N — the number of members of the club. ( 2 ≤ N ≤ 100,000 ). Next N lines contain two numbers each — Si and Bi respectively ( 1 ≤ Si, Bi ≤ 109 ).

Output

On the first line of the output file print the maximum number of the people that can be invited to the party. On the second line output N integers — numbers of members to be invited in arbitrary order. If several solutions exist, output any one.

Sample test(s)

Input


4
1 1
1 2
2 1
2 2

Output


2
1 4
[submit]
[forum]
Author:	Andrew Stankevich
Resource:	Petrozavodsk Winter Trainings 2003
Date:	2003-02-06
*/
import java.io.*;
import java.util.*;

public class Solution {
	static int nextInt() throws IOException {
		int ch = -1;
		do {
			ch = System.in.read();
		} while (!Character.isDigit(ch));
		int ret = 0;
		while (Character.isDigit(ch)) {
			ret *= 10;
			ret += Character.digit(ch, 10);
			ch = System.in.read();
		}
		return ret;
	}

	static class IndexComparator implements Comparator<Integer> {
		private final long[] a;

		public IndexComparator(long[] a) {
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

	static int[] getIndex(long[] a) {
		Integer[] ind = new Integer[a.length];
		for (int i = 0; i < ind.length; ++i) {
			ind[i] = i;
		}
		Arrays.sort(ind, new IndexComparator(a));
		int[] ret = new int[a.length];
		for (int i = 0; i < ret.length; ++i) {
			ret[i] = ind[i];
		}
		return ret;
	}

	static final long MASK = (1L << 32) - 1L;

	public static void main(String[] args) throws IOException {
		int n = nextInt();
		long[] sb = new long[n];
		for (int i = 0; i < n; ++i) {
			sb[i] = nextInt();
			sb[i] = (sb[i] << 32) ^ (nextInt() ^ MASK);
		}
		int[] index = getIndex(sb);

		long[] b = new long[n];
		int[] s = new int[n];
		int[] p = new int[n];
		int m = 0, last = -1;
		for (int i : index) {
			int bi = (int)((sb[i] & MASK) ^ MASK);
			int x = Arrays.binarySearch(b, 0, m, bi);
			if (x < 0) {
				x = -1 - x;
			}
			b[x] = bi;
			s[x] = i;
			p[i] = (x == 0) ? -1 : s[x - 1];
			if (x == m) {
				++m;
				last = i;
			}
		}

		Stack<Integer> ans = new Stack<Integer>();
		while (last != -1) {
			ans.push(last);
			last = p[last];
		}
		System.out.println(ans.size());
		while (!ans.empty()) {
			System.out.print(ans.pop() + 1);
			System.out.print(ans.empty() ? '\n' : ' ');
		}
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//873955	05.08.09 11:01	watashi	199 	.JAVA	Accepted	900 ms	9470 kb
