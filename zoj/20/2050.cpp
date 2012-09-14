#include <queue>
#include <cstdio>

using namespace std;

int mind[1 << 16];
int e[16];

inline int p(int x, int y)
{
    return (x << 2) + y;
}

void gen()
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            e[p(i, j)] = 1 << p(i, j);
            if (i != 0) e[p(i, j)] |= 1 << p(i - 1, j);
            if (i != 3) e[p(i, j)] |= 1 << p(i + 1, j);
            if (j != 0) e[p(i, j)] |= 1 << p(i, j - 1);
            if (j != 3) e[p(i, j)] |= 1 << p(i, j + 1);
        }
    }
}

void bfs()
{
    queue<int> q;

    fill(mind, mind + (1 << 16), -1);
    mind[0] = 0;
    q.push(0);
    mind[(1 << 16) - 1] = 0;
    q.push((1 << 16) - 1);
    while (!q.empty()) {
        for (int i = 0; i < 16; i++) {
            if (mind[q.front() ^ e[i]] == -1) {
                mind[q.front() ^ e[i]] = mind[q.front()] + 1;
                q.push(q.front() ^ e[i]);
            }
        }
        q.pop();
    }
}

int main()
{
    char ch;
    int re, mask;

    gen();
    bfs();
    scanf("%d", &re);
    while (re--) {
        mask = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                scanf(" %c", &ch);
                if (ch == 'b') mask |= 1 << p(i, j);
            }
        }
        if (mind[mask] == -1) puts("Impossible");
        else printf("%d\n", mind[mask]);
        if (re) putchar('\n');
    }

    return 0;
}

// Run ID   Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
// 1689780  2008-11-05 08:43:09     Accepted    2050    C++     0   432     watashi@Zodiac

// 2012-09-07 01:11:22 | Accepted | 2050 | C++ | 0 | 436 | watashi | Source
