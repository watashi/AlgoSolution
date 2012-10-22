// SGU160. Magic Multiplying Machine 
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
		int m = nextInt();
		int[] pre = new int[m];
		int[] how = new int[m];
		Arrays.fill(pre, -1);
		pre[1] = -2;
		for (int i = 0; i < n; ++i) {
			int a = nextInt();
			if (a == 1 || a == m) {
				continue;
			} else {
				int[] cur = pre.clone();
				for (int j = 0; j < m; ++j) {
					if (cur[j] != -1 && pre[(j * a) % m] == -1) {
						pre[(j * a) % m] = j;
						how[(j * a) % m] = i;
					}
				}
			}
		}
		for (int i = m - 1; i >= 0; --i) {
			if (pre[i] != -1) {
				System.out.println(i);
				ArrayList<Integer> s = new ArrayList<Integer>();
				while (i != 1) {
					s.add(how[i] + 1);
					i = pre[i];
				}
				Collections.reverse(s);
				for (int j = 0; j < s.size(); ++j) {
					System.out.print((j > 0 ? " " : "") + s.get(j));
				}
				System.out.println();
				break;
			}
		}
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status:  	Time:  	Memory:
//1079018	20.09.10 12:23	watashi	160 	.JAVA	Accepted 	187 ms	0 kb

