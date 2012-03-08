#include <iostream>
#include <algorithm>

using namespace std;

inline bool test(long long p, int i) {
	return ((p >> i) & 1LL) != 0LL;
}

long long cnt(int n, int m, long long p) {
	long long ret = 0;
	bool rev = true, inv = true;
	for (int i = 1; i + i <= n; ++i) {
		rev &= i - 1 >= m || n - i >= m || test(p, i - 1) == test(p, n - i);
		if (rev) {
			switch (n - 2 * i) {
			case 0:
				ret += 1LL << max(0, i - m);
				break;
			case 1:
				ret += 1LL << max(0, i + 1 - m);
				break;
			default:
				if ((i >= m || !test(p, i)) && (n - i - 1 >= m || test(p, n - i - 1))) {
					ret += 1LL << max(0, n - i - 1 - m - (m > i ? 0 : 1));
				}
				break;
			}
		}
		inv &= i - 1 >= m || n - i >= m || test(p, i - 1) != test(p, n - i);
		if (inv) {
			switch (n - 2 * i) {
			case 0:
				ret += 1LL << max(0, i - m);				
				break;
			case 1:
				if (i >= m || !test(p, i)) {
					ret += 1LL << max(0, i - m);
				}
				break;
			default:
				if ((i >= m || !test(p, i)) && (n - i - 1 >= m || !test(p, n - i - 1))) {
					ret += 1LL << max(0, n - i - 1 - m - (m > i ? 0 : 1));
				}
				break;
			}
		}
	}
	return ret;
}

int main() {
	int n;
	long long m, p;

//	for (int i = 0; i < 20; ++i) {
//		cout << i << "\t" << cnt(i, 1, 0LL) << endl;
//	}
	cin >> n >> m;
	if (m >= cnt(n, 1, 0LL)) {
		cout << -1 << endl;
		return 0;
	}

	p = 0;
	for (int i = 2; i <= n; ++i) {
//		cout << m << " " << cnt(n, i, p) << endl;
		if (m >= cnt(n, i, p)) {
			m -= cnt(n, i, p);
			p |= 1LL << (i - 1);
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << (test(p, i) ? '1' : '0');
	}
	cout << endl;

	return 0;
}

// A . (empty|0|1|0*1) . rev(A)
// A . (empty|0|0*0) . inv(rev(A))
// A ~= /0*/

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//457409 	May 17, 2011 4:52:26 AM 	watashi 	8E - Beads 	GNU C++ 	Accepted 	30 ms 	1400 KB
