#include <cstdio>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int MAXN = 100100;

PII p[MAXN];
int a[MAXN];

int main() {
	int n, b;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &p[i].first);
		p[i].second = i;
	}
	sort(p, p + n);

	b = -1;
	for (int i = 0; i < n; ++i) {
		a[p[i].second] = max(0, b - p[i].second);
		b = max(b, p[i].second);
	}

	for (int i = 0; i < n; ++i) {
		printf("%d ", a[i] - 1);
	}

	return 0;
}

