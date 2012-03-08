#include <cstdio>

int main() {
	int ans = 0;
	for (int i = 1; i <= 4; ++i) {
	for (int j = 1; j <= 4; ++j) {
	for (int k = 1; k <= 4; ++k) {
	for (int l = 1; l <= 4; ++l) {
		if (i <= j && j <= k && k <= l || i >= j && j >= k && k >= l) {
			++ans;
		}
	}
	}
	}
	}
	printf("%d\n", ans);

	return 0;
}

