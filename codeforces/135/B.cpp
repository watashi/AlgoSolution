#include <cstdio>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;

    Point() {
    }

    Point(int x, int y): x(x), y(y) {
    }

    bool operator<(const Point& o) const {
        return x < o.x || (x == o.x && y < o.y);
    }

    Point operator-(const Point& o) const {
        return Point(x - o.x, y - o.y);
    }

    int operator*(const Point& o) const {
        return x * o.x + y * o.y;
    }
};

bool gao(vector<Point> p, bool same = false) {
    sort(p.begin(), p.end());
    do {
        bool flag = true;
        vector<Point> q;
        for (int i = 0; flag && i < 4; ++i) {
            q.push_back(p[(i + 1) % 4] - p[i]);
            flag &= q[i] * q[i] != 0;
        }
        for (int i = 0; flag && i < 4; ++i) {
            flag &= q[(i + 1) % 4] * q[i] == 0;
        }
        flag &= q[0] * q[0] == q[2] * q[2];
        flag &= q[1] * q[1] == q[3] * q[3];
        if (same) {
            flag &= q[0] * q[0] == q[1] * q[1];
        }
        if (flag) {
            return true;
        }
    } while (next_permutation(p.begin(), p.end()));
    return false;
}

int main() {
    bool v[8];
    Point p[8];

    for (int i = 0; i < 8; ++i) {
        scanf("%d%d", &p[i].x, &p[i].y);
    }
    fill(v, v + 4, false);
    fill(v + 4, v + 8, true);
    do {
        vector<int> a, b;
        vector<Point> pa, pb;
        for (int i = 0; i < 8; ++i) {
            if (v[i]) {
                a.push_back(i);
                pa.push_back(p[i]);
            } else {
                b.push_back(i);
                pb.push_back(p[i]);
            }
        }
        if (gao(pa, true) && gao(pb)) {
            puts("YES");
            for (int i: a) {
                printf("%d ", i + 1);
            }
            puts("");
            for (int i: b) {
                printf("%d ", i + 1);
            }
            puts("");
            return 0;
        }
    } while (next_permutation(v, v + 8));
    puts("NO");
    return 0;
}
