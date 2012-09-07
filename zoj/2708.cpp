#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 64;
const char RANK[] = "6789TJQKA";
const int RANKS = sizeof(RANK) - 1;

char buf[MAXN][MAXN];
bool mat[MAXN][MAXN];
int x[MAXN], y[MAXN];
bool mark[MAXN];
int pre[MAXN];
int n, mask;
char trump;

bool canCover(const char lhs[], const char rhs[]) {
    if (lhs[1] == rhs[1]) {
        return strchr(RANK, lhs[0]) < strchr(RANK, rhs[0]);
    } else {
        return rhs[1] == trump/* && lhs[1] != trump*/;
    }
}

bool augment(int p) {
    for (int i = 0; i < n; ++i) {
        if ((y[i] & mask) != 0 && mat[p][i] && !mark[i]) {
            mark[i] = true;
            if (pre[i] == -1 || augment(pre[i])) {
                pre[i] = p;
                return true;
            }
        }
    }
    return false;
}

bool hungary() {
    bool ret = true;
    fill(pre, pre + n, -1);
    for (int i = 0; ret && i < n; ++i) {
        if ((x[i] & mask) != 0) {
            fill(mark, mark + n, false);
            ret &= augment(i);
        }
    }
    return ret;
}

int cnt(int n, int a[]) {
    int ret = 0;
    for (int i = 0; i < n; ++i) {
        if ((a[i] & mask) != 0) {
            ++ret;
        }
    }
    return ret;
}

int main() {
    while (scanf("%d %c", &n, &trump) != EOF) {
        int k = (1 << RANKS) - 1;
        for (int i = 0; i < n; ++i) {
            scanf("%s", buf[i]);
            x[i] = 1 << (strchr(RANK, buf[i][0]) - RANK);
            if (buf[i][2] == '*') {
                k = x[i];
            }
        }
        for (int j = 0; j < n; ++j) {
            scanf("%s", buf[n]);
            y[j] = 1 << (strchr(RANK, buf[n][0]) - RANK);
            for (int i = 0; i < n; ++i) {
                mat[i][j] = canCover(buf[i], buf[n]);
            }
        }

        bool ans = true;
        for (mask = 0; ans && mask < (1 << RANKS); ++mask) {
//          if ((k & mask) != 0 && (mask == (1 << RANKS) -1 || cnt(n, x) < cnt(n, y))) {
            if ((k & mask) != 0 && cnt(n, x) <= cnt(n, y)) {
                ans &= !hungary();
            }
        }
        puts(ans ? "TAKE\n" : "COVER\n");
    }

    return 0;
}

/*
        Submit     Judge       Problem          Run  Run
Run ID  Time       Status      ID      Language Time Memory User Name
                                                (ms) (KB)
2113291 2010-03-16 Accepted    2708    C++      0    184    watashi@Zodiac
        15:29:48
*/

// 2012-09-07 15:44:59 | Accepted | 2708 | C++ | 10 | 188 | watashi | Source
