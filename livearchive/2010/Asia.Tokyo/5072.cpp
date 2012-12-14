#include <map>
#include <cstdio>

using namespace std;

const int MAXN = 100100;

int a[MAXN];

int main() {
	int n, s, w, q;
	long long ans;
	map<int, int> mp;

	while (scanf("%d%d%d%d", &n, &s, &w, &q) != EOF && n > 0) {
		for (int i = 0; i < n; ++i) {
			a[i] = (s / 7) % 10;
			if (s % 2 == 0) {
				s = s / 2;
			} else {
				s = (s / 2) ^ w;
			}
		}

		ans = 0;
		if (q == 2 || q == 5) {
			s = 0;
			for (int i = 0; i < n; ++i) {
				if (a[i] != 0) {
					++s;
				}
				if (a[i] % q == 0) {
					ans += s;
				}
			}
		} else {
			mp.clear();
			s = 1;
			w = 0;
			for (int i = n - 1; i >= 0; --i) {
				++mp[w];
				w = (1LL * a[i] * s + w) % q;
				s = 10LL * s % q;
				if (a[i] != 0) {
					ans += mp[w];
				}
			}
		}
		printf("%lld\n", ans);
	}

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//771926  	2011-04-28 11:17:42 	Accepted	2.496	3076	26909	C++	5072 - Find the Multiples
/*
id => 1174085
pid => 5072
pname => Find the Multiples
status => Accepted
lang => C++
time => 0.852
date => 2012-12-14 17:20:26
*/
