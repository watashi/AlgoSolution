import java.io.*;
import java.math.*;
import java.util.*;

public class D {
  static Scanner in;
  static PrintStream out;

  static {
    if (System.getProperty("ONLINE_JUDGE") == null) {
      in = new Scanner(System.in);
      out = System.out;
    } else {
      String file = "digit";
      try {
        in = new Scanner(new File(file + ".in"));
        out = new PrintStream(new FileOutputStream(file + ".out"));
      } catch (IOException ex) {
      }
    }
  }

  public static void main(String[] args) {
    while (in.hasNextBigInteger()) {
      BigInteger r = in.nextBigInteger();
      if (r.signum() < 0) {
        break;
      }
      int c = 0;
      BigInteger x = BigInteger.ONE, y = BigInteger.ZERO;
      for (int i = 0; i < r.bitLength(); ++i) {
        if (r.testBit(i)) {
          BigInteger xx = x.add(y);
          BigInteger yy = x.multiply(BigInteger.valueOf(c)).add(y.multiply(BigInteger.valueOf(c + 1)));
          x = xx;
          y = yy;
          c = 0;
        } else {
          ++c;
        }
      }
      out.println(x.add(y));
    }
  }
}

