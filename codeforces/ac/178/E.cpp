#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 2048;
const double THRESHOLD = 2.5;
const int MINSIZE = 50;

char buf[MAXN][MAXN];
vector<pair<int, int> > v;

void floodfill(int x, int y) {
    if (buf[x][y] == '1') {
        buf[x][y] = '0';
        v.push_back({x, y});
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                floodfill(x + i, y + j);
            }
        }
    }
}

int judge() {
    double sx = 0, sy = 0;
    int n = v.size();
    for (const auto& p: v) {
        sx += p.first;
        sy += p.second;
    }
    sx /= n;
    sy /= n;
    double d = 0;
    for (const auto& p: v) {
        d = max(d, hypot(sx - p.first, sy - p.second));
    }
    return n > THRESHOLD * d * d ? 0 : 1;
}

int main() {
    int n;
    int ans[2] = {0, 0};

    scanf("%d", &n);
    memset(buf, sizeof(buf), '0');
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf(" %c", &buf[10 + i][10 + j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (buf[10 + i][10 + j] == '1') {
                v.clear();
                floodfill(10 + i, 10 + j);
                if ((int)v.size() >= MINSIZE) {
                    ++ans[judge()];
                }
            }
        }
    }
    printf("%d %d\n", ans[0], ans[1]);

    return 0;
}


