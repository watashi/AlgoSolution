// ZOJ 2507

import java.io.*;

public class Main {
    static int ch;

    public static int nextInt() {
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
        int re = nextInt();
        for (int ri = 1; ri <= re; ++ri) {
            int n = nextInt();
            int c = 0, s = 0;
            for (int i = 0; i < n; ++i) {
                int a = nextInt();
                if (a > 1) {
                    ++c;
                }
                s ^= a;
            }
            if ((s == 0 && c > 0) || (c == 0 && s > 0)) {
                System.out.println("Brother");
            } else {
                System.out.println("John");
            }
        }
    }
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1801480   2009-03-24 08:37:44     Accepted    3113    Java    0   60  watashi@Zodiac

// 2012-09-07 02:01:55 | Accepted | 3113 | Java | 40 | 254 | watashi | Source
