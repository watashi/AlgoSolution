#include <iostream>
#include <algorithm>

using namespace std;

const int MAXS = 3 * 4 * 2 * 2;
const int MOD = 2520;
int lcm[MAXS];
int _c3[10], _c2[10], _c5[10], _c7[10];
long long dp[20][MAXS][MOD];

int encode(int three, int two, int five, int seven) {
	return three * 16 + two * 4 + five * 2 + seven;
}

void decode(int code, int& three, int& two, int& five, int& seven) {
	seven = code & 1;
	code >>= 1;
	five = code & 1;
	code >>= 1;
	two = code & 3;
	code >>= 2;
	three = code;
}

void init() {
	int c3, c2, c5, c7;

	_c3[3] = 1;
	_c3[6] = 1;
	_c3[9] = 2;
	_c2[2] = 1;
	_c2[4] = 2;
	_c2[6] = 1;
	_c2[8] = 3;
	_c5[5] = 1;
	_c7[7] = 1;

	for (int i = 0; i < MAXS; ++i) {
		lcm[i] = 1;
		decode(i, c3, c2, c5, c7);
		for (int j = 0; j < c3; ++j) {
			lcm[i] *= 3;
		}
		for (int j = 0; j < c2; ++j) {
			lcm[i] *= 2;
		}
		for (int j = 0; j < c5; ++j) {
			lcm[i] *= 5;
		}
		for (int j = 0; j < c7; ++j) {
			lcm[i] *= 7;
		}
//		cout << i << ": " << lcm[i] << endl;
	}

	dp[0][0][0] = 1;
	for (int i = 0; i < 19; ++i) {
		for (int j = 0; j < MAXS; ++j) {
			decode(j, c3, c2, c5, c7);
			for (int k = 0; k < MOD; ++k) {
				if (dp[i][j][k] == 0) {
					continue;
				}
				for (int jj = 0; jj < 10; ++jj) {
					int jjj = encode(
						max(c3, _c3[jj]),
						max(c2, _c2[jj]),
						max(c5, _c5[jj]),
						max(c7, _c7[jj]));
					dp[i + 1][jjj][(k * 10 + jj) % MOD] += dp[i][j][k];
				}
			}
		}
	}
}

// < n
long long gao(long long n, long long t = 1, int d = 0) {
	if (n == 0) {
		return 0;
	} else {
		long long ret = 0;
		
		while (n % 10 != 0) {
			int c3 = 0, c2 = 0, c5 = 0, c7 = 0, cc3, cc2, cc5, cc7;

			--n;
			for (long long m = n; m > 0; m /= 10) {
				c3 = max(c3, _c3[m % 10]);
				c2 = max(c2, _c2[m % 10]);
				c5 = max(c5, _c5[m % 10]);
				c7 = max(c7, _c7[m % 10]);
			}

			for (int i = 0; i < MAXS; ++i) {
				decode(i, cc3, cc2, cc5, cc7);
				int k = lcm[encode(max(c3, cc3), max(c2, cc2), max(c5, cc5), max(c7, cc7))];
				for (int j = (k - n * t % k) % k; j < MOD; j += k) {
					ret += dp[d][i][j];
				}
			}
		}
		ret += gao(n / 10, t * 10, d + 1);
		
		return ret;
	}
}

int main() {
	int re;
	long long l, r;

	init();
//	cerr << "Ready!" << endl;
//	for (int i = 1; i < 10101; ++i) {
//		cout << gao(i) << endl;
//	}
	cin >> re;
	for (int ri = 1; ri <= re; ++ri) {
		cin >> l >> r;
		cout << gao(r + 1) - gao(l) << endl;
	}

	return 0;
}

