#include <map>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1024;

long double cc[MAXN][MAXN];
long double cnt[MAXN][MAXN], ex[MAXN][MAXN];

int ca[MAXN], cb[MAXN], cd[MAXN];
vector<pair<int, int> > v;

void init() {
    for (int i = 0; i < MAXN; ++i) {
        cc[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            cc[i][j] = cc[i - 1][j - 1] + cc[i - 1][j];
        }
    }
}

int main() {
    int n, m;

    init();

    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &ca[i]);
        for (int j = 0; j < ca[i]; ++j) {
            int k;
            scanf("%d", &k);
            v.push_back({k, i});
        }
    }
    sort(v.rbegin(), v.rend());
    for (int i = 0; i < (int)v.size(); ++i) {
        if (v[i].first < v[n - 1].first) {
            ++cb[v[i].second];
        } else if (v[i].first == v[n - 1].first) {
            ++cd[v[i].second];
        }
    }

    cnt[0][0] = 1.0;
    ex[0][0] = 1.0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (cnt[i][j] == 0.0) {
                continue;
            }
            for (int k = max(0, ca[i] - cb[i] - cd[i]); k <= ca[i] - cb[i] && j + k <= n; ++k) {
                cnt[i + 1][j + k] += cnt[i][j];
                ex[i + 1][j + k] += ex[i][j] / cc[ca[i]][k] * cnt[i][j];
            }
        }
        for (int j = 0; j <= n; ++j) {
            // printf("[%d][%d] %Lf %Lf\n", i + 1, j, cnt[i + 1][j], ex[i + 1][j]);
            ex[i + 1][j] /= cnt[i + 1][j];
        }
    }
    printf("%.10lf\n", (double)ex[m][n]);

    return 0;
}

