#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>


using namespace std;

vector<long long> lucky;

void gen(int n, long long x) {
	lucky.push_back(x);
	if (n > 0) {
		gen(n - 1, x * 10 + 4);
		gen(n - 1, x * 10 + 7);
	}
}

void init() {
	gen(10, 0);
	sort(lucky.begin(), lucky.end());
}

long long gao(long long l1, long long r1, long long l2, long long r2) {
	return max(0LL, min(r1, r2) - max(l1, l2) + 1);
}

int main() {
	long long l1, r1, l2, r2, a, b;
	int n;

	init();
	cin >> l1 >> r1 >> l2 >> r2 >> n;
	a = 0;
	b = (r1 - l1 + 1) * (r2 - l2 + 1);
	for (int i = n; i < (int)lucky.size() - 1; ++i) {
		a += gao(l1, r1, lucky[i - n] + 1, lucky[i - n + 1]) * gao(l2, r2, lucky[i], lucky[i + 1] - 1);
		a += gao(l2, r2, lucky[i - n] + 1, lucky[i - n + 1]) * gao(l1, r1, lucky[i], lucky[i + 1] - 1);
		if (n == 1) {
			a -= gao(l1, r1, lucky[i], lucky[i]) * gao(l2, r2, lucky[i], lucky[i]);
		}
	}
	cout << fixed << setprecision(12) << 1.0 * a / b << endl;

	return 0;
}

