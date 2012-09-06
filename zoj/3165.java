// Flow Cut Dinic

import java.io.*;
import java.util.*;

class Edge {
    int v, c;
    Edge r;

    public Edge(int v, int c) {
        this.v = v;
        this.c = c;
        this.r = null;
    }
}

class FlowNetwork {
    int n, source, sink;
    int[] d;
    ArrayList<ArrayList<Edge> > edge;

    public FlowNetwork(int n, int source, int sink) {
        this.n = n;
        this.source = source;
        this.sink = sink;
        this.d = new int[n];
        this.edge = new ArrayList<ArrayList<Edge> >(n);
        for (int i = 0; i < n; ++i) {
            edge.add(new ArrayList<Edge>());
        }
    }

    public void addEdge(int a, int b, int c) {
        Edge x = new Edge(b, c);
        Edge y = new Edge(a, 0);
        x.r = y;
        y.r = x;
        edge.get(a).add(x);
        edge.get(b).add(y);
    }

    private void bfs() {
        int[] q = new int[n];
        Arrays.fill(d, -1);
        q[0] = source;
        d[source] = 0;
        int begin = 0, end = 1;
        while (begin < end) {
            int front = q[begin++];
            for (Edge e : edge.get(front)) {
                if (e.c > 0 && d[e.v] == -1) {
                    d[e.v] = d[front] + 1;
                    q[end++] = e.v;
                }
            }
        }
    }

    private void augment() {
        int[] done = new int[n];
        int[] path = new int[n];
        Arrays.fill(done, 0);
        int len = 0;
        path[0] = source;
        while (len >= 0) {
            int back = path[len];
            if (back == sink) {
                int flow = Integer.MAX_VALUE;
                int todo = -1;
                for (int i = 0; i < len; ++i) {
                    Edge e = edge.get(path[i]).get(done[path[i]]);
                    if (e.c < flow) {
                        flow = e.c;
                        todo = i;
                    }
                }
                for (int i = 0; i < len; ++i) {
                    Edge e = edge.get(path[i]).get(done[path[i]]);
                    e.c -= flow;
                    e.r.c += flow;
                }
                len = todo;
            } else {
                while (done[back] < edge.get(back).size()) {
                    Edge e = edge.get(back).get(done[back]);
                    if (d[e.v] == d[back] + 1 && e.c > 0) {
                        break;
                    } else {
                        ++done[back];
                    }
                }
                if (done[back] == edge.get(back).size()) {
                    d[back] = -1; // !!
                    --len;
                } else {
                    path[++len] = edge.get(back).get(done[back]).v;
                }
            }
        }
    }

    public int solve() {
        while (true) {
            bfs();
            if (d[sink] == -1) {
                break;
            } else {
                augment();
            }
        }
        int ret = 0;
        for (Edge e : edge.get(source)) {
            ret += e.r.c;
        }
        return ret;
    }

    public boolean[] cut() {
        boolean[] ret = new boolean[n];
        for (int i = 0; i < n; ++i) {
            ret[i] = (d[i] == -1);
        }
        return ret;
    }
}

public class Main {
    static int ch;

    public static int nextInt() throws IOException {
        do {
            ch = System.in.read();
        } while (Character.isWhitespace(ch));
        int ret = 0;
        while (Character.isDigit(ch)) {
            ret *= 10;
            ret += Character.digit(ch, 10);
            ch = System.in.read();
        }
        return ret;
    }

    public static void main (String[] args) throws IOException {
        while (true) {
            int m = nextInt();
            if (ch == -1) {
                break;
            }
            int n = nextInt();
            int s = nextInt();
            FlowNetwork fn = new FlowNetwork(m + n + 2, m + n, m + n + 1);
            int ans = 0;
            for (int i = 0; i < m; ++i) {
                int v = nextInt();
                fn.addEdge(m + n, i, v);
                ans += v;
            }
            for (int i = 0; i < n; ++i) {
                int v = nextInt();
                fn.addEdge(m + i, m + n + 1, v);
                ans += v;
            }
            for (int i = 0; i < s; ++i) {
                int a = nextInt() - 1;
                int b = nextInt() - 1;
                fn.addEdge(a, m + b, Integer.MAX_VALUE);
            }
            ans -= fn.solve();
            boolean[] cut = fn.cut();
            ArrayList<Integer> S = new ArrayList<Integer>();
            ArrayList<Integer> T = new ArrayList<Integer>();
            for (int i = 0; i < m; ++i) {
                if (!cut[i]) {
                    S.add(i + 1);
                }
            }
            for (int i = 0; i < n; ++i) {
                if (cut[m + i]) {
                    T.add(i + 1);
                }
            }
            System.out.println(ans + " " + S.size() + " " + T.size());
            for (int i = 0; i < S.size(); ++i) {
                System.out.print(S.get(i) + (i == S.size() - 1 ? "\n" : " "));
            }
            for (int i = 0; i < T.size(); ++i) {
                System.out.print(T.get(i) + (i == T.size() - 1 ? "\n" : " "));
            }
        }
    }
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1801311   2009-03-23 23:13:28     Accepted    3165    Java    0   3854    watashi@Zodiac

/*
 * ZOJ BUG
Submit Time     Language    Run Time(ms)    Run Memory(KB)      User Name
2009-03-23 23:13:28     Java    0   3854    watashi@Zodiac
2009-03-09 19:54:26     C++     420     16008   Qu Jun
2009-02-16 00:16:21     C++     460     672     jackfeng
2009-02-15 18:44:36     C++     500     732     AngelClover
2009-02-16 04:14:28     C++     500     3300    huicpc035
2009-02-24 13:47:42     C++     510     1072    Scintilla
2009-02-20 12:33:55     FPC     530     512     maomingming
2009-03-01 11:35:04     C++     580     14124   小蜜蜂
2009-03-22 00:51:30     C++     590     5204    f_clocy
2009-02-15 18:42:09     C++     620     356     dandelion
2009-02-24 20:27:34     C++     620     620     small_number
2009-02-16 11:14:35     C++     650     540     北极天南星
2009-02-22 23:19:18     C++     650     24772   foresekeeper
2009-02-16 21:23:24     C++     670     8388    prayer
2009-02-24 20:12:06     C++     680     828     Tsubasa
2009-02-16 13:54:35     C++     680     8388    从头来过
*/

// 2012-09-07 02:05:12 | Accepted | 3165 | Java | 1320 | 18934 | watashi | Source
