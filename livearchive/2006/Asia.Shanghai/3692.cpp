#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 128;

int main() {
    int ri = 0;
    int s, t, m, id, x, y, ans;
    bool mark[MAXN][3];

    while (scanf("%d%d%d", &s, &t, &m) != EOF && s > 0) {
        fill(mark[1], mark[s + 1], false);
        ans = 0;
        for (int i = 1; i <= s; ++i) {
            scanf("%d%d%d", &id, &x, &y);
            if (x) {
                mark[id][0] = true;
            }
            if (y) {
                mark[id][1] = true;
            }
        }
        for (int i = 1; i <= t; ++i) {
            scanf("%d%d", &id, &x);
            if (x >= m) {
                mark[id][2] = true;
            }
        }
        ans = count(mark[1], mark[s + 1], true);
        printf("Case %d: %d\n", ++ri, ans);
    }

    return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//723915  	2011-01-22 15:58:38 	Accepted	0.006	Minimum	26909	C++	3692 - ACM Team Selection
/*
id => 1174135
pid => 3692
pname => ACM Team Selection
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:28:50
*/
