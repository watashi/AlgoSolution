#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 512;

char buf[MAXN][MAXN];
int a[MAXN][MAXN], s[MAXN][MAXN], x[MAXN];

int main() {
    int n, m, q;
    long long ans;

    cin >> n >> m >> q;
    for (int i = 0; i < n; ++i) {
        cin >> buf[i];
    }
    for (int i = 1; i + 1 < n; ++i) {
        for (int j = 1; j + 1 < m; ++j) {
            if (buf[i][j] == '1'
                && buf[i - 1][j] == '1'
                && buf[i + 1][j] == '1'
                && buf[i][j - 1] == '1'
                && buf[i][j + 1] == '1') {
                a[i][j] = 1;
            }
        }
        partial_sum(a[i], a[i] + m, s[i]);
    }

    ans = 0;
    for (int i = 1; i + 1 < m; ++i) {
        for (int j = i; j + 1 < m; ++j) {
            for (int k = 1; k + 1 < n; ++k) {
                x[k] = x[k - 1] + s[k][j] - s[k][i - 1];
            }
            for (int l = 1, r = 1; l + 1 < n; ++l) {
                while (r + 1 < n && x[r] - x[l - 1] < q) {
                    ++r;
                }
                ans += n - r - 1;
            }
        }
    }
    cout << ans << endl;

    return 0;
}

