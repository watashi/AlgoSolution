// SGU546. Ternary Password
import java.util.*;

public class Solution {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();
    int[] c = new int[3];
    c[0] = in.nextInt();
    c[1] = in.nextInt();
    c[2] = n - c[0] - c[1];
    if (c[2] < 0) {
      System.out.println(-1);
      System.exit(0);
    }

    String s = in.next();
    int[] d = new int[3];
    for (char i: s.toCharArray()) {
      ++d[Character.digit(i, 10)];
    }

    int ans = 0;
    StringBuffer sb = new StringBuffer(n);
    for (char i: s.toCharArray()) {
      int j = Character.digit(i, 10);
      if (d[j] > c[j]) {
        ++ans;
        for (int k = 0; k < 3; ++k) {
          if (d[k] < c[k]) {
            --d[j];
            ++d[k];
            j = k;
            break;
          }
        }
      }
      sb.append(j);
    }
    System.out.println(ans);
    System.out.println(sb.toString());
  }
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//1379873	22.10.12 21:26	watashi	546 	.JAVA	Accepted 	0 ms	7536 kb

