#include <cmath>
#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

int n;
pair<double, double> p[10];

inline double dist(const pair<double, double>& lhs, const pair<double, double>& rhs)
{
    double x= lhs.first - rhs.first, y = lhs.second - rhs.second;
    return sqrt(x * x + y * y);
}

inline pair<double, double> calc(const pair<double, double>& lhs, const pair<double, double>& rhs)
{
    double theta = atan2(rhs.second - lhs.second, rhs.first - lhs.first) + acos(dist(lhs, rhs) / 4.0);
    return make_pair(lhs.first + 2.0 * cos(theta), lhs.second + 2.0 * sin(theta));
}

int main(void)
{
    while(scanf("%d", &n) != EOF && n > 0) {
        for (int i = 0; i < n; i++) {
            scanf("%lf", &p[i].first);
            p[i].second = 1.0;
        }
        sort(p, p + n);
        while(--n) {
            for (int i = 0; i < n; i++)
                p[i] = calc(p[i], p[i + 1]);
        }
        printf("%.4lf %.4lf\n", p[0].first, p[0].second);
    }
    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2747034 2008-02-09 15:39:40 Accepted 2403 C++ 00:00.00 444K ¤ï¤¿¤·

// 2012-09-07 01:22:09 | Accepted | 2403 | C++ | 0 | 180 | watashi | Source
