#include <set>
#include <cstdio>
#include <algorithm>

using namespace std;

int a[22][22], b[22];

int main() {
	int n, m;
	bool flag;
	set<int> s;

	scanf("%d", &n);
	s.insert(0);
	for (int k = 1; k < n; ++k) {
		flag = false;
		while (!flag) {
			++b[k];
			flag = true;
			for (int i = 0; flag && i < k; ++i) {
				flag &= s.count(b[i] + b[k]) == 0;
			}
		}
		for (int i = 0; i < k; ++i) {
			a[i][k] = a[k][i] = b[i] + b[k];
			s.insert(a[i][k]);
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("%d%c", a[i][j], j == n - 1 ? '\n' : ' ');
		}
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//218422 	Dec 12, 2010 4:12:03 PM 	watashi 	D - Strange town 	GNU C++ 	Accepted 	30 ms 	1316 KB

