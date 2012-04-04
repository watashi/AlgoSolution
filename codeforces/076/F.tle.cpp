#include <map>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

#define fst first
#define snd second

typedef int longint;

const int MAX = 1 << 28;

struct SegmentTree {
	const int xl, xr, xm;
	map<longint, int> ys;
	SegmentTree *_pl, *_pr;

	SegmentTree(int xl, int xr):
			xl(xl), xr(xr), xm((xl + xr) / 2), _pl(NULL), _pr(NULL) {
	}

	SegmentTree* pl() {
		return _pl == NULL ? (_pl = new SegmentTree(xl, xm)) : _pl;
	}

	SegmentTree* pr() {
		return _pr == NULL ? (_pr = new SegmentTree(xm, xr)) : _pr;
	}

	void add(int x, longint y, int z) {
		map<longint, int>::iterator it = ys.lower_bound(y);
		if (it == ys.end() || it->snd < z) {
			map<longint, int>::iterator jt = it, kt = it;
			while (kt != ys.begin()) {
				--kt;
				if (kt->snd > z) {
					break;
				} else {
					jt = kt;
				}
			}
			ys.erase(jt, it);
			ys[y] = z;
		}
		if (xr - xl > 1) {
			if (x < xm) {
				pl()->add(x, y, z);
			} else {
				pr()->add(x, y, z);
			}
		}
	}

	int max(int l, int r, longint y) {
		if (ys.empty() || (xl == l && xr == r)) {
			map<longint, int>::iterator it = ys.lower_bound(y);
			return it == ys.end() ? 0 : it->snd;
		} else if (r <= xm) {
			return pl()->max(l, r, y);
		} else if (xm <= l) {
			return pr()->max(l, r, y);
		} else {
			return std::max(pl()->max(l, xm, y), pr()->max(xm, r, y));
		}
	}
};

int main() {
	int n, a, b, c, d;
	longint m;
	map<int, int> mpx;
	vector<pair<int, int> > v;

	scanf("%d", &n);
	v.resize(n);
	mpx[0];
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &v[i].snd, &v[i].fst);
		mpx[v[i].snd];
	}
	scanf("%d", &m);
//	scanf("%I64d", &m);
//	scanf("%lld", &m);
	v.push_back(make_pair(0, 0));
	sort(v.rbegin(), v.rend());
	
	c = 0;
	for (map<int, int>::iterator i = mpx.begin(); i != mpx.end(); ++i) {
		i->second = c++;
	}
	d = 1;
	while (d < c) {
		d <<= 1;
	}

	SegmentTree* lft = new SegmentTree(0, d);
	SegmentTree* rt = new SegmentTree(0, d);

	a = b = 0;
	for (int i = 0; i < (int)v.size(); ++i) {
		c = mpx[v[i].snd];
		int dp = 1 + max(
				lft->max(0, c + 1, m * v[i].fst + v[i].snd),
				rt->max(c, d, m * v[i].fst - v[i].snd));
//		printf("@%d [%d, %d] = %d\n", c, v[i].fst, v[i].snd, dp);
		if (v[i].fst == 0) {
			a = max(a, dp);
		} else {
			b = max(b, dp);
		}
		lft->add(c, m * v[i].fst + v[i].snd, dp);
		rt->add(c, m * v[i].fst - v[i].snd, dp);
	}
	printf("%d %d\n", a - 1, b);

	return 0;
}

//Test: #16, time: 910 ms., memory: 47484 KB, exit code: 0, checker exit code: 0, verdict: OK 
//Test: #17, time: 1000 ms., memory: 79740 KB, exit code: 0, checker exit code: 0, verdict: TIME_LIMIT_EXCEEDED
