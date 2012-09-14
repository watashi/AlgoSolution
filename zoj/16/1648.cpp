#include <cstdio>

struct Point
{
    double x, y;
};

const double EPS = 1e-8;

double xmult(const Point& p, const Point& a, const Point& b)
{
    return (a.x - p.x) * (b.y - p.y) - (a.y - p.y) * (b.x - p.x);
}

bool intersect(Point lhs[2], Point rhs[2])
{
    return xmult(lhs[0], lhs[1], rhs[0]) * xmult(lhs[0], lhs[1], rhs[1]) < -EPS &&
            xmult(rhs[0], rhs[1], lhs[0]) * xmult(rhs[0], rhs[1], lhs[1]) < -EPS;
}

int main()
{
    int n;
    Point p[2048][2];

    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%lf%lf%lf%lf",
                    &p[i][0].x, &p[i][0].y,
                    &p[i][1].x, &p[i][1].y);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (intersect(p[i], p[j])) {
                    puts("burned!");
                    goto CONTINUE;
                }
            }
        }
        puts("ok!");
CONTINUE:
        continue;
    }

    return 0;
}

// Run ID   Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
// 1715454  2008-12-01 02:45:00     Accepted    1648    C++     80  176     watashi@Zodiac

// 2012-09-07 00:56:58 | Accepted | 1648 | C++ | 80 | 180 | watashi | Source
