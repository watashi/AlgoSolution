#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 128;

typedef pair<int, int> PII;

vector<PII> e[MAXN];

bool cmp(const PII& lhs, const PII& rhs) {
	return lhs.first < rhs.first || (lhs.first == rhs.first && lhs.second > rhs.second);
}

void gao(int v, int p, int q, vector<PII>& ret) {
	ret.clear();
	ret.push_back(make_pair(0, 0));
	for (vector<PII>::const_iterator w = e[v].begin(); w != e[v].end(); ++w) {
		if (w->first == p) {
			continue;
		}
		vector<PII> tmp, pre(ret);
		gao(w->first, v, q, tmp);
		ret.clear();
		for (vector<PII>::const_iterator i = pre.begin(); i != pre.end(); ++i) {
			for (vector<PII>::const_iterator j = tmp.begin(); j != tmp.end(); ++j) {
				for (int d = w->second % 60; d > -60; d -= 60) {
					if (abs(j->first + d) <= q &&
						abs(j->second + d) <= q &&
						abs(i->first + j->first + d) <= q &&
						abs(i->second + j->second + d) <= q) {
						ret.push_back(make_pair(min(i->first, j->first + d), max(i->second, j->second + d)));
					}
				}
			}
		}
		if (ret.empty()) {
			throw 1;
		} else {
			sort(ret.begin(), ret.end(), cmp);
			int n = 0;
			for (int i = 0; i < (int)ret.size(); ++i) {
				while (n > 0 && ret[n - 1].second >= ret[i].second) {
					--n;
				}
				ret[n++] = ret[i];
			}
			ret.resize(n);
		}
	}
/*
	printf("@%d: ", v);
	for (vector<PII>::const_iterator i = ret.begin(); i != ret.end(); ++i) {
		printf("(%d, %d) ", i->first, i->second);
	}
	puts("");
*/
}

int main() {
	int ri = 0, n, a, b, c, l, r, m;
	vector<PII> dummy;

	while (scanf("%d", &n) != EOF && n > 0) {
		for (int i = 0; i < n; ++i) {
			e[i].clear();
		}
		for (int i = 1; i < n; ++i) {
			scanf("%d%d%d", &a, &b, &c);
			--a;
			--b;
			e[a].push_back(make_pair(b, c));
			e[b].push_back(make_pair(a, c));
		}

		l = 0;
		r = 1 << 16;
		while (l < r) {
			m = (l + r) / 2;
		//	printf("gao %d: \n", m);
			try {
				gao(0, -1, m, dummy);
				r = m;
			} catch (...) {
				l = m + 1;
			}
		}
		printf("Case %d: %d\n", ++ri, r);
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//800133 	4454 	Subway Timing 	Accepted 	C++ 	0.096 	2011-05-17 13:53:54
/*
id => 1174039
pid => 4454
pname => Subway Timing
status => Accepted
lang => C++
time => 0.095
date => 2012-12-14 17:13:50
*/
