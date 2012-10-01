#include <queue>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <unordered_set>

using namespace std;

typedef pair<int, int> PII;

const int MAXN = 100100;
const int INF = 1234567890;

int mind[MAXN];
unordered_set<int> st[MAXN];
vector<pair<int, int> > v[MAXN];

int main() {
    int n, m, a, b, c;

    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &a, &b, &c);
        --a;
        --b;
        v[a].push_back(make_pair(b, c));
        v[b].push_back(make_pair(a, c));
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &m);
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a);
            st[i].insert(a);
        }
    }

    priority_queue<PII, vector<PII>, greater<PII> > pq;

    fill(mind, mind + n, INF);
    mind[0] = 0;
    pq.push({mind[0], 0});
    while (!pq.empty()) {
        tie(c, a) = pq.top();
        pq.pop();
        if (mind[a] != c) {
            continue;
        }
        while (st[a].count(c) > 0) {
            ++c;
        }
        for (auto i: v[a]) {
            b = i.first;
            if (mind[b] > c + i.second) {
                mind[b] = c + i.second;
                pq.push({mind[b], b});
            }
        }
    }
    printf("%d\n", mind[n - 1] < INF ? mind[n - 1] : -1);

    return 0;
}

