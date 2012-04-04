#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 90;
long long fib[MAXN];

struct Matrix {
	long long a[2][2];

	Matrix() {
		fill(a[0], a[2], 0);
	}

	explicit Matrix(int d) {
		a[0][0] = a[0][1] = 1;
		a[1][0] = d / 2;
		a[1][1] = (d + 1) / 2;
	}

	Matrix operator*(const Matrix& o) const {
		Matrix ret;
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j) {
				for (int k = 0; k < 2; ++k) {
					ret.a[i][j] += a[i][k] * o.a[k][j];
				}
			}
		}
		return ret;
	}
};

int main() {
	int re, m;
	long long n;
	int b[MAXN];
	Matrix xx;

	fib[0] = 1;
	fib[1] = 2;
	for (int i = 2; i < MAXN; ++i) {
		fib[i] = fib[i - 1] + fib[i - 2];
//		cout << i << "\t" << fib[i] << endl;
	}
//	cout << MAXN << "\t" << (long long)1e18 << endl;
	cin >> re;
	for (int ri = 1; ri <= re; ++ri) {
		cin >> n;
		m = 0;
		for (int i = MAXN - 1; i >= 0; --i) {
			if (n >= fib[i]) {
			//	cout << " - " << fib[i] << endl;
				n -= fib[i];
				b[m++] = i;
			}
		}
		for (int i = 1; i < m; ++i) {
			b[i - 1] = b[i - 1] - b[i] - 1;
		}
		xx.a[0][0] = xx.a[1][1] = 1;
		xx.a[0][1] = xx.a[1][0] = 0;
		for (int i = 0; i < m; ++i) {
			xx = xx * Matrix(b[i]);
		}
		cout << xx.a[1][0] + xx.a[0][0] << endl;
	}

	return 0;
}

