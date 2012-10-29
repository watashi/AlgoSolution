#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 200200;

vector<pair<int, int> > e;
vector<int> v[MAXN], w;
int d[MAXN];

int main() {
    int n, m, s, t;

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &d[i]);
        v[d[i]].push_back(i);
    }
    for (int i = m; i > 0; --i) {
        while (!v[i].empty()) {
            s = v[i].back();
            v[i].pop_back();
            for (int j = i; j > 0; --j) {
                while (d[s] > 0 && !v[j].empty()) {
                    t = v[j].back();
                    v[j].pop_back();
                    w.push_back(t);
                    --d[s];
                    --d[t];
                    e.push_back({s, t});
                }
            }
            if (d[s] != 0) {
                puts("No");
                return 0;
            }
            for (int j: w) {
                v[d[j]].push_back(j);
            }
            w.clear();
        }
    }

    puts("Yes");
    printf("%d\n", (int)e.size());
    for (auto i: e) {
        printf("%d %d\n", i.first + 1, i.second + 1);
    }

    return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//1132960 	Feb 2, 2012 4:02:35 PM 	watashi 	134C - Swaps 	GNU C++0x 	Accepted 	140 ms 	8200 KB
