#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	bool swp = false;
	bool extra = false;
	vector<pair<int, int> > ans;

	scanf("%d%d", &n, &m);
	if (n > m) {
		swap(n, m);
		swp = !swp;
	}
	if (n == 1) {
		for (int i = 1; i <= m; ++i) {
			ans.push_back(make_pair(1, i));
		}
		extra = (m > 2);
	} else if (n % 2 != 0 && m % 2 != 0) {
		for (int i = 1; i <= n; ++i) {
			if (i & 1) {
				for (int j = 1; j <= m; ++j) {
					ans.push_back(make_pair(i, j));
				}
			} else {
				for (int j = m; j >= 1; --j) {
					ans.push_back(make_pair(i, j));
				}
			}
		}
		extra = true;
	} else {
		if (n % 2 != 0) {
			swap(n, m);
			swp = !swp;
		}
		ans.push_back(make_pair(1, 1));
		for (int i = 1; i <= n; ++i) {
			if (i & 1) {
				for (int j = 2; j <= m; ++j) {
					ans.push_back(make_pair(i, j));
				}
			} else {
				for (int j = m; j >= 2; --j) {
					ans.push_back(make_pair(i, j));
				}
			}
		}
		for (int i = n; i > 1; --i) {
			ans.push_back(make_pair(i, 1));
		}
	}

	if (swp) {
		for (vector<pair<int, int> >::iterator it = ans.begin(); it != ans.end(); ++it) {
			swap(it->first, it->second);
		}
	}
	if (extra == 0) {
		printf("%d\n", 0);
	} else {
		printf("%d\n%d %d %d %d\n", 1, ans.back().first, ans.back().second, 1, 1);
	}
	for (vector<pair<int, int> >::const_iterator it = ans.begin(); it != ans.end(); ++it) {
		printf("%d %d\n", it->first, it->second);
	}
	puts("1 1");

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//208986 	Dec 6, 2010 12:26:36 PM 	watashi 	D - Journey 	GNU C++ 	Accepted 	30 ms 	1560 KB 
// 1y
