#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	bool flag;
	int a[4][3];
	vector<vector<long long> > v;

	while (true) {
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 3; ++j) {
				scanf("%d", &a[i][j]);
			}
			if (a[i][0] == 0 && a[i][1] == 0 && a[i][2] == 0) {
				return 0;
			}
		}
		
		flag = true;
		v.clear();
		for (int i = 0; flag && i < 3; ++i) {
			vector<long long> w;
			w.push_back(a[0][i] - a[2][i]);
			w.push_back(a[1][i] - a[2][i]);
			w.push_back(a[3][i] - a[2][i]);
			if (w[0] != 0 || w[1] != 0) {
				for (int j = 0; flag && !w.empty() && j < (int)v.size(); ++j) {
					if (v[j][0] * w[1] - v[j][1] * w[0] == 0) {
						if (v[j][2] * w[1] - v[j][1] * w[2] != 0 ||
							v[j][0] * w[2] - v[j][2] * w[0] != 0) {
							flag = false;
						} else {
							w.clear();
						}
					}
				}
				if (flag && !w.empty()) {
					v.push_back(w);
				}
			} else if (w[2] != 0) {
				flag = false;
			}
		}

		if (v.size() > 1) {
			long long d = v[0][0] * v[1][1] - v[0][1] * v[1][0];
			long long x = v[0][2] * v[1][1] - v[0][1] * v[1][2];
			long long y = v[0][0] * v[1][2] - v[0][2] * v[1][0];
			if (d < 0) {
				d = -d;
				x = -x;
				y = -y;
			}
		//	printf("[%lld %lld %lld]\n", d, x, y);
			flag &= 0 < x && 0 < y && x + y < d;
			for (int i = 0; i < (int)v.size(); ++i) {
		//		printf("flag = %d\n", flag);
		//		printf("[%lld %lld %lld]\n", v[i][0], v[i][1], v[i][2]);
				flag &= (v[i][0] * x + v[i][1] * y - v[i][2] * d) == 0;
			}
		} else if (v.size() == 1) {
			long long a = v[0][0];
			long long b = v[0][1];
			long long c = v[0][2];
			if (a == 0) {
				swap(a, b);
			}
			if (a < 0) {
				a = -a;
				b = -b;
				c = -c;
			}
			double l = 0.0;
			double r = 1.0;
			// (c - by) / a > 0
			if (b > 0) {
				r = min(r, 1.0 * c / b);
			} else if (b < 0) {
				l = max(l, 1.0 * c / b);
			} else {
				flag &= c > 0;
			}
			// (c - by) / a + y < 1
			if (a - b > 0) {
				r = min(r, 1.0 * (a - c) / (a - b));
			} else if (a - b < 0) {
				l = max(l, 1.0 * (a - c) / (a - b));
			} else {
				flag &= a - c > 0;
			}
			flag &= r - l > 1e-8;
		}

		puts(flag ? "YES" : "NO");
	}
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//904149 	4963 	3-sided dice 	Accepted 	C++ 	0.012 	2011-10-11 13:43:05
/*
id => 1174211
pid => 4963
pname => 3-sided dice
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:39:08
*/
