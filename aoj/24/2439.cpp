#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long llint;

const llint MOD = 1000000007;

inline void add(llint& lhs, llint rhs) {
    lhs = (lhs + rhs) % MOD;
}

int main() {
    int n;
    char op;
    vector<vector<llint> > cur;

    scanf("%d", &n);
    vector<vector<llint> >(n + 1, vector<llint>(n + 1)).swap(cur);
    cur[0][0] = 1;
    for (int k = 0; k < n; ++k) {
        scanf(" %c", &op);
        if (op == '-') {
            continue;
        }
        vector<vector<llint> > pre(cur);
        fill(cur.begin(), cur.end(), vector<llint>(n + 1));
        if (op == 'D') {
            for (int i = 1; i <= n; ++i) {
                for (int j = 0; j <= n; ++j) {
                    add(cur[i][j], pre[i][j] * i);
                    if (j > 0) {
                        add(cur[i - 1][j - 1], pre[i][j] * i * j);
                    }
                }
            }
        } else if (op == 'U') {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    add(cur[i + 1][j + 1], pre[i][j]);
                    if (j > 0) {
                        add(cur[i][j], pre[i][j] * j);
                    }
                }
            }
        }
        /*
        printf("\n@%d:\n", k);
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (cur[i][j] != 0) {
                    printf("[%d][%d] = %lld\n", i, j, cur[i][j]);
                }
            }
        }
        */
    }
    printf("%lld\n", cur[0][0]);

    return 0;
}

//Run# 	Author 	Problem 	Status 	Lang 	Time 	Memory 	Code 	Submission Date
//#490655 	watashi 	2439 	: Accepted 	C++ 	00:04 sec 	1536 KB 	1591 Bytes 	Fri Sep 21 02:06:14

