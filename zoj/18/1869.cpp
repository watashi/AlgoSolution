#include <cmath>
#include <cstdio>
using namespace std;

inline double sqr(const double x)
{
    return x * x;
}

double x[1001], y[1001], r[1001];
bool mp[1024][1024];

void bfs(int n, int s)
{
    static bool m[1024];
    static int p, t, q[1024];

    for (int i = 0; i < n; i++)
        m[i] = false;
    m[s] = true;
    q[0] = s;
    p = 0;
    t = 1;
    while(p < t) {
        for (int i = 0; i < n; i++)
            if(!m[i] && mp[q[p]][i]) {
                m[i] = true;
                q[t++] = i;
            }
        ++p;
    }
    for (int i = 0; i < n; i++)
        if(m[i])
            mp[s][i] = mp[i][s] = true;
}

int main(void)
{
    int n;
    double a, b;

    while(scanf("%d", &n) != EOF) {
        for (int i = 0; i <= n + 1; i++)
            for (int j = 0; j <= n + 1; j++)
                mp[i][j] = false;
        for (int i = 0; i < n; i++) {
            scanf("%lf%lf%lf", &x[i], &y[i], &r[i]);
            if(y[i] - r[i] < 0)
                mp[i][n] = mp[n][i] = true;
            if(y[i] + r[i] > 1000)
                mp[i][n + 1] = mp[n + 1][i] = true;
            for (int j = 0; j < i; j++)
                if (sqr(x[i] - x[j]) + sqr(y[i] - y[j]) < sqr(r[i] + r[j]))
                    mp[i][j] = mp[j][i] = true;
        }
        if(mp[n][n + 1]) {
            printf("Bill will be bitten.\n");
            continue;
        }
        bfs(n + 2, n + 1); // not bfs(n + 2, n);
        if(mp[n][n + 1]) {
            printf("Bill will be bitten.\n");
            continue; // -_-b
        }
        a = b = 1000.0;
        for (int i = 0; i < n; i++) {
            if(!mp[i][n + 1])
                continue;
            if(x[i] - r[i] < 0) {
                /* a <?= y[i] - sqrt(sqr(r[i]) - sqr(x[i])); */ /* auto fix <?= */
                a = a < y[i] - sqrt(sqr(r[i]) - sqr(x[i])) ? a : y[i] - sqrt(sqr(r[i]) - sqr(x[i]));
            }
            if(x[i] + r[i] > 1000) {
                /* b <?= y[i] - sqrt(sqr(r[i]) - sqr(1000 - x[i])); */ /* auto fix <?= */
                b = b < y[i] - sqrt(sqr(r[i]) - sqr(1000 - x[i])) ? b : y[i] - sqrt(sqr(r[i]) - sqr(1000 - x[i]));
            }
        }
        printf("Bill enters at (0.00, %.2lf) and leaves at (1000.00, %.2lf).\n", a, b);
    }
}
//2916572   2008-05-15 19:31:23     Accepted    1869    C++     00:00.03    1452K   Re:ReJudge

// 2012-09-07 13:54:29 | Accepted | 1869 | C++ | 10 | 1232 | watashi | Source
