// SGU155. Cartesian Tree 
import java.io.*;
import java.util.*;

public class Solution {
	static int nextInt() throws IOException {
		int ch = -1;
		do {
			ch = System.in.read();
		} while (Character.isWhitespace(ch));
		boolean negative = (ch == '-');
		if (negative) {
			ch = System.in.read();
		}
		int ret = 0;
		while (Character.isDigit(ch)) {
			ret *= 10;
			ret += Character.digit(ch, 10);
			ch = System.in.read();
		}
		return negative ? -ret : ret;
	}

	public static void main(String[] args) throws IOException {
		int n = nextInt();

		int[] k = new int[n];
		int[] a = new int[n];
		int[] b = new int[65536];
		Arrays.fill(b, -1);
		for (int i = 0; i < n; ++i) {
			k[i] = nextInt();
			a[i] = nextInt();
			b[k[i] + 32768] = i;
		}

		int[] p = new int[n];
		int[] l = new int[n];
		int[] r = new int[n];
		Arrays.fill(p, -1);
		Arrays.fill(l, -1);
		Arrays.fill(r, -1);

		Stack<Integer> s = new Stack<Integer>();
		for (int i : b) {
			if (i == -1) {
				continue;
			}
			int c = -1;
			while (!s.empty() && a[s.peek()] > a[i]) {
				c = s.pop();
			}
			if (!s.empty()) {
				r[s.peek()] = i;
				p[i] = s.peek();
			}
			if (c != -1) {
				l[i] = c;
				p[c] = i;
			}
			s.push(i);
		}

		System.out.println("YES");
		for (int i = 0; i < n; ++i) {
			System.out.println(++p[i] + " " + ++l[i] + " " + ++r[i]);
		}
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status:  	Time:  	Memory:
//1076164	14.09.10 18:13	watashi	155 	.JAVA	Accepted 	646 ms	0 kb

