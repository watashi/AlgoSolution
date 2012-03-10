// SGU116. Index of super-prime
/*
116. Index of super-prime

time limit per test: 0.50 sec.
memory limit per test: 4096 KB

Let P1, P2, … ,PN, … be a sequence of prime numbers. Super-prime number is such a prime number that its current number in prime numbers sequence is a prime number too. For example, 3 is a super-prime number, but 7 is not. Index of super-prime for number is 0 iff it is impossible to present it as a sum of few (maybe one) super-prime numbers, and if such presentation exists, index is equal to minimal number of items in such presentation. Your task is to find index of super-prime for given numbers and find optimal presentation as a sum of super-primes.

Input

There is a positive integer number in input. Number is not more than 10000.

Output

Write index I for given number as the first number in line. Write I super-primes numbers that are items in optimal presentation for given number. Write these I numbers in order of non-increasing.

Sample Input

6

Sample Output

2
3 3

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

class SuperPrimeTable implements Iterable<Integer> {
	ArrayList<Integer> sp;

	public SuperPrimeTable(int maxn) {
		PrimeTable pTab = new PrimeTable(maxn);
		sp = new ArrayList<Integer>();
		try {
			for (int p : pTab) {
				sp.add(pTab.get(p - 1));
			}
		} catch (IndexOutOfBoundsException e) {
		}
	}

	public int size() {
		return sp.size();
	}

	public int get(int i) {
		return sp.get(i);
	}

	public Iterator<Integer> iterator() {
		return sp.iterator();
	}
}

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		SuperPrimeTable spTab = new SuperPrimeTable(n + 1);
		int[] dp = new int[n + 1];
		int[] pd = new int[n + 1];
		Arrays.fill(dp, Integer.MAX_VALUE);
		dp[0] = 0;
		for (int i = 0; i < dp.length; ++i) {
			if (dp[i] == Integer.MAX_VALUE) {
				dp[i] = 0;
				continue;
			}
			try {
				for (int sp : spTab) {
					if (dp[i + sp] > dp[i] + 1) {
						dp[i + sp] = dp[i] + 1;
						pd[i + sp] = sp;
					}
				}
			} catch (ArrayIndexOutOfBoundsException e) {
			}
		}
		if (dp[n] == 0) {
			System.out.println(0);
		} else {
			System.out.println(dp[n]);
			while (n > 0) {
				System.out.print(pd[n]);
				n -= pd[n];
				System.out.print(n == 0 ? '\n' : ' ');
			}
		}
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//866405	03.07.09 16:21	watashi	116 	.JAVA	Accepted	139 ms	3230 kb


