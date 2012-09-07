import java.util.*;

class Hanoi {
    static final int MAX = 66;
    static final long INF = 1234567890987654321L;
    static final long[][] dp;
    static final int[][] pre;

    static {
        dp = new long[MAX][MAX];
        pre = new int[MAX][MAX];
        for (int i = 0; i < MAX; ++i) {
            Arrays.fill(dp[i], INF);
        }
        for (int j = 1; j < MAX; ++j) {
            dp[1][j] = 1L;
        }
        for (int i = 2; i < MAX; ++i) {
            for (int j = 3; j < MAX; ++j) {
                for (int k = 1; k < i; ++k) {
                    if (dp[i][j] > dp[i - k][j - 1] + 2 * dp[k][j]) {
                        dp[i][j] = dp[i - k][j - 1] + 2 * dp[k][j];
                        pre[i][j] = k;
                    }
                }
            }
        }
    }

    private int n, m;
    private boolean[] b;
    private ArrayList<LinkedList<Integer> > s;

    public Hanoi(int n, int m) {
        // m >= 4
        this.n = n;
        this.m = m;
        b = new boolean[m];
        s = new ArrayList<LinkedList<Integer> >(m);
        for (int i = 0; i < m; ++i) {
            s.add(new LinkedList<Integer>());
        }
    }

    public long moves() {
        return dp[n][m];
    }

    private void move(int an, int am, int f, int t) {
        if (an == 1) {
            int e = s.get(f).pollFirst();
            String str = "move " + (e + 1) + " from " + (f + 1) + " to " + (t + 1);
            if (!s.get(t).isEmpty()) {
                str += " atop " + (s.get(t).getFirst() + 1);
            }
            System.out.println(str);
            s.get(t).addFirst(e);
        } else {
            int p = pre[an][am];
            int q = -1;
            for (int i = 0; i < b.length; ++i) {
                if (i != f && i != t && !b[i]) {
                    q = i;
                    break;
                }
            }
            move(p, am, f, q);
            b[q] = true;
            move(an - p, am - 1, f, t);
            b[q] = false;
            move(p, am, q, t);
        }
    }

    public void print() {
        Arrays.fill(b, false);
        for (LinkedList list : s) {
            list.clear();
        }
        for (int i = 0; i < n; ++i) {
            s.get(0).addLast(i);
        }
        move(n, m, 0, m - 1);
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int re = in.nextInt();
        for (int ri = 1; ri <= re; ++ri) {
            if (ri > 1) {
                System.out.println();
            }
            int n = in.nextInt();
            int m = in.nextInt();
            Hanoi h = new Hanoi(n, m);
            System.out.println(h.moves());
            h.print();
        }
    }
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1788682   2009-03-14 15:02:26     Accepted    2338    Java    0   2348    watashi@Zodiac

// 2012-09-07 15:38:14 | Accepted | 2338 | Java | 770 | 1304 | watashi | Source
