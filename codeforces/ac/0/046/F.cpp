#include <map>
#include <queue>
#include <bitset>
#include <cstdio>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 1024;
vector<pair<int, int> > e[MAXN];

struct DisjointSet {
	int p[MAXN];
	bitset<MAXN + MAXN> b[MAXN];

	void init(int n) {
		for (int i = 0; i < n; ++i) {
			p[i] = i;
			b[i].reset();
		}
	}

	int root(int i) {
		return p[i] == i ? i : (p[i] = root(p[i]));
	}

	bool setp(int i, int j) {
		i = root(i);
		j = root(j);
		if (i != j) {
			p[i] = j;
			b[j] |= b[i];
			return true;
		} else {
			return false;
		}
	}

	void gao(const int n, const int s) {
		if (root(s) != s) {
			return;
		}
		bool loop = true;
		while (loop) {
			vector<bool> mark(n, false);
			queue<int> q;
			int t;
			q.push(s);
			mark[s] = true;
			loop = false;
			while (!q.empty()) {
				t = q.front();
				q.pop();
				loop |= setp(t, s);
				for (vector<pair<int, int> >::const_iterator it = e[t].begin(); it != e[t].end(); ++it) {
					if (!mark[it->first] && b[s].test(it->second)) {
						mark[it->first] = true;
						q.push(it->first);
					}
				}
			}
		}
	}
} ds1, ds2;

map<string, int> mp;

int getId(const string& s) {
	if (mp.count(s) > 0) {
		return mp[s];
	} else {
		int ret = mp.size();
		mp[s] = ret;
		return ret;
	}
}

void gao(int n, int m, int k, DisjointSet& ds) {
	int r, c, t;
	static char buf[80];
	ds.init(n);
	for (int i = 0; i < k; ++i) {
		scanf("%s%d%d", buf, &r, &c);
		--r;
		ds.b[r].set(m + getId(buf));
		for (int j = 0; j < c; ++j) {
			scanf("%d", &t);
			--t;
			ds.b[r].set(t);
		}
	}
	for (int i = 0; i < n; ++i) {
		ds.gao(n, i);
	}
}

int main() {
	int n, m, k, a, b;

	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &a, &b);
		--a;
		--b;
		e[a].push_back(make_pair(b, i));
		e[b].push_back(make_pair(a, i));
	}
	gao(n, m, k, ds1);
	gao(n, m, k, ds2);
	bool flag = true;
	for (int i = 0; i < n; ++i) {
		flag &= (ds1.b[ds1.root(i)] == ds2.b[ds2.root(i)]);
	}
	puts(flag ? "YES" : "NO");

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//208618 	Dec 5, 2010 7:54:59 PM 	watashi 	F - Hercule Poirot Problem 	GNU C++ 	Accepted 	80 ms 	1928 KB 
