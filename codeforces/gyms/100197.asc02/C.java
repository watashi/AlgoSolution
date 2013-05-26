import java.io.*;

public class C {
  static InputStream in;
  static PrintWriter out;

  static {
    String file = "huffman";
    try {
      in = new BufferedInputStream(new FileInputStream(file + ".in"));
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

  public static void main(String[] args) throws IOException {
    int n = nextInt();
    // PriorityQueue<Long> pq = new PriorityQueue<Long>(n);	// TLE18
    PriorityQueue pq = new PriorityQueue(n);
    for (int i = 0; i < n; ++i) {
      pq.add((long)nextInt());
    }
    long ans = 0;
    for (int i = 1; i < n; ++i) {
      long tmp = 0;
      tmp += pq.poll();
      tmp += pq.poll();
      ans += tmp;
      pq.add(tmp);
    }
    out.println(ans);
    out.flush();
  }
}

// [module] PriorityQueue
class PriorityQueue {
  int n;
  long[] a;

  public PriorityQueue(int capacity) {
    n = 1;
    a = new long[capacity + 1];
  }

  public void add(long v) {
    int p = n++, q;
    while (p > 1) {
      q = p >> 1;
      if (a[q] <= v) {
        break;
      } else {
        a[p] = a[q];
        p = q;
      }
    }
    a[p] = v;
  }

  public long poll() {
    long ret = a[1], v = a[--n];
    int p = 1, l, r;
    while (true) {
      l = p << 1;
      r = l ^ 1;
      if (l >= n) {
        break;
      } else if (r == n || a[l] <= a[r]) {
        if (v <= a[l]) {
          break;
        } else {
          a[p] = a[l];
          p = l;
        }
      } else {
        if (v <= a[r]) {
          break;
        } else {
          a[p] = a[r];
          p = r;
        }
      }
    }
    a[p] = v;
    return ret;
  }
}

