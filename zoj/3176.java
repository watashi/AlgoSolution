import java.io.*;

class Interval {
    int l, r;
    public Interval(int l, int r) {
        this.l = l;
        this.r = r;
    }
    public Interval intersect(Interval i) {
        return new Interval(Math.max(l, i.l), Math.min(r, i.r));
    }
    public boolean isEmpty() {
        return l >= r;
    }
}

public class Main {
    static String[] ans = new String[]{
        "Neither",      // 00
        "Rounding",     // 01
        "Truncation",   // 10
        "Either"        // 11
    };

    static int ch;

    public static int nextInt() {
        int ret = 0;
        try {
            do {
                ch = System.in.read();
            } while (!Character.isDigit(ch));
            do {
                ret *= 10;
                ret += Character.digit(ch, 10);
                ch = System.in.read();
            } while (Character.isDigit(ch));
        } catch(IOException e) {
        }
        return ret;
    }

    static Interval getIntervalR(int m, int p) {
        if (p == 0) {
            return new Interval(1000 * m / 5 + 1, Integer.MAX_VALUE);
        } else if (p == 100) {
            return new Interval(m, 1000 * m / 995 + 1);
        } else {
            m *= 1000;
            p *= 10;
            return new Interval(m / (p + 5) + 1, m / (p - 5) + 1);
        }
    }

    static Interval getIntervalT(int m, int p) {
        if (p == 0) {
            return new Interval(100 * m + 1, Integer.MAX_VALUE);
        } else if (p == 100) {
            return new Interval(m, m + 1);
        } else {
            m *= 100;
            return new Interval(m / (p + 1) + 1, m / p + 1);
        }
    }

    public static void main(String[] args) {
        int re = nextInt();
        for (int ri = 1; ri <= re; ++ri) {
            int n = nextInt();
            Interval r = new Interval(Integer.MIN_VALUE, Integer.MAX_VALUE);
            Interval t = new Interval(Integer.MIN_VALUE, Integer.MAX_VALUE);
            for (int i = 0; i < n; ++i) {
                int m = nextInt();
                int p = nextInt();
                r = r.intersect(getIntervalR(m, p));
                t = t.intersect(getIntervalT(m, p));
            }
            int ind = 3;
            if (r.isEmpty()) {
                ind ^= 1;
            }
            if (t.isEmpty()) {
                ind ^= 2;
            }
            System.out.println(ans[ind]);
        }
    }
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1801402   2009-03-24 01:01:20     Accepted    3176    Java    0   2485    watashi@Zodiac

// 2012-09-07 02:06:13 | Accepted | 3176 | Java | 130 | 2598 | watashi | Source
