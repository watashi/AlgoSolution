#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
	
const int MAXN = 10086;
int s[MAXN], t[MAXN];

int main() {
	int n, m, a, b;

	while (scanf("%d%d", &n, &m) != EOF && n > 0) {
		for (int i = 0; i < n; ++i) {
			scanf("%*d%*d%d%d", &s[i], &t[i]);
			t[i] += s[i];
		}
		sort(s, s + n);
		sort(t, t + n);
		for (int i = 0; i < m; ++i) {
			scanf("%d%d", &a, &b);
			b += a;
			a = upper_bound(t, t + n, a) - t;
			b = s + n - lower_bound(s, s + n, b);
			printf("%d\n", n - a - b);
		}
	}

	return 0;
}
// 714992  	2011-01-04 06:30:33 	Accepted	0.094	Minimum	26909	C++	4512 - Happy Telephones
/*
id => 1174101
pid => 4512
pname => Happy Telephones
status => Accepted
lang => C++
time => 0.052
date => 2012-12-14 17:22:16
*/
