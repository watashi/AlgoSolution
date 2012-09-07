import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    private static int buffer = -1;

    public static int nextInt() throws IOException {
        int ret = 0;

        while (!Character.isDigit(buffer)) {
            buffer = System.in.read();
        }
        do {
            ret *= 10;
            ret += Character.digit(buffer, 10);
            buffer = System.in.read();
        } while (Character.isDigit(buffer));

        return ret;
    }

    private static final int ROOT = 0;

    private ArrayList<ArrayList<Integer> > e;
    private boolean done;
    private int depth, count;
    private int[] m, d, f, u;

    public Main(int n) {
        e = new ArrayList<ArrayList<Integer> >(n);
        for (int i = 0; i < n; ++i) {
            e.add(new ArrayList<Integer>());
        }
        done = false;
        m = new int[n];
        d = new int[n];
        f = new int[n];
        u = new int[n];
    }

    public void add(int a, int b) {
        e.get(a).add(b);
        e.get(b).add(a);
        done = false;
    }

    public ArrayList<Integer> cutVertex() {
        ArrayList<Integer> ret = new ArrayList<Integer>();

        gao();
        Arrays.fill(m, 0);
        // ROOT
        if (count >= 2) {
            ret.add(ROOT);
        }
        m[ROOT] = 1;
        // !ROOT
        for (int i = 1; i < m.length; ++i) {
            if (m[f[i]] == 0 && u[i] >= d[f[i]]) {
                ret.add(f[i]);
                m[f[i]] = 1;
            }
        }

        return ret;
    }

    /*
    // Bridge
    public ArrayList<...> cutEdge() {

    }
    */

    private void dfs(int p) {
        d[p] = depth;
        u[p] = depth;
        m[p] = 1;
        ++depth;
        for (int i : e.get(p)) {
            if (i == f[p]) {
                continue;
            }
            if (m[i] == 1) {
                u[p] = Math.min(u[p], d[i]);
            } else if (m[i] == 0) {
                if (p == ROOT) {
                    ++count;
                }
                f[i] = p;
                dfs(i);
                u[p] = Math.min(u[p], u[i]);
            }
        }
        --depth;
        m[p] = 2;
    }

    private void gao() {
        if (done) {
            return;
        }
        // !assert! connected
        Arrays.fill(m, 0);
        f[ROOT] = -1;
        depth = 0;
        count = 0;
        dfs(ROOT);
        done = true;
    }

    // main
    public static void main(String[] args) throws IOException {
        /*
        // TLE
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        Scanner in = new Scanner(System.in);

        while (true) {
            int n = Integer.parseInt(in.readLine());
            while (true) {
                String[] a = in.readLine().split(" ");
                int a0 = Integer.parseInt(a[0]);
                if (a0 == 0) {
                    break;
                }else {
                    for (int i = 1; i < a.length; ++i) {
                        solution.add(a0 - 1, Integer.parseInt(a[i]) - 1);
                    }
                }
            }
            System.out.println(solution.cutVertex().size());
        }
        */
        int n, a;

        while ((n = nextInt()) != 0) {
            Main solution = new Main(n);
            while ((a = nextInt()) != 0) {
                while (buffer != '\n') {
                    solution.add(a - 1, nextInt() - 1);
                }
            }
            System.out.println(solution.cutVertex().size());
        }
    }
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1750643   2009-01-29 01:38:05     Accepted    1311    Java    0   1453    watashi@Zodiac

// 2012-09-07 13:57:45 | Accepted | 1311 | Java | 160 | 1478 | watashi | Source
