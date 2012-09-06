// ²î·ÖÔ¼Êø

#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int inf = 123456789;

bool bellman_ford(int n, int s, const vector<pair<pair<int, int>, int> >& e, int mind[])
{
    for (int i = 0; i < n; i++) {
        mind[i] = inf;
    }
    mind[s] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < e.size(); j++) {
            mind[e[j].first.second] = min(mind[e[j].first.second], mind[e[j].first.first] + e[j].second);
        }
    }
    for (int j = 0; j < e.size(); j++) {
        if (mind[e[j].first.first] + e[j].second < mind[e[j].first.second]) {
            return false;
        }
    }
    return true;
}

int mind[128];

int main(void)
{
    int n, m;
    int s, k, v;
    char o[4];

    while (scanf("%d%d", &n, &m) == 2 && n > 0) {
        vector<pair<pair<int, int>, int> > e(m + n + 1);

        for (int i = 0; i < m; i++) {
            scanf("%d%d%s%d", &s, &k, o, &v);
            if (o[0] == 'l') {
                e[i].first.first = s - 1;
                e[i].first.second = s + k;
                e[i].second = v - 1;
            }
            else {
                e[i].first.first = s + k;
                e[i].first.second = s - 1;
                e[i].second = -v - 1;
            }
        }
        for (int i = 0; i <= n; i++) {
            e[m + i].first.first = n + 1;
            e[m + i].first.second = i;
            e[m + 1].second = 0;
        }

        puts(bellman_ford(n + 2, n + 1, e, mind) ?
            "lamentable kingdom" :
            "successful conspiracy");
    }

    return 0;
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2958279   2008-06-29 07:26:37     Accepted    1260    C++     00:00.00    844K    Re:ReJudge

// 2012-09-07 00:43:27 | Accepted | 1260 | C++ | 0 | 180 | watashi | Source
