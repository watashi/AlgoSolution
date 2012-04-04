#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100100;

int main() {
	int n, a[MAXN], l, r, m;
	long long c, s;

	cin >> n >> s;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	l = 0;
	r = *max_element(a, a + n) + 1;
	while (l < r) {
		m = (l + r) / 2;
		c = 0;
		for (int i = 0; i < n && c <= s; ++i) {
			c += min(a[i], m);
		}
		if (c <= s) {
			l = m + 1;
		} else {
			r = m;
		}
	}
	
	--r;
	for (int i = 0; i < n; ++i) {
		s -= min(a[i], r);
		a[i] -= min(a[i], r);
	}
	m = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] == 0) {
			continue;
		} else if (s == 0) {
			m = i;
			break;
		} else {
			--a[i];
			--s;
		}
	}

	if (s > 0) {
		cout << "-1" << endl;
	} else {
		for (int i = 0; i < n; ++i) {
			if (a[(m + i) % n] > 0) {
				cout << (m + i) % n + 1 << " ";
			}
		}
	}

	return 0;
}

