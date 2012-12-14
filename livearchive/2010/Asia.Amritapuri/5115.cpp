#include <deque>
#include <cstdio>
#include <cstdlib>
#include <numeric>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	int re, n, a, b, c, x, y, g;
	deque<int> v, d;

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d%d%d%d", &n, &a, &b, &c);
		v.resize(n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &v[i]);
		}
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		d.clear();
		for (int i = 0; i < n; ++i) {
			if (d.size() % 2 == 0) {
				d.push_front(v[i]);
			} else {
				d.push_back(v[i]);
			}
		}

		x = 0;
		y = accumulate(d.begin(), d.end(), 0);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				x += d[i] * d[j] * ((a * abs(i - j) + b) * abs(i - j) + c);
			}
		}
		y *= y;
		g = gcd(x, y);
		x /= g;
		y /= g;
		printf("%d/%d\n", x, y);
	}

	return 0;
}
//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//716583  	2011-01-07 10:55:38 	Accepted	0.008	Minimum	26909	C++	5115 - Shopping Rush

/*
id => 1174197
pid => 5115
pname => Shopping Rush
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:36:55
*/
