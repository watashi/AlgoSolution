#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Hikari {
	double l1, r1, l2, r2;
};

double area(const Hikari& h) {
	return ((h.r1 - h.l1) + (h.r2 - h.l2)) / 2;
}

void gao(double u1, double d1, double u2, double d2, vector<double>& ret) {
	if (u1 == u2 || d1 == d2) {
		return;
	} else if (u1 > u2) {
		gao(u2, d2, u1, d1, ret);
	} else if (d1 > d2) {
		d1 -= u1;
		d2 -= u2;
		ret.push_back((u2 - u1) / (d1 - d2));
	}
}

double area(const Hikari& a, const Hikari& b) {
	vector<double> v;
	v.push_back(0);
	v.push_back(1);
	gao(a.l1, a.l2, b.l1, b.l2, v);
	gao(a.l1, a.l2, b.r1, b.r2, v);
	gao(a.r1, a.r2, b.l1, b.l2, v);
	gao(a.r1, a.r2, b.r1, b.r2, v);
	sort(v.begin(), v.end());
	double ret = 0, w1 = 0, w2 = 0;
	for (int i = 0; i < (int)v.size(); ++i) {
		double ll = max(a.l1 + v[i] * (a.l2 - a.l1), b.l1 + v[i] * (b.l2 - b.l1));
		double rr = min(a.r1 + v[i] * (a.r2 - a.r1), b.r1 + v[i] * (b.r2 - b.r1));
		w2 = max(0.0, rr - ll);
//		printf("[%lf] %lf\n", v[i], w2);
		if (i > 0) {
			ret += (w1 + w2) * (v[i] - v[i - 1]) / 2;
		}
		w1 = w2;
	}
	return ret;
}

Hikari hx;
vector<Hikari> vx;

int main() {
	int n;
	double h, f, ans;

	scanf("%d%lf%lf", &n, &h, &f);
	for (int i = 0; i < n; ++i) {
		scanf("%lf%lf", &hx.l1, &hx.r1);
		hx.l2 = f / (f - h) * hx.l1;
		hx.r2 = f / (f - h) * hx.r1;
		vx.push_back(hx);
		hx.l1 = (f + h) / f * hx.l2;
		hx.r1 = (f + h) / f * hx.r2;
		vx.push_back(hx);
	}
	ans = 0;
	for (int i = 0; i < (int)vx.size(); ++i) {
		ans += area(vx[i]);
		for (int j = 0; j < i; ++j) {
			ans -= area(vx[i], vx[j]);
		}
	}
	printf("%.10lf\n", ans * h * 2);

	return 0;
}

