#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct R {
	int a, b, c;
} r[1 << 20];

bool operator<(const R& l, const R& r) {
	return l.a < r.a;
}

int main() {
	int re, n;

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d", &n);
		for (int i = 1; i < n + n; ++i) {
			scanf("%d%d", &r[i].a, &r[i].b);
			r[i].c = i;
		}
		sort(r + 1, r + n + n);
		puts("YES");
		for (int i = 2; i < n + n; i += 2) {
			printf("%d ", r[r[i - 1].b > r[i].b ? i - 1 : i].c);
		}
		printf("%d\n", r[n + n - 1].c);
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//301675 	Feb 24, 2011 6:53:18 PM 	watashi 	23C - Oranges and Apples 	GNU C++ 	Accepted 	230 ms 	13600 KB 
