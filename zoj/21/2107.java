import java.io.*;
import java.util.*;

class Point implements Comparable<Point> {
    double x, y;
    public Point(double ax, double ay) {
        x = ax;
        y = ay;
    }
    public int compareTo(Point p) {
        //return new Double(x).compareTo(p.x);  // TLE
        return (x == p.x) ? 0 : ((x < p.x) ? -1 : 1);   // AC
    }
    public double distanceTo(Point p) {
        return Math.hypot(x - p.x, y - p.y);
    }
}

class ClosestPair/*ofPoints*/ {
    static final int BOUND = 8;

    Point[] p;
    double ans;

    public ClosestPair(Point[] ap) {
        p = ap;
        Arrays.sort(p);
    }

    void gao(int begin, int end, double xdiv, ArrayList<Point> todo) {
        if (end - begin < BOUND) {
            for (int i = begin; i < end; ++i) {
                int k = i;
                for (int j = i + 1; j < end; ++j) {
                    if (p[j].y < p[k].y) {
                        k = j;
                    }
                }
                Point pp;
                pp = p[i]; p[i] = p[k]; p[k] = pp;
                for (int j = i + 1; j < end; ++j) {
                    ans = Math.min(ans, p[i].distanceTo(p[j]));
                }
            }
            for (int i = begin; i < end; ++i) {
                if (Math.abs(p[i].x - xdiv) <= ans) {
                    todo.add(p[i]);
                }
            }
        } else {
            int mid = (begin + end) / 2;
            double div = p[mid].x;
            ArrayList<Point> dol = new ArrayList<Point>(), dor = new ArrayList<Point>();
            gao(begin, mid, div, dol);
            gao(mid, end, div, dor);
            int l = 0, r = 0;
            Point pp = null;
            while (l < dol.size() || r < dor.size()) {
                if (l == dol.size()) {
                    pp = dor.get(r);
                    ++r;
                } else if (r == dor.size() || dol.get(l).y < dor.get(r).y) {
                    pp = dol.get(l);
                    ++l;
                } else {
                    pp = dor.get(r);
                    ++r;
                }
                if (Math.abs(pp.x - div) <= ans) {
                    todo.add(pp);
                }
            }
            for (int i = 0; i < todo.size(); ++i) {
                for (int j = i + 1; j < todo.size(); ++j) {
                    if (todo.get(j).y - todo.get(i).y >= ans) {
                        break;
                    } else {
                        ans = Math.min(ans, todo.get(i).distanceTo(todo.get(j)));
                    }
                }
            }
        }
    }

    public double solve() {
        ans = Double.MAX_VALUE;
        gao(0, p.length, Double.NaN, new ArrayList<Point>());
        return ans;
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        StreamTokenizer in = new StreamTokenizer(
                new BufferedReader(new InputStreamReader(System.in)));
        while (true) {
            // System.err.printf(">1");
            in.nextToken();
            int n = (int)in.nval;
            if (n == 0) {
                break;
            }
            double x, y;
            Point[] p = new Point[n];
            for (int i = 0; i < n; ++i) {
                in.nextToken();
                x = in.nval;
                in.nextToken();
                y = in.nval;
                p[i] = new Point(x, y);
            }
            // System.err.printf(">2");
            ClosestPair cpp = new ClosestPair(p);
            // System.err.printf(">3");
            System.out.printf("%.2f\n", cpp.solve() / 2);
            // System.err.printf(">4");
        }
    }
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1782697   2009-03-08 22:51:22     Accepted    2107    Java    0   7707    watashi@Zodiac

/*
 * ZOJ BUG
Submit Time     Language    Run Time(ms)    Run Memory(KB)      User Name
Submit Time     Language    Run Time(ms)    Run Memory(KB)      User Name
2009-03-08 22:51:22     Java    0   7707    watashi@Zodiac
2008-11-20 20:03:20     C   360     1724    sieg heil
2007-04-12 11:04:49     C++     370     2792    9911
2007-12-12 22:54:07     C++     380     2788    Snail
2008-12-09 16:31:01     C   380     2892    kiddlee
2008-12-02 12:02:50     C++     390     1748    rongyan
2008-12-03 20:51:09     C++     390     1748    og
2009-01-24 15:12:58     FPC     390     2372    shik
*/

// 2012-09-07 01:13:06 | Accepted | 2107 | Java | 2120 | 13464 | watashi | Source
