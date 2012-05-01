#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

bool test(int i, int j) {
    return ((i >> j) & 1) != 0;
}

int set(int i, int j) {
    return i | (1 << j);
}

int main() {
    int n, m, q;
    int a, b, c, d;
    vector<pair<int, pair<int, int>>> e;

    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &a, &b, &c);
        e.push_back({c, {a - 1, b - 1}});
    }
    sort(e.rbegin(), e.rend());

    priority_queue<pair<pair<int, int>, pair<int, int>>> pq;
    pq.push({{0, e.size()}, {0, 0}});
    while (q > 0) {
        d = pq.top().first.first;
        c = pq.top().first.second;
        b = pq.top().second.first;
        a = pq.top().second.second;
        pq.pop();
        if (--q == 0) {
            printf("%d\n", -d);
            break;
        }
        for (int i = c - 1; i >= 0; --i) {
            if (!test(b, e[i].second.first) && !test(a, e[i].second.second)) {
                pq.push({{d - e[i].first, i},
                    {set(b, e[i].second.first), set(a, e[i].second.second)}});
            }
        }
    }

    return 0;
}

/*
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
1643545 	Apr 29, 2012 11:34:17 AM 	watashi 	F2 - Script Generation (70 points) 	GNU C++0x 	Accepted 	630 ms 	198400 KB
1643543 	Apr 29, 2012 11:34:10 AM 	watashi 	F1 - Script Generation (30 points) 	GNU C++0x 	Accepted 	30 ms 	1400 KB
*/
