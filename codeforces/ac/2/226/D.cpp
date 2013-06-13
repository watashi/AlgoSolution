#include <set>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAXN = 1024;

int a[MAXN][MAXN];
int sr[MAXN], sc[MAXN];
bool fr[MAXN], fc[MAXN];

void show(int n, const bool b[MAXN]) {
    set<int> st;
    for (int i = 0; i < n; ++i) {
        if (b[i]) {
            st.insert(i);
        }
    }
    printf("%d", (int)st.size());
    for (int i: st) {
        printf(" %d", i + 1);
    }
    puts("");
}

int main() {
    int r, c;

    scanf("%d%d", &r, &c);
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            scanf("%d", &a[i][j]);
            sr[i] += a[i][j];
            sc[j] += a[i][j];
        }
    }
    while (true) {
        int mr = min_element(sr, sr + r) - sr;
        int mc = min_element(sc, sc + c) - sc;
        if (sr[mr] >= 0 && sc[mc] >= 0) {
            break;
        } else if (sr[mr] <= sc[mc]) {
            fr[mr] = !fr[mr];
            sr[mr] = -sr[mr];
            for (int j = 0; j < c; ++j) {
                sc[j] -= a[mr][j];
                a[mr][j] = -a[mr][j];
                sc[j] += a[mr][j];
            }
        } else {
            fc[mc] = !fc[mc];
            sc[mc] = -sc[mc];
            for (int i = 0; i < r; ++i) {
                sr[i] -= a[i][mc];
                a[i][mc] = -a[i][mc];
                sr[i] += a[i][mc];
            }
        }
    }

    show(r, fr);
    show(c, fc);

    return 0;
}

