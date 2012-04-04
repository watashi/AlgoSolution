#include <set>
#include <cstdio>

using namespace std;

const int MAXN = 404;
int id[MAXN][MAXN];
bool e[MAXN][MAXN];
char buf[MAXN][MAXN];

int sg[10][10];

int r, c;

int main() {
    // scanf("%d%d", &r, &c);

    // for (int i = 0; i < r; ++i) {
    // }
    for (int i = 0; i < 20; ++i) {
        sg[0][i] = i + 1;
    }
    for (int i = 1; i < 20; ++i) {
        for (int j = i; j < 20; ++j) {
            set<int> s;
            for (int k = 0; k < i; ++k) {
                s.insert(sg[min(j, k)][max(j, k)]);
            }
            for (int k = 0; k < j; ++k) {
                s.insert(sg[min(i, k)][max(i, k)]);
            }
            for (int k = 1; ; ++k) {
                if (s.count(k) == 0) {
                    sg[i][j] = k;
                    break;
                }
            }
            printf("[%d][%d] = %d\n", i, j, sg[i][j]);
        }
    }

    return 0;
}

