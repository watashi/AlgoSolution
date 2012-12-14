#include <queue>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int x[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
vector<pair<int, int> > pre[128][3003];
vector<int> nxt[128][3003];
int dp[128][3003];
int cm[3003];

int main() {
    int ri = 0;
    int n, m, ii, jj, kk, iii, jjj, ans;

    while (scanf("%d%d", &n, &m) == 2 && n > 0) {
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j < m; ++j) {
                dp[i][j] = 0;
                pre[i][j].clear();
                nxt[i][j].clear();
            }
        }
      /*  for (int k = 1; k < 10; ++k) {
            dp[x[k]][k % m] = 1;
        }*/
        for (int j = 0; j < m; ++j) {
            cm[j] = 1;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                /*   if (dp[i][j] < cm[j]) {
                     continue;
                     } else {
                     cm[j] = dp[i][j];
                     }

*/
                if (!(i == 0 && j == 0) && dp[i][j] == 0) {
                    continue;
                }
                jj = (j * 10) % m;
                for (int k = 0; k < 10; ++k) {
                    ii = i + x[k];
                    if (ii <= n) {
                        if (dp[ii][jj] < dp[i][j] + 1) {
                            dp[ii][jj] = dp[i][j] + 1;
                            /*       pre[ii][jj].clear();
                            //      pre[ii][jj].push_back(make_pair(k, j));
                            } else if (dp[ii][jj] == dp[i][j] + 1) {
                            //    pre[ii][jj].push_back(make_pair(k, j));
                            }*/
                        }
                    }
                    ++jj;
                    if (jj == m) {
                        jj = 0;
                    }
                }
            }
        }
        for (int j = 0; j < m; ++j) {
            cm[j] = 1;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                /*   if (dp[i][j] < cm[j]) {
                     continue;
                     } else {
                     cm[j] = dp[i][j];
                     }
                     */ jj = (j * 10) % m;
                if (!(i == 0 && j == 0) && dp[i][j] == 0) {
                    continue;
                }
                for (int k = 0; k < 10; ++k) {
                    ii = i + x[k];
                    if (ii <= n) {
                        if (dp[ii][jj] == dp[i][j] + 1) {
                            pre[ii][jj].push_back(make_pair(k, j));
                        }
                    }
                    ++jj;
                    if (jj == m) {
                        jj = 0;
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i <= n; ++i) {
            if (dp[i][0] > ans) {
                ans = dp[i][0];
            }
        }
        printf("Case %d: ", ++ri);
        if (ans == 0) {
            puts(n >= 6 ? "0" : "-1");
        } else {
            queue<pair<int, int> > bfs;
            for (int i = 0; i <= n; ++i) {
                if (dp[i][0] == ans) {
                    bfs.push(make_pair(i, 0));
                    dp[i][0] = -1;
                }
            }
            while (!bfs.empty()) {
                ii = bfs.front().first;
                jj = bfs.front().second;
                bfs.pop();
                for (size_t i = 0; i < pre[ii][jj].size(); ++i) {
                    kk = pre[ii][jj][i].first;
                    iii = ii - x[kk];
                    jjj = pre[ii][jj][i].second;
                    nxt[iii][jjj].push_back(kk);
                //    printf("%d %d do %d (%d %d)\n", iii, jjj, kk, ii, jj);
                    if (dp[iii][jjj] > 0) {
                        dp[iii][jjj] = -1;
                        bfs.push(make_pair(iii, jjj));
                    }
                }
            }
            ii = 0;
            jj = 0;
            while (true) {
                kk = -1;
                for (size_t i = 0; i < nxt[ii][jj].size(); ++i) {
                    kk = max(kk, nxt[ii][jj][i]);
                }
                if (kk == -1) {
                    break;
                } else {
                    putchar('0' + kk);
                    ii = ii + x[kk];
                    jj = (jj * 10 + kk) % m;
                }
            }
            puts("");
        }
    }

    return 0;
}
//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//727356  	2011-01-29 11:57:05 	Accepted	1.514	17952	26909	C++	3782 - Bigger is Better

/*
id => 1174150
pid => 3782
pname => Bigger is Better
status => Accepted
lang => C++
time => 0.786
date => 2012-12-14 17:30:21
*/
