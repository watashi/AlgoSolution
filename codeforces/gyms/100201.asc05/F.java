import java.io.*;
import java.math.*;
import java.util.*;

public class F {
  static Scanner in;
  static PrintStream out;

  static {
    if (System.getProperty("ONLINE_JUDGE") == null) {
      in = new Scanner(System.in);
      out = System.out;
    } else {
      String file = "gsm";
      try {
        in = new Scanner(new File(file + ".in"));
        out = new PrintStream(new FileOutputStream(file + ".out"));
      } catch (IOException ex) {
      }
    }
  }

  static BigDecimal c = BMath.sqrt3.divide(B(4));

  static BigDecimal B(double val) {
    return BigDecimal.valueOf(val);
  }

  static BigDecimal getAns(int h, int r) {
    BigDecimal bc = BMath.sqrt(B(r * r).subtract(B(3 * h * h).divide(B(4))));
    BigDecimal sina = bc.divide(B(r), BMath.mc);
    BigDecimal a = BMath.asin(sina);
    BigDecimal sub = null;
    sub = B(h).multiply(c).multiply(B(h).subtract(bc.multiply(B(2))), BMath.mc);
    sub = sub.subtract(B(r * r).multiply(BMath.pi.divide(B(6), BMath.mc).subtract(a)));
    BigDecimal tri = B(h * h).multiply(c);
    return BigDecimal.ONE.subtract(sub.divide(tri, BMath.mc));
  }

  public static void main(String[] args) {
    int h = in.nextInt();
    int r = in.nextInt();
    BigDecimal ans = null;
    if (r >= h) {
      ans = BigDecimal.ONE;
    } else if (4 * r * r <= 3 * h * h) {
      BigDecimal cir = B(r * r).multiply(BMath.pi);
      BigDecimal hex = B(h * h).multiply(c.multiply(B(6)));
      ans = cir.divide(hex, BMath.mc);
    } else {
      ans = getAns(h, r);
    }
    out.printf("%.110f\n", ans);
  }
}

class BMath {
  static int cnt1, cnt2;
  public static MathContext mc = null;
  public static BigDecimal eps = null;
  public static BigDecimal two = null;
  public static BigDecimal sqrt3 = null;
  public static BigDecimal pi = null;

  static {
    mc = new MathContext(128);
    eps = BigDecimal.ONE.scaleByPowerOfTen(-128);
    two = BigDecimal.valueOf(2);
    sqrt3 = sqrt(BigDecimal.valueOf(3));
    pi = asin(BigDecimal.valueOf(0.5)).multiply(BigDecimal.valueOf(6));
    // System.err.printf("sqrt3 = new BigDecimal(\"%.128f\");\n", sqrt3);
    // System.err.printf("pi = new BigDecimal(\"%.128f\");\n", pi);
  }

  // val > 0
  public static BigInteger sqrt(BigInteger val) {
    int len = val.bitLength();
    BigInteger left = BigInteger.ONE.shiftLeft((len - 1) / 2);
    BigInteger right = BigInteger.ONE.shiftLeft(len / 2 + 1);
    while (left.compareTo(right) < 0) {
      BigInteger mid = left.add(right).shiftRight(1);
      if (mid.multiply(mid).compareTo(val) <= 0) {
        left = mid.add(BigInteger.ONE);
      } else {
        right = mid;
      }
    }
    return right.subtract(BigInteger.ONE);
  }

  public static BigDecimal sqrt(BigDecimal val) {
    BigInteger unscaledVal = val.scaleByPowerOfTen(2 * mc.getPrecision()).toBigInteger();
    return new BigDecimal(sqrt(unscaledVal)).scaleByPowerOfTen(-mc.getPrecision());
  }

  /*
  public static BigDecimal sqrt(BigDecimal val) {
    BigDecimal a = BigDecimal.ONE;
    BigDecimal b = a.add(val.divide(a, mc)).divide(two, mc);
    while (b.subtract(a).abs().compareTo(eps) > 0) {
      a = b;
      b = a.add(val.divide(a, mc)).divide(two, mc);
      // ++cnt1;
    }
    return b;
  }
  */

  // arcsin x =∑(n=1～∞) [(2n)!]x^(2n+1)/[4^n*(n!)^2*(2n+1)]
  // arctan x =∑(n=1～∞) [(-1)^n]x^(2n+1)/(2n+1)
  public static BigDecimal asin(BigDecimal val) {
    BigDecimal tmp = val;
    BigDecimal ret = tmp;
    val = val.multiply(val, mc);
    for (int n = 1; tmp.compareTo(eps) > 0; ++n) {
      tmp = tmp.multiply(val, mc).multiply(
          BigDecimal.valueOf(2 * n - 1).divide(BigDecimal.valueOf(2 * n), mc), mc);
      ret = ret.add(tmp.divide(BigDecimal.valueOf(2 * n + 1), mc), mc);
      // ++cnt2;
    }
    return ret;
  }
}

