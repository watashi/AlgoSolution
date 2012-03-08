#include <cstdio>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int a[128];

void no() {
	puts("No");
	exit(0);
}

int main() {
	int n, m, k;
	vector<int> v;

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	if (m <= 0) {
		no();
	} else if (n == 1) {
		if (m != a[1]) {
			no();
		}
	} else if (m == 1) {
		k = find(a + 1, a + n + 1, 1) - a;
		if (k > n) {
			no();
		}
		--a[k];
		v.push_back(k);
		for (int i = 1; i <= n; ++i) {
			v.insert(v.end(), a[i] * 2, i);
			a[i] = 0;
		}
		v.push_back(k);
	} else {
		m = accumulate(a + 1, a + n + 1, 0) - m;
		if (m < 0) {
			no();
		}
		--a[1];
		--a[2];
		v.push_back(1);
		for (int i = 2; m > 0 && i <= n; ++i) {
			k = min(a[i], m);
			v.insert(v.end(), k * 2, i);
			a[i] -= k;
			m -= k;
		}
		v.push_back(1);
		v.push_back(2);
		k = min(a[1], m);
		v.insert(v.end(), k * 2, 1);
		a[1] -= k;
		m -= k;
		v.push_back(2);
	}

	for (int i = 1; i <= n; ++i) {
		v.insert(v.end(), a[i] * 2, i);
	}
	puts("Yes");
	for (int i = 0; i < (int)v.size(); ++i) {
		printf("%d ", v[i]);
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//309328 	Feb 28, 2011 2:09:27 PM 	watashi 	26E - Multithreading 	GNU C++ 	Accepted 	60 ms 	3600 KB 
