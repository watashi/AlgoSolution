/*
import java.io.*;
import java.math.*;

public class Main {
    static final int inf = 1 << 20;

    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int re = Integer.parseInt(in.readLine());

        for (int ri = 1; ri <= re; ++ri) {
            String[] wh = in.readLine().split(" ");
            int w = Integer.parseInt(wh[0]), h = Integer.parseInt(wh[1]);
            String[] mp = new String[h + 1];

            for (int i = 1; i <= h; ++i) {
                mp[i] = " " + in.readLine();
            }

            int n = w + h, l, r;
            int[][][] dp = new int[n + 1][h + 2][h + 2];

            for (int k = 2; k <= n; ++k) {
                l = Math.max(1, k - w);
                r = Math.min(h + 1, k);
                for (int i = l - 1; i <= r; ++i) {
                    for (int j = l - 1; j <= r; ++j) {
                        dp[k][i][j] = -inf;
                    }
                }
                if (k == 2) {
                    dp[2][1][1] = (mp[1].charAt(1) == '*') ? 1 : 0;
                    continue;
                }
                for (int i = l; i < r; i++) {
                    for (int j = l; j < r; j++) {
                        if (mp[i].charAt(k - i) == '#' || mp[j].charAt(k - j) == '#') {
                            continue;
                        }
                        dp[k][i][j] = Math.max(dp[k][i][j], dp[k - 1][i][j]);
                        dp[k][i][j] = Math.max(dp[k][i][j], dp[k - 1][i - 1][j]);
                        dp[k][i][j] = Math.max(dp[k][i][j], dp[k - 1][i][j - 1]);
                        dp[k][i][j] = Math.max(dp[k][i][j], dp[k - 1][i - 1][j - 1]);
                        if (dp[k][i][j] == -inf) {
                            continue;
                        }
                        if (mp[i].charAt(k - i) == '*') {
                            ++dp[k][i][j];
                        }
                        if (j != i && mp[j].charAt(k - j) == '*') {
                            ++dp[k][i][j];
                        }
                    }
                }
            }
            System.out.println(dp[n][h][h]);
        }
    }
}
*/

#include <cstdio>
#include <algorithm>

using namespace std;

char mp[128][128];
int dp[256][128][128];

int main() {
    int re, w, h, n, l, r;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d%d", &w, &h);
        for (int i = 1; i <= h; ++i) {
            scanf("%s", mp[i] + 1);
        }
        n = w + h;
        for (int k = 2; k <= n; ++k) {
            l = max(1, k - w);
            r = min(h + 1, k);
            for (int i = l - 1; i <= r; ++i) {
                for (int j = l - 1; j <= r; ++j) {
                    dp[k][i][j] = -1;
                }
            }
            if (k == 2) {
                dp[2][1][1] = (mp[1][1] == '*');
            }
            for (int i = l; i < r; ++i) {
                for (int j = l; j < r; ++j) {
                    if (mp[i][k - i] == '#' || mp[j][k - j] == '#') {
                        continue;
                    } else {
                        dp[k][i][j] = max(
                            max(dp[k - 1][i][j], dp[k - 1][i][j - 1]),
                            max(dp[k - 1][i - 1][j], dp[k - 1][i - 1][j - 1])
                            );
                    }
                    if (dp[k][i][j] == -1) {
                        continue;
                    }
                    if (mp[i][k - i] == '*') {
                        ++dp[k][i][j];
                    }
                    if (j != i && mp[j][k - j] == '*') {
                        ++dp[k][i][j];
                    }
                }
            }
        }
        printf("%d\n", dp[n][h][h]);
    }
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1746057   2009-01-21 01:42:31     Accepted    3089    C++     100     16576   watashi@Zodiac
//1746056   2009-01-21 01:29:58     Time Limit Exceeded     3089    Java    1001    60  watashi@Zodiac

// 2012-09-07 02:01:19 | Accepted | 3089 | C++ | 100 | 16580 | watashi | Source
