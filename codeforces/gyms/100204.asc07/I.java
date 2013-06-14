import java.io.*;
import java.math.*;
import java.util.*;

public class I {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    boolean blank = false;

    while (scanner.hasNextBigInteger()) {
      if (blank) {
        System.out.println();
      }
      else {
        blank = true;
      }
      BigInteger a = scanner.nextBigInteger();
      BigInteger b = scanner.nextBigInteger();
      System.out.println(a.gcd(b));
    }
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
        String file = "toral";
        in = new BufferedInputStream(new FileInputStream(file + ".in"));
        out = new PrintStream(new FileOutputStream(file + ".out"));
      } catch (IOException ex) {
      }
    }
  }
}

