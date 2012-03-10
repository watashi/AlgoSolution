// SGU149. Computer Network 
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
		int[] p = new int[n];
		int[] e = new int[n];
		for (int i = 1; i < n; ++i) {
			p[i] = nextInt() - 1;
			e[i] = nextInt();
		}

		int[] d = new int[n];
		int[] t = new int[n];
		int[] w = new int[n];
		for (int i = n - 1; i > 0; --i) {
			if (d[p[i]] < d[i] + e[i]) {
				t[p[i]] = d[p[i]];
				d[p[i]] = d[i] + e[i];
				w[p[i]] = i;
			} else if (t[p[i]] < d[i] + e[i]) {
				t[p[i]] = d[i] + e[i];
			}
		}
		
		int[] u = new int[n];
		u[0] = 0;
		for (int i = 1; i < n; ++i) {
			u[i] = Math.max(u[p[i]], i == w[p[i]] ? t[p[i]] : d[p[i]]) + e[i];
		}

		for (int i = 0; i < n; ++i) {
	//		System.out.println(d[i] + " " + t[i] + " " + w[i] + " " + u[i]);
			System.out.println(Math.max(d[i], u[i]));
		}
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status:  	Time:  	Memory:
//1078778	19.09.10 21:26	watashi	149 	.JAVA	Accepted 	127 ms	0 kb

