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
    int n, m, c;
    map<int, int> mp;
    vector<pair<int, int> > v;

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d%d", &t[i].a, &t[i].h, &t[i].l, &t[i].r);
        t[i].l /= 100;
        t[i].r /= 100;
        t[i].tag = -1;
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &s[i].b, &s[i].z);
    }
    sort(s, s + m);
    for (int i = 0; i < n; ++i) {
        v.push_back({t[i].a - t[i].h + 1, i});
        v.push_back({t[i].a, i});
        v.push_back({t[i].a + t[i].h, i});
    }
    sort(v.rbegin(), v.rend());

    c = 0;
    p = 1;
    for (int i = 0; i < m; ++i) {
        while (!v.empty() && v.back().first <= s[i].b) {
            int j = v.back().second;
            if (t[j].tag == -1) {
                if (l[j] == 1) {
                    ++c;
                } else if (l[j] > 0) {
                    p *= 1 - l[j];
                }
            } else if (t[j].tag == 0) {
                if (l[j] == 1) {
                    --c;
                } else if (l[j] > 0) {
                    p /= 1 - l[j];
                }
                if (r[j] == 1) {
                    ++c;
                } else if (r[j] > 0) {
                    p *= 1 - r[j];
                }
            } else if (t[j].tag == 1) {
                if (r[j] == 1) {
                    --c;
                } else if (r[j] > 0) {
                    p /= 1 - r[j];
                }
            }
            ++t[j].tag;
            if (c > 0) {
                ans *= ;
            } else {
            }
        }
    }

    return 0;
}

