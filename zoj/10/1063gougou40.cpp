#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 64;

const int dx[] = {1, -1, 0, 0, 0, 0};
const int dy[] = {0, 0, 1, -1, 0, 0};
const int dz[] = {0, 0, 0, 0, 1, -1};

struct Point {
    int x, y, z;
    Point(int x, int y, int z) : x(x), y(y), z(z) { }
};

int main() {
    int x, y, z, n;
    int s[MAXN][MAXN][MAXN];

    while (scanf("%d%d%d%d", &x, &y, &z, &n) != EOF && x > 0) {
        int xy = x * y;
        int a, b, c;

        memset(s, 0, sizeof(s));
        for (int i = 0; i < n; ++i) {
            scanf("%d", &c);
            b = c % xy;
            c = c / xy;
            a = b % x;
            b = b / x;
            s[a + 1][b + 1][c + 1] = 1;
        }

        int ans = 0;
        int aa, bb, cc;
        queue<Point> q;

        x += 2;
        y += 2;
        z += 2;
        s[0][0][0] = -1;
        q.push(Point(0, 0, 0));
        while (!q.empty()) {
            a = q.front().x;
            b = q.front().y;
            c = q.front().z;
            q.pop();
            for (int i = 0; i < (int)(sizeof(dx) / sizeof(int)); ++i) {
                aa = a + dx[i];
                bb = b + dy[i];
                cc = c + dz[i];
                if (0 <= aa && aa < x && 0 <= bb && bb < y && 0 <= cc && cc < z) {
                    if (s[aa][bb][cc] == 0) {
                        s[aa][bb][cc] = -1;
                        q.push(Point(aa, bb, cc));
                    } else if (s[aa][bb][cc] == 1) {
                        ++ans;
                    }
                }
            }
        }

        printf("The number of faces needing shielding is %d.\n", ans);
    }

    return 0;
}

// 2012-09-30 23:37:42 | Accepted | 1063 | C++ | 70 | 180 | watashi | Source
