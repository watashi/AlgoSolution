#include <map>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 10086;

int x[2 * MAXN];
int mind[2 * MAXN], bfs[2 * MAXN];

int main(void)
{
    int n, s, f;
    int t, p, q;
    char buf[128];

    while(scanf("%d%d%d", &n, &s, &f) != EOF) {
        map<string, int>* mp = new map<string, int>();
        for (int i = 0; i < n; i++) {
            scanf("%*s%s", buf);
            (*mp)[buf] = i;
        }
        p = 0;
        for (map<string, int>::const_iterator it = mp->begin(); it != mp->end(); ++it) {
            q = it->second;
            x[q] = n + p;
            x[n + p] = q;
            ++p;
        }
        delete mp;

        --s;
        --f;
        memset(mind, 0xff, 2 * sizeof(int) * n);
        p = 0;
        q = 0;
        bfs[q++] = s;
        mind[s] = 0;
        while(p < q && mind[f] == -1 && mind[x[f]] == -1) {
            t = bfs[p] - 1;
            if (t == -1 || t == n - 1)
                t += n;
            if (mind[t] == -1) {
                mind[t] = mind[bfs[p]] + 1;
                bfs[q++] = t;
            }
            t = bfs[p] + 1;
            if (t == n || t == n + n)
                t -= n;
            if (mind[t] == -1) {
                mind[t] = mind[bfs[p]] + 1;
                bfs[q++] = t;
            }
            t = x[bfs[p]];
            if (mind[t] == -1) {
                mind[t] = mind[bfs[p]] + 1;
                bfs[q++] = t;
            }
            ++p;
        }
        if(mind[f] != -1) {
            printf("%d\n", mind[f]);
        }
        else {
            printf("%d\n", mind[x[f]]);
        }
    }

    return 0;
}


//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2947897   2008-06-11 22:40:48     Accepted    2031    C++     00:00.08    1564K   Re:ReJudge

// 2012-09-07 01:10:57 | Accepted | 2031 | C++ | 30 | 944 | watashi | Source
