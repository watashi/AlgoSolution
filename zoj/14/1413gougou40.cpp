#include <cstdio>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<VPII> VVPII;

void uniform(VPII& v) {
    int x = v.front().first;
    int y = v.front().second;
    for (VPII::const_iterator i = v.begin(); i != v.end(); ++i) {
        x = min(x, i->first);
        y = min(y, i->second);
    }
    for (VPII::iterator i = v.begin(); i != v.end(); ++i) {
        i->first -= x;
        i->second -= y;
    }
    sort(v.begin(), v.end());
}

VPII _minpres3(VPII v) {
    VPII ret(v);
    for (VPII::iterator i = v.begin(); i != v.end(); ++i) {
        swap(i->first, i->second);
    }
    uniform(v);
    ret = min(ret, v);
    return ret;
}

VPII _minpres2(VPII v) {
    VPII ret(_minpres3(v));
    for (VPII::iterator i = v.begin(); i != v.end(); ++i) {
        i->second = -i->second;
    }
    uniform(v);
    ret = min(ret, _minpres3(v));
    return ret;
}

VPII _minpres1(VPII v) {
    VPII ret(_minpres2(v));
    for (VPII::iterator i = v.begin(); i != v.end(); ++i) {
        i->first = -i->first;
    }
    uniform(v);
    ret = min(ret, _minpres2(v));
    return ret;
}

void minpres(VPII& v) {
    uniform(v);
    v = _minpres1(v);
}

const int MAXN = 128;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
/*
void dump(int x) {
    printf("%d", x);
}

template<typename T, typename S>
void dump(const pair<T, S>& p) {
    printf("(");
    dump(p.first);
    printf(", ");
    dump(p.second);
    printf(")");
}

template<typename T>
void dump(const vector<T>& v) {
    printf("{");
    for (typename vector<T>::const_iterator i = v.begin(); i != v.end(); ++i) {
        dump(*i);
        printf(", ");
    }
    puts("}");
}
*/
void gao(int r, int c, int n, VVPII& ret) {
    static int x, y, p;
    static bool a[MAXN][MAXN];

    memset(a, 0, sizeof(a));
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &x, &y);
        a[x + 1][y + 1] = true;
    }

    ret.clear();
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            if (!a[i][j]) {
                continue;
            }
            ret.push_back(VPII());
            a[i][j] = false;
            ret.back().push_back(make_pair(i, j));
            p = 0;
            while (p < (int)ret.back().size()) {
                x = ret.back()[p].first;
                y = ret.back()[p].second;
                ++p;
                for (int k = 0; k < 4; ++k) {
                    if (a[x + dx[k]][y + dy[k]]) {
                        a[x + dx[k]][y + dy[k]] = false;
                        ret.back().push_back(make_pair(x + dx[k], y + dy[k]));
                    }
                }
            }
            minpres(ret.back());
        }
    }
    sort(ret.begin(), ret.end());
//  dump(ret);
}

int main() {
    int re, r, c, n;
    VVPII a, b;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d%d%d", &r, &c, &n);
        gao(r, c, n, a);
        gao(r, c, n, b);
        puts(a == b ? "YES" : "NO");
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//362   2010-07-05 19:32:04     Accepted    1029    C++     10  196     anotherpeg  Source

// 2012-09-30 23:40:15 | Accepted | 1413 | C++ | 0 | 196 | watashi | Source
