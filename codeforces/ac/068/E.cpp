#include <set>
#include <cmath>
#include <cstdio>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

const double EPS = 1e-8;
const double INF = 1e100;

struct Point {
	double x, y;
	Point() { }
	Point(double x, double y) : x(x), y(y) { }
	double abs() const { return hypot(x, y); }
	double arg() const { return atan2(y, x); }
	Point operator*(double o) const { return Point(x * o, y * o); }
	Point operator+(const Point& o) const { return Point(x + o.x, y + o.y); }
	Point operator-(const Point& o) const { return Point(x - o.x, y - o.y); }
	bool operator<(const Point& o) const { return x < o.x - EPS || (x < o.x + EPS && y < o.y - EPS); }
	Point scale(double o) const { return *this * (o / abs()); }
	Point rotl() const { return Point(-y, x); }
	Point rotr() const { return Point(y, -x); }
};

struct Triangle {
	Point p[4];
	double q[3];
	void init() {
		p[3] = p[0];
		for (int i = 0; i < 3; ++i) {
			q[i] = (p[i + 1] - p[i]).abs();
		}
		sort(q, q + 3);
	}
};

void gao(const Point& a, const Point& b, double da, double db, vector<Point>& ret, int dump = 0) {
	double sum = (b - a).abs();
	double dif = (da * da - db * db) / sum;
	double ra = (sum + dif) / 2;
	double rb = (sum - dif) / 2;
	double h = da * da - ra * ra;
	if (h < -EPS) {
		return;
	} else {
		h = sqrt(max(0.0, h));
	}
	Point v = (b - a).scale(h);
	ret.push_back(a + (b - a).scale(ra) + v.rotl());
	ret.push_back(a + (b - a).scale(ra) + v.rotr());
	ret.push_back(a + (b - a).scale(rb) + v.rotl());
	ret.push_back(a + (b - a).scale(rb) + v.rotr());
}

int main() {
	int ans;
	double e[4];
	Triangle t[4];
	vector<Point> v;

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 3; ++j) {
			scanf("%lf%lf", &t[i].p[j].x, &t[i].p[j].y);
		}
		t[i].init();
	}

	// 0:
	ans = 9;
	for (int i = 0; i < 81; ++i) {
		for (int j = 0, k = i; j < 4; ++j, k /= 3) {
			e[j] = t[j].q[k % 3];
		}
		if (*max_element(e, e + 4) * 2 - accumulate(e, e + 4, 0.0) < EPS) {
			ans = 8;
			break;
		}
	}
	
	// 1:
	for (int i = 0; i < 12; ++i) {
		for (int j = (i / 3 + 1) * 3; j < 12; ++j) {
			for (int k = (j / 3 + 1) * 3; k < 12; ++k) {
				Point a(0, 0);
				Point b(t[i / 3].q[i % 3], 0);
				v.clear();
				gao(a, b, t[j / 3].q[j % 3], t[k / 3].q[k % 3], v);
				if (v.empty()) {
					continue;
				}
				Point c = v[0];
				vector<Point> va, vb, vc;
				gao(a, b, t[i / 3].q[(i + 1) % 3], t[i / 3].q[(i + 2) % 3], va);
				gao(a, c, t[j / 3].q[(j + 1) % 3], t[j / 3].q[(j + 2) % 3], vb);
				gao(b, c, t[k / 3].q[(k + 1) % 3], t[k / 3].q[(k + 2) % 3], vc);
				for (const Point& pa: va) {
					for (const Point& pb: vb) {
						for (const Point& pc: vc) {
							set<Point> st = {a, b, c, pa, pb, pc};
							ans = min(ans, (int)st.size() + 2);
							for (int l = 0; l < 12; ++l) {
								if (i / 3 + j / 3 + k / 3 + l / 3 != 6) {
									continue;
								}
								for (const Point& u: st) {
									for (const Point& v: st) {
										if (fabs((u - v).abs() - t[l / 3].q[l % 3]) > EPS) {
											continue;
										}
										vector<Point> vd;
										gao(u, v, t[l / 3].q[(l + 1) % 3], t[l / 3].q[(l + 2) % 3], vd);
										for (const Point& pd: vd) {
											ans = min(ans, (int)st.size() + 1 - (int)st.count(pd));
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	// 2:
	int tmp = 3;
	for (int i = 1; i < 4; ++i) {
		int acc = 2;
		for (int j = 0; j < i; ++j) {
			bool same = true;
			for (int k = 0; k < 3 && same; ++k) {
				same &= fabs(t[i].q[k] - t[j].q[k]) < EPS;
			}
			if (same) {
				acc = 0;
				break;
			}
		}
		for (int j = 0; j < 3 * i && acc > 1; ++j) {
			for (int k = 0; k < 3; ++k) {
				if (fabs(t[j / 3].q[j % 3] - t[i].q[k]) < EPS) {
					acc = 1;
					break;
				}
			}
		}
		tmp += acc;
	}
	ans = min(ans, tmp);

	printf("%d\n", ans);

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//443803 	May 9, 2011 7:10:47 PM 	watashi 	68E - Contact 	GNU C++0x 	Accepted 	750 ms 	1400 KB 
