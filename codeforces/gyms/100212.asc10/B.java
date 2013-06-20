import java.io.*;
import java.util.*;

public class B {
  static class Trie {
    static final int SIGMA = 10;
    static final int BLANK = -1;

    int tag;
    Trie[] p;

    Trie() {
      tag = BLANK;
      p = new Trie[SIGMA];
    }

    Trie insert(String s) {
      Trie p = this;
      for (char c : s.toCharArray()) {
        int i = Character.digit(c, 10);
        if (p.p[i] == null) {
          p.p[i] = new Trie();
        }
        p = p.p[i];
      }
      return p;
    }

    Trie find(String s) {
      Trie p = this;
      for (char c : s.toCharArray()) {
        if (p == null || p.tag != BLANK) {
          break;
        } else {
          p = p.p[Character.digit(c, 10)];
        }
      }
      return p;
    }
  };

  static int len, ch;
  static byte[] buf = new byte[1024];

  static void next() throws IOException {
    len = 0;
    do {
      ch = System.in.read();
    } while (Character.isWhitespace(ch));
    while (Character.isDigit(ch)) {
      buf[len++] = (byte)ch;
      ch = System.in.read();
    }
  }

  static String nextString() throws IOException {
    next();
    return new String(buf, 0, len);
  }

  static int nextInt() throws IOException {
    int ret = 0;
    next();
    for (int i = 0; i < len; ++i) {
      ret *= 10;
      ret += Character.digit(buf[i], 10);
    }
    return ret;
  }

  public static void main(String[] args) throws IOException {
    int t = nextInt();
    int m = nextInt();
    int n = nextInt();
    int d = nextInt();
    Trie root = new Trie();
    Trie[] subroot = new Trie[m];
    int[] s = new int[m];
    for (int i = 0; i < m; ++i) {
      s[i] = nextInt() - 1;
      subroot[i] = root.insert(nextString());
    }
    int[] r = new int[t];
    for (int i = 0; i < t; ++i) {
      r[i] = nextInt() - 1;
      int p = nextInt();
      if (p == 0) {
        subroot[r[i]].insert("").tag = i;
      } else {
        for (int j = 0; j < p; ++j) {
          subroot[r[i]].insert(nextString()).tag = i;
        }
      }
    }
    int home = nextInt() - 1;
    int z = nextInt();
    boolean[] covered = new boolean[m];
    for (int i = 0; i < z; ++i) {
      covered[nextInt() - 1] = true;
    }
    // covered[home]
    int[][] cost = new int[4][4];
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        cost[i][j] = nextInt();
      }
    }
    int c = nextInt();
    long ans = 0L;
    for (int i = 0; i < c; ++i) {
      int from = nextInt() - 1;
      Trie p = root.find(nextString());
      int length = nextInt();
      if (p == null) {
        continue;
      }
      int to = p.tag;
      int fromType = -1;
      if (r[from] == home) {
        // from home region
        fromType = 0;
      } else if (covered[r[from]] && s[r[from]] == s[home]) {
        // from home network within home superregion
        fromType = 1;
      } else if (covered[r[from]] && s[r[from]] != s[home]) {
        // from home network outside home superregion
        fromType = 2;
      } else if (!covered[r[from]]) {
        // from alien network
        fromType = 3;
      }
      int toType = -1;
      if (from == to) {
        // The call is local if it is made to the same town that the caller is
        toType = 0;
      } else if (r[from] == r[to]) {
        // The call is regional if it is made to the same region
        toType = 1;
      } else if (covered[r[to]]) {
        // The call is interregional, if it is made to another region, covered by the network
        toType = 2;
      } else {
        // In the other case the call is long distance
        toType = 3;
      }
      ans += cost[fromType][toType] * length;
    }
    System.out.println(ans);
  }
}

final class System {
  public static InputStream in = java.lang.System.in;
  public static PrintStream out = java.lang.System.out;
  public static PrintStream err = java.lang.System.err;

  public static void exit(int status) {
    java.lang.System.exit(status);
  }

  static {
    if (java.lang.System.getProperty("ONLINE_JUDGE") != null) {
      try {
        String file = "called";
        in = new BufferedInputStream(new FileInputStream(file + ".in"));
        out = new PrintStream(new FileOutputStream(file + ".out"));
      } catch (IOException ex) {
      }
    }
  }
}

