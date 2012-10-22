// SGU344. Weed
/*
344. Weed
Time limit per test: 4 second(s)
Memory limit: 65536 kilobytes
input: standard
output: standard


Andrew has visited his garden for the last time many years ago. Today's property taxes are so high, so Andrew decided to sell his garden. The land was not cultivated for a long time and now it is probably a lot of weed on it. Andrew wants to remove everything from the ground before selling. Now he wants to estimate the amount of work.

The garden has the rectangular form and is divided into N ×M equal squares. Andrew's memory is phenomenal. He remembers which squares were occupied by the weed. For the purpose of simplicity, Andrew thinks that each square is either fully occupied by the weed or completely free from it. Andrew likes botany and he knows that if some square is free from the weed but at least two of its adjacent squares are occupied by the weed (two squares are adjacent if they have common side), that square will be also occupied by the weed soon. Andrew is pretty sure that during last years weed occupied every square possible. Please help Andrew to estimate how many squares is occupied by the weed.

Input
The first line of the input contains integers N and M (1 ≤ N, M ≤ 1000). Next N lines contain M characters each. Character

X

denotes that the corresponding square is occupied by the weed. A period character (

.

) denotes an empty square.

Output
Print one integer denoting the number of squares occupied by the weed after so many years.

Example(s)

sample input

	

sample output

3 3
X..
.X.
.X.

	

6


sample input

	

sample output

3 4
X..X
.X..
.X..

	

12

*/
import java.io.*;

public class Solution {
	static final int[] dx = new int[]{0, 1, 0, -1};
	static final int[] dy = new int[]{1, 0, -1, 0};

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String[] inputs = in.readLine().split(" ");
		int n = Integer.parseInt(inputs[0]);
		int m = Integer.parseInt(inputs[1]);
		int[][] d = new int[n][m];
		int[] q = new int[n * m];
		int begin = 0, end = 0;
		for (int i = 0; i < n; ++i) {
			String s = in.readLine();
			for (int j = 0; j < m; ++j) {
				if (s.charAt(j) == 'X') {
					d[i][j] = 5;
					q[end++] = (i << 10) ^ j;
				}
			}
		}
		while (begin < end) {
			int x = q[begin] >> 10;
			int y = q[begin] & 1023;
			for (int k = 0; k < 4; ++k) {
				int xx = x + dx[k];
				int yy = y + dy[k];
				try {
					if (++d[xx][yy] == 2) {
						q[end++] = (xx << 10) ^ yy;
					}
				} catch (ArrayIndexOutOfBoundsException e) {
				}
			}
			++begin;
		}
		System.out.println(end);
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//874949	10.08.09 16:22	watashi	344 	.JAVA	Accepted	185 ms	13062 kb
