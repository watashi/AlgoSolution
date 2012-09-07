#include <map>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>

using namespace std;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

map<int, bool> hash;

int r, c;
char xe[10][10];

bool gao() {
    int h = 0;
    bool ret = false;

    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            h <<= 1;
            if (xe[i][j] == 'e') {
                h ^= 1;
            }
        }
    }
    if (hash.count(h) > 0) {
        return hash[h];
    }
    for (int i = 1; i <= r && !ret; ++i) {
        for (int j = 1; j <= c && !ret; ++j) {
            if (xe[i][j] == 'x') {
                continue;
            }
            for (int d = 0; d < 4 && !ret; ++d) {
                int x = i, y = j, k = 0;
                while (xe[x][y] == 'e') {
                    xe[x][y] = 'x';
                    x += dx[d];
                    y += dy[d];
                    ++k;
                }
                if (k > 1 && xe[x][y] == 'x') {
                    xe[x][y] = 'e';
                    if (!gao()) {
                        ret = true;
                    }
                    xe[x][y] = 'x';
                }
                while (k > 0) {
                    x -= dx[d];
                    y -= dy[d];
                    --k;
                    xe[x][y] = 'e';
                }
            }
        }
    }

    return hash[h] = ret;
}

int main() {
    while (scanf("%d%d", &r, &c) != EOF) {
        assert(1 <= r && r <= 5);
        assert(1 <= c && c <= 5);
        fprintf(stderr, "[%d %d]\n", r, c);
        memset(xe, 0, sizeof(xe));
        hash.clear();
        for (int i = 1; i <= r; ++i) {
            scanf("%s", xe[i] + 1);
            for (int j = 1; j <= c; ++j) {
                assert(xe[i][j] == 'x' || xe[i][j] == 'e');
            }
            assert(xe[i][c + 1] == '\0');
        }
        puts(gao() ? "Tewi first" : "Reisen first");
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//353   2010-07-02 05:51:27     Accepted    1060    C++     890     1500    anotherpeg  Source

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//218   2010-08-12 15:09:55     Accepted    inaba   C++     700     1496    watashi@Zodiac  Source

// 2012-09-07 15:50:24 | Accepted | 3377 | C++ | 660 | 1500 | watashi | Source
