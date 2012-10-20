// SGU200. Cracking RSA
/*
200. Cracking RSA
time limit per test: 2 sec.
memory limit per test: 65536 KB
input: standard
output: standard



The following problem is somehow related to the final stage of many famous integer factorization algorithms involved in some cryptoanalytical problems, for example cracking well-known RSA public key system.

The most powerful of such algorithms, so called quadratic sieve descendant algorithms, utilize the fact that if n = pq where p and q are large unknown primes needed to be found out, then if v2=w2 (mod n), u ≠ v (mod n) and u ≠ -v (mod n), then gcd(v + w, n) is a factor of n (either p or q).

Not getting further in the details of these algorithms, let us consider our problem. Given m integer numbers b1, b2, ..., bm such that all their prime factors are from the set of first t primes, the task is to find such a subset S of {1, 2, ..., m} that product of bi for i from S is a perfect square i.e. equal to u2 for some integer u. Given such S we get one pair for testing (product of S elements stands for v when w is known from other steps of algorithms which are of no interest to us, testing performed is checking whether pair is nontrivial, i.e. u ≠ v (mod n) and u ≠ -v (mod n)). Since we want to factor n with maximum possible probability, we would like to get as many such sets as possible. So the interesting problem could be to calculate the number of all such sets. This is exactly your task.

Input

The first line of the input file contains two integers t and m (1 ≤ t ≤ 100, 1 ≤ m ≤ 100). The second line of the input file contains m integer numbers bi such that all their prime factors are from t first primes (for example, if t = 3 all their prime factors are from the set {2, 3, 5}). 1 ≤ bi ≤ 109 for all i.

Output

Output the number of non-empty subsets of the given set {bi}, the product of numbers from which is a perfect square


Sample test(s)

Input


3 4
9 20 500 3

Output


3
[submit]
[forum]
Author:	Andrew Stankevich
Resource:	Petrozavodsk Winter Trainings 2003
Date:	2003-02-06 
*/
import java.math.*;
import java.util.*;

public class Solution {
	static int np;
	static int[] p;

	static {
		np = 0;
		p = new int[256];
		boolean[] m = new boolean[1024];
		for (int i = 2; i < m.length; ++i) {
			if (m[i]) {
				continue;
			}
			p[np++] = i;
			for (int j = i + i; j < m.length; j += i) {
				m[j] = true;
			}
		}
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		int m = in.nextInt();
		boolean[][] a = new boolean[t][m];
		for (int j = 0; j < m; ++j) {
			int b = in.nextInt();
			for (int i = 0; i < t; ++i) {
				int k = 0;
				while (b % p[i] == 0) {
					b /= p[i];
					++k;
				}
				a[i][j] = (k % 2 != 0);
			}
		}
		// elimination
		int r = 0, c = 0;
		boolean swap;
		while (r < t && c < m) {
			int rr = -1;
			for (int i = r; i < t; ++i) {
				if (a[i][c]) {
					rr = i;
					break;
				}
			}
			if (rr == -1) {
				++c;
			} else {
				for (int j = c; j < m; ++j) {
					swap = a[r][j];
					a[r][j] = a[rr][j];
					a[rr][j] = swap;
				}
				for (int i = r + 1; i < t; ++i) {
					if (a[i][c]) {
						a[i][c] = false;
						for (int j = c + 1; j < m; ++j) {
							if (a[r][j]) {
								a[i][j] = !a[i][j];
							}
						}
					}
				}
				++r;
			}
		}
		System.out.println(BigInteger.valueOf(2).pow(m - r).subtract(BigInteger.ONE));
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//873765	04.08.09 20:08	watashi	200 	.JAVA	Accepted	30 ms	2530 kb

