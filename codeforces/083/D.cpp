#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1 << 20;
int p[MAXN];
int np, pl[MAXN];

void init() {
	p[1] = 1;
	np = 0;
	for (int i = 2; i < MAXN; ++i) {
		if (p[i] == 0) {
			p[i] = -1;
			for (int j = i + i; j < MAXN; j += i) {
				p[j] = i;
			}
			pl[np++] = i;
		} else if (i / p[i] % p[i] == 0) {
			p[i] = 0;
		} else {
			p[i] = -p[i / p[i]];
		}
	}
}

bool isprime(long long n) {
	for (long long i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

long long gao(long long n, int i, bool f) {
	if (i == 0 || n == 0) {
		return f ? n : -n;
	} else {
		--i;
		return gao(n, i, f) + gao(n / pl[i], i, !f);
	}
}

int main() {
	long long a, b, c, d;

	cin >> a >> b >> c;
	if (!isprime(c)) {
		puts("0");
		return 0;
	}

	init();
	d = lower_bound(pl, pl + np, c) - pl;
	cout << gao(b / c, d, true) - gao((a - 1) / c, d, true) << endl;

	return 0;
}

