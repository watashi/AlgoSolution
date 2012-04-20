#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 2048;

struct S {
    int n;
    string s;
    vector<int> nex[26];
} s[MAXN];

int idx[MAXN], nex[26][MAXN];
char str[MAXN];
pair<int, int> dp[MAXN][MAXN];

void read(S& s) {
    static char buf[1 << 20];
    scanf("%s", buf);
    s.s = buf;
    s.n = s.s.length();
    for (int i = 0; i < 26; ++i) {
        s.nex[i].resize(s.n + 1);
    }
    for (int j = 0; j < 26; ++j) {
        s.nex[j][s.n] = s.n;
    }
    for (int i = s.n - 1; i >= 0; --i) {
        for (int j = 0; j < 26; ++j) {
            s.nex[j][i] = s.nex[j][i + 1];
        }
        s.nex[s.s[i] - 'a'][i] = i;
    }
}

int main() {
    int n, m, l, ans;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        read(s[i]);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &idx[i]);
        --idx[i];
    }
    scanf("%s", str);
    l = strlen(str);

    for (int j = 0; j < 26; ++j) {
        nex[j][m] = m;
    }
    for (int i = m - 1; i >= 0; --i) {
        int k = idx[i];
        for (int j = 0; j < 26; ++j) {
            nex[j][i] = nex[j][i + 1];
            if (s[k].nex[j][0] < s[k].n) {
                nex[j][i] = i;
            }
        }
    }

    ans = 0;
    fill(dp[0], dp[MAXN], make_pair(m, 0));
    dp[0][0] = make_pair(0, 0);
    for (int i = 0; i < l; ++i) {
        int ch = str[i] - 'a';
        for (int j = 0; j <= i; ++j) {
            pair<int, int> t = dp[i][j];
            // printf("[%d][%d] = <%d, %d>\n", i, j, t.first, t.second);
            dp[i + 1][j] = min(dp[i + 1][j], t);
            while (t.first < m) {
                t.second = s[idx[t.first]].nex[ch][t.second];
                if (t.second == s[idx[t.first]].n) {
                    t.first = nex[ch][t.first + 1];
                    t.second = 0;
                } else {
                    break;
                }
            }
            // printf("%d %d\n", t.first, t.second);
            if (t.first < m) {
                // printf("\t=> [%d][%d]\n", i + 1, j + 1);
                ans = max(ans, j + 1);
                if (++t.second == s[idx[t.first]].n) {
                    ++t.first;
                    t.second = 0;
                }
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1], t);
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}

