#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1024;

bool a[MAXN][MAXN];
int s[MAXN][MAXN];
int x[MAXN], y[MAXN];

int main() {
    int ri = 0;
    int n, nx, ny, ans, cur, tmp;
    vector<int> vx, vy;

    while (scanf("%d", &n) != EOF && n > 0) {
        vx.clear();
        vy.clear();
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &x[i], &y[i]);
            vx.push_back(x[i]);
            vy.push_back(y[i]);
        }
        sort(vx.begin(), vx.end());
        vx.erase(unique(vx.begin(), vx.end()), vx.end());
        nx = max<int>(vx.size(), 2);
        sort(vy.begin(), vy.end());
        vy.erase(unique(vy.begin(), vy.end()), vy.end());
        ny = max<int>(vy.size(), 2);
        for (int i = 0; i < nx; ++i) {
            for (int j = 0; j < ny; ++j) {
                a[i][j] = false;
            }
        }
        for (int i = 0; i < n; ++i) {
            x[i] = lower_bound(vx.begin(), vx.end(), x[i]) - vx.begin();
            y[i] = lower_bound(vy.begin(), vy.end(), y[i]) - vy.begin();
            a[x[i]][y[i]] = true;
        }
        for (int i = 0; i < nx; ++i) {
            s[i][0] = 0;
            for (int j = 0; j < ny; ++j) {
                if (a[i][j]) {
                    s[i][j + 1] = s[i][j] + 1;
                } else {
                    s[i][j + 1] = s[i][j];
                }
            }
        }
        ans = 0;
        for (int l = 0; l < ny; ++l) {
            for (int r = l + 1; r < ny; ++r) {
                cur = 0;
                for (int i = 0; i < nx; ++i) {
                    if (a[i][l]) {
                        ++cur;
                    }
                    if (a[i][r]) {
                        ++cur;
                    }
                    ans = max(ans, cur + s[i][r] - s[i][l + 1]);
                    cur = max(cur, s[i][r + 1] - s[i][l]);
                }
            }
        }
        printf("Case %d: %d\n", ++ri, ans);
    }

    return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//723918  	2011-01-22 16:02:41 	Accepted	0.021	Minimum	26909	C++	3695 - Distant Galaxy
/*
id => 1174133
pid => 3695
pname => Distant Galaxy
status => Accepted
lang => C++
time => 0.012
date => 2012-12-14 17:28:29
*/
