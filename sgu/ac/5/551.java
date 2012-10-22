// SGU551. Preparing Problem
import java.util.*;

public class Solution {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    long n = in.nextLong();
    long a = in.nextLong();
    long b = in.nextLong();

    long l = 0, r = Math.min(a, b) * n;
    while (l < r) {
      long m = (l + r) / 2;
      if (m / a + m / b < n) {
        l = m + 1;
      } else {
        r = m;
      }
    }

    long x = (r + a - 1) / a;
    long y = (r + b - 1) / b;
    System.out.println((x + y) + " " + Math.max(x * a, y * b));
  }
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//1379886	22.10.12 21:31	watashi	551 	.JAVA	Accepted 	0 ms	7620 kb

