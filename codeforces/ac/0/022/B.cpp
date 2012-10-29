// NWERC2010 - G
// O(n*m)

#include <map>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1024;
char s[MAXN];
int h[MAXN];
int l[MAXN];

struct Gao {
	vector<pair<int, int> > s;

	void init() {
		s.clear();
	}

	void insert(int h, int p) {
		while (!s.empty() && s.back().first > h) {
			s.pop_back();
		}
		if (s.empty() || s.back().second < p) {
			s.push_back(make_pair(h, p));
		}
	}

	int query() const {
		return s.back().second;
	}
} gao;

int main() {
	int re;
	int n, m;
	map<int, int> ans;

	scanf("%d%d", &n, &m);
	ans.clear();
	fill(h, h + m, 0);
	for (int i = 0; i < n; ++i) {
		scanf("%s", s);
		gao.init();
		for (int j = 0; j < m; ++j) {
			++h[j];
			if (s[j] == '1') {
				h[j] = 0;
				gao.init();
			}
			l[j] = j - 1;
			while (l[j] >= 0 && h[j] <= h[l[j]]) {
				l[j] = l[l[j]];
			}
			if (h[j] > 0) {
				gao.insert(h[j], h[j] - l[j]);
				++ans[gao.query() + j];
			}
		}
	}
	printf("%d\n", 2 * ans.rbegin()->first);

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//219392 	Dec 15, 2010 3:28:31 PM 	watashi 	B - Bargaining Table 	GNU C++ 	Accepted 	30 ms 	1316 KB 
