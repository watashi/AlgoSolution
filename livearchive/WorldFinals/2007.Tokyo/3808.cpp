#include <map>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1024;
const int INF = 1000000007;

int main() {
	int ri = 0, n, m, idx, todo, cur, tmp, ans;
	int s[12], x[12], p[12], a[MAXN], b[MAXN], c[MAXN];
	map<int, int> y[12];

	while (scanf("%d%d", &n, &m) != EOF && n > 0) {
		for (int i = 0; i < n; ++i) {
			scanf("%d", &s[i]);
			p[i] = i;
		}
		for (int i = 0; i < m; ++i) {
			scanf("%d%d%d", &a[i], &b[i], &c[i]);
			--a[i];
			--b[i];
		}
		ans = INF;

		do {
		//	printf("%d\n", ans);
			for (int i = 0; i < n; ++i) {
				x[i] = 0;
				y[i].clear();
			}
			idx = 0;
			cur = tmp = 0;
			for (int i = 0; i < m; ++i) {
			//	printf("%d %d %d\n", a[i], b[i], c[i]);
				y[a[i]][b[i]] = max(y[a[i]][b[i]], c[i]);
				cur += c[i] - b[i];
				while (idx < n) {
					todo = p[idx];
				//	printf("%d: %d\n", todo, x[todo]);
					if (x[todo] == s[todo]) {
						++idx;
					} else if (y[todo].count(x[todo]) != 0) {
						cur -= y[todo][x[todo]] - x[todo];
						x[todo] = y[todo][x[todo]];
					} else {
						break;
					}
				}
				tmp = max(tmp, cur);
			}
			ans = min(ans, tmp);
		} while (next_permutation(p, p + n));
		printf("Case %d: %d\n\n", ++ri, ans);
	}

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//727333  	2011-01-29 09:24:38 	Accepted	0.670	496	26909	C++	3808 - Network

/*
id => 1174092
pid => 3808
pname => Network
status => Accepted
lang => C++
time => 0.092
date => 2012-12-14 17:21:17
*/
