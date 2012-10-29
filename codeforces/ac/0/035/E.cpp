#include <set>
#include <queue>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
	int n, h, l, r;
	multiset<int> s;
	vector<pair<int, int> > v, w;
	vector<pair<int, int> >::const_iterator it, jt;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d%d", &h, &l, &r);
		v.push_back(make_pair(l, h));
		v.push_back(make_pair(r, -h));
	}
	sort(v.begin(), v.end());

	s.insert(h = 0);
	it = v.begin();
	while (it != v.end()) {
		jt = it;
		do {
			if (jt->second > 0) {
				s.insert(jt->second);
			} else if (jt->second < 0) {
				s.erase(s.find(-jt->second));
			}
			++jt;
		} while (jt != v.end() && jt->first == it->first);

		if (*s.rbegin() != h) {
			w.push_back(make_pair(it->first, h));
			w.push_back(make_pair(it->first, h = *s.rbegin()));
		}
		it = jt;
	}

	printf("%d\n", (int)w.size());
	for (int i = 0; i < (int)w.size(); ++i) {
		printf("%d %d\n", w[i].first, w[i].second);
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//234704 	Dec 29, 2010 11:01:28 AM 	watashi 	E - Parade 	GNU C++ 	Accepted 	500 ms 	11864 KB 
