import java.io.*;
import java.util.*;

public class Sum {
	public static void main(String[] args) throws Exception {
		StreamTokenizer in = new StreamTokenizer(new BufferedInputStream(System.in));
		PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
		int n, a, b;

		in.nextToken();
		n = (int)in.nval;

		byte[] c = new byte[n];

		for (int i = 0; i < n; i++) {
			in.nextToken();
			a = (int)in.nval;
			in.nextToken();
			b = (int)in.nval;
			c[i] = (byte)(a + b);
		}
		for (int i = n - 1; i >= 0; i--) {
			if (c[i] >= 10) {
				c[i] -= 10;
				++c[i - 1];
			}
			c[i] += '0';
		}
		out.println(new String(c));
		out.flush();
	}
}
/*
id => 4677346
date => 18:03:0915 Dec 2012
user => watashi
pname => Superlong Sums
lang => Java
status => Accepted
testid => 
time => 0.406
mem => 3 526 KB
pid => 1048
*/
