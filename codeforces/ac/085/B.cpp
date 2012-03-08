#include <set>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {
	int n, c[3], t[3];
	long long x, y, z;
	queue<long long> q[3];

	for (int i = 0; i < 3; ++i) {
		cin >> c[i];
	}
	for (int i = 0; i < 3; ++i) {
		cin >> t[i];
	}
	cin >> n;

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < c[i] && j < n; ++j) {
			q[i].push(0);
		}
	}

	z = 0;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		y = x;
		for (int j = 0; j < 3; ++j) {
			y = max(y, q[j].front()) + t[j];
			q[j].pop();
			q[j].push(y);
		}
		z = max(z, y - x);
	}
	cout << z << endl;

	return 0;
}

