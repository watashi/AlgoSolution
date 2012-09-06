#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

typedef vector<pair<int, int> > Edge;

bool bellman_ford(int n, const vector<Edge>& e, int mind[])
{
    bool flag = true;

    for (int i = 0; i <= n && flag; i++) {
        flag = false;
        for (int j = 0; j < n; j++) {
            for (Edge::const_iterator k = e[j].begin(); k != e[j].end(); ++k) {
                int t = mind[j] + k->second;
                if (t < mind[k->first]) {
                    mind[k->first] = t;
                    flag = true;
                }
            }
        }
    }

    return !flag;
}

int mind[1024];

int main(void)
{
    int n, m, a, b, c;

    while (scanf("%d%d", &n, &m) != EOF) {
        vector<Edge> e(n + 1);

        mind[0] = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &c);
            mind[i] = 0;
            e[i].push_back(make_pair(i - 1, 0));
            e[i - 1].push_back(make_pair(i, c));
        }
        while (m--) {
            scanf("%d%d%d", &a, &b, &c);
            e[b].push_back(make_pair(a - 1, -c));
        }

        if (!bellman_ford(n + 1, e, mind)) {
            printf("Bad Estimations\n");
        }
        else {
            printf("%d\n", mind[n] - mind[0]);
        }
    }
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2958596   2008-06-29 23:07:35     Accepted    2770    C++     00:00.08    2988K   Re:ReJudge

// 2012-09-07 01:38:43 | Accepted | 2770 | C++ | 30 | 316 | watashi | Source
