#include <set>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void read(int n, vector<int>& ret) {
    ret.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &ret[i]);
    }
}

int main() {
    int n, m, r;
    vector<int> a, b;

    scanf("%d%d", &n, &m);
    read(n, a);
    read(n, b);

    multiset<int> x(b.begin(), b.end());
    r = 0;
    sort(a.begin(), a.end());
    for (int i: a) {
        auto j = x.lower_bound(m - i);
        if (j != x.end()) {
            ++r;
            x.erase(j);
        }
    }

    printf("%d %d\n", 1, max(1, r));

    return 0;
}

