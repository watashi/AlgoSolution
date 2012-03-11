#include <map>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n, m, x, y;
    vector<pair<int, int> > a, b, c;

    scanf("%d%d%d%d", &n, &m, &x, &y);
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i].first);
        a[i].first -= x;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end());
    b.resize(m);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &b[i].first);
        b[i].second = i + 1;
    }
    sort(b.begin(), b.end());
    y += x;
    for (int i = 0, j = 0; i < n && j < m; ++j) {
        while (i < n && a[i].first + y < b[j].first) {
            ++i;
        }
        if (i < n && a[i].first <= b[j].first) {
            c.push_back({a[i].second, b[j].second});
            ++i;
        }
    }
    printf("%d\n", (int)c.size());
    for (auto& i: c) {
        printf("%d %d\n", i.first, i.second);
    }

    return 0;
}

