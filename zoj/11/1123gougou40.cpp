#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

int cross(const Point& p, const Point& a, const Point& b) {
    return (a.x - p.x) * (b.y - p.y) - (b.x - p.x) * (a.y - p.y);
}

int sameside(const Point& a, const Point& b, const Point& p, const Point& q) {
    return cross(p, a, b) * cross(q, a, b) > 0;
}

int intriangle(const Point& a, const Point& b, const Point& c, const Point& p) {
    return sameside(a, b, c, p) && sameside(b, c, a, p) && sameside(c, a, b, p);
}

int main() {
    Point a, b, c, p;
    int xmin, xmax, ymin, ymax;
    vector<int> x, y;

    puts("Program 4 by team X");
    while (scanf("%d%d%d%d%d%d", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y) != EOF) {
        xmin = min(min(a.x, b.x), c.x);
        xmax = max(max(a.x, b.x), c.x);
        ymin = min(min(a.y, b.y), c.y);
        ymax = max(max(a.y, b.y), c.y);
        x.clear();
        y.clear();
        for (p.x = xmin + 1; p.x < xmax; ++p.x) {
            for (p.y = ymin + 1; p.y < ymax; ++p.y) {
                if (intriangle(a, b, c, p)) {
                    x.push_back(p.x);
                    y.push_back(p.y);
                }
            }
        }

        xmin = *min_element(x.begin(), x.end());
        xmax = *max_element(x.begin(), x.end());
        ymin = *min_element(y.begin(), y.end());
        ymax = *max_element(y.begin(), y.end());
        for (p.y = ymax; p.y >= ymin; --p.y) {
            bool in = false;
            for (p.x = xmin; p.x <= xmax; ++p.x) {
                if (intriangle(a, b, c, p)) {
                    in = true;
                } else if (in) {
                    break;
                }
                if (p.x > xmin) {
                    putchar(' ');
                }
                if (in) {
                    printf("(%2d, %2d)", p.x, p.y);
                } else {
                    printf("        ");
                }
            }
            puts("");
        }
        puts("");
    }
    puts("End of program 4 by team X");

    return 0;
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//257   2010-06-25 00:08:29     Accepted    1011    C++     10  180     anotherpeg  Source

// 2012-09-30 23:38:14 | Accepted | 1123 | C++ | 0 | 180 | watashi | Source
