import java.io.*;
import java.util.*;

public class SMSSpam {
	public static void main(String[] args)
			throws IOException {
		int[] c = new int[256];

		for (int i = 'a'; i <= 'z'; i++) {
			c[i] = (i - 'a') % 3 + 1;
		}
		c[' '] = 1;
		c['.'] = 1;
		c[','] = 2;
		c['!'] = 3;

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String str = in.readLine();
		int ans = 0;

		for (char ch: str.toCharArray()) {
			ans += c[ch];
		}
		System.out.println(ans);
	}
}
/*
id => 4678650
date => 15:37:4516 Dec 2012
user => watashi
pname => SMS-spam
lang => Java
status => Accepted
testid => 
time => 0.078
mem => 362 KB
pid => 1567
*/
