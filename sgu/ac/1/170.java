// SGU170. Particles

/*
170. Particles
time limit per test: 0.50 sec.
memory limit per test: 4096 KB
input: standard
output: standard



A new kind of elementary particles was discovered in recent physical experiments. These particles were named "buons". It was also discovered that there exist two types of buons, which were named "Y+" (psi +) and "Y-" (psi -) buons. It became known that buons tend to form chains. Moreover, a very interesting property of buons, named "going through", was discovered: if two buons with different types are neighbors in a chain, they can easily exchange places one with other.

Because one "going through" takes very short time, the order of buons in chain can quickly change. Now the physicists are interested, how many "goings through" must happen for one chain to become other.

You are to help them. Write a program, which determines the minimal number of "goings through" which will allow one chain to become other.

Input
First two lines of input contains strings of "+" and "-" characters, describing first and second buon chains. The "+" character stands for Y+ buon, and "-" character stands for Y- buon. The length of each string doesn't exceed 5000; moreover, there is at leat one buon in each chain.

Output
If it is possible to make the second chain from the first, using only "goings trough", write on the first line of output the minimal number K of "goings through" which are required. If it is impossible to make the secong chain from the first, output only integer "-1".

Sample test(s)

Input

++-+--+
-++--++

Output

4
[submit]
[forum]
Author:	NNSU #2 team
Resource:	Compiled from many sources
Date:	
*/

import java.io.*;

public class Solution {
	static void impossible() {
		System.out.println(-1);
		System.exit(0);
	}

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String src = in.readLine();
		String tar = in.readLine();
		if (src.length() != tar.length()) {
			impossible();
		}
		int p = 0;
		int ans = 0;
		for (int i = 0; i < src.length(); ++i) {
			if (src.charAt(i) == '+') {
				while (p < tar.length() && tar.charAt(p) != '+') {
					++p;
				}
				ans += Math.abs(p - i);
				if (++p > tar.length()) {
					impossible();
				}
			}
		}
		if (tar.indexOf("+", p) != -1) {
			impossible();
		}
		System.out.println(ans);
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//866394	03.07.09 14:53	watashi	170 	.JAVA	Accepted	6 ms	698 kb


