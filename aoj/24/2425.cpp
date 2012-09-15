#include <queue>
#include <cstdio>
#include <vector>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1024;

const int dx[][7] = {
    {0, 1, 1, 0, -1, -1, 0},
    {0, 1, 1, 0, -1, -1, 0},
};
const int dy[][7] = {
    {1, 0, -1, -1, -1, 0, 0},
    {1, 1, 0, -1, 0, 1, 0},
};

int lx, ly;
bool b[MAXN + MAXN][MAXN + MAXN];
bool a[MAXN + MAXN][MAXN + MAXN][6];

struct Status {
    int x, y, z;
    Status() { }
    Status(int x, int y, int z): x(x), y(y), z(z) { }
    int d() const {
        return abs(x * y * z) % 6;
    }
    int k() const {
        return x & 1;
    }
    bool& a() {
        static bool aa = true;
        return ::b[MAXN + x][MAXN + y] || abs(x) > lx || abs(y) > ly ? aa : ::a[MAXN + x][MAXN + y][z];
    }
};

int main() {
    int n, sx, sy, gx, gy;

    memset(b, 0, sizeof(b));
    memset(a, 0, sizeof(a));
    scanf("%d%d", &sx, &sy);
    scanf("%d%d", &gx, &gy);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &lx, &ly);
        b[lx + MAXN][ly + MAXN] = true;
    }
    scanf("%d%d", &lx, &ly);

    int ans = 0;
    vector<Status> cur(1, Status(sx, sy, 0));
    cur[0].a() = true;
    while (!cur.empty()) {
        for (int i = 0; i < (int)cur.size(); ++i) {
            Status s = cur[i];
            // printf("[%d,%d,%d] (%d) %d\n", cur[i].x, cur[i].y, cur[i].z, ans, cur[i].d());
            if (cur[i].x == gx && cur[i].y == gy) {
                printf("%d\n", ans);
                return 0;
            }
            int k = cur[i].k();
            int d = cur[i].d();
            s.x += dx[k][d];
            s.y += dy[k][d];
            s.z = s.z == 5 ? 0 : s.z + 1;
            if (!s.a()) {
                s.a() = true;
                cur.push_back(s);
            }
        }
        vector<Status> pre;
        pre.swap(cur);
        for (int i = 0; i < (int)pre.size(); ++i) {
            int d = pre[i].d();
            for (int j = 0; j < 7; ++j) {
                if (j == d) {
                    continue;
                }
                Status s = pre[i];
                int k = pre[i].k();
                s.x += dx[k][j];
                s.y += dy[k][j];
                s.z = s.z == 5 ? 0 : s.z + 1;
                if (!s.a()) {
                    s.a() = true;
                    cur.push_back(s);
                }
            }
        }
        ++ans;
    }
    printf("%d\n", -1);
    return 0;
}

//Run# 	Author 	Problem 	Status 	Lang 	Time 	Memory 	Code 	Submission Date
//#485972 	watashi 	2425 	: Accepted 	C++ 	00:01 sec 	29876 KB 	2465 Bytes 	Sun Sep 16 02:01:41

