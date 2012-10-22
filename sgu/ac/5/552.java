// SGU552. Database optimization
import java.io.*;
import java.util.*;

public class Solution {
  static String[] readProp(BufferedReader in) throws IOException {
    String[] ret = in.readLine().split(" ");
    ret = Arrays.copyOfRange(ret, 1, ret.length);
    Arrays.sort(ret);
    return ret;
  }

  public static void main(String[] args) throws IOException {
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(in.readLine());
    HashMap<String, Integer> map = new HashMap<String, Integer>(4 * n);
    for (int i = 0; i < n; ++i) {
      String prop[] = readProp(in);
      for (int j = 1; j < (1 << prop.length); ++j) {
        StringBuilder sb = new StringBuilder(50);
        for (int k = 0; k < prop.length; ++k) {
          if ((j & (1 << k)) != 0) {
            sb.append(prop[k]);
            sb.append(';');
          }
        }
        String props = sb.toString();
        if (!map.containsKey(props)) {
          map.put(props, 1);
        } else {
          map.put(props, map.get(props) + 1);
        }
      }
    }

    int m = Integer.parseInt(in.readLine());
    for (int i = 0; i < m; ++i) {
      String prop[] = readProp(in);
      StringBuilder sb = new StringBuilder(50);
      for (String j: prop) {
        sb.append(j);
        sb.append(';');
      }
      Integer ans = map.get(sb.toString());
      System.out.println(ans != null ? ans : 0);
    }
  }
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//1379918	22.10.12 21:55	watashi	552 	.JAVA	Accepted 	1215 ms	174620 kb

