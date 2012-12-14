#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 4096;

int main() {
	int n, l, r, ans, a[MAXN], b[MAXN], p[MAXN];

	while (scanf("%d", &n) != EOF && n > 0) {
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			b[a[i]] = i;
		}
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &p[i]);
			p[i] = b[p[i]];
		}
		
		ans = 0;
		for (int i = 1; i <= n; ++i) {
			l = r = p[i];
			for (int j = i + 1; j <= n; ++j) {
				l = min(l, p[j]);
				r = max(r, p[j]);
				if (r - l == j - i) {
					++ans;
				}
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}
//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//716018  	2011-01-06 09:06:25 	Accepted	0.109	448	26909	C++	5052 - Genome Evolution

/*
id => 1174143
pid => 5052
pname => Genome Evolution
status => Accepted
lang => C++
time => 0.032
date => 2012-12-14 17:29:55
*/
