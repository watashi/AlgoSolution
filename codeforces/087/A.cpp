#include <iostream>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	bool swp;
	long long a, b, c, x, y;

	cin >> a >> b;
	c = gcd(a, b);
	a /= c;
	b /= c;

	swp = false;
	if (a < b) {
		swap(a, b);
		swp = true;
	}
	x = y = 0;
	for (int i = 1; i <= a; ++i) {
		c = i * b / a * a;
//		cerr << i << ':' << c << endl;
		x += c - (i - 1) * b;
		y += i * b - c;
	}
//	cerr << a << ' ' << b << endl;
//	cerr << x << ' ' << y << endl;
	if (x == y) {
		cout << "Equal" << endl;
	} else if ((x < y) == swp) {
		cout << "Dasha" << endl;
	} else {
		cout << "Masha" << endl;
	}

	return 0;
}

