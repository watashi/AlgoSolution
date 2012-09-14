import java.util.*;

class Edge {
    int v;
    double w;
    Edge(int v, double w) {
        this.v = v;
        this.w = w;
    }
}

public class Main {
    public static final double EPS = 1e-6;
    public static final double INF = 1e99;

    // Algo: SPFA [for all]
    public static boolean SPFA(ArrayList<ArrayList<Edge> > e, double[] d) {
        if (d == null) {
            d = new double[e.size()];
        } else {
            Arrays.fill(d, 0);
        }
        boolean[] m = new boolean[e.size()];
        int[] c = new int[e.size()];
        ArrayDeque<Integer> q = new ArrayDeque<Integer>();
        for (int i = 0; i < e.size(); ++i) {
            q.addLast(i);
        }
        while (!q.isEmpty()) {
            int t = q.pollFirst();
            m[t] = true;
            for (Edge edge : e.get(t)) {
                if (d[edge.v] > d[t] + edge.w + EPS) {
                    if ((c[edge.v] = c[t] + 1) >= e.size()) {
                        return false;
                    } else if (m[edge.v]) {
                        m[edge.v] = false;
                        q.addLast(edge.v);
                    }
                    d[edge.v] = d[t] + edge.w;
                }
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int re = in.nextInt();
        for (int ri = 1; ri <= re; ++ri) {
            if (ri > 1) {
                System.out.println();
            }
            int n = in.nextInt();
            double[] x = new double[n];
            double[] y = new double[n];
            double[] l = new double[n];
            double[] r = new double[n];
            double x0, y0, r0;
            for (int i = 0; i < n; ++i) {
                x[i] = in.nextDouble();
                y[i] = in.nextDouble();
                r[i] = in.nextDouble();
            }
            x0 = in.nextDouble();
            y0 = in.nextDouble();
            r0 = in.nextDouble();
            for (int i = 0; i < n; ++i) {
                x[i] -= x0;
                y[i] -= y0;
                l[i] = Math.hypot(x[i], y[i]);
                r[i] += r0;
            }
            ArrayList<ArrayList<Edge> > e = new ArrayList<ArrayList<Edge> >(n);
            for (int i = 0; i < n; ++i) {
                e.add(new ArrayList<Edge>());
            }
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    if (Math.hypot(x[i] - x[j], y[i] - y[j]) >= r[i] + r[j] - EPS) {
                        continue;
                    }
                    boolean flag = (x[i] * y[j] - x[j] * y[i] >= 0);
                    double angle = Math.acos((x[i] * x[j] + y[i] * y[j]) / (l[i] * l[j]));
                    e.get(i).add(new Edge(j, flag ? angle : -angle));
                    e.get(j).add(new Edge(i, flag ? -angle : angle));
                }
            }
            System.out.println(SPFA(e, null) ? "YES" : "NO");
        }
    }
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1776928   2009-03-03 21:54:31     Accepted    2318    Java    0   2398    watashi@Zodiac

// 2012-09-07 15:37:49 | Accepted | 2318 | Java | 1880 | 5439 | watashi | Source
