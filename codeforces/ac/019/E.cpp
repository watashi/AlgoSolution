#include <set>
#include <map>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 1 << 16;

struct Disjoint {
	int p[MAXN];

	void init(int n) {
		for (int i = 1; i <= n; ++i) {
			p[i] = i;
		}
	}

	int getp(int i) {
		if (i > 0) {
			return i == p[i] ? i : (p[i] = getp(p[i]));
		} else {
			return -getp(-i);
		}
	}

	void setp(int i, int j) {
		i = getp(i);
		j = getp(j);
		if (i == j) {
		} else if (i == -j) {
			throw -1;
		} else if (i > 0) {
			p[i] = j;
		} else {
			p[-i] = -j;
		}
	}
} ds;

int tag[MAXN];
vector<int> e[MAXN];
vector<int> odd;

void dfs(int v, int c) {
	if (tag[v] == 0) {
		tag[v] = c;
		for (vector<int>::const_iterator w = e[v].begin(); w != e[v].end(); ++w) {
			try {
				dfs(*w, -c);
			} catch (int u) {
				if (u == -1 || u == v) {
					throw -1;
				} else {
					odd.push_back(v);
					throw;
				}
			}
		}
	} else if (tag[v] != c) {
		odd.push_back(v);
		throw v;
	}
}

bool ok[MAXN];
int lst[MAXN];

int go(int i) {
	return ok[i] ? i : (lst[i] = go(lst[i]));
}

void clear(int begin, int end) {
	for (int i = begin; i < end; i = go(i)) {
		ok[i] = false;
	}
}

int main() {
	int n, m, a, b;
	vector<int> ans;
	map<int, set<int> > next;
	map<pair<int, int>, int> mp;

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d", &a, &b);
		e[a].push_back(b);
		e[b].push_back(a);
		mp[make_pair(a, b)] = mp[make_pair(b, a)] = i;
	}

	try {
		fill(tag + 1, tag + n + 1, 0);
		for (int i = 1; i <= n; ++i) {
			if (tag[i] == 0) {
				dfs(i, 1);
			}
		}
		for (int i = 1; i <= m; ++i) {
			ans.push_back(i);
		}
		goto OUTPUT;
	} catch (...) {
	}

	fill(tag + 1, tag + n + 1, -1);
	m = odd.size();
	for (int i = 0; i < m; ++i) {
		tag[odd[i]] = i;
	}
	ds.init(n);
	try {
		int c = 0;
		for (map<pair<int, int>, int>::const_iterator i = mp.begin(); i != mp.end(); ++i) {
			a = i->first.first;
			b = i->first.second;
			if (tag[a] == -1 || tag[b] == -1 || (tag[a] != (tag[b] + 1) % m && tag[b] != (tag[a] + 1) % m)) {
				ds.setp(a, -b);
				++c;
			}
		}
	} catch (...) {
		goto OUTPUT;
	}

	for (int i = 0; i < 2 * m; ++i) {
		next[ds.getp(i % 2 == 0 ? odd[i % m] : -odd[i % m])].insert(i);
	}
	for (int i = 0; i <= m; ++i) {
		ok[i] = true;
		lst[i] = i + 1;
	}
	for (int i = 0; i < m; ++i) {
		int j = -ds.getp(i % 2 == 0 ? odd[i] : -odd[i]);
		if (next.count(j) == 0) {
			continue;
		}
		set<int>::const_iterator it = next[j].upper_bound(i);
		if (*it < i + m) {
			if (*it < m) {
				clear(0, i);
				clear(*it, m);
			} else {
				clear(*it - m, i);
			}
		}
	}
	
	for (int i = 0; i < m; ++i) {
		if (ok[i]) {
			ans.push_back(mp[make_pair(odd[i % m], odd[(i + 1) % m])]);
		}
	}
	sort(ans.begin(), ans.end());

OUTPUT:
	printf("%d\n", ans.size());
	for (int i = 0; i < (int)ans.size(); ++i) {
		printf("%d ", ans[i]);
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//445734 	May 12, 2011 5:27:35 PM 	watashi 	19E - Fairy 	GNU C++ 	Accepted 	80 ms 	6800 KB 
