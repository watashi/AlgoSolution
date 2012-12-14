#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXM = 128;

int main() {
	int re, m, n, a[MAXM], p, c;

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d%d", &m, &n);
		for (int i = 0; i < m; ++i) {
			scanf("%d", &a[i]);
		}
		if ((p = find(a, a + m, 2) - a) != m) {
		} else if ((p = find(a, a + m, 3) - a) != m) {
			if (p >= 1 && p <= m - 1) {
				p = m + m - 2 - p;
			}
		}
		for (int i = 1; i < m - 1; ++i) {
			a[m + m - 2 - i] = a[i];
		}
		m = m + m - 2;

		c = 0;
		for (int i = 1; i <= n; ++i) {
			if (a[(p + i) % m] == 0) {
				++c;
			}
		}
		printf("%d\n", c);
	}

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//716147  	2011-01-06 17:13:42 	Accepted	0.002	Minimum	26909	C++	5046 - Gholam's Simple Game

/*
id => 1174145
pid => 5046
pname => Gholam's Simple Game
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:30:02
*/
