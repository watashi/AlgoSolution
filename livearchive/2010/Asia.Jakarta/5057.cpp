#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {
	bool flag;
	int re, n, m, xa, ya, xb, yb, z;

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d%d%d%d%d%d", &n, &xa, &ya, &xb, &yb, &z);
		--n;
		xa = xa - 1 + (1 << n);
		xb = xb - 1 + (1 << n);
		m = 0;
		while ((xa >> m) != (xb >> m)) {
			++m;
		}

		flag = true;
		for (int i = (ya + 1) / 2; flag && i <= ya && i <= n; ++i) {
			for (int j = (yb + 1) / 2; flag && j <= yb && j <= n; ++j) {
				if (i > m || j > m) {
					if (i != j) {
						flag &= abs(i - j) + (ya - i) + (yb - j) <= z;
					} else if (i != ya && j != yb) {
						flag &= (ya - i - 1) + (yb - j - 1) <= z;
					} else {
						flag &= (ya - i) + (yb - j) <= z;
					}
				} else if (i < m && j < m) {
					flag &= (m - i) + (ya - i) + (m - j) + (yb - j) <= z;
				} else {
					if (i == m && j < m) {
						if (ya == m) {
							flag &= (m - j) + (yb - j) <= z;
						} else {
							flag &= (m - 1 - j) + (yb - j) + (ya - m - 1) <= z;
						}
					} else if (j == m && i < m) {
						if (yb == m) {
							flag &= (m - i) + (ya - i) <= z;
						} else {
							flag &= (m - 1 - i) + (ya - i) + (yb - m - 1) <= z;
						}
					} else {
						flag &= (ya - i) + (yb - j) <= z;
					}
				}
			}
		}
		puts(flag ? "NO" : "YES");
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//798613 	5057 	Worst Locations 	Accepted 	C++ 	0.036 	2011-05-13 12:41:57
/*
id => 1174305
pid => 5057
pname => Worst Locations
status => Accepted
lang => C++
time => 0.032
date => 2012-12-14 17:51:58
*/
