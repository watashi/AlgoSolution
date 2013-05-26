import java.io.*;
import java.util.*;

public class G {
  static Scanner in;
  static PrintWriter out;

  static {
    try {
      in = new Scanner(new File("input.txt"));
      out = new PrintWriter(new FileOutputStream("output.txt"));
    } catch (IOException ex) {
    }
  }

  public static void main(String[] args) {
    int n = in.nextInt();
    long m = in.nextLong();
    long y = in.nextLong();
    long[] x = new long[n];
    for (int i = 0; i < n; ++i) {
      x[i] = in.nextLong();
    }
    long[] k = new long[n];
    long[] d = new long[n];
    long r = m;
    for (int i = 0; i < n; ++i) {
      k[i] = x[i] * m / y;
      r -= k[i];
      d[i] = (2 * k[i] + 1) * y - 2 * x[i] * m;
      d[i] = (d[i] << 10) ^ i;
    }
    Arrays.sort(d);
    for (int i = 0; i < r; ++i) {
      k[(int)(d[i] & 1023L)]++;
    }
    for (int i = 0; i < n; ++i) {
      out.print(k[i]);
      out.print(i == n - 1 ? '\n' : ' ');
    }
    out.flush();
  }
}

