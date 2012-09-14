// 1023 1576
// Stable Matching

import java.io.*;
import java.util.*;

public class Main {
    private static int getid(String s, HashMap<String, Integer> map, String[] list) {
        if (map.containsKey(s)) {
            return map.get(s);
        } else {
            int ret = map.size();
            map.put(s, ret);
            list[ret] = s;
            return ret;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String input;

        while ((input = in.readLine()) != null) {
            int n = Integer.parseInt(input);
            String[] boys = new String[n];
            String[] girls = new String[n];
            HashMap<String, Integer> b2i = new HashMap<String, Integer>(n);
            HashMap<String, Integer> g2i = new HashMap<String, Integer>(n);
            int[][] bg = new int[n][n];
            int[][] gb = new int[n][n];
            for (int i = 0; i < n; ++i) {
                String[] all = in.readLine().split(" ");
                int b = getid(all[0], b2i, boys);
                for (int j = 0; j < n; ++j) {
                    int g = getid(all[j + 1], g2i, girls);
                    bg[b][j] = g;
                }
            }
            for (int i = 0; i < n; ++i) {
                String[] all = in.readLine().split(" ");
                int g = getid(all[0], g2i, girls);
                for (int j = 0; j < n; ++j) {
                    int b = getid(all[j + 1], b2i, boys);
                    gb[g][b] = j;
                }
            }

            int[] next = new int[n];
            Arrays.fill(next, 0);
            int[] best = new int[n];
            Arrays.fill(best, -1);
            ArrayList<Integer> todo = new ArrayList<Integer>(n);
            for (int i = 0; i < n; ++i) {
                todo.add(i);
            }
            while (!todo.isEmpty()) {
                ArrayList<Integer> momo = new ArrayList<Integer>(todo.size());
                for (int boy : todo) {
                    int girl = bg[boy][next[boy]++];
                    if (best[girl] == -1) {
                        best[girl] = boy;
                    } else if (gb[girl][best[girl]] < gb[girl][boy]) {
                        momo.add(boy);
                    } else {
                        momo.add(best[girl]);
                        best[girl] = boy;
                    }
                }
                todo = momo;
            }
            for (int i = 0; i < n; ++i) {
                System.out.println(boys[best[i]] + " " + girls[i]);
            }
            System.out.println();
        }
    }
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1756286   2009-02-04 19:13:34     Accepted    1576    Java    0   5953    watashi@Zodiac

/*
##BUG##
Submit Time     Language    Run Time(ms)    Run Memory(KB)      User Name
2009-02-04 19:13:34     Java    0   5953    watashi@Zodiac
2007-12-16 16:13:18     C++     300     2872    vacuum_zhou
2006-11-13 01:57:46     C++     310     2736    aaan
*/

// 2012-09-07 00:54:26 | Accepted | 1576 | Java | 440 | 7587 | watashi | Source
