// SGU548. Dragons and Princesses
import java.io.*;
import java.util.*;

class Indexer implements Comparator<Integer> {
  int[] a;

  public Indexer(int[] a) {
    this.a = a;
  }

  public int compare(Integer o1, Integer o2) {
    return a[o1] - a[o2];
  }
}

public class Solution {
  static int nextChar() throws IOException {
    int ch = -1;
		do {
			ch = System.in.read();
		} while (Character.isWhitespace(ch));
    return ch;
  }

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
    int n = nextInt() - 1;
    int[] key = new int[n];
    int[] val = new int[n];
    for (int i = 0; i < n; ++i) {
      key[i] = nextChar();
      val[i] = nextInt();
    }
    int limit = Integer.MAX_VALUE;
    for (int i = n - 2; i >= 0; --i) {
      if (key[i] == 'p') {
        limit = Math.min(limit, val[i] - 1);
        val[i] = limit;
      }
    }

    PriorityQueue<Integer> pq = new PriorityQueue<Integer>(n, new Indexer(val));
    for (int i = 0; i < n - 1; ++i) {
      if (key[i] == 'd') {
        pq.add(i);
      } else {
        while (pq.size() > val[i]) {
          pq.poll();
        }
      }
    }

    if (pq.size() < val[n - 1]) {
      System.out.println(-1);
    } else {
      int sum = 0;
      ArrayList<Integer> ans = new ArrayList<Integer>(pq);
      Collections.sort(ans);
      for (int i: ans) {
        sum += val[i];
      }

      System.out.println(sum);
      System.out.println(ans.size());
      boolean blank = false;
      for (int i: ans) {
        if (blank) {
          System.out.print(' ');
        } else {
          blank = true;
        }
        System.out.print(i + 2);
      }
      System.out.println();
    }
  }
}

// ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
// 1379878	22.10.12 21:28	watashi	548 	.JAVA	Accepted 	512 ms	7676 kb
// 1374527	22.10.12 18:19	watashi	G 	.JAVA	Accepted	473 ms	7684 kb
