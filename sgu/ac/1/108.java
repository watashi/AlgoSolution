// SGU108. Self-numbers 2
/*
108. Self-numbers 2

time limit per test: 2.50 sec.
memory limit per test: 4096 KB

In 1949 the Indian mathematician D.R. Kaprekar discovered a class of numbers called self-numbers. For any positive integer n, define d(n) to be n plus the sum of the digits of n. (The d stands for digitadition, a term coined by Kaprekar.) For example, d(75) = 75 + 7 + 5 = 87. Given any positive integer n as a starting point, you can construct the infinite increasing sequence of integers n, d(n), d(d(n)), d(d(d(n))), .... For example, if you start with 33, the next number is 33 + 3 + 3 = 39, the next is 39 + 3 + 9 = 51, the next is 51 + 5 + 1 = 57, and so you generate the sequence 33, 39, 51, 57, 69, 84, 96, 111, 114, 120, 123, 129, 141, ... The number n is called a generator of d(n). In the sequence above, 33 is a generator of 39, 39 is a generator of 51, 51 is a generator of 57, and so on. Some numbers have more than one generator: for example, 101 has two generators, 91 and 100. A number with no generators is a self-number. Let the a[i] will be i-th self-number. There are thirteen self-numbers a[1]..a[13] less than 100: 1, 3, 5, 7, 9, 20, 31, 42, 53, 64, 75, 86, and 97. (the first self-number is a[1]=1, the second is a[2] = 3, :, the thirteen is a[13]=97);

Input

Input contains integer numbers N, K, s1...sk. (1<=N<=107, 1<=K<=5000) delimited by spaces and line breaks.

Output

At first line you must output one number - the quantity of self-numbers in interval [1..N]. Second line must contain K numbers - a[s1]..a[sk], delimited by spaces. It`s a gaurantee, that all self-numbers a[s1]..a[sk] are in interval [1..N]. (for example if N = 100, sk can be 1..13 and cannot be 14, because 14-th self-number a[14] = 108, 108 > 100)

Sample Input

100 10
1 2 3 4 5 6 7 11 12 13

Sample Output

13
1 3 5 7 9 20 31 75 86 97
*/

import java.io.*;
import java.util.*;

public class Solution {
	static final int SWAPSIZE = 64;
	static final int BLOCKSIZE = 2 * 1024 * 1024;

	static class IndexComparator implements Comparator<Integer> {
		private final int[] a;

		public IndexComparator(int[] a) {
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

	static int[] getIndex(int[] a) {
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

	public static void main(String[] args) throws IOException {
	//	BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	//	String[] inputs = in.readLine().split(" ");
	//	int n = Integer.parseInt(inputs[0]);
	//	int k = Integer.parseInt(inputs[1]);
	//	String[] as = in.readLine().split(" ");
		int n = nextInt();
		int k = nextInt();
		int[] a = new int[k];
		for (int i = 0; i < a.length; ++i) {
			a[i] = nextInt();
		}
		int[] b = getIndex(a);

		int cur = 0, cnt = 0, off = 0;
		int d = 10, t = 0;
		boolean[] f = new boolean[BLOCKSIZE + SWAPSIZE];
GAO:
		while (true) {
			for (int i = 0; i < SWAPSIZE; ++i) {
				f[i] = f[BLOCKSIZE + i];
			}
			Arrays.fill(f, SWAPSIZE, f.length, false);
			for (int i = 0; i < BLOCKSIZE; ++i) {
				int s = off + i;
				if (s > n) {
					break GAO;
				} else if (!f[i]) {
					while (cur < b.length && a[b[cur]] == cnt) {
						a[b[cur]] = s;
						++cur;
					}
					++cnt;
				}
				if (d == 10) {
					t = 0;
					while (s > 0) {
						t += s % 10;
						s /= 10;
					}
					d = 1;
				} else {
					++t;
					++d;
				}
				f[i + t] = true;
			}
			off += BLOCKSIZE;
		}

		System.out.println(cnt - 1);
		boolean blank = false;
		for (int i = 0; i < a.length; ++i) {
			if (i > 0) {
				System.out.print(' ');
			}
			System.out.print(a[i]);
		}
		System.out.println();
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//867736	08.07.09 19:08	watashi	108 	.JAVA	Accepted	502 ms	3926 kb


