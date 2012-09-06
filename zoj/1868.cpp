#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

const double PI = acos(-1.0);

struct Position
{
    double latitude/*-PI/2~+PI/2*/, longitude/*-PI~+PI*/;
    void convert()
    {
        latitude *= PI / 180;
        longitude *= PI / 180;
    }
};

inline double sqr(double x)
{
    return x * x;
}

double delta(const Position& p1, const Position& p2)
{
    static double tmp, x, y, z;

    // 这里应该单独计算x, y, z，这里重复算了n次，太慢了
    tmp = abs(p1.longitude - p2.longitude);
    if (tmp > PI) {
        tmp = 2 * PI - tmp;
    }
    x = cos(tmp);
    y = sin(tmp);
    tmp = cos(p2.latitude);
    x = x * tmp - cos(p1.latitude);
    y = y * tmp;
    z = sin(p2.latitude) - sin(p1.latitude);

    return acos(1 - (sqr(x) + sqr(y) + sqr(z)) / 2);
}

Position p[1024];
double d[1024][1024];

int main(void)
{
    int n, id;
    double tmp, ans;

    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%lf%lf", &p[i].latitude, &p[i].longitude);
            p[i].convert();
            d[i][i] = 0;
            for (int j = 0; j < i; j++) {
                d[i][j] = d[j][i] = delta(p[i], p[j]);
            }
        }
        id = -1;
        for (int i = 0; i < n; i++) {
            tmp = *max_element(d[i], d[i] + n);
            if (id == -1 || tmp < ans - 1e-8) {
                ans = tmp;
                id = i;
            }
        }
        printf("%.2lf %.2lf\n", p[id].latitude / PI * 180, p[id].longitude / PI * 180);
    }

    return 0;
}

//3024737 2008-08-06 16:17:46 Accepted 1868 C++ 00:00.48 8648K Re:ReJudge

// 2012-09-07 01:03:28 | Accepted | 1868 | C++ | 230 | 8388 | watashi | Source
