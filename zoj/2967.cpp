#include <cmath>
#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

#pragma warning(disable:4996)

typedef pair<double, double> line;
typedef pair<int, double> rec;
const double eps = 1e-8;
const double inf = 1e123;

inline double zero(const double x)
{
    return fabs(x) < 1e-8;
}

inline bool le(const double a, const double b)
{
    return a < b + eps;
}

line a[5005];
rec s[5005];

int main(void)
{
    int re, n, m;
    double x;

    scanf("%d", &re);
    while(re--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%lf%lf", &a[i].first, &a[i].second);
        sort(a, a + n);
        m = 0;
        s[m].first = 0;
        s[m].second = -inf;
        for (int i = 1; i < n; i++) {
            while(true) {
                if(m == -1) {   // <RE> if no, RE
                    ++m;
                    s[m].first = i;
                    s[m].second = -inf;
                    break;
                }   // ... </RE>
                if(zero(a[i].first - a[s[m].first].first)) {
                    --m;
                    continue;
                }
                x = -(a[i].second - a[s[m].first].second) / (a[i].first - a[s[m].first].first);
                if(le(x, s[m].second)) {
                    --m;
                }
                else {
                    ++m;
                    s[m].first = i;
                    s[m].second = x;
                    break;
                }
            }
        }
        printf("%d\n", m + 1);
    }
}

/*
Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
2920383 2008-05-18 03:02:05 Accepted 2967 C++ 00:00.18 580K Re:ReJudge
*/

// 2012-09-07 01:50:43 | Accepted | 2967 | C++ | 70 | 316 | watashi | Source
