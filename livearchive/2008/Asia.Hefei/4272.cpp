#include <cstdio>

const int MAXN = 128;

int main() {
    int ri = 0;
    int n, m, a, b;
    int id[MAXN], s[MAXN], w[MAXN][MAXN], e[MAXN][MAXN];

    while (scanf("%d%d", &n, &m) != EOF && n > 0) {
        for (int i = 0; i < n; ++i) {
            id[i] = -1;
            s[i] = 0;
            for (int j = 0; j < n; ++j) {
                w[i][j] = 0;
                e[i][j] = 0;
            }
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &a, &b);
            w[a - 1][b - 1] = 1;
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    w[i][j] |= w[i][k] & w[k][j];
                }
            }
        }
        m = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (w[i][j] & w[j][i]) {
                    id[i] = id[j];
                }
            }
            if (id[i] == -1) {
                id[i] = m++;
            }
            ++s[id[i]];
        //    printf("id[%d] = %d\n", i, id[i]);
        }
        b = 0;
        for (int i = 0; i < m; ++i) {
            b += (s[i] == 1 ? 0 : s[i]);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (id[i] != id[j] && w[i][j]) {
                    e[id[i]][id[j]] = 1;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                a = e[i][j];
                for (int k = 0; k < m; ++k) {
                    if (e[i][k] & e[k][j]) {
                        a = 0;
                    }
                }
                b += a;
            }
        }
        printf("Case %d: %d\n", ++ri, b);
    }

    return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//727379  	2011-01-29 12:53:05 	Accepted	0.445	524	26909	C++	4272 - Polynomial-time Reductions

/*
id => 1174035
pid => 4272
pname => Polynomial-time Reductions
status => Accepted
lang => C++
time => 0.076
date => 2012-12-14 17:13:23
*/
