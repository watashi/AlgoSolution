#include <cstdlib> // auto fix CE
#include <algorithm> // auto fix CE
#include <cstdlib> // auto fix CE
#include <cmath>
#include <cstdlib> // auto fix CE
#include <algorithm> // auto fix CE
#include <cstdlib> // auto fix CE
#include <cstdio>
#include <cstdlib> // auto fix CE
#include <algorithm> // auto fix CE
#include <cstdlib> // auto fix CE
#include <vector>
#include <cstdlib> // auto fix CE
#include <algorithm> // auto fix CE
#include <cstdlib> // auto fix CE
#include <cstring>

using namespace std;

const int MAXN = 128;
const double EPS = 1e-4;

double d[MAXN][MAXN];

void init() {
    int k = 0;
    const double h = sqrt(3.0);
    static double x[MAXN], y[MAXN];

    for (int i = 0; i < 13; ++i) {
        for (int j = -i; j <= i; j += 2) {
            x[k] = i * h;
            y[k] = j;
            ++k;
        }
    }
    for (int i = 0; i < k; ++i) {
        for (int j = i + 1; j < k; ++j) {
            d[i][j] = hypot(y[j] - y[i], x[j] - x[i]);
        }
    }
}

inline bool judge(int i, int j, int k) {
    return fabs(d[i][j] - d[i][k]) < EPS && fabs(d[i][j] - d[j][k]) < EPS;
}

int main() {
    int n, m;
    char buf[MAXN], ans[MAXN];

    init();
    while (scanf("%d", &n) != EOF && n > 0) {
        scanf("%s", buf);
        n = strlen(buf);
        m = 0;
        for (char c = 'a'; c <= 'z'; ++c) {
            vector<int> v;
            for (int i = 0; i < n; ++i) {
                if (buf[i] == c) {
                    v.push_back(i);
                }
            }
            for (vector<int>::const_iterator i = v.begin(); i != v.end(); ++i) {
                for (vector<int>::const_iterator j = i + 1; j != v.end(); ++j) {
                    for (vector<int>::const_iterator k = j + 1; k != v.end(); ++k) {
                        if (judge(*i, *j, *k)) {
                            ans[m++] = c;
                            goto NEXT;
                        }
                    }
                }
            }
NEXT:
            continue;
        }
        if (m == 0) {
            strcpy(ans, "LOOOOOOOOSER!");
        } else {
            ans[m] = '\0';
        }
        puts(ans);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//266   2010-06-25 22:04:37     Accepted    1037    C++     10  308     anotherpeg  Source

// 2012-09-30 23:41:06 | Accepted | 1504 | C++ | 0 | 308 | watashi | Source
