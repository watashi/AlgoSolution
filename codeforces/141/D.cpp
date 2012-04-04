#include <queue>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

const int MAXN = 200200;
const int INF = 1000000007;

struct Ramp {
    int i, x, d, t, p;

    bool operator<(int o) const {
        return x < o;
    }

    bool operator<(const Ramp& o) const {
        return x < o.x;
    }
} r[MAXN], rr;

struct Edge {
    int a, b, c, t;

    Edge(int a, int b, int c, int t = -1): a(a), b(b), c(c), t(t) {
    }
};

vector<Edge> e[MAXN];

int d[MAXN];
const Edge* pre[MAXN];

int main() {
    int n, m;

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        r[i].i = i + 1;
        scanf("%d%d%d%d", &r[i].x, &r[i].d, &r[i].t, &r[i].p);
        r[n + i].i = -1;
        r[n + i].x = r[i].x + r[i].d;
    }
    n += n;
    r[n].x = 0;
    r[n + 1].x = m;
    r[n].i = r[n + 1].i = -1;
    n += 2;
    sort(r, r + n);

    for (int i = 1; i < n; ++i) {
        e[i - 1].push_back(Edge(i - 1, i, r[i].x - r[i - 1].x));
        e[i].push_back(Edge(i, i - 1, r[i].x - r[i - 1].x));
    }
    for (int i = 0; i < n; ++i) {
        if (r[i].i == -1 || r[i].x < r[i].p) {
            continue;
        }
        rr.x = r[i].x - r[i].p;
        int a = lower_bound(r, r + n, rr) - r;
        rr.x = r[i].x + r[i].d;
        int b = lower_bound(r, r + n, rr) - r;
        for (int aa = a - 1; aa <= a; ++aa) {
            for (int bb = b; bb <= b; ++bb) {
                if (0 <= aa && aa < bb && bb < n) {
                    int cc = r[i].p + r[i].t;
                    cc += abs(r[i].x - r[i].p - r[aa].x);
                    cc += abs(r[i].x + r[i].d - r[bb].x);
                    e[aa].push_back(Edge(aa, bb, cc, r[i].i));
                }
            }
        }
    }

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    fill(d, d + n, INF);
    fill(pre, pre + n, (Edge*)NULL);
    d[0] = 0;
    q.push({d[0], 0});
    while (!q.empty()) {
        int t = q.top().first;
        int v = q.top().second;
        q.pop();
        if (d[v] != t) {
            continue;
        }
        for (const Edge& w: e[v]) {
            if (d[w.b] > t + w.c) {
                d[w.b] = t + w.c;
                q.push({d[w.b], w.b});
                pre[w.b] = &w;
            }
        }
    }
    printf("%d\n", d[n - 1]);

    vector<int> ans;
    for (int i = n - 1; i > 0; i = pre[i]->a) {
        if (pre[i]->t != -1) {
            ans.push_back(pre[i]->t);
        }
    }
    reverse(ans.begin(), ans.end());
    printf("%d\n", (int)ans.size());
    for (int i: ans) {
        printf("%d ", i);
    }

    return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//1146625 	Feb 3, 2012 3:41:05 PM 	watashi 	141D - Take-off Ramps 	GNU C++0x 	Accepted 	440 ms 	24900 KB
