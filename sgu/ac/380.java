// SGU380. Synchronised Alpinism
/*
380. Synchronised Alpinism
Time limit per test: 2 second(s)
Memory limit: 262144 kilobytes
input: standard
output: standard
The progress does not stand! An institute of Sport Experiments (SE) is preparing new surprises for future Olympic Games. There is no doubt that you are familiar with synchronised swimming. But do you know anything about synchronised boxing or synchronised basketball? In this problem we will consider only synchronised alpinism. It is a team competition, each team consists of two members. Initially one of them stands at the east side of the mountain and other — at the west side. Their aim is to meet at some point as fast as possible. There is also one additional difficulty: at any moment of time they have to be at the same height. Unfortunatly, SE's synchronised alpinism experimental contest was unsuccessful. No team managed to fulfill the task, so it was impossible to determine a winner! Now SE is interested, is it really impossible to meet on the mountain under above restrictions or the teams just have to train harder. Try to help SE!
Input
Here we will assume that mountain is flat figure, and its border is a polyline, with a peaks at points . The first line of the input file consists one integer number (). The second line contains integer numbers . Points and are initial positions of alpinists. It is guaranteed that , and do not exceed by absolute value.
Output
If it is possible for the alpinists to meet, output " ", otherwise output " " (quotes for clarity).
Example(s)

sample input

	

sample output

7
0 3 1 5 2 4 0

	

YES

*/
import java.io.*;

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

	static int signum(int x) {
		return x < 0 ? -1 : x == 0 ? 0 : 1;
	}

	public static void main(String[] args) throws IOException {
		int n = nextInt();
		int[] y = new int[n];
		for (int i = 0; i < y.length; ++i) {
			y[i] = nextInt();
		}
		int l = 0, r = n - 1;
		int u = 0, d = 0;
		while (l < r) {
			if (d <= y[l + 1] && y[l + 1] <= u) {
				++l;
			} else if (d <= y[r - 1] && y[r - 1] <= u) {
				--r;
			} else if (y[l + 1] > u && y[r - 1] > u) {
				if (y[l + 1] >= y[r - 1]) {
					u = y[--r];
				} else {
					u = y[++l];
				}
			} else if (y[l + 1] < d && y[r - 1] < d) {
				if (y[l + 1] < y[r - 1]) {
					d = y[--r];
				} else {
					d = y[++l];
				}
			} else {
				System.out.println("NO");
				System.exit(0);
			}
		}
		System.out.println("YES");
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//887531	16.09.09 08:56	watashi	380 	.JAVA	Accepted	94 ms	0 kb


