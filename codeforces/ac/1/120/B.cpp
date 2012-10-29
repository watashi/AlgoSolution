#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int n, m, t;
	bool a[1024];

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	--m;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &t);
		a[i] = t != 0;
	}
	while (!a[m % n]) {
		++m;
	}
	printf("%d\n", m % n + 1);

	return 0;
}
