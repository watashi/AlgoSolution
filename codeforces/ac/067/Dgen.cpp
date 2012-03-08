#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1000000;
int a[MAXN + 10];

int main() {
	printf("%d\n", MAXN);
	for (int i = 1; i <= MAXN; ++i) {
		a[i] = i;
	}
	random_shuffle(a + 1, a + 1 + MAXN);
	for (int i = 1; i <= MAXN; ++i) {
		printf("%d%c", a[i], i == MAXN ? '\n' : ' ');
	}
	reverse(a + 1, a + 1 + MAXN);
	random_shuffle(a + 1, a + 1 + MAXN);
	for (int i = 1; i <= MAXN; ++i) {
		printf("%d%c", a[i], i == MAXN ? '\n' : ' ');
	}
	return 0;
}

