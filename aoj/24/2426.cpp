#include <map>
#include <cstdio>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;

const int MAXN = 5050;
const int INF = 1000000007;

int remap(map<int, int>& mp) {
    int ret = 0;
    for (map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it) {
        it->second = ret++;
    }
    return ret;
}

int x[MAXN], y[MAXN];
int s[MAXN][MAXN];

int main() {
    int n, nx, ny, m;
    map<int, int> mpx, mpy;

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &x[i], &y[i]);
        mpx[x[i]];
        mpy[y[i]];
    }
    mpx[-INF];
    mpx[INF];
    nx = remap(mpx);
    mpy[-INF];
    mpy[INF];
    ny = remap(mpy);

    for (int i = 0; i < n; ++i) {
        ++s[mpx[x[i]]][mpy[y[i]]];
    }
    for (int i = 1; i < nx; ++i) {
        partial_sum(s[i], s[i] + ny, s[i]);
        transform(s[i - 1], s[i - 1] + ny, s[i], s[i], plus<int>());
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d%d", &x[1], &y[1], &x[2], &y[2]);
        x[1] = mpx.lower_bound(x[1])->second - 1;
        y[1] = mpy.lower_bound(y[1])->second - 1;
        x[2] = mpx.upper_bound(x[2])->second - 1;
        y[2] = mpy.upper_bound(y[2])->second - 1;
        printf("%d\n", s[x[2]][y[2]] + s[x[1]][y[1]] - s[x[1]][y[2]] - s[x[2]][y[1]]);
    }

    return 0;
}

//Run# 	Author 	Problem 	Status 	Lang 	Time 	Memory 	Code 	Submission Date
//#485973 	watashi 	2426 	: Accepted 	C++ 	00:52 sec 	100204 KB 	1322 Bytes 	Sun Sep 16 02:02:45
