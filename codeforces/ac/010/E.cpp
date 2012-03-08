#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 512;
const long long INF = 1000000007LL * 1000000007LL;

long long gao(const long long* begin, const long long* end, long long x) {
	long long y = 0;
	for (const long long* p = begin; p != end; ++p) {
		y += x / *p;
		x %= *p;
	}
	return y;
}

int main() {
	int n;
	long long c[MAXN], g[MAXN], x, y, ans;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
	}

	ans = INF;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			fill(g, g + n, 0);
			x = c[i] - 1;
			for (int k = i + 1; k <= j; ++k) {
				g[k] = x / c[k];
				x %= c[k];
			}
			++g[j];
			y = inner_product(g, g + n, c, 0LL);
			if (ans > y && gao(c, c + n, y) > accumulate(g, g + n, 0LL)) {
				ans = y;
			}
		}
	}
	cout << (ans == INF ? -1LL : ans) << endl;

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//457368 	May 17, 2011 3:21:07 AM 	watashi 	10E - Greedy Change 	GNU C++ 	Accepted 	390 ms 	1400 KB 

//ref:coins2.ps
