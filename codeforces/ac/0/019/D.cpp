#include <set>
#include <map>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 1 << 18;

vector<int> vx, vy;
map<int, int> mpx, mpy;
pair<char, pair<int, int> > q[MAXN];

struct SegTree {
	int n;
	int maxy[MAXN + MAXN];
	multiset<int> st[MAXN + MAXN];

	static int L(int p) { return p << 1; }
	static int R(int p) { return L(p) ^ 1; }

	void init(int m) {
		n = 1;
		while (n < m) {
			n <<= 1;
		}
		fill(maxy, maxy + n + n, -1);
		fill(st, st + n + n, multiset<int>());
	}

	void add(int x, int y) {
		x += n;
		st[x].insert(y);
		maxy[x] = *st[x].rbegin();
		while (x > 1) {
			x >>= 1;
			maxy[x] = max(maxy[L(x)], maxy[R(x)]);
		}
	}

	void del(int x, int y) {
		x += n;
		st[x].erase(st[x].find(y));
		maxy[x] = st[x].empty() ? -1 : *st[x].rbegin();
		while (x > 1) {
			x >>= 1;
			maxy[x] = max(maxy[L(x)], maxy[R(x)]);
		}
	}

	pair<int, int> gao(int p, int pl, int pr, int l, int r, int y) {
		if (maxy[p] < y) {
			return make_pair(-1, -1);
		} else if (pr - pl == 1) {
			return make_pair(pl, *st[p].lower_bound(y));
		} else {
			int pm = (pl + pr) / 2;
			if (r <= pm) {
				return gao(L(p), pl, pm, l, r, y);
			} else if (pm <= l) {
				return gao(R(p), pm, pr, l, r, y);
			} else {
				pair<int, int> ret;
				ret = gao(L(p), pl, pm, l, pm, y);
				if (ret.first == -1) {
					ret = gao(R(p), pm, pr, pm, r, y);
				}
				return ret;
			}
		}
	}

	pair<int, int> gao(int x, int y) {
		return gao(1, 0, n, x + 1, n, y + 1);
	}
} st;

int main() {
	int n;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf(" %c%*s%d%d", &q[i].first, &q[i].second.first, &q[i].second.second);
		mpx[q[i].second.first];
		mpy[q[i].second.second];
	}
	for (map<int, int>::iterator it = mpx.begin(); it != mpx.end(); ++it) {
		it->second = vx.size();
		vx.push_back(it->first);
	}
	for (map<int, int>::iterator it = mpy.begin(); it != mpy.end(); ++it) {
		it->second = vy.size();
		vy.push_back(it->first);
	}
	
	st.init(vx.size() + 1);
	for (int i = 0; i < n; ++i) {
		pair<int, int> p = q[i].second;
		p.first = mpx[p.first];
		p.second = mpy[p.second];
		if (q[i].first == 'a') {
			st.add(p.first, p.second);
		} else if (q[i].first == 'r') {
			st.del(p.first, p.second);
		} else {
			p = st.gao(p.first, p.second);
			if (p.first != -1) {
				printf("%d %d\n", vx[p.first], vy[p.second]);
			} else {
				puts("-1");
			}
		}
	}

	return 0;
}

// without maxy: Time limit exceeded on test 13
//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//444578 	May 10, 2011 10:40:16 PM 	watashi 	19D - Points 	GNU C++ 	Accepted 	1230 ms 	36500 KB
