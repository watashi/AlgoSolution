import java.io.*;
import java.math.*;
import java.util.*;

public class A {
  static Scanner in;
  static PrintStream out;

  static {
    if (System.getProperty("ONLINE_JUDGE") == null) {
      in = new Scanner(System.in);
      out = System.out;
    } else {
      String file = "brackets";
      try {
        in = new Scanner(new File(file + ".in"));
        out = new PrintStream(new FileOutputStream(file + ".out"));
      } catch (IOException ex) {
      }
    }
  }

  static final int N = 52;

  public static void main(String[] args) {
    BigInteger[][] tree = new BigInteger[N + 1][N + 1]; // not necessary
    BigInteger[][] forest = new BigInteger[N + 1][N + 1];

    for (int i = 0; i <= N; i++) {
      forest[0][i] = tree[0][i] = BigInteger.ONE;
    }
    for (int i = 1; i <= N; i++) {
      tree[i][0] = BigInteger.ZERO;
      for (int j = 1; j < i; j++) {
        tree[i][j] = forest[i - 1][j - 1];
      }
      tree[i][i] = tree[i][i - 1].add(BigInteger.ONE);
      for (int j = i + 1; j <= N; j++) {
        tree[i][j] = tree[i][i];
      }

      for (int j = 0; j <= N; j++) {
        forest[i][j] = BigInteger.ZERO;
        for (int k = 1; k <= i; k++) {
          forest[i][j] = forest[i][j].add(tree[k][j].multiply(forest[i - k][j]));
        }
      }
    }

    for (int ri = 1; ; ri++) {
      int n = in.nextInt();
      int k = in.nextInt();
      if (n == 0 && k == 0) {
        break;
      }
      if (ri > 1) {
        out.println();
      }
      out.println("Case " + ri + ": "
          + forest[n][k].subtract(forest[n][k - 1]));
    }
  }
}

