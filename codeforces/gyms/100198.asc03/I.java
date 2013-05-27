import java.io.*;
import java.util.*;

public class I {
  static Scanner in;
  static PrintWriter out;

  @SuppressWarnings("deprecation")
  static void runFinalizersOnExit() {
    Runtime.runFinalizersOnExit(true);
  }

  static {
    String file = "twocyl";
    try {
      in = new Scanner(new File(file + ".in"));
      out = new PrintWriter(new FileOutputStream(file + ".out")) {
        @Override
        public void finalize() throws Throwable {
          flush();
          close();
        }
      };
      runFinalizersOnExit();
    } catch (IOException ex) {
    }
  }

  static final long N = 1L << 20;	// 2^15~2^18 -> WA12

  static double solve(double a, double b) {
    double aa = a * a, bb = b * b;
    double s = a / N, ss = s * s, xx;
    double sum = Math.sqrt(aa * bb);
    for (long i = 2; i < N; i += 2) {
      xx = i * i * ss;
      sum += 2 * Math.sqrt((aa - xx) * (bb - xx));
    }
    for (long i = 1; i < N; i += 2) {
      xx = i * i * ss;
      sum += 4 * Math.sqrt((aa - xx) * (bb - xx));
    }
    return 8 * (sum * s / 3);
  }

  public static void main(String[] args) {
    double r1 = in.nextDouble();
    double r2 = in.nextDouble();
    out.println(solve(Math.min(r1, r2), Math.max(r1, r2)));
  }
}

