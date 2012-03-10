// SGU291. Evolution
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

	static final int[] dx = new int[]{1, 0, -1, 0};
	static final int[] dy = new int[]{0, 1, 0, -1};

	public static void main(String[] args) throws IOException {
		int r = nextInt();
		int c = nextInt();
		int n = nextInt();
		int t = nextInt();
		int[][] a = new int[r][c];
		
		ArrayList<Integer> q = new ArrayList<Integer>();
		for (int i = 1; i <= n; ++i) {
			int x = nextInt() - 1;
			int y = nextInt() - 1;
			a[x][y] = i;
			q.add((x << 16) ^ y);
		}

		while (!q.isEmpty() && t-- > 0) {
			ArrayList<Integer> qq = new ArrayList<Integer>();
			for (int xy : q) {
				int x = xy >> 16;
				int y = xy & 0xffff;
				for (int d = 0; d < 4; ++d) {
					int xx = x + dx[d];
					int yy = y + dy[d];
					try {
						if (a[xx][yy] == 0) {
							a[xx][yy] = a[x][y];
							qq.add((xx << 16) ^ yy);
						}
					} catch (ArrayIndexOutOfBoundsException e) {
					}
				}
			}
			q = qq;
		}

		int[] ans = new int[n];
		for (int[] ai : a) {
			for (int aij : ai) {
				if (aij > 0) {
					++ans[aij - 1];
				}
			}
		}
		for (int ansi : ans) {
			System.out.println(ansi);
		}
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status:  	Time:  	Memory:
//1077478	17.09.10 12:47	watashi	291 	.JAVA	Accepted 	900 ms	14339 kb

