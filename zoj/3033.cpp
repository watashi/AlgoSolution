// 必希龙龙

#include <queue>
#include <limits>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

template<class T>
bool SPFA(int n, int s, vector<pair<int, T> > e[], T mind[], int pre[])
{
    queue<int> q;
    vector<int> d(n, 0);
    vector<bool> mark(n, false);

    fill(pre, pre + n, -1);
    fill(mind, mind + n, numeric_limits<T>::max());
    pre[s] = s;
    mind[s] = 0;
    mark[s] = true;
    q.push(s);
    while (!q.empty()) {
        s = q.front();
        mark[s] = false;
        q.pop();
        for (typename vector<pair<int, T> >::const_iterator i =e[s].begin(); i != e[s].end(); ++i) {
            if (mind[i->first] > mind[s] + i->second) {
                mind[i->first] = mind[s] + i->second;
                d[i->first] = d[s] + 1;
                pre[i->first] = s;
                if (d[i->first] >= n) {
                    return false;
                }
                if (!mark[i->first]) {
                    mark[i->first] = true;
                    q.push(i->first);
                }
            }
        }
    }

    return true;
}

vector<pair<int, long long> > e[303];
long long mind[303];
int pre[303];

int main()
{
    int re, n, m, s, t;
    int a, b;
    long long c;

    scanf("%d", &re);
    while (re--) {
        scanf("%d%d%d%d", &n, &s, &t, &m);
        for (int i = 0; i < n; i++) {
            e[i].clear();
        }
        while (m--) {
            scanf("%d%d%lld", &a, &b, &c);
            e[a].push_back(make_pair(b, c));
        }
        if (!SPFA(n, s, e, mind, pre) || pre[t] == -1) {
            puts("infinity");
        }
        else {
            printf("%lld\n", mind[t]);
        }
    }

    return 0;
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//3048177   2008-08-24 02:30:58     Accepted    3033    C++     00:00.31    872K    watashi@Zodiac

/*
Rank    Submit time     Run time    Run memory      Language    User
1   2008-08-23 14:09:19     00:00.29    1636K   C++     nbut_vegetable
2   2008-08-24 02:30:58     00:00.31    872K    C++     watashi@Zodiac
3   2008-08-23 19:06:23     00:00.71    1912K   C++     chinachen
4   2008-08-23 15:22:08     00:00.74    2012K   C++     zjl
5   2008-08-23 19:17:01     00:00.96    980K    C++     Rainco
6   2008-08-23 19:16:46     00:00.97    984K    C++     Rainco_test
7   2008-08-23 14:11:01     00:01.19    3448K   C++     asmn
8   2008-08-23 14:18:04     00:01.19    3448K   C++     EZdestroyer
9   2008-08-23 21:05:05     00:01.36    2096K   C++     Fandywang
10  2008-08-23 20:35:21     00:01.36    3400K   C++     亦纷菲ぁ幻剑
11  2008-08-23 14:11:36     00:01.45    22680K  C++     yaya_ke
12  2008-08-23 16:11:07     00:01.53    3964K   C++     Freshines
13  2008-08-23 17:32:18     00:01.57    1860K   C++     hhanger@Zodiac
*/

// 2012-09-07 01:56:56 | Accepted | 3033 | C++ | 100 | 1112 | watashi | Source
