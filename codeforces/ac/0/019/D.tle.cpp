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
	set<pair<int, int> > st[MAXN << 1];

	static int L(int p) { return p << 1; }
	static int R(int p) { return L(p) ^ 1; }

	void init(int m) {
		n = 1;
		while (n < m) {
			n <<= 1;
		}
		fill(st, st + n + n, set<pair<int, int> >());
	}

	void add(int x, int y) {
		for (int i = y + n; i > 0; i >>= 1) {
			st[i].insert(make_pair(x, y));
		}
	}

	void del(int x, int y) {
		for (int i = y + n; i > 0; i >>= 1) {
			st[i].erase(make_pair(x, y));
		}
	}

	pair<int, int> gao(int p, int pl, int pr, int l, int r, int x) {
		if (pl == l && pr == r) {
			set<pair<int, int> >::const_iterator it = st[p].lower_bound(make_pair(x, -1));
			return it == st[p].end() ? make_pair(n, n) : *it;
		} else {
			int pm = (pl + pr) / 2;
			if (r <= pm) {
				return gao(L(p), pl, pm, l, r, x);
			} else if (pm <= l) {
				return gao(R(p), pm, pr, l, r, x);
			} else {
				return min(gao(L(p), pl, pm, l, pm, x), gao(R(p), pm, pr, pm, r, x));
			}
		}
	}

	pair<int, int> gao(int x, int y) {
		return gao(1, 0, n, y + 1, n, x + 1);
	}
} st;

int main() {
	int n, m;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf(" %c%*s%d%d", &q[i].first, &q[i].second.first, &q[i].second.second);
		mpx[q[i].second.first];
		mpy[q[i].second.second];
	}
	m = 0;
	for (map<int, int>::iterator it = mpx.begin(); it != mpx.end(); ++it) {
		vx.push_back(it->first);
		it->second = m++;
	}
	m = 0;
	for (map<int, int>::iterator it = mpy.begin(); it != mpy.end(); ++it) {
		vy.push_back(it->first);
		it->second = m++;
	}
	
	st.init(++m);
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
			if (p.second < m) {
				printf("%d %d\n", vx[p.first], vy[p.second]);
			} else {
				puts("-1");
			}
		}
	}

	return 0;
}

//Time limit exceeded on test 13
