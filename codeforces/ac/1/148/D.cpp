#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1024;

int n;
double dp[MAXN][MAXN];

double gao(int w, int b) {
    int m = w + b;
    double& ret = dp[w][b];
    if (ret < 0) {
        if ((n - m) % 3 == 0) {
            if (w == 0) {
                ret = 0;
            } else {
                ret = 1.0 * w / m;
                if (b > 0) {
                    ret += 1.0 * b / m * (1 - gao(w, b - 1));
                }
            }
        } else {
            if (w == 0 || m < 3) {
                ret = 1;
            } else {
                ret = 1.0 * w / m;
                if (b > 0) {
                    ret += 1.0 * b / m * w / (m - 1) * (1 - gao(w - 1, b - 1));
                    if (b > 1) {
                        ret += 1.0 * b / m * (b - 1) / (m - 1) * (1 - gao(w, b - 2));
                    }
                }
            }
        }
    }
    return ret;
}

int main() {
    int w, b;

    scanf("%d%d", &w, &b);
    fill(dp[0], dp[MAXN], -1.0);
    n = w + b;
    printf("%.10f\n", gao(w, b));

    return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//1144349 	Feb 2, 2012 11:49:14 PM 	watashi 	148D - Bag of mice 	GNU C++0x 	Accepted 	50 ms 	9700 KB

