#include <list>
#include <cstdio>

using namespace std;

const int MAXN = 128;
bool e[MAXN][MAXN];

template<typename T>
T pred(T value) {
    return --value;
}

int main() {
    int re, n, a, b;
    list<int> ans;

    scanf("%d", &re);
    for (int ri = 0; ri < re; ++ri) {
        scanf("%d", &n);
        for (int i = 0; i < n * (n - 1) / 2; ++i) {
            scanf("%d%d", &a, &b);
            e[a][b] = true;
            e[b][a] = false;
        }
        ans.clear();
        ans.push_back(1);
        for (int i = 2; i <= n; ++i) {
            for (list<int>::iterator j = ans.begin(); ; ++j) {
                if ((j == ans.begin() || e[*pred(j)][i]) && (j == ans.end() || e[i][*j])) {
                    ans.insert(j, i);
                    break;
                }
            }
        }
        for (list<int>::const_iterator i = ans.begin(); i != ans.end(); ++i) {
            if (i != ans.begin()) {
                putchar(' ');
            }
            printf("%d", *i);
        }
        puts("");
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//2172269   2010-04-21 20:37:06     Accepted    3332    C++     100     192     watashi@Zodiac

// 2012-09-07 02:08:39 | Accepted | 3332 | C++ | 90 | 196 | watashi | Source
