#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 4096;

int d[MAXN], p[MAXN];

int gao(int i) {
	if (d[i] == -1) {
		if (p[i] == -1) {
			d[i] = 0;
		} else {
			d[i] = gao(p[i]) + 1;
		}
	}
	return d[i];
}

int main() {
	int n, m;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		d[i] = -1;
		scanf("%d", &p[i]);
		if (p[i] > 0) {
			--p[i];
		}
	}
	m = 0;
	for (int i = 0; i < n; ++i) {
		m = max(m, gao(i));
	}
	printf("%d\n", m + 1);

	return 0;
}

