import java.io.*;
import java.math.*;
import java.util.*;

public class J {
  Point[] p;
  int[] ch;
  BigInteger[][][] tri;
  BigInteger[][] dp;
  BigInteger ans;

  public J(ConvexHull convexHull) {
    p = convexHull.p;
    ch = convexHull.ch;
    tri = new BigInteger[p.length][p.length][p.length];
    dp = new BigInteger[ch.length][ch.length];
    ans = gao(1, 0);
  }

  BigInteger gao(int a, int b, int c) {
    if (tri[a][b][c] == null) {
      BigInteger s = BigInteger.ZERO;
      Triangle triangle = new Triangle(p[a], p[b], p[c]);
      for (int i = 0; i < p.length; ++i) {
        if (triangle.contains(p[i])) {
          BigInteger t = BigInteger.ONE;
          t = t.multiply(gao(i, b, c));
          t = t.multiply(gao(a, i, c));
          t = t.multiply(gao(a, b, i));
          s = s.add(t);
        }
      }
      if (s.equals(BigInteger.ZERO)) {
        s = BigInteger.ONE;
      }
      tri[a][b][c] = tri[a][c][b] = tri[b][a][c] = tri[b][c][a] = tri[c][a][b] = tri[c][b][a] = s;
    }
    return tri[a][b][c];
  }

  BigInteger gao(int a, int b) {
    if (dp[a][b] == null) {
      BigInteger s = BigInteger.ZERO;
      for (int i = (a + 1) % ch.length; i != b; i = (i + 1) % ch.length) {
        BigInteger t = BigInteger.ONE;
        t = t.multiply(gao(ch[a], ch[b], ch[i]));
        t = t.multiply(gao(a, i));
        t = t.multiply(gao(i, b));
        s = s.add(t);
      }
      if (s.equals(BigInteger.ZERO)) {
        s = BigInteger.ONE;
      }
      dp[a][b] = s;
    }
    return dp[a][b];
  }

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    while (in.hasNextInt()) {
      int n = in.nextInt();
      Point[] p = new Point[n];
      for (int i = 0; i < n; ++i) {
        p[i] = new Point();
        p[i].x = in.nextInt();
        p[i].y = in.nextInt();
      }
      ConvexHull ch = new ConvexHull(p);
      for (int i : ch.ch) {
        System.err.println(i + ":" + ch.p[i]);
      }
      J main = new J(ch);
      System.out.println(main.ans);
    }
  }
}

class Point implements Comparable<Point> {
  int x, y;

  public int compareTo(Point p) {
    if (y != p.y) {
      return y < p.y ? -1 : 1;
    } else if (x != p.x) {
      return x < p.x ? -1 : 1;
    } else {
      return 0;
    }
  }

  public int xmult(Point a, Point b) {
    return (a.x - x) * (b.y - y) - (a.y - y) * (b.x - x);
  }

  public String toString() {
    return "(" + x + "," + y + ")";
  }
}

class Triangle {
  Point a, b, c;

  Triangle(Point x, Point y, Point z) {
    a = x;
    if (x.xmult(y, z) > 0) {
      b = y;
      c = z;
    } else {
      b = z;
      c = y;
    }
  }

  public boolean contains(Point p) {
    return a.xmult(b, p) > 0 && b.xmult(c, p) > 0 && c.xmult(a, p) > 0;
  }
}

class ConvexHull {
  Point[] p;
  int[] ch;

  public ConvexHull(Point[] point) {
    int size, oldSize;

    p = point;
    Arrays.sort(p);
    ch = new int[p.length + 1];
    size = 0;
    ch[size++] = 0;
    oldSize = 1;
    ch[size++] = 1;
    for (int i = 2; i < p.length; ++i) {
      while (size > oldSize && p[ch[size - 2]].xmult(p[ch[size - 1]], p[i]) > 0) {
        --size;
      }
      ch[size++] = i;
    }
    oldSize = size;
    ch[size++] = p.length - 2;
    for (int i = p.length - 3; i >= 0; --i) {
      while (size > oldSize && p[ch[size - 2]].xmult(p[ch[size - 1]], p[i]) > 0) {
        --size;
      }
      ch[size++] = i;
    }
    ch = Arrays.copyOf(ch, size - 1);
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
        String file = "tria";
        in = new BufferedInputStream(new FileInputStream(file + ".in"));
        out = new PrintStream(new FileOutputStream(file + ".out"));
      } catch (IOException ex) {
      }
    }
  }
}

