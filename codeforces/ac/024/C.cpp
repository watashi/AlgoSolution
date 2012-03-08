#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100100;

int x[MAXN], y[MAXN];

int main() {
	int n, m, x0, y0;
	long long k;

	cin >> n >> k >> x0 >> y0;
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
	}
	m = k % (n + n);
	for (int i = 0; i < m; ++i) {
		x0 += (i & 1 ? 2 : -2) * x[i % n];
		y0 += (i & 1 ? 2 : -2) * y[i % n];
	}
	if (m & 1) {
		x0 = -x0;
		y0 = -y0;
	}
	cout << x0 << " " << y0 << endl;

	return 0;
}

// the problem is still easy for n is even
//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//301783 	Feb 24, 2011 9:24:09 PM 	watashi 	24C - Sequence of points 	GNU C++ 	Accepted 	390 ms 	2100 KB 
