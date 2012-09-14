// 可谓下降序列覆盖的构造解证明^^

#include <stack>
#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

int vs[200002];
int vi[200002];
pair<int, int> vp[200002];

int main()
{
    int n, m, x, k, len;

    while(scanf("%d%d", &n, &m) != EOF && n > 0) {
        k = 0;
        scanf("%d", &x);
        vs[len = 1] = x;
        vi[0] = 1;
        for (int i = 1; i < n; i++) {
            scanf("%d", &x);
            if(x < vs[len]) {
                vs[++len] = x;
                vi[i] = len;
            }
            else {
                int l = 1, r = len;
                while(l < r) {
                    int m = (l + r) >> 1;
                    if(x < vs[m]) l = m + 1;
                    else r = m;
                }
                vp[k++] = make_pair(vs[l], l);
                vs[l] = x;
                vi[i] = l;
            }
        }
        if(len > m) puts("Transportation failed");
        else {
            printf("%d", vi[0]);
            for (int i = 1; i < n; i++)
                printf(" %d", vi[i]);
            printf("\n");
            for (int i = 1; i <= len; i++)
                vp[k++] = make_pair(vs[i], i);
            sort(vp, vp + n);
            printf("%d", vp[0].second);
            for (int i = 1; i < n; i++)
                printf(" %d", vp[i].second);
            printf("\n");
        }
    }
    return 0;
}

// Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
// 2750856 2008-02-14 14:41:31 Accepted 2909 C++ 00:00.56 3564K わたし

// 可以改为提前break(len >> m),priority_queue输出(m << n时)优化

// 2012-09-07 01:46:34 | Accepted | 2909 | C++ | 200 | 3304 | watashi | Source
