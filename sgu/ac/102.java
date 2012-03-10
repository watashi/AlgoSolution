// SGU102. Coprimes
/*
102. Coprimes

time limit per test: 0.50 sec.
memory limit per test: 4096 KB

For given integer N (1£N£104) find amout of positive numbers not greater than N that coprime with N. Let us call two positive integers (say, A and B, for example) coprime if (and only if) their greatest common divisor is 1. (i.e. A and B are coprime iff gcd(A,B) = 1).

Input

Input file contains integer N.

Output

Write answer in output file.

Sample Input

9

Sample Output

6

*/

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
	// [algo] Euler's totient function
	static int phi(int n, PrimeTable pTab) {
		if (pTab == null) {
			pTab = new PrimeTable(n + 1);
		}
		int ret = 1;
		for (int p : pTab) {
			if (n % p == 0) {
				ret *= p - 1;
				n /= p;
				while (n % p == 0) {
					ret *= p;
					n /= p;
				}
			}
		}
		return ret;
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		System.out.println(phi(n, null));
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//865687	30.06.09 05:58	watashi	102 	.JAVA	Accepted	6 ms	1958 kb

