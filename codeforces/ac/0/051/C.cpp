#include <cstdio>
#include <algorithm>

using namespace std;

int a[200200];

int main() {
	int n, l, r, m, p;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	
	l = 0;
	r = a[n - 1];
	while (l < r) {
		m = (l + r) / 2;
		p = 0;
		for (int i = 0; i < 3; ++i) {
			p = upper_bound(a + p, a + n, a[p] + m) - a;
		}
		if (p < n) {
			l = m + 1;
		} else {
			r = m;
		}
	}

	printf("%d.%c00000\n", r / 2, r % 2 == 0 ? '0' : '5');
	p = 0;
	for (int i = 0; i < 3; ++i) {
		printf("%d.%c00000%c", (p < n ? a[p] : 0) + r / 2, r % 2 == 0 ? '0' : '5', i == 2 ? '\n' : ' ');
		p = upper_bound(a + p, a + n, a[p] + r) - a;
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//235252 	Dec 30, 2010 6:48:15 AM 	watashi 	C - Three Base Stations 	GNU C++ 	Accepted 	110 ms 	2076 KB

