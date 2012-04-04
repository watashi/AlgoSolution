#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100100;

struct Tree {
    int a, h, l, r;
    int tag;
} t[MAXN];

struct Mushroom {
    int b, z;
    bool operator<(const Mushroom& o) const {
        return b < o.b;
    }
} s[MAXN];

int main() {
    int n, m;
    int cnt[101];
    double tmp, ans;
    vector<pair<int, int> > v;

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d%d", &t[i].a, &t[i].h, &t[i].l, &t[i].r);
        t[i].tag = 0;
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &s[i].b, &s[i].z);
    }
    sort(s, s + m);
    for (int i = 0; i < n; ++i) {
        v.push_back({t[i].a - t[i].h, i});
        v.push_back({t[i].a, i});
        v.push_back({t[i].a + 1, i});
        v.push_back({t[i].a + 1 + t[i].h, i});
    }
    sort(v.rbegin(), v.rend());

    ans = 0;
    fill(cnt, cnt + 101, 0);
    for (int i = 0; i < m; ++i) {
        while (!v.empty() && v.back().first <= s[i].b) {
            int j = v.back().second;
            v.pop_back();
            switch (t[j].tag++) {
            case 0: ++cnt[100 - t[j].l]; break;
            case 1: --cnt[100 - t[j].l]; break;
            case 2: ++cnt[100 - t[j].r]; break;
            case 3: --cnt[100 - t[j].r]; break;
            }
            //    printf("%d %d %d %d %d\n", s[i].b, j, cnt[0], cnt[50], cnt[100]);
        }
        if (cnt[0] == 0) {
            tmp = 1;
            for (int j = 1; j < 100; ++j) {
                if (cnt[j] > 0) {
                    tmp *= pow(j / 100.0, cnt[j]);
                }
            }
            ans += s[i].z * tmp;
        }
    }
    printf("%.10lf\n", ans);

    return 0;
}

