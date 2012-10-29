#include <set>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 100100;

int main() {
	int n, k, p, best;
	static int a[MAXN];
	multiset<int> st;
	vector<pair<int, int> > ans;

	scanf("%d%d", &n, &k);
	p = 0;
	best = -1;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		st.insert(a[i]);
		while (*st.rbegin() - *st.begin() > k) {
			st.erase(st.find(a[p++]));
		}
		if (best < i - p) {
			best = i - p;
			ans.clear();
		}
		if (best == i - p) {
			ans.push_back(make_pair(p, i));
		}
	}
	printf("%d %d\n", best + 1, ans.size());
	for (int i = 0; i < (int)ans.size(); ++i) {
		printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//201388 	Nov 30, 2010 8:04:16 PM 	watashi 	E - Exposition 	GNU C++ 	Accepted 	130 ms 	4836 KB
