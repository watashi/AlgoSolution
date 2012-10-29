#include <cstdio>

const int MAXN = 100100;
int a[MAXN], c[MAXN];

int main() {
	int n;

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		++c[a[i]];
	}
	for (int i = 2; i < MAXN; ++i) {
		if (c[i] > c[i - 1]) {
			puts("-1");
			return 0;
		}
	}
	printf("%d\n", c[1]);
	for (int i = 1; i <= n; ++i) {
		printf("%d%c", c[a[i]]--, i == n ? '\n' : ' ');
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//218383 	Dec 12, 2010 3:47:19 PM 	watashi 	D - Permutations 	GNU C++ 	Accepted 	80 ms 	2076 KB 
