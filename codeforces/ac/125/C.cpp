#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	vector<vector<int> > v;

	scanf("%d", &n);
	m = 1;
	while (m * (m + 1) <= 2 * n) {
		++m;
	}
	v.resize(m);
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < i; ++j) {
			v[i].push_back(n);
			v[j].push_back(n);
			--n;
		}
	}
	printf("%d\n", m);
	for (const auto& vi: v) {
		for (int i: vi) {
			printf("%d ", i);
		}
		puts("");
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//863312 	Nov 14, 2011 4:53:16 PM 	watashi 	125C - Hobbits Party 	GNU C++0x 	Accepted 	30 ms 	1500 KB
