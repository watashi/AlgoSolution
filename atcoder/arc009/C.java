import java.util.*;

public class Main {
  static final long mod = 1777777777;

  static long[] extGcd(long a, long b) {
    if (b == 0) {
      return new long[]{a, 1, 0};
    } else {
      long[] g = extGcd(b, a % b);
      return new long[]{g[0], g[2], g[1] - a / b * g[2]};
    }
  }

  static long modInv(long x, long m) {
    long[] g = extGcd(x, m);
    return (g[1] % m + m) % m;
  }

  static long derangement(long n) {
    long a = 0, b = 1;
    for (int i = 1; i < n; ++i) {
      long c = (a + b) * (i + 1) % mod;
      a = b;
      b = c;
    }
    return a;
  }

  static long choose(long n, long m) {
    long ret = 1;
    for (int i = 0; i < m; ++i) {
      ret *= (n - i) % mod;
      ret %= mod;
      ret *= modInv(i + 1, mod);
      ret %= mod;
    }
    return ret;
  }

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    long n = in.nextLong();
    long m = in.nextLong();
    long ans = choose(n, m) * derangement(m) % mod;
    System.out.println(ans);
  }
}


