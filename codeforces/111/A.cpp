#include <vector>
#include <iostream>

using namespace std;

int main() {
	long long n, x, y;
	vector<long long> a;

	cin >> n >> x >> y;
	if (n <= y) {
		vector<long long>(n, 1).swap(a);
		a[0] += y - n;
		for (int i = 0; i < n; ++i) {
			x -= a[i] * a[i];
		}
	}
	if (x > 0) {
		a.clear();
	}
	if (a.empty()) {
		cout << -1 << endl;
	} else {
		for (int i = 0; i < n; ++i) {
			cout << a[i] << "\n";
		}
	}

	return 0;
}

