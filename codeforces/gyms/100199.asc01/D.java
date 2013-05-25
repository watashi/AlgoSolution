import java.io.*;

public class D {
  static FileInputStream in;
  static PrintWriter out;

  static {
    String file = "matrix";
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

  public static void main(String[] args) throws IOException {
    int n = nextInt();
    int m = nextInt();
    int[] x = new int[n];
    for (int i = 0; i < 2 * m; ++i) {
      int v = nextInt();
      ++x[v - 1];
    }
    long ans = 0;
    for (long xi : x) {
      ans += xi * xi;
    }
    out.println(ans);
    out.flush();
  }
}
