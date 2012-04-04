#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100100;
bool mark[MAXN];
vector<int> p[MAXN];
int s[MAXN];

int main() {
    for (int i = 2; i < MAXN; ++i) {
        if (mark[i]) {
            continue;
        }
        for (int j = i; j < MAXN; j += i) {
            mark[j] = true;
            p[j].push_back(i);
        }
    }

    int n, m, x;
    char op;

    scanf("%d%d", &n, &m);
    fill(mark, mark + MAXN, false);
    for (int i = 0; i < m; ++i) {
        scanf(" %c%d", &op, &x);
        if (op == '-') {
            if (!mark[x]) {
                puts("Already off");
            } else {
                puts("Success");
                mark[x] = false;
                for (int y: p[x]) {
                    s[y] = 0;
                }
            }
        } else {
            if (mark[x]) {
                puts("Already on");
            } else {
                bool flag = true;
                for (int y: p[x]) {
                    if (s[y] != 0) {
                        printf("Conflict with %d\n", s[y]);
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    puts("Success");
                    mark[x] = true;
                    for (int y: p[x]) {
                        s[y] = x;
                    }
                }
            }
        }
    }

    return 0;
}

