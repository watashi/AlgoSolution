#include <set>
#include <cstdio>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 128;
vector<pair<int, int> > e[MAXN];
int dp[MAXN][MAXN][3];
pair<int, int> pre[MAXN][MAXN][3];
// sect - from - free

pair<int, int> mymin(const pair<int, int>& lhs, const pair<int, int>& rhs) {
    if (lhs.first == rhs.first) {
        return make_pair(lhs.first, lhs.second | rhs.second);
    } else {
        return min(lhs, rhs);
    }
}

int main() {
    int n, m, a, b, c, d;
    pair<int, int> p;

    while (scanf("%d", &m) != EOF && m > 0) {
        n = 2;
        for (int i = 0; i < 2 * m; ++i) {
            e[i].clear();
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &a, &b, &c);
            n = max(n, max(a, b) + 1);
            e[b].push_back(make_pair(a, c));
            e[a].push_back(make_pair(b, c));
        }
        memset(dp, 0x77, sizeof(dp));
        dp[0][1][0] = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 2 - (i == 0); j < n; ++j) {
                for (int k = 0; k < 3; ++k) {
                    for (vector<pair<int, int> >::const_iterator it = e[j].begin(); it != e[j].end(); ++it) {
                        if (dp[i + 1][it->first][k] > dp[i][j][k] + it->second) {
                            dp[i + 1][it->first][k] = dp[i][j][k] + it->second;
                            pre[i + 1][it->first][k] = make_pair(j, 1);
                        } else if (dp[i + 1][it->first][k] == dp[i][j][k] + it->second) {
                            pre[i + 1][it->first][k] = mymin(pre[i + 1][it->first][k], make_pair(j, 1));
                        }
                        if (k < 2) {
                            if (dp[i + 1][it->first][k + 1] > dp[i][j][k]) {
                                dp[i + 1][it->first][k + 1] = dp[i][j][k];
                                pre[i + 1][it->first][k + 1] = make_pair(j, 2);
                            } else if (dp[i + 1][it->first][k + 1] == dp[i][j][k]) {
                                pre[i + 1][it->first][k + 1] = mymin(pre[i + 1][it->first][k + 1], make_pair(j, 2));
                            }
                        }
                    }
                }
            }
        }
        
        a = b = c = 0;
        for (int i = 0; i <= m; ++i) {
            for (int k = 0; k < 3 && k < i; ++k) {
                if (dp[i][0][k] < dp[a][0][c]) {
                    a = i;
                    c = k;
                }
            }
        }
        d = dp[a][0][c];
        set<int> st;
        for (int k = 0; k < 3 && k < a; ++k) {
            if (dp[a][0][k] == d) {
                st.insert(k);
            }
        }
        while (b != 1) {
            printf("%d ", b);
            set<int> todo;
            c = n;
            for (set<int>::const_iterator it = st.begin(); it != st.end(); ++it) {
                if (pre[a][b][*it].first > c) {
                    continue;
                }
                if (pre[a][b][*it].first < c) {
                    todo.clear();
                    c = pre[a][b][*it].first;
                }
                switch (pre[a][b][*it].second) {
                    case 1: todo.insert(*it); break;
                    case 2: todo.insert(*it - 1); break;
                    case 3: todo.insert(*it); todo.insert(*it - 1); break;
                }
            }
            b = c;
            --a;
            st.clear();
            st.swap(todo);
        }
        printf("1 %d\n", d);
    }    

    return 0;
}
//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//727361  	2011-01-29 12:14:38 	Accepted	0.016	Minimum	26909	C++	4248 - You'll be Working on the Railroad
/*
id => 1174295
pid => 4248
pname => You'll be Working on the Railroad
status => Accepted
lang => C++
time => 0.012
date => 2012-12-14 17:50:46
*/
