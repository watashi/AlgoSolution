#include <cstdio>

const int MAXN = 1024;
int a[MAXN], b[MAXN];

int main() {
	int n, m;

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		a[i] = -1;
		scanf("%d", &b[i]);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (b[j] == 0) {
				a[i] = j;
				b[j] = -1;
				for (int k = 0; k + m <= j; ++k) {
					if (b[k] > 0) {
						--b[k];
					}
				}
				break;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		printf("%d ", a[i] + 1);
	}

	return 0;
}

