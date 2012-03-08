#include <cstdio>
#include <vector>
#include <numeric>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
	int n, m, t, p;
	vector<pair<int, int> > v[3];

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &t, &p);
		v[t].push_back(make_pair(p, i));
	}
	v[1].push_back(make_pair(0, 0));
	for (int i = 1; i <= 2; ++i) {
		sort(v[i].begin(), v[i].end());
		reverse(v[i].begin(), v[i].end());
	}
	v[2].resize(min<int>(v[2].size(), m / 2));
	t = min<int>(v[1].size(), m - v[2].size() * 2);
	while (!v[2].empty() && t + 2 <= (int)v[1].size() && v[1][t].first + v[1][t + 1].first > v[2].back().first) {
		v[2].pop_back();
		t += 2;
	}
	v[1].resize(t);

	p = 0;
	for (int i = 1; i <= 2; ++i) {
		for (vector<pair<int, int> >::const_iterator it = v[i].begin(); it != v[i].end(); ++it) {
			p += it->first;
		}
	}
	printf("%d\n", p);
	for (int i = 1; i <= 2; ++i) {
		for (vector<pair<int, int> >::const_iterator it = v[i].begin(); it != v[i].end(); ++it) {
			if (it->second > 0) {
				printf("%d ", it->second);
			}
		}
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//255705 	Jan 20, 2011 8:11:27 PM 	watashi 	3B - Lorry 	GNU C++ 	Accepted 	90 ms 	3100 KB 

