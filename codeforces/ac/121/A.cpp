#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<long long> lucky;

void gen(int n, long long m) {
	lucky.push_back(m);
	if (n > 0) {
		gen(n - 1, m * 10 + 4);
		gen(n - 1, m * 10 + 7);
	}
}

void init() {
	lucky.clear();
	gen(10, 0);
	sort(lucky.begin(), lucky.end());
}

int main() {
	long long l, r, m, s;

	init();
	cin >> l >> r;
	s = 0;
	while (l <= r) {
		m = *lower_bound(lucky.begin(), lucky.end(), l);
		s += m * (min(m, r) - l + 1);
		l = m + 1;
	}
	cout << s << endl;

	return 0;
}


