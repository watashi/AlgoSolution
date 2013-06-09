import java.io.*;
import java.util.*;

public class F {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();
    in.nextLine();
    String s = in.nextLine();
    for (char c: s.toCharArray()) {
      if (c == '-') {
        n -= 2;
      }
    }
    System.out.println(Math.max(n, 0));
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
        String file = "positive";
        in = new BufferedInputStream(new FileInputStream(file + ".in"));
        out = new PrintStream(new FileOutputStream(file + ".out"));
      } catch (IOException ex) {
      }
    }
  }
}

