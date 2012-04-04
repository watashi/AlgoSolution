#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, a, b;
	long long s, t;

	cin >> n >> a;
	s = t = 1;
	for (int i = 1; i < n; ++i) {
		cin >> b;
		if (a == b) {
			++t;
		} else {
			t = 1;
		}
		s += t;
		a = b;
	}
	cout << s << endl;
	
	return 0;
}

