#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 1000;
const double eps = 1e-8;
const double PI = atan2(0.0, -1.0);
inline double sqr(double x){ return x * x; }
inline bool zero(double x){ return (x > 0 ? x : -x) < eps; }
inline int sgn(double x){ return (x > eps ? 1 : (x + eps < 0 ? -1 : 0)); }
struct point3{
    double x, y, z;
    point3(double x, double y, double z):x(x), y(y), z(z){}
    point3() {}
    bool operator == (const point3 & a) const{ return sgn(x - a.x) == 0 && sgn(y - a.y) == 0 && sgn(z - a.z) == 0; }
    bool operator != (const point3 & a) const{ return sgn(x - a.x) != 0 || sgn(y - a.y) != 0 || sgn(z - a.z) != 0; }
    bool operator < (const point3 & a) const{ return sgn(x - a.x) < 0 || sgn(x - a.x) == 0 && sgn(y - a.y) < 0 || sgn(x - a.x) == 0 && sgn(y - a.y) == 0 && sgn(z - a.z) < 0; }
    point3 operator + (const point3 & a) const{ return point3(x + a.x, y + a.y, z + a.z); }
    point3 operator - (const point3 & a) const{ return point3(x - a.x, y - a.y, z - a.z); }
    point3 operator * (const double & a) const{ return point3(x * a, y * a, z * a); }
    point3 operator / (const double & a) const{ return point3(x / a, y / a, z / a); }
    point3 operator * (const point3 & a) const{ return point3(y * a.z - z * a.y, z * a.x - x * a.z, x * a.y - y * a.x); }//xmult
    double operator ^ (const point3 & a) const{ return x * a.x + y * a.y + z * a.z; }//dmult
    double sqrlen() const{ return sqr(x) + sqr(y) + sqr(z); }
    double length() const{ return sqrt(sqrlen()); }
    point3 trunc(double a) const{ return (*this) * (a / length()); }
    point3 rotate(const point3 & a, const point3 & b, const point3 & c) const{ return point3(a ^ (*this), b ^ (*this), c ^ (*this)); }//abc正交且模为1
};
inline point3 pvec(const point3 & a, const point3 & b, const point3 & c){
    return (a - b) * (b - c);
}//平面法向量
inline bool dotsInline(const point3 & a, const point3 & b, const point3 & c){
    return zero(((a - b) * (b - c)).length());
}//判三点共线
inline bool dotOnlineIn(const point3 & p, const point3 & l1, const point3 & l2){
    return zero(((p - l1) * (p - l2)).length()) && (l1.x - p.x) * (l2.x - p.x) < eps && (l1.y - p.y) * (l2.y - p.y) < eps && (l1.z - p.z) * (l2.z - p.z) < eps;
}//判点是否在线段上,包括端点和共线
inline int decideSide(const point3 & p1, const point3 & p2, const point3 & l1, const point3 & l2){
    return sgn(((l1 - l2) * (p1 - l2)) ^ ((l1 - l2) * (p2 - l2)));
}//点p1和p2,直线l1-l2,-1表示在异侧,0表示在线上,1表示同侧,须保证所有点共面
inline int decideSide(const point3 & p1, const point3 & p2, const point3 & a, const point3 & b, const point3 & c){
    return sgn((pvec(a, b, c) ^ (p1 - a)) * (pvec(a, b, c) ^ (p2 - a)));
}//点p1和p2,平面abc,-1表示在异侧,0表示在面上,1表示同侧
inline bool parallel(const point3 & u1, const point3 & u2, const point3 & v1, const point3 & v2){
    return zero(((u1 - u2) * (v1 - v2)).length());
}//判两直线平行
inline bool parallel(const point3 & a, const point3 & b, const point3 & c, const point3 & d, const point3 & e, const point3 & f){
    return zero((pvec(a, b, c) * pvec(d, e, f)).length());
}//判两平面平行
inline bool parallel(const point3 & l1, const point3 & l2, const point3 & a, const point3 & b, const point3 & c){
    return zero((l1 - l2) ^ pvec(a, b, c));
}//判直线与平面平行
point3 intersection(const point3 & l1, const point3 & l2, const point3 & a, const point3 & b, const point3 & c){
    point3 temp = pvec(a, b, c); return l1 + (l2 - l1) * ((temp ^ (a - l1)) / (temp ^ (l2 - l1)));
}//计算直线与平面交点,须预判是否平行,并保证三点不共线
void intersection(const point3 & a, const point3 & b, const point3 & c, const point3 & d, const point3 & e, const point3 & f, point3 & p1, point3 & p2){
    p1 = parallel(d, e, a, b, c) ? intersection(e, f, a, b, c) : intersection(d, e, a, b, c);
    p2 = parallel(f, d, a, b, c) ? intersection(e, f, a, b, c) : intersection(f, d, a, b, c);
}//计算两平面交线,注意事先判断是否平行,并保证三点不共线,p-q为交线
inline point3 ptoline(const point3 & p, const point3 & l1, const point3 & l2){
    point3 temp = l2 - l1; return l1 + temp * ((p - l1) ^ temp) / (temp ^ temp);
}//点到直线最近点
inline point3 ptoplane(const point3 & p, const point3 & a, const point3 & b, const point3 & c){
    return intersection(p, p + pvec(a, b, c), a, b, c);
}//点到平面最近点
inline double dislinetoline(const point3 & u1, const point3 & u2, const point3 & v1, const point3 & v2){
    point3 temp = (u1 - u2) * (v1 - v2); return fabs((u1 - v1) ^ temp) / temp.length();
}//直线到直线距离
void linetoline(const point3 & u1, const point3 & u2, const point3 & v1, const point3 & v2, point3 & p1, point3 & p2){
    point3 ab = u2 - u1, cd = v2 - v1, ac = v1 - u1;
    p2 = v1 + cd * (((ab ^ cd) * (ac ^ ab) - (ab ^ ab) * (ac ^ cd)) / ((ab ^ ab) * (cd ^ cd) - sqr(ab ^ cd)));
    p1 = ptoline(p2, u1, u2);
}//直线到直线的最近点对,p1在u上,p2在v上,须保证直线不平行

#include <cstdio>

const double EPS = 1e-8;
const double INF = 1e6;

double gao(const point3& u, const point3& v, double r) {
	double a = (v ^ v);
	double b = 2 * (u ^ v);
	double c = (u ^ u) - r * r;
	double d = b * b - 4 * a * c;
	if (d < -EPS) {
		return INF;
	}
	d = sqrt(max(0.0, d));
	double t1 = (-b - d) / (2 * a);
	double t2 = (-b + d) / (2 * a);
	if (t1 > t2) {
		swap(t1, t2);
	}
	if (t1 > -EPS) {
		return t1;
	} else if (t2 > -EPS) {
		return t2;
	} else {
		return INF;
	}
}

double dis(const point3& a, const point3& b, const point3& c) {
	if (dotOnlineIn(c, a, b)) {
		return 0.0;
	} else {
		return min((c - a).length(), (c - b).length());
	}
}

double gao(point3 a, point3 b, point3 c, point3 d) {
	double ret = min(
		min((c - a).length(), (d - a).length()),
		min((c - b).length(), (d - b).length()));
	double tmp = dislinetoline(a, b, c, d);
	if (parallel(a, b, c, d)) {
	//	printf("%lf %lf %lf, %lf %lf %lf\n", (b - a).x, (b - a).y, (b - a).z,
	//		(d - c).x, (d - c).y, (d - c).z);
		c = ptoline(c, a, b);
		d = ptoline(d, a, b);
		ret = min(ret, hypot(tmp, dis(a, b, c)));
		ret = min(ret, hypot(tmp, dis(a, b, d)));
		ret = min(ret, hypot(tmp, dis(c, d, a)));
		ret = min(ret, hypot(tmp, dis(c, d, b)));
	//	printf("ret = %lf\n", ret);
	} else {
		point3 u, v;
		linetoline(a, b, c, d, u, v);
		if (dotOnlineIn(u, a, b) && dotOnlineIn(v, c, d)) {
			ret = min(ret, dislinetoline(a, b, c, d));
		}
		u = ptoline(a, c, d);
		if (dotOnlineIn(u, c, d)) {
			ret = min(ret, (a - u).length());
		}
		u = ptoline(b, c, d);
		if (dotOnlineIn(u, c, d)) {
			ret = min(ret, (b - u).length());
		}
		u = ptoline(c, a, b);
		if (dotOnlineIn(u, a, b)) {
			ret = min(ret, (c - u).length());
		}
		u = ptoline(d, a, b);
		if (dotOnlineIn(u, a, b)) {
			ret = min(ret, (d - u).length());
		}
	}
	return ret;
}

int main() {
	int n, m, p;
	point3 a[200], b[10000], c[1000], v;
	double r[200], lo = 0, up = INF;

	scanf("%lf%lf%lf%lf%lf%lf%lf", &a[0].x, &a[0].y, &a[0].z, &v.x, &v.y, &v.z, &r[0]);
	scanf("%d", &n);
	m = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%lf%lf%lf%lf%d", &a[i].x, &a[i].y, &a[i].z, &r[i], &p);
		up = min(up, gao(a[0] - a[i], v, r[0] + r[i]));
		for (int j = 0; j < p; ++j) {
			scanf("%lf%lf%lf", &c[m].x, &c[m].y, &c[m].z);
			b[m] = a[i];
			c[m] = b[m] + c[m];
			++m;
		}
	}

//	printf("%lf %lf\n", lo, up);
	for (int tt = 0; tt < 1000; ++tt) {
		double mid = (lo + up) / 2;
		point3 aa = a[0] + v * mid;
		bool flag = true;
		for (int i = 0; flag && i < m; ++i) {
//			printf("%d %lf\n", i, gao(a[0], aa, b[i], c[i]));
			if (gao(a[0], aa, b[i], c[i]) <= r[0]) {
				flag = false;
			}
		}
		if (flag) {
			lo = mid;
		} else {
			up = mid;
		}
	}
	lo = (lo + up) / 2;
	if (lo > INF / 2) {
		puts("-1");
	} else {
		printf("%.10lf\n", lo);
	}

	return 0;
}
