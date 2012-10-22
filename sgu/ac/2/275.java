// SGU275. To xor or not to xor 
import java.io.*;
import java.util.*;

public class Solution {
	static long nextLong() throws IOException {
		int ch = -1;
		do {
			ch = System.in.read();
		} while (!Character.isDigit(ch));
		long ret = 0;
		while (Character.isDigit(ch)) {
			ret *= 10;
			ret += Character.digit(ch, 10);
			ch = System.in.read();
		}
		return ret;
	}

	static boolean gao(int n, boolean[][] a, boolean[] b) {
		for (int i = 0; i < n; ++i) {
			if (b[i]) {
				if (a[i] == null) {
					a[i] = b;
					return true;
				} else {
					for (int j = i; j <= n; ++j) {
						b[j] ^= a[i][j];
					}
				}
			}
		}
		return !b[n];
	}

	public static void main(String[] args) throws IOException {
		int n = (int)nextLong();
		long[] x = new long[n];
		for (int i = 0; i < n; ++i) {
			x[i] = nextLong();
		}
		
		boolean[] ZERO = new boolean[n + 1];
		boolean[] ONE = new boolean[n + 1];
		ONE[n] = true;
		
		long ans = 0;
		boolean[][] a = new boolean[n][];
		for (int i = 60; i >= 0; --i) {
			boolean[] b = new boolean[n + 1];
			for (int j = 0; j < n; ++j) {
				b[j] = ((x[j] & (1L << i)) != 0);
			}
			b[n] = true;
			ans <<= 1;
			if (gao(n, a, b)) {
				ans ^= 1;
			}
		}
		System.out.println(ans);
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status:  	Time:  	Memory:
//1079214	20.09.10 19:28	watashi	275 	.JAVA	Accepted 	0 ms	0 kb
