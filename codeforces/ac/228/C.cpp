#include <cstdio>
#include <algorithm>

using namespace std;

int a[512][512][10];
int b[512][512][10];

const int dx[4] = {0, 0, 1, 1};
const int dy[4] = {0, 1, 0, 1};

inline int BIN(int i) { return 1 << i; }

int main() {
    int r, c, ans;
    char ch;

    scanf("%d%d", &r, &c);
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            scanf(" %c", &ch);
            a[i][j][0] = (ch == '*' ? 1 : 0);
        }
    }
    ans = 0;
    for (int k = 1; BIN(k) <= r && BIN(k) <= c; ++k) {
        for (int i = 0; i + BIN(k) <= r; ++i) {
            for (int j = 0; j + BIN(k) <= c; ++j) {
                a[i][j][k] = 0;
                b[i][j][k] = 0;
                for (int t = 0; t < 4; ++t) {
                    a[i][j][k] += a[i + (dx[t] << (k - 1))][j + (dy[t] << (k - 1))][k - 1];
                    if (a[i + (dx[t] << (k - 1))][j + (dy[t] << (k - 1))][k - 1] == BIN(2 * (k - 1))) {
                        b[i][j][k] ^= 1 << t;
                    }
                }
                if (k > 1) {
                    for (int t = 0; t < 4; ++t) {
                        if ((b[i][j][k] & (1 << t)) == 0 &&
                            b[i + (dx[t] << (k - 1))][j + (dy[t] << (k - 1))][k - 1] != b[i][j][k]) {
                            b[i][j][k] = -1;
                            break;
                        }
                    }
                    if (b[i][j][k] != -1) {
                        ++ans;
                    }
                }
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}

