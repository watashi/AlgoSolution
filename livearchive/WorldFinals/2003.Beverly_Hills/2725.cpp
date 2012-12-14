#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

#define fst first
#define snd second

typedef pair<int, int> PII;
typedef pair<int, PII> PXY;

const int MAXN = 108;
const int INF = 1000000000;

PII ordered_pair(int x, int y) {
	return make_pair(min(x, y), max(x, y));
}

void read(int n, vector<PXY>& v, int& ymin, int& ymax) {
	static PII p[MAXN];

	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &p[i].fst, &p[i].snd);
	}
	p[n] = p[0];
	ymin = ymax = p[0].snd;
	for (int i = 0; i < n; ++i) {
		ymin = min(ymin, p[i].snd);
		ymax = max(ymax, p[i].snd);
		if (p[i].fst == p[i + 1].fst) {
			v.push_back(make_pair(p[i].fst, ordered_pair(p[i].snd, p[i + 1].snd)));
		}
	}
}

void cut(int h1, int h2, const vector<PXY>& v, vector<PII>& r) {
	vector<int> x;

	for (vector<PXY>::const_iterator i = v.begin(); i != v.end(); ++i) {
		if (i->snd.fst <= h1 && h2 <= i->snd.snd) {
			x.push_back(i->fst);
		}
	}
	sort(x.begin(), x.end());
	for (int i = 0; i < (int)x.size(); i += 2) {
		r.push_back(make_pair(x[i], x[i + 1]));
	}
}

vector<PII> intersection(const vector<PII>& lhs, const vector<PII>& rhs) {
	int i = 0, j = 0;
	vector<PII> r;

	while (i < (int)lhs.size() && j < (int)rhs.size()) {
		if (lhs[i].snd < rhs[j].fst) {
			++i;
		} else if (rhs[j].snd < lhs[i].fst) {
			++j;
		} else {
			r.push_back(make_pair(max(lhs[i].fst, rhs[j].fst), min(lhs[i].snd, rhs[j].snd)));
			if (r.back().snd == lhs[i].snd) {
				++i;
			}
			if (r.back().snd == rhs[j].snd) {
				++j;
			}
		}
	}

	return r;
}

int main() {
	bool flag;
	vector<PXY> u, v;
	vector<PII> uu, vv, r, rr;
	vector<int> off, y;
	int ri = 0, n, m, ymin1, ymax1, ymin2, ymax2;

	while (scanf("%d%d", &n, &m) != EOF && n > 0) {
		u.clear();
		v.clear();
		read(n, u, ymin1, ymax1);
		read(m, v, ymin2, ymax2);
		ymax2 -= ymax1;
		ymin2 -= ymin1;
		off.clear();
		for (vector<PXY>::const_iterator i = u.begin(); i != u.end(); ++i) {
			for (vector<PXY>::const_iterator j = v.begin(); j != v.end(); ++j) {
				int k;
				k = j->snd.fst - i->snd.fst;
				if (ymin2 <= k && k <= ymax2) {
					off.push_back(k);
				}
				k = j->snd.fst - i->snd.snd;
				if (ymin2 <= k && k <= ymax2) {
					off.push_back(k);
				}
				k = j->snd.snd - i->snd.fst;
				if (ymin2 <= k && k <= ymax2) {
					off.push_back(k);
				}
				k = j->snd.snd - i->snd.snd;	// if only this one, then WA
				if (ymin2 <= k && k <= ymax2) {
					off.push_back(k);
				}
			}
		}
		sort(off.begin(), off.end());
		off.erase(unique(off.begin(), off.end()), off.end());

		flag = false;
		for (vector<int>::const_iterator d = off.begin(); d != off.end(); ++d) {
			y.clear();
			for (vector<PXY>::const_iterator i = u.begin(); i != u.end(); ++i) {
				y.push_back(i->snd.fst + *d);
				y.push_back(i->snd.snd + *d);
			}
			for (vector<PXY>::const_iterator j = v.begin(); j != v.end(); ++j) {
				y.push_back(j->snd.fst);
				y.push_back(j->snd.snd);
			}
			sort(y.begin(), y.end());
			y.erase(unique(y.begin(), y.end()), y.end());

			r.clear();
			r.push_back(make_pair(-INF, INF));
			for (vector<int>::const_iterator h = y.begin() + 1; h != y.end() && !r.empty(); ++h) {
				uu.clear();
				cut(*(h - 1) - *d, *h - *d, u, uu);
				if (uu.empty()) {
					continue;
				}
				vv.clear();
				cut(*(h - 1), *h, v, vv);
				for (vector<PII>::const_iterator i = uu.begin(); i != uu.end() && !r.empty(); ++i) {
					rr.clear();
					for (vector<PII>::const_iterator j = vv.begin(); j != vv.end(); ++j) {
						if (j->snd - j->fst >= i->snd - i->fst) {
							rr.push_back(make_pair(j->fst - i->fst, j->snd - i->snd));
						}
					}
					r = intersection(r, rr);
				}
			}
			if (!r.empty()) {
				flag = true;
				break;
			}
		}
		printf("Hole %d: %s\n", ++ri, flag ? "Yes" : "No");
	}

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//723430  	2011-01-21 19:48:56 	Accepted	0.012	Minimum	26909	C++	2725 - Covering Whole Holes

/*
	CPU Time	Memory	Author	Source	Date (UTC)	ID   (host)
1	0.012	Minimum	watashi	C++	2011-01-21 19:48:56	723430   (H1)
2	0.043	Minimum	Jiaqi Zhai	C++	2009-12-03 00:44:35	518224   (H1)
3	0.045	Minimum	Pawel Gawrychowski	Pascal	2003-07-15 14:09:46	1743   (H1)
-	0.045	Minimum	Shao-Huan Wang	C++	2009-05-13 12:33:27	408004   (H1)
5	0.055	Minimum	Lemon Tree	C++	2005-10-03 08:47:03	66812   (H1)
6	0.070	Minimum	Xavier Pujol	C++	2007-10-12 13:15:57	214669   (H1)
7	0.133	936	Hanna Papaj	C++	2007-06-25 18:02:58	184551   (H1)
8	0.146	508	Paul Nelson	C++	2006-03-31 23:30:56	94438   (H1)
9	0.164	488	Samee Zahur	C++	2009-03-24 07:44:30	384414   (H1)
10	0.170	412	Eduardo Ribas	C++	2010-11-04 05:28:18	683419   (H1)
11	0.236	2908	qq 2003	C++	2006-03-12 06:34:32	91994   (H1)
12	0.244	536	Malcolm Sharpe	C++	2009-03-24 04:14:07	384361   (H1)
*/
/*
id => 1174158
pid => 2725
pname => Covering Whole Holes
status => Accepted
lang => C++
time => 0.012
date => 2012-12-14 17:31:18
*/
