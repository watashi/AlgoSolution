import java.io.*;
import java.math.*;

public class Main {
    static int ch;

    public static int nextInt() throws IOException {
        while (Character.isWhitespace(ch = System.in.read())) {
        }
        if (ch == -1) {
            return -1;
        }
        int ret = 0;
        do {
            ret = ret * 10 + Character.digit(ch, 10);
        } while (Character.isDigit(ch = System.in.read()));
        return ret;
    }

    // static int[] d;
    static int[][] p;
    static BigDecimal[][] r;
    // final static BigDecimal TWO = new BigDecimal("2");
    final static BigDecimal HALF = new BigDecimal("0.5");

    public static void main(String[] args) throws IOException {
        boolean blank = false;
        int n, m, a, b;

        while ((n = nextInt()) != -1) {
            if (blank) {
                System.out.println();
            } else {
                blank = true;
            }

            // readInput
            int[] c = new int[n];
            p = new int[n][2];
            m = nextInt();
            for (int i = 0; i < n; ++i) {
                p[i][0] = p[i][1] = -1;
            }
            for (int i = 0; i < m; ++i) {
                a = nextInt() - 1;
                p[a][0] = nextInt() - 1;
                p[a][1] = nextInt() - 1;
                ++c[p[a][0]];
                ++c[p[a][1]];
            }

            // topSort
            int[] tp = new int[n];
            int end = 0;
            for (int i = 0; i < n; ++i) {
                if (c[i] == 0) {
                    tp[end++] = i;
                }
            }
            for (int i = 0; i < end; ++i) {
                if (p[tp[i]][0] != -1) {
                    if (--c[p[tp[i]][0]] == 0) {
                        tp[end++] = p[tp[i]][0];
                    }
                    if (--c[p[tp[i]][1]] == 0) {
                        tp[end++] = p[tp[i]][1];
                    }
                }
            }
            // d = new int[n];
            // for (int i = 0; i < n; ++i) {
            //  d[tp[i]] = i;
            // }
            // d[parent] > d[child]

            // genAns
            r = new BigDecimal[n][n];
            for (int i = n - 1; i >= 0; --i) {
                r[tp[i]][tp[i]] = BigDecimal.ONE;
                for (int j = i + 1; j < n; ++j) {
                    if (p[tp[i]][0] == -1) {
                        r[tp[i]][tp[j]] = BigDecimal.ZERO;
                    } else {
                        r[tp[i]][tp[j]] = r[p[tp[i]][0]][tp[j]].add(r[p[tp[i]][1]][tp[j]]).multiply(HALF);
                    }
                    r[tp[j]][tp[i]] = r[tp[i]][tp[j]];
                }
            }

            // printAns
            m = nextInt();
            for (int i = 0; i < m; ++i) {
                a = nextInt() - 1;
                b = nextInt() - 1;
                String s = r[a][b].movePointRight(2).toPlainString();
                if (s.indexOf('.') != -1) {
                    int l = s.length() - 1;
                    while (s.charAt(l) == '0') {
                        --l;
                    }
                    if (s.charAt(l) != '.') {
                        ++l;
                    }
                    s = s.substring(0, l);
                }
                System.out.print(s);
                System.out.println("%");
            }
        }
    }
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//374   2010-07-06 17:12:59     Accepted    1039    Java    900     7188    anotherpeg  Source

// 2012-09-30 23:44:03 | Accepted | 1509 | Java | 1430 | 12104 | watashi | Source
