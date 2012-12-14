#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const double EPS = 1e-8;
const int MAXN = 128;
const int INF = 1 << 20;

bool lt(double lhs, double rhs) {
	return lhs < rhs - EPS;
}

bool le(double lhs, double rhs) {
	return lhs <= rhs + EPS;
}

bool eq(double lhs, double rhs) {
	return fabs(lhs - rhs) < EPS;
}

bool lt2(const pair<double, double>& lhs, const pair<double, double>& rhs) {
	return lt(lhs.first, rhs.first) || (eq(lhs.first, rhs.first) && lt(lhs.second, rhs.second));
}

struct Point {
	double x, y;
	Point() { }
	Point(double x, double y) : x(x), y(y) { }
};

struct Line {
	Point a, b;
	Line() { }
	Line(const Point& a, const Point& b) : a(a), b(b) { }
	void std() {
		if (lt(b.y, a.y)) {
			swap(a, b);
		}
	}
	bool intersection(double yb, double yt, double& xb, double& xt) {
		if (le(a.y, yb) && le(yt, b.y)) {
			xb = a.x + (b.x - a.x) / (b.y - a.y) * (yb - a.y);
			xt = a.x + (b.x - a.x) / (b.y - a.y) * (yt - a.y);
			return true;
		} else {
			return false;
		}
	}	
};

struct Block {
	int h, d;
	double b, t, lb, rb, lt, rt;
	vector<vector<Block>::iterator> p;
	Block(int h, double b, double t, double lb, double rb, double lt, double rt) :
		h(h), d(INF), b(b), t(t), lb(lb), rb(rb), lt(lt), rt(rt) { }
	double area() const {
		return ((rb - lb) + (rt - lt)) * (t - b);
	}
};


int main() {
	int ri = 0, n, hh;
	bool h[MAXN];
	double xb, xt, ans;
	Point ps[MAXN];
	Line ls[MAXN];
	vector<double> yy;
	vector<vector<Block> > bs;
	vector<pair<double, double> > vx;

	while (scanf("%d", &n) != EOF && n > 0) {
		// init
		yy.clear();
		for (int i = 0; i < n; ++i) {
			scanf("%lf%lf%d", &ps[i].x, &ps[i].y, &hh);
			yy.push_back(ps[i].y);
			h[i] = (hh != 0);
		}
		for (int i = 0; i < n; ++i) {
			ls[i].a = ps[i];
			ls[i].b = ps[(i + 1) % n];
			ls[i].std();
		}
		sort(yy.begin(), yy.end(), lt);
		yy.erase(unique(yy.begin(), yy.end(), eq), yy.end());

		// calc block
		bs.clear();
		for (int i = 1; i < (int)yy.size(); ++i) {
			vx.clear();
			for (int j = 0; j < n; ++j) {
				if (ls[j].intersection(yy[i - 1], yy[i], xb, xt)) {
					vx.push_back(make_pair(xb, xt));
				}
			}
			sort(vx.begin(), vx.end(), lt2);
//			fprintf(stderr, "vx.size() = %u\n", vx.size());
			bs.push_back(vector<Block>());
			for (int j = 0; j < (int)vx.size(); j += 2) {
				bs.back().push_back(Block(i,
						yy[i - 1], yy[i],
						vx[j].first, vx[j + 1].first,
						vx[j].second, vx[j + 1].second));
			}
		}

		// build edge
		for (int k = 1; k < (int)bs.size(); ++k) {
			for (vector<Block>::iterator i = bs[k - 1].begin(); i != bs[k - 1].end(); ++i) {
				for (vector<Block>::iterator j = bs[k].begin(); j != bs[k].end(); ++j) {
					if (!le(i->rt, j->lb) && !le(j->rb, i->lt)) {
						i->p.push_back(j);
						j->p.push_back(i);
					}
				}
			}
		}

		// init heap
		priority_queue<pair<int, vector<Block>::iterator> > pq;
		for (int k = 0; k < (int)bs.size(); ++k) {
			for (vector<Block>::iterator i = bs[k].begin(); i != bs[k].end(); ++i) {
				for (int j = 0; j < n; ++j) {
					if (!h[j]) {
						continue;
					}
					if (eq(ps[j].y, i->b) && le(i->lb, ps[j].x) && le(ps[j].x, i->rb)) {
						i->d = min(i->d, i->h);
					}
					if (eq(ps[j].y, i->t) && le(i->lt, ps[j].x) && le(ps[j].x, i->rt)) {
						i->d = min(i->d, i->h + 1);
					}
				}
				if (i->d < INF) {
					pq.push(make_pair(-i->d, i));
				}
			}
		}

		// sp
		while (!pq.empty()) {
			vector<Block>::iterator i = pq.top().second;
			hh = -pq.top().first;
			pq.pop();
			if (hh != i->d) {
				continue;
			}
			hh = max(i->d, i->h);
			for (vector<vector<Block>::iterator>::iterator j = i->p.begin(); j != i->p.end(); ++j) {
				if ((*j)->d > hh) {
					(*j)->d = hh;
					pq.push(make_pair(-hh, (*j)));
				}
			}
		}
		
		// sum
		ans = 0;
		for (int k = 0; k < (int)bs.size(); ++k) {
			for (vector<Block>::iterator i = bs[k].begin(); i != bs[k].end(); ++i) {
				if (i->d > i->h) {
					ans += i->area();
				}
			}
		}
		printf("Cave %d: Oil capacity = %.0lf\n\n", ++ri, ans / 2 + EPS);	// !! + EPS
	}	

	return 0;
}

// orz myself
//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//722963  	2011-01-20 15:13:55 	Accepted	0.371	532	26909	C++	2479 - Toil for Oil

/*
id => 1174103
pid => 2479
pname => Toil for Oil
status => Accepted
lang => C++
time => 0.086
date => 2012-12-14 17:22:30
*/
