// SGU142. Keyword
/*
142. Keyword

time limit per test: 2 sec.
memory limit per test: 16384 KB

Kevin has invented a new algorithm to crypt and decrypt messages, which he thinks is unbeatable. The algorithm uses a very large key-string, out of which a keyword is found out after applying the algorithm. Then, based on this keyword, the message is easily crypted or decrypted. So, if one would try to decrypt some messages crypted with this algorithm, then knowing the keyword would be enough. Someone has found out how the keyword is computed from the large key-string, but because he is not a very experienced computer programmer, he needs your help. The key-string consists of N characters from the set {'a','b'}. The keyword is the shortest non-empty string made up of the letters 'a' and 'b', which is not contained as a contiguous substring (also called subsequence) inside the key-string. It is possible that more than one such string exists, but the algorithm is designed in such a way that any of these strings can be used as a keyword. Given the key-string, your task is to find one keyword.

Input

The first line contains the integer number N, the number of characters inside the key-string (1 <= N <= 500 000). The next line contains N characters from the set {'a','b'} representing the string.

Output

The first line of output should contain the number of characters of the keyword. The second line should contain the keyword.

Sample Input

11
aabaaabbbab

Sample Output

4
aaaa

Author	: Mugurel Ionut Andreica
Resource	: SSU::Online Contester Fall Contest #2
Date	: Fall 2002
*/
import java.io.*;

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
		byte[] s = new byte[n];
		do {
			s[0] = (byte)System.in.read();
		} while (Character.isWhitespace(s[0]));
		System.in.read(s, 1, s.length - 1);
		for (int i = 0; i < s.length; ++i) {
			s[i] -= (byte)'a';
		}
		for (int k = 1; ; ++k) {
			boolean[] b = new boolean[1 << k];
			int mask = 0;
			for (int i = 0; i < k; ++i) {
				if (s[i] > 0) {
					mask |= 1 << i;
				}
			}
			b[mask] = true;
			for (int i = k; i < s.length; ++i) {
				if (s[i] > 0) {
					mask |= 1 << k;
				}
				mask >>= 1;
				b[mask] = true;
			}
			for (int i = 0; i < b.length; ++i) {
				if (!b[i]) {
					System.out.println(k);
					for (int j = 0; j < k; ++j) {
						System.out.print((i & (1 << j)) == 0 ? 'a' : 'b');
					}
					System.out.println();
					System.exit(0);
				}
			}
		}
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//887875	16.09.09 20:24	watashi	142 	.JAVA	Accepted	56 ms	0 kb


