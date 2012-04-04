#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1024;

long long MOD = 1000000007LL;
long long p8[MAXN], p10[MAXN];

int main() {
	int re, m;

	p8[0] = p10[0] = 1LL;
	for (int i = 1; i < MAXN; ++i) {
		p8[i] = p8[i - 1] * 8 % MOD;
		p10[i] = p10[i - 1] * 10 % MOD;
	}
	scanf("%d%d", &re, &m);

	return 0;
}

