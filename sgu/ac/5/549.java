// SGU549. Dumbbells
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

  static void rsort(ArrayList<Integer> a) {
    Collections.sort(a);
    Collections.reverse(a);
  }

  static int topn(ArrayList<Integer> a, int n) {
    int ret = 0;
    rsort(a);
    n = Math.min(n, a.size());
    for (int i = 0; i < n; ++i) {
      ret += a.get(i);
    }
    return ret;
  }

  public static void main(String[] args) throws IOException {
    int n = nextInt();
    int m = nextInt();
    Map<Integer, ArrayList<Integer> > mp = new HashMap<Integer, ArrayList<Integer> >();
    for (int i = 0; i < n; ++i) {
      int w = nextInt();
      int c = nextInt();
      if (!mp.containsKey(w)) {
        mp.put(w, new ArrayList<Integer>());
      }
      mp.get(w).add(c);
    }

    ArrayList<Integer> size = new ArrayList<Integer>();
    for (Map.Entry<Integer, ArrayList<Integer> > i: mp.entrySet()) {
      size.add(i.getValue().size());
    }
    rsort(size);
    int limit = m <= size.size() ? size.get(m - 1) : 0;

    ArrayList<Integer> cost = new ArrayList<Integer>();
    for (Map.Entry<Integer, ArrayList<Integer> > i: mp.entrySet()) {
      ArrayList<Integer> a = i.getValue();
      if (a.size() >= limit) {
        cost.add(topn(a, limit));
      }
    }
    System.out.println(limit + " " + topn(cost, m));
  }
}

// ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
// 1379879	22.10.12 21:30	watashi	549 	.JAVA	Accepted 	0 ms	7548 kb
// 1373972	22.10.12 17:32	watashi	H 	.JAVA	Accepted	0 ms	7536 kb
