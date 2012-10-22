// SGU113. Nearly prime numbers
/*
113. Nearly prime numbers

time limit per test: 0.50 sec.
memory limit per test: 4096 KB

Nearly prime number is an integer positive number for which it is possible to find such primes P1 and P2 that given number is equal to P1*P2. There is given a sequence on N integer positive numbers, you are to write a program that prints “Yes” if given number is nearly prime and “No” otherwise.

Input

Input file consists of N+1 numbers. First is positive integer N (1£N£10). Next N numbers followed by N. Each number is not greater than 109. All numbers separated by whitespace(s).

Output

Write a line in output file for each number of given sequence. Write “Yes” in it if given number is nearly prime and “No” in other case.

Sample Input

1
6

Sample Output

Yes

Author	: Michael R. Mirzayanov
Resource	: PhTL #1 Training Contests
Date	: Fall 2001
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
	static PrimeTable pTab = new PrimeTable((int)Math.ceil(Math.sqrt(1e9)));

	static boolean isPrime (int n) {
		if (n < 2) {
			return false;
		} else {
			for (int p : pTab) {
				if (p * p > n) {
					return true;
				} else if (n % p == 0) {
					return false;
				}
			}
			return true;
		}
	}

	static boolean isNearlyPrime(int n) {
		for (int p : pTab) {
			if (p * p > n) {
				return false;
			} else if (n % p == 0) {
				return isPrime(n / p);
			}
		}
		return false;
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int re = in.nextInt();
		for (int ri = 1; ri <= re; ++ri) {
			int n = in.nextInt();
			System.out.println(isNearlyPrime(n) ? "Yes" : "No");
		}
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//866397	03.07.09 15:10	watashi	113 	.JAVA	Accepted	30 ms	2414 kb

