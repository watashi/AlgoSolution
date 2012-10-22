// SGU499. Greatest Greatest Common Divisor
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

	public static void main(String[] args) throws IOException {
		int n = nextInt();
		int[] c = new int[1 << 20];
		for (int i = 0; i < n; ++i) {
			int m = nextInt();
			for (int j = 1; j * j <= m; ++j) {
				if (m % j == 0) {
					++c[j];
					if (j * j < m) {
						++c[m / j];
					}
				}
			}
		}
		for (int i = 1000000; i >= 0; --i) {
			if (c[i] > 1) {
				System.out.println(i);
				break;
			}
		}
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//1137292	05.02.11 23:52	watashi	499 	.JAVA	Accepted 	1246 ms	0 kb
