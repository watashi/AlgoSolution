import java.util.*;

class S implements Cloneable {
    static int t;
    int a, b, c;
    void set(int aa, int bb, int cc) {
        a = aa;
        b = bb;
        c = cc;
        if (c < b) {t = c; c = b; b = t; }
        if (b < a) {t = b; b = a; a = t; }
        if (c < b) {t = c; c = b; b = t; }
    }
    public S clone() {
        S ret = new S();
        ret.a = a;
        ret.b = b;
        ret.c = c;
        return ret;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int re = in.nextInt();
        for (int ri = 1; ri <= re; ++ri) {
            S s, t;
            int a, b, c;
            a = in.nextInt();
            b = in.nextInt();
            c = in.nextInt();
            s = new S();
            s.set(a, b, c);
            a = in.nextInt();
            b = in.nextInt();
            c = in.nextInt();
            t = new S();
            t.set(a, b, c);
            boolean f = false;
            if (s.a == t.a && s.b == t.b && s.c == t.c) {
                f = true;
            } else if (s.a + s.b - 1 != s.c) {
                f = false;
            } else {
                S p = new S();
                p.set(-1, -1, -1);
                while (true) {
                    if (s.a == t.a && s.b == t.b ||
                            s.a == t.a && s.b == t.c ||
                            s.a == t.b && s.b == t.c) {
                        f = true;
                        break;
                    } else if (s.a == p.a && s.b == p.b && s.c == p.c) {
                        f = false;
                        break;
                    }
                    p = s;
                    s = new S();
                    s.set(p.b + 1 - p.a, p.a, p.b);
                }
            }
            System.out.println(f ? "Yes" : "No");
        }
    }
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1801434   2009-03-24 01:57:27     Accepted    3180    Java    0   969     watashi@Zodiac

// 2012-09-07 02:06:38 | Accepted | 3180 | Java | 90 | 1134 | watashi | Source
