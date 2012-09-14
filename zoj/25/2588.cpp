// cutEdge bridge graph-connectivity

/*
import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    private static final int ROOT = 0;
    private ArrayList<ArrayList<Integer> > e;
    private Hashtable<Integer, Integer> tab;
    private int depth;
    private int[] m, u, d;
    private ArrayList<Integer> a;

    public Main(int n) {
        e = new ArrayList<ArrayList<Integer> >(n);
        for (int i = 0; i < n; i++) {
            e.add(new ArrayList<Integer>());
        }
        tab = new Hashtable<Integer, Integer>();
        m = new int[n];
        u = new int[n];
        d = new int[n];
        a = new ArrayList<Integer>();
    }

    private int hash(int a, int b) {
        if (a <= b) {
            return a * 10000 + b;
        } else {
            return b * 10000 + a;
        }
    }

    public void add(int a, int b, int c) {
        e.get(a).add(b);
        e.get(b).add(a);
        int tmp = hash(a, b);
        if (tab.put(tmp, c) != null) {
            tab.put(tmp, -1);
        }
    }

    private void dfs(int p, int f) {
        d[p] = depth;
        u[p] = depth;
        m[p] = 1;
        ++depth;
        for (int i : e.get(p)) {
            if (i == f) {
                continue;
            }
            if (m[i] == 1) {
                u[p] = Math.min(u[p], d[i]);
            } else if (m[i] == 0) {
                dfs(i, p);
                u[p] = Math.min(u[p], u[i]);
                if (u[i] > d[p]) {
                    int tmp = tab.get(hash(i, p));
                    if (tmp != -1) {
                        a.add(tmp);
                    }
                }
            }
        }
        --depth;
        m[p] = 2;
    }

    public void solve() {
        // !assert! connected
        depth = 0;
        Arrays.fill(m, 0);
        dfs(ROOT, -1);

        Collections.sort(a);
        System.out.println(a.size());
        for (int i = 0; i < a.size(); i++) {
            if (i > 0) {
                System.out.print(' ');
            }
            System.out.print(a.get(i));
        }
        System.out.println();
    }

    // static
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

    public static void main(String[] args) throws IOException {
        int re = nextInt();
        for (int ri = 1; ri <= re; ri++) {
            int n = nextInt();
            int m = nextInt();
            Main solution = new Main(n);
            for (int i = 1; i <= m; i++) {
                int a = nextInt();
                int b = nextInt();
                solution.add(a - 1, b - 1, i);
            }
            solution.solve();
            if (ri < re) {
                System.out.println();
            }
        }
    }
}
*/

#include <map>
#include <cctype>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int ROOT = 0;
const int MAXN = 10001;

map<int, int> tab;
vector<int> e[MAXN];
int m[MAXN], u[MAXN], d[MAXN];
int depth, temp;
vector<int> ans;

int hash(int a, int b) {
    if (a <= b) {
        return a * 10000 + b;
    } else {
        return b * 10000 + a;
    }
}

void clear(int n) {
    tab.clear();
    for (int i = 0; i < n; ++i) {
        e[i].clear();
    }
    fill(m, m + n, 0);
    depth = 0;
    ans.clear();
}

void add(int a, int b, int c) {
    e[a].push_back(b);
    e[b].push_back(a);
    temp = hash(a, b);
    if (tab.count(temp) == 0) {
        tab[temp] = c;
    } else {
        tab[temp] = -1;
    }
}

void dfs(int p, int f) {
    d[p] = depth;
    u[p] = depth;
    m[p] = 1;
    ++depth;
    for (int i = 0; i < e[p].size(); ++i) {
        int t = e[p][i];
        if ((t = e[p][i]) == f) {
            continue;
        }
        if (m[t] == 1) {
            u[p] = min(u[p], d[t]);
        } else if (m[t] == 0) {
            dfs(t, p);
            u[p] = min(u[p], u[t]);
            if (u[t] > d[p]) {
                temp = tab[hash(t, p)];
                if (temp != -1) {
                    ans.push_back(temp);
                }
            }
        }
    }
    --depth;
    m[p] = 2;
}

void solve() {
    // !assert! connected
    dfs(ROOT, -1);
    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) {
        printf("%d%c", ans[i], (i == ans.size() - 1) ? '\n' : ' ');
    }
}

void nextInt(int& i) {
    static char ch = 0;

    while (!isdigit(ch = getchar())) {
        continue;
    }
    i = 0;
    do {
        i *= 10;
        i += ch - '0';
    } while (isdigit(ch = getchar()));
}

int main() {
    int re, n, m, a, b;

    nextInt(re);
    for (int ri = 1; ri <= re; ri++) {
        nextInt(n);
        nextInt(m);
        clear(n);
        for (int i = 1; i <= m; i++) {
            nextInt(a);
            nextInt(b);
            add(a - 1, b - 1, i);
        }
        solve();
        if (ri < re) {
            puts("");
        }
    }

    return 0;
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1752139   2009-01-30 22:33:31     Accepted    2588    C++     1040    7416    watashi@Zodiac

// 2012-09-07 15:41:10 | Accepted | 2588 | C++ | 1090 | 7412 | watashi | Source
