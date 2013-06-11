#include <map>
#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 128;

int main() {
	int n;
	int ans[MAXN];
	map<int, int> next;
	pair<pair<int, int>, int> p[MAXN];

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &p[i].first.second, &p[i].first.first);
		p[i].second = i;
	}
	sort(p, p + n);

	next[0] = 1;
	for (int i = 0; i < n; ++i) {
		map<int, int>::iterator it = next.upper_bound(p[i].first.second);
		--it;
		if (it->second >= p[i].first.second) {
			ans[p[i].second] = it->second++;
		} else {
			ans[p[i].second] = p[i].first.second;
			it = next.insert(make_pair(p[i].first.second, p[i].first.second + 1)).first;
		}
		map<int, int>::iterator jt = it;
		++jt;
		if (jt != next.end() && it->second == jt->first) {
			it->second = jt->second;
			next.erase(jt);
		}
	}

	for (int i = 0; i < n; ++i) {
		printf("%d ", ans[i]);
	}

	return 0;
}

// O(nlgn)
//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//413352 	Apr 28, 2011 1:56:17 AM 	watashi 	45D - Event Dates 	GNU C++ 	Accepted 	30 ms 	1400 KB 
