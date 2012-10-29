#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
#ifndef __WATASHI__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m, s, a;

	scanf("%d%d", &n, &m);
	s = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a);
		s += a - min(3, a / m) * m;
	}
	printf("%d\n", s);

	return 0;
}
