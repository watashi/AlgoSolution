#include <set>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1 << 21;
bool p[MAXN];	// np = 155611

int main() {
	int n, t, x, y = 0;
	set<int> a;

	scanf("%d%d", &n, &x);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &t);
		a.insert(t);
	}
	if (x == 2) {
		puts("0");
		return 0;
	} else if (a.count(1) > 0) {
		puts("1");
		return 0;
	}

	for (int i = 2; i < MAXN && i < x; ++i) {
		if (!p[i]) {
			if (a.count(i) > 0) {
				++y;
			} else {
				puts("-1");
				return 0;
			}
			for (int j = i; j < MAXN; j += i) {
				p[j] = true;
			}
		}
	}
	printf("%d\n", y);

	return 0;
}

