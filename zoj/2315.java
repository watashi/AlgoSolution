// matching -> greedy

import java.io.*;
import java.util.*;

public class Main {
    private int[] p;

    public Main(int[] p) {
        this.p = p;
    }

    public int[] solve() {
        int[] c = new int[p.length];
        c[0] = p.length;
        for (int i = 1; i < p.length; ++i) {
            ++c[p[i]];
        }
        int begin = 0, end = 0;
        int[] q = new int[p.length];
        for (int i = 1; i < p.length; ++i) {
            if (c[i] == 0) {
                q[end++] = i;
            }
        }
        int[] tag = new int[p.length];
        int cnt = 0;
        while (begin < end) {
            int cur = q[begin++];
            // System.err.println(cur + " " + p[cur] + " " + tag[cur] + " " + tag[p[cur]]);
            if (tag[cur] == 0 && tag[p[cur]] == 0) {
                tag[cur] = 1;
                tag[p[cur]] = -1;
                ++cnt;
            }
            if (--c[p[cur]] == 0) {
                q[end++] = p[cur];
            }
        }
        int[] ret = new int[cnt];
        cnt = 0;
        for (int i = 0; i < p.length; ++i) {
            if (tag[i] == 1) {
                ret[cnt++] = i;
            }
        }
        return ret;
    }

    private static int ch;

    public static int read() {
        int ret = 0;
        try {
            do {
                ch = System.in.read();
            } while (Character.isWhitespace(ch));
            while (Character.isDigit(ch)) {
                ret *= 10;
                ret += Character.digit(ch, 10);
                ch = System.in.read();
            }
        } catch (IOException e) {
        }
        return ret;
    }

    public static void main(String[] args) {
        int re = read();
        for (int ri = 1; ri <= re; ++ri) {
            if (ri > 1) {
                System.out.println();
            }
            int n = read();
            int[] p = new int[n];
            p[0] = -1;
            for (int i = 1; i < n; ++i) {
                p[i] = read() - 1;
            }
            Main solution = new Main(p);
            int[] ans = solution.solve();
            System.out.println(ans.length * 1000);
            for (int i = 0; i < ans.length; ++i) {
                if (i > 0) {
                    System.out.print(' ');
                }
                System.out.print(ans[i] + 1);
            }
            System.out.println();
        }
    }
}

//1777531   2009-03-04 15:57:18       Accepted      2315    Java    0   9522    watashi@Zodiac

/*
 * ZOJ BUG
Submit Time     Language    Run Time(ms)    Run Memory(KB)      User Name
2009-03-04 15:57:18     Java    0   9522    watashi@Zodiac
2009-01-19 01:39:02     Java    0   23484   moonancient
2009-01-16 19:51:51     FPC     320     7840    birdor
2009-02-05 20:17:42     C   330     19688   dodowater
2009-02-06 19:17:43     C++     350     7996    wode
2009-02-05 20:15:21     C++     360     19716   dodowater
2009-01-17 23:48:02     C++     370     176     大家一起用java
2009-01-12 14:27:38     C++     380     4572    HyperHexagon
2009-01-11 18:52:03     C++     390     4572    igoogle
2009-01-16 15:42:46     FPC     390     12332   FD
2009-02-06 19:07:28     C++     420     7996    wode
*/

// 2012-09-07 15:37:31 | Accepted | 2315 | Java | 1350 | 9678 | watashi | Source
