#include <iostream>

using namespace std;

bool mark[1 << 20];

int main() {
	long long n, d, m, l, p;

	cin >> n >> d >> m >> l;
	p = (((n - 1) * m + l) / d + 1) * d;
	for (long long a = 0, b = 0; a < p && !mark[b]; a += d, b = (b + d) % m) {
		if (b > l) {
			p = a;
			break;
		} else {
			mark[b] = true;
		}
	}
	cout << p << endl;

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//213051 	Dec 10, 2010 1:57:37 PM 	watashi 	B - Platforms 	GNU C++ 	Accepted 	50 ms 	2344 KB 
