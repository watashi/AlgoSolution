#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	long long n, u, d, ans;
	int m;

	while (scanf("%lld%d", &n, &m) != EOF) {
		ans = 12345678987654321LL;
		for (int i = 0; i < m; ++i) {
			scanf("%lld%lld", &u, &d);
			ans = min(ans, n * u - (n * u - 1) / (u + d) * (u + d));
		}
		printf("%lld\n", ans);
	}

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//715016  	2011-01-04 07:03:05 	Accepted	0.033	Minimum	26909	C++	4590 - Business Center

/*
id => 1174222
pid => 4590
pname => Business Center
status => Accepted
lang => C++
time => 0.022
date => 2012-12-14 17:40:46
*/
