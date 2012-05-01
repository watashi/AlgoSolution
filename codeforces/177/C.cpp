#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 4096;

vector<int> e[MAXN];
int id[MAXN], sz[MAXN];

void dfs(int v, int tag) {
    if (id[v] == -1) {
        ++sz[tag];
        id[v] = tag;
        for (int w: e[v]) {
            dfs(w, tag);
        }
    }
}

int main() {
    int n, m, a, b, c;

    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &a, &b);
        --a;
        --b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    c = 0;
    fill(id, id + n, -1);
    for (int i = 0; i < n; ++i) {
        if (id[i] == -1) {
            sz[c] = 0;
            dfs(i, c++);
        }
    }

    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &a, &b);
        --a;
        --b;
        if (id[a] == id[b]) {
            sz[id[a]] = 0;
        }
    }
    n = 0;
    for (int i = 0; i < c; ++i) {
        n = max(n, sz[i]);
    }
    printf("%d\n", n);

    return 0;
}

/*
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
1643626 	Apr 29, 2012 12:01:37 PM 	watashi 	C2 - Party (70 points) 	GNU C++0x 	Accepted 	80 ms 	2900 KB
1643625 	Apr 29, 2012 12:01:34 PM 	watashi 	C1 - Party (30 points) 	GNU C++0x 	Accepted 	30 ms 	1500 KB
*/
