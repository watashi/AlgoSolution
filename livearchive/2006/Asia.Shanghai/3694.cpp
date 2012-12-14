#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100000;
long long s[MAXN];
vector<int> e[MAXN];

long long llabs_(long long x) {
    return x > 0 ? x : -x;
}

void gao(int v, int p) {
    for (size_t i = 0; i < e[v].size(); ++i) {
        int w = e[v][i];
        if (w != p) {
            gao(w, v);
            s[v] += s[w];
        }
    }
}

int main() {
    int ri = 0;
    int n, m, a, b;
    long long ans;

    while (scanf("%d%d", &n, &m) != EOF && n > 0) {
        for (int i = 0; i < n; ++i) {
            scanf("%lld", &s[i]);
            e[i].clear();
        }
        for (int i = 1; i < n; ++i) {
            scanf("%d%d", &a, &b);
            --a;
            --b;
            e[a].push_back(b);
            e[b].push_back(a);
        }
        gao(0, -1);
        ans = s[0];
        for (int i = 1; i < n; ++i) {
            ans = min(ans, llabs_(2 * s[i] - s[0]));
        }
        printf("Case %d: %lld\n", ++ri, ans);
    }

    return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//723917  	2011-01-22 16:01:39 	Accepted	0.316	3860	26909	C++	3694 - Contestants Division
/*
id => 1174137
pid => 3694
pname => Contestants Division
status => Accepted
lang => C++
time => 0.255
date => 2012-12-14 17:29:08
*/
