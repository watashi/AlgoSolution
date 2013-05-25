import java.io.*;
import java.util.*;

public class F {
  static Scanner in;
  static PrintWriter out;

  static {
    String file = "out";
    try {
      in = new Scanner(new File(file + ".in"));
      out = new PrintWriter(new FileOutputStream(file + ".out"));
    } catch (IOException ex) {
    }
  }

  public static void main(String[] args) {
    int n = in.nextInt();
    double[] x = new double[n], y = new double[n], r = new double[n], d = new double[n];
    for (int i = 0; i < n; ++i) {
      x[i] = in.nextDouble();
      y[i] = in.nextDouble();
      r[i] = in.nextDouble();
    }
    double x0 = in.nextDouble();
    double y0 = in.nextDouble();
    double r0 = in.nextDouble();
    double[][] w = new double[n][n];
    for (int i = 0; i < n; ++i) {
      x[i] -= x0;
      y[i] -= y0;
      r[i] += r0;
      d[i] = Math.hypot(x[i], y[i]);
      w[i][i] = 0;
      for (int j = 0; j < i; ++j) {
        if (r[i] + r[j] > Math.hypot(x[i] - x[j], y[i] - y[j]) + 1e-6) {
          double a = Math.acos(Math.max(-1.0, Math.min(1.0,	// WA12
                  (x[i] * x[j] + y[i] * y[j]) / (d[i] * d[j]))));
          boolean b = (x[i] * y[j] - x[j] * y[i] >= 0);
          w[i][j] = b ? a : -a;
          w[j][i] = b ? -a : a;
        } else {
          w[i][j] = w[j][i] = 1e100;
        }
      }
    }
    // floyd => WA17
    double[] v = new double[n];
    for (int k = 0; k < n; ++k) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          v[j] = Math.min(v[j], v[i] + w[i][j]);
        }
      }
    }
    boolean flag = true;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (v[j] > v[i] + w[i][j] + 1e-6) {
          flag = false;
        }
      }
    }
    out.println(flag ? "YES" : "NO");
    out.flush();
  }
}

