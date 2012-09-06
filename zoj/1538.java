import java.io.*;

public class Main {
    private static int ch = 0;

    public static int nextInt() throws IOException {
        do {
            ch = System.in.read();
        } while (Character.isWhitespace(ch));
        if (!Character.isDigit(ch)) {
            System.err.println(ch);
            throw new IOException();
        } else {
            int ret = ch - '0';
            while (Character.isDigit(ch = System.in.read())) {
                ret *= 10;
                ret += ch - '0';
            }
            return ret;
        }
    }

    public static void main(String[] args) {
        try {
            while (true) {
                int n = nextInt();
                int[] a = new int[n];
                for (int i = 0; i < a.length; ++i) {
                    a[i] = nextInt();
                }
                int p = 0;
                for (int i = 0; i < n; ++i) {
                    p = p + a[p];
                    if (p >= a.length) {
                        p -= a.length;
                    }
                }
                System.out.println(a[p]);
            }
        } catch (IOException dump) {
            System.err.println("IOException");
        }
    }
}

// BufferedReader TLE

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1756388   2009-02-04 20:02:29     Accepted    1538    Java    0   724     watashi@Zodiac

/*
##BUG##
Submit Time     Language    Run Time(ms)    Run Memory(KB)      User Name
2009-02-04 20:02:29     Java    0   724     watashi@Zodiac
2009-01-27 23:17:22     C++     40  424     大家一起用java
2005-10-25 21:15:41     FPC     80  640     llzvista
2006-01-09 13:42:19     FPC     80  644     AndyZhau
2006-06-16 23:48:22     FPC     80  644     Justice
2007-06-21 23:33:58     FPC     90  520     t__nt@gdb
*/

// 2012-09-07 00:52:54 | Accepted | 1538 | Java | 170 | 795 | watashi | Source
