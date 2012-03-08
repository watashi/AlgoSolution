#include <cmath>
#include <cstdio>

int main() {
	int re, n;
	double r, a, b, c, x, y, z;

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%lf%lf%d", &r, &a, &n);
		b = r / a;
		x = (1 + b) / 2;
		y = (b - 1) * n;
		z = atan2(y, x);
		c = (b - 1) / 2;
		a = hypot(x - c * cos(z), y - c * sin(z));
		b = hypot(x + c * cos(z), y + c * sin(z));
		printf("%.10lf\n", (1 / a - 1 / b) * r);
	}

	return 0;
}

// orz asmn
// 圆关于圆的仿射变换还是一个圆（直线就是半径无穷大的圆）
// 555

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//446148 	May 13, 2011 12:51:11 PM 	watashi 	77E - Martian Food 	GNU C++ 	Accepted 	80 ms 	1300 KB 
