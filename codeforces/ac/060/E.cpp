#include <cmath>
#include <cstdio>
#include <numeric>
#include <iomanip>
// #include <iostream>
#include <algorithm>

using namespace std;

struct Mat {
	static long long MOD;
	long long a[2][2];
};
const Mat FIB = {{{1, 1}, {1, 0}}};
const Mat SUM = {{{3, -1}, {0, 1}}};
long long Mat::MOD;

Mat operator*(const Mat& lhs, const Mat& rhs) {
	Mat ret;
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			ret.a[i][j] = 0;
			for (int k = 0; k < 2; ++k) {
				ret.a[i][j] += lhs.a[i][k] * rhs.a[k][j];
			}
			ret.a[i][j] %= Mat::MOD;
		}
	}
	return ret;
}

Mat pow(Mat a, long long b) {
	Mat ret;
	ret.a[0][0] = ret.a[1][1] = 1;
	ret.a[0][1] = ret.a[1][0] = 0;
	while (b > 0) {
		if (b & 1) {
			ret = ret * a;
		}
		b >>= 1;
		a = a * a;
	}
	return ret;
}

const int MAXN = 1 << 20;
const double PHI = (sqrt(5.0) + 1) / 2;

double f[65];
long long a[MAXN];

void init() {
	double a = 0, b = 1, c;
	for (int i = 0; i < 64; ++i) {
		f[i] = a / b;
		c = a + b;
		a = b;
		b = c;
	}
	f[64] = PHI;
}

int main() {
	int n;
	Mat prod;
	double cur, tmp;
	long long x, y, l, r, u, v;

	init();
//	cin >> n >> x >> y >> Mat::MOD;
	scanf("%I64d%I64d%I64d%I64d", &n, &x, &y, &Mat::MOD);
	for (int i = 0; i < n; ++i) {
//		cin >> a[i];
		scanf("%I64d", &a[i]);
	}

	l = r = *min_element(a, a + n);
	cur = -1;
	prod = pow(FIB, x);
	for (int i = 1; i < n; ++i) {
		u = a[i - 1];
		v = a[i];
		if (u > v) {
			swap(u, v);
		}
		tmp = u * f[min(64LL, x)] + v;
		if (cur < tmp) {
			cur = tmp;
			r = (prod.a[0][0] * v + prod.a[0][1] * u) % Mat::MOD;
		}
	}

	u = accumulate(a, a + n, 0LL) % Mat::MOD;
	v = a[0] + a[n - 1];
	prod = pow(SUM, x);
	u = (prod.a[0][0] * u + prod.a[0][1] * v) % Mat::MOD;
	v = l + r;
	prod = pow(SUM, y);
	u = (prod.a[0][0] * u + prod.a[0][1] * v) % Mat::MOD;
//	cout << (u + Mat::MOD) % Mat::MOD << endl;
	printf("%I64d\n", (u + Mat::MOD) % Mat::MOD);

	return 0;
}

// TLE39 (iostream => cstdio)
// WA51 (n == 1, r = -1 => r = l)
//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//292430 	Feb 20, 2011 1:13:41 PM 	watashi 	60E - Mushroom Gnomes 	GNU C++ 	Accepted 	500 ms 	9500 KB
