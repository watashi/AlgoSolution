#include <cstdio>
#include <numeric>
#include <algorithm>

using namespace std;

const int MAXN = 2 << 20;
const int MOD = 51123987;

int add(int a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
	return a;
}

// [ALGO] Algo: Manacher
// [MODULE] Module: Manacher
void manacher(int n, const char s[], int p[]) {
	for (int i = 0, j = 0, k = 0; i <= 2 * (n - 1); ++i) {
		int l = i < k ? min(p[j + j - i], (k - i) / 2) : 0;
		int a = i / 2 - l, b = (i + 1) / 2 + l;
		while (0 <= a && b < n && s[a] == s[b]) {
			--a;
			++b;
			++l;
		}
		p[i] = l;
		if (k < 2 * b) {
			j = i;
			k = 2 * b;
		}
	}
}

char buf[MAXN];
int p[MAXN + MAXN], d[4][MAXN];

#include <string>

int main() {
	int n;

	scanf("%d%s", &n, buf);
	manacher(n, buf, p);
	for (int i = 0; i <= 2 * (n - 1); ++i) {
		++d[0][(i + 1) / 2];
		--d[0][(i + 1) / 2 + p[i]];
	}
	partial_sum(d[0], d[0] + n, d[1], add);
	partial_sum(d[1], d[1] + n, d[2], add);
	partial_sum(d[2], d[2] + n, d[3], add);

	int sum = 0;
	long long ans = 0;
	
	for (int i = 0; i <= 2 * (n - 1); ++i) {
		ans += 1LL * p[i] * sum;
		ans += 1LL * p[i] * (p[i] - 1) / 2;
		ans -= i / 2 - 1 >= 0 ? d[3][i / 2 - 1] : 0;
		ans += i / 2 - p[i] - 1 >= 0 ? d[3][i / 2 - p[i] - 1] : 0;
		ans %= MOD;
		sum = add(sum, p[i]);
	//	printf("[%d,%d] %d / %lld (%d, %d)\n", i, p[i], sum, ans, i / 2 - p[i] - 1, i / 2 - 1);
	}
	printf("%d\n", add(ans, MOD));

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//423319 	May 3, 2011 10:37:08 PM 	watashi 	17E - Palisection 	GNU C++ 	Accepted 	230 ms 	52600 KB 
