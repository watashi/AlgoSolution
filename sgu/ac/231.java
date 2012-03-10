// SGU231. Prime Sum
/*
231. Prime Sum
time limit per test: 0.75 sec.
memory limit per test: 4096 KB
input: standard
output: standard



Find all pairs of prime numbers (A, B) such that A<=B and their sum is also a prime number and does not exceed N.

Input
The input of the problem consists of the only integer N (1<=N<=10^6).

Output
On the first line of the output file write the number of pairs meeting the requirements. Then output all pairs one per line (two primes separated by a space).

Sample test(s)

Input

4

Output

0
[submit]
[forum]
Author:	Antony Popovich
Resource:	Leningrad Regional School Programming Olympiad
Date:	January 9, 2004
*/

// => A = 2

/*
// Memory Limit Exceeded on test 6

import java.util.*;

class PrimeTable implements Iterable<Integer> {
	ArrayList<Integer> p;

	public PrimeTable(int maxn) {
		// [algo] Sieve of Eratosthenes
		boolean[] f = new boolean[maxn];
		
		p = new ArrayList<Integer>();
		for (int i = 2; i < f.length; ++i) {
			if (!f[i]) {
				p.add(i);
				for (int j = i + i; j < f.length; j += i) {
					f[j] = true;
				}
			}
		}
	}

	public int size() {
		return p.size();
	}

	public int get(int i) {
		return p.get(i);
	}

	public Iterator<Integer> iterator() {
		return p.iterator();
	}
}

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int pp = -1;
		int ans = 0;
		PrimeTable pTab = new PrimeTable(n + 1);
		for (int i = 1; i < pTab.size(); ++i) {
			if (pTab.get(i) == pTab.get(i - 1) + 2) {
				++ans;
			}
		}
		System.out.println(ans);
		for (int i = 1; i < pTab.size(); ++i) {
			if (pTab.get(i) == pTab.get(i - 1) + 2) {
				System.out.print("2 ");
				System.out.println(pTab.get(i - 1));
			}
		}
	}
}
*/

// Memory Limit Exceeded on test 6

import java.io.*;
import java.util.*;

public class Solution {
	public static void main(String[] args) throws IOException {
		int c;
		int n = 0;
		while (Character.isDigit(c = System.in.read())) {
			n *= 10;
			n += Character.digit(c, 10);
		}
//		Scanner in = new Scanner(System.in);
//		int n = in.nextInt();
//		ArrayList<Integer> ans = new ArrayList<Integer>();
		int ans = 0;
		boolean[] f = new boolean[n + 1];
		f[0] = f[1] = true;
		for (int i = 2; i < f.length; ++i) {
			if (!f[i]) {
				if (!f[i - 2]) {
					++ans;
				}
				for (int j = i + i; j < f.length; j += i) {
					f[j] = true;
				}
			}
		}
		System.out.println(ans);
		for (int i = 2; i < f.length; ++i) {
			if (!f[i] && !f[i - 2]) {
				System.out.print("2 ");
				System.out.println(i - 2);
			}
		}
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//866760	04.07.09 21:12	watashi	231 	.JAVA	Accepted	163 ms	2826 kb


