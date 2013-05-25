import java.io.*;
import java.math.*;
import java.util.*;

public class A {
  public static void main(String[] args) throws IOException {
    Scanner in = new Scanner(new File("china.in"));
    PrintWriter out = new PrintWriter(new FileOutputStream("china.out"));
    BigInteger n = in.nextBigInteger();
    if (n.testBit(0)) {
      n = n.shiftRight(1);
    } else {
      n = n.shiftRight(2).shiftLeft(1).subtract(BigInteger.ONE);
    }
    out.println(n);
    out.flush();
  }
}


