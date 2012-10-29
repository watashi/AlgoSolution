#include <queue>
#include <cmath>
#include <cstdio>
#include <utility>

using namespace std;

const int MAXN = 2012;
const double EPS = 1e-8;

struct Segment {
    int d;
    double t;
    double x1, x2, y1, y2;
} line[MAXN];

int a, b;

double dist(double a, double b, double c, double d) {
    if (a > c) {
        swap(a, c);
        swap(b, d);
    }
    return b < c ? c - b : 0.0;
}

bool gao(const Segment& from, Segment& to) {
    double dx = dist(from.x1, from.x2, to.x1, to.x2);
    double dy = dist(from.y1, from.y2, to.y1, to.y2);
    double dd = hypot(dx, dy);
    if (dd > a + EPS) {
        return false;
    }
    to.t = min(to.t, from.d * (a + b) + dd);
    if (to.d > from.d + 1) {
        to.d = from.d + 1;
        return true;
    } else {
        return false;
    }
}

int main() {
    int n;
    double sx, sy, tx, ty;

    scanf("%d%d", &a, &b);
    scanf("%lf%lf%lf%lf", &sx, &sy, &tx, &ty);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lf%lf%lf%lf", &line[i].x1, &line[i].y1, &line[i].x2, &line[i].y2);
        if (line[i].x1 > line[i].x2) {
            swap(line[i].x1, line[i].x2);
        }
        if (line[i].y1 > line[i].y2) {
            swap(line[i].y1, line[i].y2);
        }
    }
    line[n].x1 = line[n].x2 = sx;
    line[n].y1 = line[n].y2 = sy;
    ++n;
    line[n].x1 = line[n].x2 = tx;
    line[n].y1 = line[n].y2 = ty;
    ++n;
    for (int i = 0; i < n; ++i) {
        line[i].d = MAXN;
        line[i].t = MAXN * (a + b);
    }
    line[n - 2].d = 0;
    line[n - 2].t = 0;

    priority_queue<pair<int, int> > q;
    q.push({-line[n - 2].d, n - 2});
    while (!q.empty()) {
        int d = -q.top().first;
        int k = q.top().second;
        q.pop();
        if (d != line[k].d) {
            continue;
        }
        for (int i = 0; i < n; ++i) {
            if (line[i].d > d && gao(line[k], line[i])) {
                q.push({-line[i].d, i});
            }
        }
    }

    if (line[n - 1].d < MAXN) {
        printf("%.10lf\n", line[n - 1].t);
    } else {
        puts("-1");
    }

    return 0;
}

