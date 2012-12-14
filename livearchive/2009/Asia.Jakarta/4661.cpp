#include <map>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Float {
	long double a;
	long long b;

	Float(long double a_ = 1.0, long long b_ = 0LL) : a(a_), b(b_) {
		while (a < 1) {
			a *= 10;
			--b;
		}
		while (a >= 9.999995L) {
			a /= 10;
			++b;
		}
	}

	void print() {
		printf("%.5Lf x 10^%lld\n", a, b);
	}
};

Float operator*(const Float& lhs, const Float& rhs) {
	return Float(lhs.a * rhs.a, lhs.b + rhs.b);
}

Float operator/(const Float& lhs, const Float& rhs) {
	return Float(lhs.a / rhs.a, lhs.b - rhs.b);
}

int main() {
	int re, m, q, n, x;
	long double t;
	Float p[100], ans;
	map<int, int> mp;

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d", &m);
		for (int i = 1; i <= m; ++i) {
			scanf("%Lf", &t);
			p[i] = Float(t);
		}
		scanf("%d", &q);

		printf("Test Case #%d:\n", ri);
		for (int i = 1; i <= q; ++i) {
			scanf("%d", &n);
			ans = Float();
			mp.clear();
			for (int j = 1; j <= n; ++j) {
				scanf("%d", &x);
				++mp[x];
				ans = ans * p[x] * Float(j);
			}
			for (map<int, int>::const_iterator it = mp.begin(); it != mp.end(); ++it) {
				for (int j = 2; j <= it->second; ++j) {
					ans = ans / Float(j);
				}
			}
			ans.print();
		}
	}

	return 0;
}
//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//715036  	2011-01-04 08:02:41 	Accepted	0.008	Minimum	26909	C++	4661 - 1:1000000000000...

/*
id => 1174225
pid => 4661
pname => 1:1000000000000...
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:41:20
*/
