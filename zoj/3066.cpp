#include <cmath>
#include <cstdio>

struct Point
{
    int x, y, z;
    Point() { }
    Point(int x, int y, int z)
        : x(x), y(y), z(z)
    {
    }
};

int sign(int x)
{
    if (x > 0) return 1;
    else if (x < 0) return -1;
    else return 0;
}

double sqr(int x)
{
    return x * x;
}

double abs(const Point& p)
{
    return sqrt(sqr(p.x) + sqr(p.y) + sqr(p.z));
}

Point operator-(const Point& a, const Point& b)
{
    return Point(a.x - b.x, a.y - b.y, a.z - b.z);
}

int dmult(const Point& a, const Point& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Point xmult(const Point& a, const Point& b)
{
    return Point(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}

Point p[32];
int s[32], ss;

int main()
{
    int n;
    bool flag;
    double ans;

    while (scanf("%d", &n) != EOF && n > 0) {
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].z);
        }
        ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    Point dn = xmult(p[j] - p[i], p[k] - p[i]);
                    ss = 0;
                    flag = true;
                    for (int t = 0; t < n; t++) {
                        s[t] = sign(dmult(dn, p[t] - p[i]));
                        if (s[t] != 0) {
                            if (ss == 0) {
                                ss = s[t];
                            }
                            else if (ss != s[t]) {
                                flag = false;
                                break;
                            }
                        }
                    }
                    if (flag) {
                        ans += abs(dn);
                    }
                }
            }
        }
        printf("%.0lf\n", ans / 2);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1750210   2009-01-28 15:37:10     Accepted    3066    C++     10  176     watashi@Zodiac

// 2012-09-07 01:59:35 | Accepted | 3066 | C++ | 0 | 180 | watashi | Source
