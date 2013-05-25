import java.io.*;
import java.util.*;

public class G {
  static FileInputStream in;
  static PrintWriter out;

  static {
    String file = "people";
    try {
      in = new FileInputStream(file + ".in");
      out = new PrintWriter(new FileOutputStream(file + ".out"));
    } catch (IOException ex) {
    }
  }

  static int nextInt() throws IOException {
    int ch = -1;
    do {
      ch = in.read();
    } while (!Character.isDigit(ch));
    int ret = 0;
    while (Character.isDigit(ch)) {
      ret *= 10;
      ret += Character.digit(ch, 10);
      ch = in.read();
    }
    return ret;
  }

  static class IndexComparator implements Comparator<Integer> {
    private final long[] a;

    public IndexComparator(long[] a) {
      this.a = a;
    }

    public int compare(Integer o1, Integer o2) {
      if (a[o1] != a[o2]) {
        return a[o1] < a[o2] ? -1 : 1;
      } else {
        return 0;
      }
    }
  }

  static int[] getIndex(long[] a) {
    Integer[] ind = new Integer[a.length];
    for (int i = 0; i < ind.length; ++i) {
      ind[i] = i;
    }
    Arrays.sort(ind, new IndexComparator(a));
    int[] ret = new int[a.length];
    for (int i = 0; i < ret.length; ++i) {
      ret[i] = ind[i];
    }
    return ret;
  }

  static final long MASK = (1L << 32) - 1L;

  public static void main(String[] args) throws IOException {
    int n = nextInt();
    long[] sb = new long[n];
    for (int i = 0; i < n; ++i) {
      sb[i] = nextInt();
      sb[i] = (sb[i] << 32) ^ (nextInt() ^ MASK);
    }
    int[] index = getIndex(sb);

    long[] b = new long[n];
    int[] s = new int[n];
    int[] p = new int[n];
    int m = 0, last = -1;
    for (int i : index) {
      int bi = (int)((sb[i] & MASK) ^ MASK);
      int x = Arrays.binarySearch(b, 0, m, bi);
      if (x < 0) {
        x = -1 - x;
      }
      b[x] = bi;
      s[x] = i;
      p[i] = (x == 0) ? -1 : s[x - 1];
      if (x == m) {
        ++m;
        last = i;
      }
    }

    Stack<Integer> ans = new Stack<Integer>();
    while (last != -1) {
      ans.push(last);
      last = p[last];
    }
    out.println(ans.size());
    while (!ans.empty()) {
      out.print(ans.pop() + 1);
      out.print(ans.empty() ? '\n' : ' ');
    }
    out.flush();
  }
}
