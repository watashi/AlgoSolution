/*
 * World Finals - 2004/2005
 * Shanghai (China)
 * G. Tiling the Plane
You might find the following information useful: It is known that there are only two fundamentally different tilings of the plane, the regular tiling by squares (chessboard tiling) and the tiling by regular hexagons (honeycomb tiling). A polygon can therefore tile the plane if and only if it satisfies one of the following two conditions:

1.
    There are points A, B, C, D in order on the polygon boundary (the points are not necessarily vertices of the polygon) such that the polygon boundaries from A to B and from D to C are congruent and the boundaries from B to C and from A to D are congruent. This leads to a tiling equivalent to the square tiling.
2.
    There are points A, B, C, D, E, F in order on the polygon boundary, such that the boundary pairs AB and ED, BC and FE, CD and AF are congruent. This leads to a tiling equivalent to the hexagon tiling.
*/

// WA
// 2
// ***.
// ..**

#include <algorithm> // auto fix CE
#include <map>
#include <algorithm> // auto fix CE
#include <queue>
#include <algorithm> // auto fix CE
#include <cstdio>
#include <algorithm> // auto fix CE
#include <vector>
#include <algorithm> // auto fix CE
#include <cstring>
#include <algorithm> // auto fix CE
#include <utility>

using namespace std;

typedef pair<int, int> Point;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const int dz[] = {2, 3, 0, 1};
const int x1[] = {1, 1, 0, 0};
const int y1[] = {0, 1, 1, 0};
const int x2[] = {1, 0, 0, 1};
const int y2[] = {1, 1, 0, 0};

char buf[64][64];
vector<Point> vp;
vector<int> vd;

// 3
// ***
// *.*
// ***

bool checkPolyomino(int n, int m, int x, int y) {   // -> WA
    queue<Point> q;
    buf[x][y] = ' ';
    q.push(Point(x, y));
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        for (int i = 0; i < 4; ++i) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (0 <= xx && xx < n && 0 <= yy && yy < m && buf[xx][yy] == '.') {
                buf[xx][yy] = ' ';
                q.push(Point(xx, yy));
            }
        }
        q.pop();
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (buf[i][j] == '.') {
                return false;
            }
        }
    }
    return true;
}

bool nextPolyomino() {
    int n, m = 60;

    if (scanf("%d", &n) == EOF) {
        return false;
    }
    memset(buf[0], '.', sizeof(buf[0]));
    for (int i = 1; i <= n; ++i) {
        buf[i][0] = '.';
        scanf("%s", buf[i] + 1);
        memset(buf[i] + strlen(buf[i]), '.', sizeof(buf[i]) - strlen(buf[i]));
    }
    memset(buf[n + 1], '.', sizeof(buf[n + 1]));
    vp.clear();
    vd.clear();
    if (!checkPolyomino(n + 2, m, 0, 0)) {
        return true;
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if ((buf[i + 1][j + 1] == '*') ^ (buf[i + 1][j] == '*')) {
                vp.push_back(Point(i, j));
                vp.push_back(Point(i + 1, j));
                vd.push_back(0);
                goto GOTO;
            } else if ((buf[i + 1][j + 1] == '*') ^ (buf[i][j + 1] == '*')) {
                vp.push_back(Point(i, j));
                vp.push_back(Point(i, j + 1));
                vd.push_back(1);
                goto GOTO;
            }
        }
    }
GOTO:
    do {
        int x = vp.back().first;
        int y = vp.back().second;
        for (int i = 0; i < 4; ++i) {
            if (i == dz[vd.back()]) {
                continue;
            }
            if ((buf[x + x1[i]][y + y1[i]] == '*') ^ (buf[x + x2[i]][y + y2[i]] == '*')) {
                vp.push_back(Point(x + dx[i], y + dy[i]));
                vd.push_back(i);
                break;
            }
        }
    } while (vp.back() != vp.front());
    vp.pop_back();

    return true;
}

int w[64][64];

int main() {
    while (nextPolyomino()) {
        // C <= 2 * S + 2
        int n = vd.size();  // n \subset [4, 62]
        int m = n / 2;
    /*  for (int i = 0; i < n; ++i) {
            fprintf(stderr, "%d %d\n", i, vd[i]);
        }
    */  memset(w, 0x0f, sizeof(w));
        for (int i = 0; i < m; ++i) {
            for (int j = 1; j < m; ++j) {
                bool flag = true;
                int l = i, r = i + m + (j - 1);
                for (int k = 0; k < j; ++k) {
                    if (vd[l + k] != dz[vd[(r - k) % n]]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
    //          fprintf(stderr, "%d->%d\n", i, i + j);
                    w[i][i + j] = 1;
                }
            }
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (w[i][j] > w[i][k] + w[k][j]) {
                        w[i][j] = w[i][k] + w[k][j];
                    }
                }
            }
        }
        bool flag = false;
        for (int k = 0; k < m; ++k) {
            if (w[k][k + m] <= 3) {
                flag = true;
                break;
            }
        }
        puts(flag ? "YES" : "NO");
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1830246   2009-04-11 22:16:00     Accepted    2566    C++     0   196     watashi@Zodiac

// 2012-09-07 15:40:40 | Accepted | 2566 | C++ | 10 | 200 | watashi | Source
