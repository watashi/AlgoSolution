#include <map>
#include <iostream>

using namespace std;

map<int, bool> e;
map<int, bool> m;
int k;

bool end(int n) {
	if (e.count(n)) {
		return e[n];
	} else {
		for (int i = 1; i * i <= n; ++i) {
			if (n % i != 0) {
				continue;
			}
			int a = i, b = n / i;
			if (a >= 2 && b >= k) {
				return e[n] = false;
			}
			swap(a, b);
			if (a >= 2 && b >= k) {
				return e[n] = false;
			}
		}
		return e[n] = true;
	}
}

bool gao(int n) {
	if (m.count(n)) {
		return m[n];
	} else {
		for (int i = 1; i * i <= n; ++i) {
			if (n % i != 0) {
				continue;
			}
			int a = i, b = n / i;
			if (a >= 2 && b >= k && (end(b) || (a % 2 != 0 && !gao(b)))) {
				return m[n] = true;
			}
			swap(a, b);
			if (a >= 2 && b >= k && (end(b) || (a % 2 != 0 && !gao(b)))) {
				return m[n] = true;
			}
		}
		return m[n] = false;
	}
}

int main() {
	int n, m;

	cin >> n >> m >> k;
	cout << (n % 2 != 0 && gao(m) ? "Timur" : "Marsel") << endl;

	return 0;
}

