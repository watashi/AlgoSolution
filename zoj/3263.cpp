#include <map>
#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <cassert>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

const int MAXQ = 23;
const int MAXN = 221;
const double EPS = 1e-6;
const double INF = 2e21;

double d[MAXN];
vector<pair<int, double> > e[MAXN];

double dijkstra(int n, int s, int t, double v, double ex[MAXN]) {
    if (s == t) {
        return 0;
    }
    fill(d, d + n, INF);
    d[s] = -ex[s];
    priority_queue<pair<double, int>,
            vector<pair<double, int> >,
            greater<pair<double, int> > > q;
    q.push(make_pair(d[s], s));
    while (!q.empty()) {
        double dis = q.top().first;
        int cur = q.top().second;
        q.pop();
        if (d[cur] != dis) {
            continue;
        }
        dis += ex[cur];
        if (cur == t) {
            break;
        }
        for (vector<pair<int, double> >::const_iterator it = e[cur].begin(); it != e[cur].end(); ++it) {
            double tmp = dis + it->second / v;
            if (d[it->first] > tmp) {
                d[it->first] = tmp;
                q.push(make_pair(d[it->first], it->first));
            }
        }
    }
    return d[t];
}


int main() {
    char buf[1024];
    int n, m, q, a, b, s[MAXQ];
    double c, x[MAXQ], y[MAXQ], t[MAXQ][MAXN];
    double ql[MAXQ], qr[MAXQ], qm[MAXQ];

    while (scanf("%d%d%d", &n, &m, &q) != EOF) {
        // input
        assert(1 <= n && n <= 100); // 1 <= N <= 100
        assert(1 <= m && m <= 1000);    // 1 <= M 1000
        assert(1 <= q && q <= 16); // 1 <= Q <= 16
        map<string, int> mp;
        for (int i = 0; i < n; ++i) {
            assert(scanf("%s", buf) == 1);
            mp[buf] = i;
            e[i].clear();
        }
        assert(mp.find("Hakurei_Shrine") != mp.end());
        assert((int)mp.size() == n);
        for (int i = 0; i < m; ++i) {
            assert(scanf("%s", buf) == 1);
            assert(mp.find(buf) != mp.end());
            a = mp[buf];
            assert(scanf("%s", buf) == 1);
            assert(mp.find(buf) != mp.end());
            b = mp[buf];
            assert(scanf("%lf", &c) == 1);
            assert(0.01 <= c && c <= 1e6);
            e[a].push_back(make_pair(b, c));
            e[b].push_back(make_pair(a, c));
        }
        for (int i = 0; i < q; ++i) {
            assert(scanf("%*s%s", buf) == 1);
            assert(mp.find(buf) != mp.end());
            s[i] = mp[buf];
            assert(scanf("%lf%lf", &x[i], &y[i]) == 2);
            assert(0.01 <= x[i] && x[i] <= 1e6);
            assert(0.01 <= y[i] && y[i] <= 1e6);
            for (int j = 0; j < n; ++j) {
                assert(scanf("%lf", &t[i][j]) == 1);
                assert(0.01 <= t[i][j] && t[i][j] <= 1e6);
            }
        }
        assert(scanf("%lf", &c) == 1);
        assert(0.1 <= c && c <= 1e6);
        // gao
        s[q] = mp["Hakurei_Shrine"];
        double l = 0;
        double r = 0;
        for (int i = 0; i < q; ++i) {
            ql[i] = 0;
            qr[i] = c + 1;
            r = max(r, dijkstra(n, s[i], s[q], x[i], t[i]));
        }
        while (r - l > EPS && (r - l) / r > EPS) {
            double mid = (l + r) / 2;
            double cmp = c;
            for (int j = 0; j < q; ++j) {
                double ll = ql[j];
                double rr = qr[j];
                while (rr - ll > EPS && (rr - ll) / c > EPS) {
                    double mm = (ll + rr) / 2;
                    if (dijkstra(n, s[j], s[q], x[j] + y[j] * sqrt(mm), t[j]) <= mid) { // OK
                        rr = mm;
                    } else {
                        ll = mm;
                    }
                }
                qm[j] = (ll + rr) / 2;
                cmp -= qm[j];
                if (cmp < 0) {
                    for (int k = 0; k <= j; ++k) {
                        qr[k] = qm[k];
                    }
                    l = mid;
                    break;
                }
            }
            if (cmp >= 0) { // OK
                for (int k = 0; k < q; ++k) {
                    ql[k] = qm[k];
                }
                r = mid;
            }
        }
        // output
        printf("%.16lf\n", (l + r) / 2);
    }

    return 0;
}

// 2012-09-07 15:46:00 | Accepted | 3263 | C++ | 980 | 184 | watashi | Source
