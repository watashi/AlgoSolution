#include <map>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 512;

struct Ones {
    int a[MAXN * MAXN];

    Ones() {
        a[0] = 0;
        for (int i = 1; i < MAXN * MAXN; ++i) {
            a[i] = a[i >> 1] + (i & 1);
        }
    }

    int operator[](int i) const {
        return a[i];
    }
} ones;

struct DisjointSet {
    int r, c;
    int p[MAXN * MAXN];
    int s[MAXN * MAXN];
    map<int, int> mp;   // moon姐说不用map用list可以O(1)的

    void init(int r, int c) {
        this->r = r;
        this->c = c;
        for (int i = 0; i < r * c; ++i) {
            p[i] = i;
            s[i] = 1;
        }
        mp.clear();
    }

    int idx(int x, int y) {
        return (x - 1) * c + (y - 1);
    }

    int root(int i) {
        return i == p[i] ? i : (p[i] = root(p[i]));
    }

    int root(int x, int y) {
        return root(idx(x, y));
    }

    void unionset(int i, int j) {
        i = root(i);
        j = root(j);
        if (i != j) {
            if (--mp[s[i]] == 0) {
                mp.erase(s[i]);
            }
            if (--mp[s[j]] == 0) {
                mp.erase(s[j]);
            }
            p[i] = j;
            s[j] += s[i];
            ++mp[s[j]];
        }
    }

    void unionset(int x1, int y1, int x2, int y2) {
        return unionset(idx(x1, y1), idx(x2, y2));
    }

    long long calc(int a) const {
        long long ret = 0;
        for (map<int, int>::const_iterator i = mp.begin(); i != mp.end(); ++i) {
//          printf("has %d * %d\n", i->first, i->second);
            ret += i->second * (1LL << ones[i->first & a]);
        }
//      printf("sum %lld\n", ret);
        return ret;
    }
} ds;

int a[MAXN][MAXN];
bool b[MAXN][MAXN];
vector<pair<int, pair<int, int> > > v;
vector<pair<int, pair<int, int> > > w;
vector<pair<int, pair<int, int> > >::const_iterator pv, pw;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int main() {
    int r, c, q, x, y;
    vector<long long> ans;

    while (scanf("%d%d", &r, &c) != EOF) {
        memset(a, 0, sizeof(a));
        memset(b, true, sizeof(b));
        v.clear();
        w.clear();

        priority_queue<pair<int, pair<int,  int> > > qq;
        for (int i = 1; i <= r; ++i) {
            for (int j = 1; j <= c; ++j) {
                scanf("%d", &a[i][j]);
                if (i == 1 || i == r || j == 1 || j == c) {
                    qq.push(make_pair(-a[i][j], make_pair(i, j)));
                } else {
                    b[i][j] = false;
                }
            }
        }

        // retreat
        while (!qq.empty()) {
            x = qq.top().second.first;
            y = qq.top().second.second;
            qq.pop();
            for (int i = 0; i < 4; ++i) {
                if (!b[x + dx[i]][y + dy[i]]) {
                    a[x + dx[i]][y + dy[i]] = max(a[x + dx[i]][y + dy[i]], a[x][y]);
                    b[x + dx[i]][y + dy[i]] = true;
                    qq.push(make_pair(-a[x + dx[i]][y + dy[i]], make_pair(x + dx[i], y + dy[i])));
                }
            }
        }


        for (int i = 1; i <= r; ++i) {
            for (int j = 1; j <= c; ++j) {
                v.push_back(make_pair(a[i][j], make_pair(i, j)));
            }
        }

        scanf("%d", &q);
        w.resize(q);
        for (int i = 0; i < q; ++i) {
            scanf("%d%d", &w[i].first, &w[i].second.first);
            w[i].second.second = i;
        }
        ans.resize(q);

        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        pv = v.begin();
        sort(w.begin(), w.end());
        reverse(w.begin(), w.end());
        pw = w.begin();
        ds.init(r, c);

        // process
        while (pw != w.end()) {
//          printf("do [%d] %d\n", pw->second.second, pw->first);
            while (pv != v.end() && pv->first > pw->first) {
//              printf("   [%d][%d] %d\n", pv->second.first, pv->second.second, pv->first);
                x = pv->second.first;
                y = pv->second.second;
                a[x][y] = -1;
                ++ds.mp[1];
                for (int i = 0; i < 4; ++i) {
                    if (a[x + dx[i]][y + dy[i]] == -1) {
                        ds.unionset(x, y, x + dx[i], y + dy[i]);
                    }
                }
                ++pv;
            }
            ans[pw->second.second] = ds.calc(pw->second.first);
            ++pw;
        }

        for (int i = 0; i < q; ++i) {
            printf("%lld\n", ans[i]);
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//617   2010-07-16 23:52:18     Accepted    1083    C++     2510    10688   anotherpeg  Source

// 2012-09-07 15:48:03 | Accepted | 3354 | C++ | 1630 | 10688 | watashi | Source
