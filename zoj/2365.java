import java.io.*;
import java.util.*;

public class Main {
    static int ch;

    static int nextInt() throws IOException {
        int ret = 0;
        do {
            ch = System.in.read();
        } while (Character.isWhitespace(ch));
        while (Character.isDigit(ch)) {
            ret *= 10;
            ret += Character.digit(ch, 10);
            ch = System.in.read();
        }
        return ret;
    }

    public static void main(String[] args) throws IOException {
        int re = nextInt();
        for (int ri = 1; ri <= re; ++ri) {
            if (ri > 1) {
                System.out.println();
            }
            int n = nextInt();
            int m = nextInt();
            int s = nextInt() - 1;
            int t = nextInt() - 1;
            ArrayList<ArrayList<Integer> > e = new ArrayList<ArrayList<Integer> >(n);
            for (int i = 0; i < n; ++i) {
                e.add(new ArrayList<Integer>());
            }
            int[] a = new int[m];
            int[] b = new int[m];
            int[] c = new int[m];
            for (int i = 0; i < m; ++i) {
                a[i] = nextInt() - 1;
                b[i] = nextInt() - 1;
                e.get(a[i]).add(i);
                e.get(b[i]).add(i);
            }
            Arrays.fill(c, -1);
            int[] d = new int[n];
            int[] q = new int[n];
            Arrays.fill(d, -1);
            d[s] = 0;
            q[0] = s;
            for (int begin = 0, end = 1; begin < end; ++begin) {
                s = q[begin];
                if (d[t] != -1 && d[s] >= d[t]) {
                    break;
                }
                for (int edge : e.get(s)) {
                    int v = (s == a[edge]) ? b[edge] : a[edge];
                    if (d[v] == -1) {
                        d[v] = d[s] + 1;
                        q[end++] = v;
                    }
                    if (d[v] == d[s] + 1) {
                        c[edge] = d[s];
                    }
                }
            }
            if (d[t] == -1) {   // NoSuchTestCase
                d[t] = m;
                for (int i = 0; i < m; ++i) {
                    c[i] = i;
                }
                // throw new IOException();
            }
            ArrayList<ArrayList<Integer> > ans = new ArrayList<ArrayList<Integer> >(d[t]);
            for (int i = 0; i < d[t]; ++i) {
                ans.add(new ArrayList<Integer>());
            }
            for (int i = 0; i < m; ++i) {
                if (c[i] != -1) {
                    ans.get(c[i]).add(i);
                }
            }
            System.out.println(ans.size());
            for (ArrayList<Integer> ai : ans) {
                System.out.print(ai.size());
                for (int i : ai) {
                    System.out.print(" " + (i + 1));
                }
                System.out.println();
            }
        }
    }
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1806139   2009-03-27 07:05:50     Accepted    2365    Java    0   2541    watashi@Zodiac

// 2012-09-07 01:20:56 | Accepted | 2365 | Java | 270 | 2747 | watashi | Source
