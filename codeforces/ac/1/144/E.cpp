#include <set>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    int n, m, r, c;
    set<int> s;
    vector<int> w;
    vector<pair<pair<int, int>, int> > v;

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        s.insert(i + 1);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &r, &c);
        v.push_back({{r, n + 1 - c}, i + 1});
    }
    sort(v.begin(), v.end());

    r = 1;
    for (auto i: v) {
        auto j = s.lower_bound(i.first.second);
        if (j != s.end() && *j <= i.first.first) {
            s.erase(j);
            w.push_back(i.second);
        }
    }
    printf("%d\n", (int)w.size());
    for (int i: w) {
        printf("%d ", i);
    }

    return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//1133483 	Feb 2, 2012 6:16:30 PM 	watashi 	144E - Competition 	GNU C++0x 	Accepted 	190 ms 	6800 KB
