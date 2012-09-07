#include <cstdlib> // auto fix CE
#include <set>
#include <cstdlib> // auto fix CE
#include <cstdio>
#include <cstdlib> // auto fix CE
#include <vector>
#include <cstdlib> // auto fix CE
#include <algorithm>

using namespace std;

const int MAXN = 50;
const int MAXM = MAXN * MAXN;

struct Point {
    int x, y;
    Point() { }
    Point(int x, int y) : x(x), y(y) { }
    int abs2() const { return x * x + y * y; }
};

int operator*(const Point& lhs, const Point& rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y;
}

int operator%(const Point& lhs, const Point& rhs) {
    return lhs.x * rhs.y - lhs.y * rhs.x;
}

vector<Point> v[MAXM + 1], w;
// int c[MAXM + 1], ans[MAXN + 1];
int x[MAXM + 1][MAXM + 1];

int read() {
    double x;
    scanf("%lf", &x);
    int y = (int)(x * 100 + .5);
    return y * y;
}

int main() {
    int re;
    int a, b, c, d, n;
    Point p;

    for (p.x = 0; p.x <= MAXN; ++p.x) {
        for (p.y = -MAXN; p.y <= MAXN; ++p.y) {
            if (p.abs2() <= MAXM) {
                v[p.abs2()].push_back(p);
            }
        }
    }
    for (int i = 1; i <= MAXM; ++i) {
        for (int j = 1; j <= i; ++j) {
            set<int> s;
            for (vector<Point>::const_iterator it = v[i].begin(); it != v[i].end(); ++it) {
                for (vector<Point>::const_iterator jt = v[j].begin(); jt != v[j].end(); ++jt) {
                    if (*it * *jt >= 0 && *it % *jt > 0) {
                        s.insert(*it % *jt);
                    }
                }
            }
            x[i][j] = s.size();
            // c[i] += s.size();
        }
    }
/*
    for (int i = 1; i <= MAXN; ++i) {
        ans[i] = ans[i - 1];
        for (int j = (i - 1) * (i - 1) + 1; j <= i * i; ++j) {
            ans[i] += c[j];
        }
    }
*/
    for (int i = 1; i <= MAXM; ++i) {
        for (int j = 1; j <= MAXM; ++j) {
            x[i][j] += x[i][j - 1];
        }
        for (int j = 1; j <= MAXM; ++j) {
            x[i][j] += x[i - 1][j];
        }
    }

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
//      scanf("%d", &n);
//      printf("%d\n", ans[n]);
        a = (read() + 9999) / 10000 - 1;
        b = read() / 10000;
        c = (read() + 9999) / 10000 - 1;
        d = read() / 10000;
        n = 0;
        n += x[b][d] + x[a][c] - x[a][d] - x[b][c];
        n += x[d][b] + x[c][a] - x[d][a] - x[c][b];
        a = max(a, c);
        b = min(b, d);
        if (a < b) {
            n -= x[b][b] + x[a][a] - x[a][b] - x[b][a];
        }
        printf("%d\n", n);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//218   2011-04-03 01:11:23     Accepted    H   C++     1480    24640   watashi     Source

// 2012-09-07 16:00:52 | Accepted | 3484 | C++ | 840 | 24644 | watashi | Source
