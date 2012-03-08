#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

const int MAXN = 5050;
const long long MOD = 1000000007LL;

long long bin[MAXN];
int x[MAXN], y[MAXN];

bool in(const pair<int, int>& p, int x) {
	return p.first <= x && x <= p.second;
}

long long gao(int n, int a, int b, int m) {
	pair<int, int> x1(0, m), x2(a - m, a), y1(0, m), y2(b - m, b);
	long long ret = 0;
	for (int i = 0; i < 2; ++i) {
		if (i == 0 || m < a) {
			for (int j = 0; j < 2; ++j) {
				if (j == 0 || m < b) {
					int c[3] = {0, 0, 0};
					for (int k = 0; k < n; ++k) {
						if (in(x1, x[k]) && in(x2, x[k]) && in(y1, y[k]) && in(y2, y[k])) {
							++c[2];
						} else if (in(x1, x[k]) && in(y1, y[k])) {
							++c[0];
						} else if (in(x2, x[k]) && in(y2, y[k])) {
							++c[1];
						}
					}
				//	printf("m = %d, a = %d, b = %d: %d %d %d\n", m, a, b, c[0], c[1], c[2]);
					if (c[0] + c[1] + c[2] == n) {
						ret += bin[c[2]];
					}
				}
				swap(y1, y2);
			}
		}
		swap(x1, x2);
	}
	return ret;
}

int main() {
	int n, a, b, l, r, m;

	bin[0] = 1;
	for (int i = 1; i < MAXN; ++i) {
		bin[i] = bin[i - 1] << 1;
		if (bin[i] > MOD) {
			bin[i] -= MOD;
		}
	}

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &a, &b);
		x[i] = a - b;
		y[i] = a + b;
	}
	transform(x, x + n, x, bind2nd(minus<int>(), *min_element(x, x + n)));
	transform(y, y + n, y, bind2nd(minus<int>(), *min_element(y, y + n)));
	a = *max_element(x, x + n);
	b = *max_element(y, y + n);

	l = 0;
	r = max(a, b);
	while (l < r) {
		m = (l + r) / 2;
		if (gao(n, a, b, m) == 0) {
			l = m + 1;
		} else {
			r = m;
		}
	}
	printf("%d\n%d\n", r, (int)(gao(n, a, b, r) % MOD));

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//464897 	May 21, 2011 12:25:48 AM 	watashi 	85E - Guard Towers 	GNU C++ 	Accepted 	30 ms 	1400 KB 
