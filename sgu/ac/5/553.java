// SGU553. Sultan's Pearls
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

  static int upperBound(int[] a, int key) {
    int pos = Arrays.binarySearch(a, key);
    if (pos >= 0) {
      return pos + 1;
    } else {
      return -1 - pos;
    }
  }

  public static void main(String[] args) throws IOException {
    int n = nextInt();
    int m = nextInt();
    int r = nextInt();
    int[] w = new int[n + 1];
    int[] c = new int[n + 1];
    for (int i = 0; i < n; ++i) {
      w[i + 1] = w[i] + nextInt();
      c[i + 1] = c[i] + nextInt();
    }

    int[] ans = new int[]{0, 0, 0, 0};
    for (int i = n; i >= m; --i) {
      int wh = w[i] - w[i - m];
      int wt = (wh + r - 1) / r;
      int j = upperBound(w, w[i - m] - wt) - 1;
      if (j < 0) {
        break;
      }
      if ((c[n] - c[i]) + (c[j] - c[0]) >= ans[1]) {
        ans = new int[]{(n - i) + (j - 0), (c[n] - c[i]) + (c[j] - c[0]), i, j};
      }
    }
    System.out.println(ans[0] + " " + ans[1]);
    for (int i = ans[2]; i < n; ++i) {
      System.out.print('H');
    }
    for (int j = 0; j < ans[3]; ++j) {
      System.out.print('T');
    }
    if (ans[0] > 0) { // Presentation Error on test 29
      System.out.println();
    }
  }
}

// ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
// 1379924	22.10.12 21:58	watashi	553 	.JAVA	Accepted 	231 ms	7568 kb
// 1375544	22.10.12 20:12	watashi	L 	.JAVA	Accepted	285 ms	7568 kb

