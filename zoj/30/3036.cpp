#include <algorithm> // auto fix CE
#include <map>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <utility>

using namespace std;

map<string, int> mp;

int get_id(const string& str)
{
    int ret;

    if (mp.count(str) == 0) {
        ret = mp.size();
        mp[str] = ret;
    }
    else {
        ret = mp[str];
    }

    return ret;
}

template<int MAXN>
struct DisjointSet
{
    int p[MAXN];
    void clear(int n)
    {
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
    }
    int root(int x)
    {
        return p[x] == x ? x : (p[x] = root(p[x]));
    }
    void set_friend(int i, int j)
    {
        i = root(i);
        j = root(j);
        p[i] = j;
    }
    bool is_friend(int i, int j)
    {
        return root(i) == root(j);
    }
};

DisjointSet<2008> ds;

int main()
{
    int re, n, m, ans;
    vector<pair<int, pair<int, int> > > e;
    static char from[256], to[256];

    scanf("%d", &re);
    while(re--) {
        scanf("%d%d", &n, &m);
        mp.clear();
        ds.clear(n);
        e.resize(m);
        for(int i = 0; i < m; i++) {
            scanf("%s%s%d", from, to, &e[i].first);
            e[i].second = make_pair(get_id(from), get_id(to));
        }
        sort(e.begin(), e.end());
        ans = 0;
        for (int i = 0; n > 1 && i < m; i++) {
            if (!ds.is_friend(e[i].second.first, e[i].second.second)) {
                ds.set_friend(e[i].second.first, e[i].second.second);
                ans += e[i].first;
                --n;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//3048765   2008-08-24 13:40:26     Accepted    3036    C++     00:00.55    1560K   watashi@Zodiac

// 2012-09-07 13:37:42 | Accepted | 3036 | C++ | 280 | 908 | watashi | Source
