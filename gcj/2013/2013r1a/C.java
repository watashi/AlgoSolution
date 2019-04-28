import java.io.*;
import java.util.*;

public class C {
  static long nextLong() throws IOException {
    int ch = -1;
    do {
      ch = System.in.read();
    } while (!Character.isDigit(ch));
    long ret = 0;
    while (Character.isDigit(ch)) {
      ret *= 10;
      ret += Character.digit(ch, 10);
      ch = System.in.read();
    }
    return ret;
  }

  static final int T = 1;
  static final int R = 8000;
  static final int N = 12;
  static final int M = 8;
  static final int K = 12;

  static long[][] choose;

  static class Comb {
    int[] a;
    long s;
    HashMap<Long, Integer> c;

    Comb(int[] a) {
      this.a = a.clone();
      this.c = new HashMap<Long, Integer>();
      this.s = 1;
      for (int i = 0; i < a.length; ) {
        int j = i;
        while (j < a.length && a[j] == a[i]) {
          ++j;
        }
        s *= choose[j][i];
        i = j;
      }
      for (int i = 0; i < 1 << a.length; ++i) {
        long p = 1;
        for (int j = 0; j < a.length; ++j) {
          if ((i & (1 << j)) != 0) {
            p *= a[j];
          }
        }
        c.put(p, c.containsKey(p) ? c.get(p) + 1 : 1);
      }
    }

    double score(HashMap<Long, Integer> o) {
      double ret = s;
      int k = K;
      for (Map.Entry<Long, Integer> i: o.entrySet()) {
        if (c.containsKey(i.getKey())) {
          ret *= choose[k][i.getValue()];
          ret *= Math.pow(c.get(i.getKey()), i.getValue());
          k -= i.getValue();
        } else {
          return Double.MIN_VALUE;
        }
      }
      return ret;
    }

    public String toString() {
      StringBuffer sb = new StringBuffer(a.length);
      for (int i: a) {
        sb.append(i);
      }
      return sb.toString();
    }
  };

  static int[] a = new int[N];
  static ArrayList<Comb> comb = new ArrayList<Comb>();

  static void gen(int n, int m) {
    if (n == N) {
      comb.add(new Comb(a));
    } else {
      for (int i = m; i <= M; ++i) {
        a[n] = i;
        gen(n + 1, i);
      }
    }
  }

  static {
    choose = new long[N + 1][N + 1];
    for (int i = 0; i <= N; ++i) {
      choose[i][0] = 1;
      for (int j = 1; j <= i; ++j) {
        choose[i][j] = choose[i - 1][j - 1] + choose[i - 1][j];
      }
    }

    gen(0, 2);
    System.err.println(comb.size());
  }

  public static void main(String[] args) throws IOException {
    nextLong(); // T = 1
    nextLong(); // R = 8000
    nextLong(); // N = 12
    nextLong(); // M = 8
    nextLong(); // K = 12

    System.out.println("Case #1:");
    for (int r = 0; r < R; ++r) {
      if (r % 100 == 0) {
        System.err.println(r);
      }
      HashMap<Long, Integer> c = new HashMap<Long, Integer>();
      for (int i = 0; i < K; ++i) {
        long x = nextLong();
        c.put(x, c.containsKey(x) ? c.get(x) + 1 : 1);
      }

      Comb best = comb.get(0);
      double bestScore = Double.MIN_VALUE;
      for (Comb i: comb) {
        double tempScore = i.score(c);
        if (tempScore > bestScore) {
          best = i;
          bestScore = tempScore;
        }
      }
      System.out.println(best);
    }
  }
}

// java C < C-small-practice-2.in > C-small-practice-2.out  95.97s user 0.79s system 107% cpu 1:30.29 total

