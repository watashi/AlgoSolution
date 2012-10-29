#include <queue>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 100100;
const int INF = 1000000007;

struct Edge {
    int v, w;
    Edge(int v, int w): v(v), w(w) { }
};

int mark[MAXN];
int d[MAXN];
vector<Edge> e[MAXN];

int main() {
    int n, m, s, a, b, c;

    scanf("%d%d%d", &n, &m, &s);
    fill(mark, mark + n, false);
    fill(d, d + n, INF);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &a, &b, &c);
        --a;
        --b;
        e[a].push_back({b, c});
        e[b].push_back({a, c});
    }

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    --s;
    d[s] = 0;
    q.push({-d[s], s});
    scanf("%d", &s);

    m = 0;
    while (!q.empty()) {
        c = q.top().first;
        a = q.top().second;
        q.pop();
        if (d[a] != c) {
            continue;
        }
        if (d[a] == s) {
            ++m;
        }
        mark[a] = true;
        for (auto& i: e[a]) {
            if (mark[i.v]) {
                if (d[i.v] < s) {
                    b = s - d[i.v];
                    if (b < i.w) {
                        if (s < d[a] + (i.w - b)) {
                            ++m;
                            if (d[a] < s) {
                                ++m;
                            }
                        } else if (s == d[a] + (i.w - b)) {
                            ++m;
                        }
                    }
                }
            } else if (d[i.v] > d[a] + i.w) {
                d[i.v] = d[a] + i.w;
                q.push({d[i.v], i.v});
            }
        }
    }
    printf("%d\n", m);

    return 0;
}
//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//1133411 	Feb 2, 2012 5:49:15 PM 	watashi 	144D - Missile Silos 	GNU C++0x 	Accepted 	200 ms 	6700 KB
