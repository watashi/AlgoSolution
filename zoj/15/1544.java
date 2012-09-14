import java.util.*;

class Graph {
    public static double eps = 1e-8;

    static class Edge {
        private int v;
        private double r, c;

        public Edge(int v, double r, double c) {
            this.v = v;
            this.r = r;
            this.c = c;
        }
    }

    private ArrayList<ArrayList<Edge> > e;

    public Graph(int n) {
        e = new ArrayList<ArrayList<Edge> >(n);
        for (int i = 0; i < n; ++i) {
            e.add(new ArrayList<Edge>());
        }
    }

    public void addEdge(int f, int t, double r, double c) {
        e.get(f).add(new Edge(t, r, c));
    }

    // SPFA
    public boolean solve(int s, double ws) {
        int[] d = new int[e.size()];
        Arrays.fill(d, -1);
        double[] w = new double[e.size()];
        Arrays.fill(w, 0);
        boolean[] m = new boolean[e.size()];
        Arrays.fill(m, false);
        LinkedList<Integer> q = new LinkedList<Integer>();

        d[s] = 0;
        w[s] = ws;
        m[s] = true;
        q.addLast(s);
        while (!q.isEmpty()) {
            int v = q.getFirst();
            m[v] = false;
            for (Edge edge : e.get(v)) {
                double ww = (w[v] - edge.c) * edge.r;
                if (ww > w[edge.v] + eps) {
                    if ((d[edge.v] = d[v] + 1) >= e.size()) {
                        return true;
                    }
                    w[edge.v] = ww;
                    if (!m[edge.v]) {
                        m[edge.v] = true;
                        q.addLast(edge.v);
                    }
                }
            }
            q.removeFirst();
        }
        return false;
    }
}

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);
        while (in.hasNextInt()) {
            int n = in.nextInt();
            int m = in.nextInt();
            int s = in.nextInt() - 1;
            double v = in.nextDouble();
            Graph g = new Graph(n);
            for (int i = 0; i < m; ++i) {
                int a = in.nextInt() - 1;
                int b = in.nextInt() - 1;
                double r, c;
                r = in.nextDouble();
                c = in.nextDouble();
                g.addEdge(a, b, r, c);
                r = in.nextDouble();
                c = in.nextDouble();
                g.addEdge(b, a, r, c);
            }
            System.out.println(g.solve(s, v) ? "YES" : "NO");
        }
    }
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1759426   2009-02-06 19:07:53     Accepted    1544    Java    0   2748    watashi@Zodiac

// 2012-09-07 00:53:25 | Accepted | 1544 | Java | 310 | 8673 | watashi | Source
