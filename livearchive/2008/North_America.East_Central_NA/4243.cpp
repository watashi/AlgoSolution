#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int w, c[20];
char buf[1 << 20];

void move(int s, int t) {
    if (--c[s] == 0) {
        --w;
    }
    if (c[t]++ == 0) {
        ++w;
    }
}

int main() {
    int ri = 0;
    bool flag;
    int n, m, p, q, cc;

    while (scanf("%d", &n) != EOF && n > 0) {
        scanf("%s", buf);
        m = strlen(buf);
        for (int i = 0; i < n; ++i) {
            c[i] = 3;
        }
        c[n] = 1;
        p = q = 0;
        w = n;
        flag = false;
        while (w > 1) {
            cc = min(c[q], 3);
            if (p + cc > m) {
                break;
            }
            while (cc-- > 0) {
                switch (buf[p++]) {
                    case 'R': move(q, (q - 1 + n) % n); break;
                    case 'L': move(q, (q + 1) % n); break;
                    case 'C': move(q, n); break;
                }
            }
            ++q;
            if (q == n) {
                q = 0;
            }
        }
        if (ri > 0) {
            puts("");
        }
        printf("Game %d:\n", ++ri);
        for (int i = 0; i < n; ++i) {
            printf("Player %d:%d", i + 1, c[i]);
            if (w == 1 && c[i] > 0) {
                puts("(W)");
            } else if (w != 1 && i == q) {
                puts("(*)");
            } else {
                puts("");
            }
        }
        printf("Center:%d\n", c[n] - 1);
    }

    return 0;
}
//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//727359  	2011-01-29 12:12:38 	Accepted	0.002	Minimum	26909	C++	4243 - LCR
/*
id => 1174296
pid => 4243
pname => LCR
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:50:54
*/
