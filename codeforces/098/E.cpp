#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1024;
long double p[MAXN][MAXN];

long double gao(int a, int b) {
	long double& ret = p[a][b];
	if (ret >= 0) {
	} else if (a == 0) {
		ret = 1.0 / (b + 1);
	} else if (b == 0) {
		ret = 1.0;
	} else {
		long double p, q;
		ret = 0.0;
		p = 1.0 / (b + 1);
		q = 1.0 - p;
		// try guess
		ret = max(ret, p);
		// try name others
		ret = max(ret, q * (1 - gao(b - 1, a)));
		// try name self
		ret = max(ret, 1 - gao(b, a - 1));
	}
	return ret;
}

int main() {
	int a, b;

	for (int i = 0; i < MAXN; ++i) {
		for (int j = 0; j < MAXN; ++j) {
			p[i][j] = -1;
		}
	}
	while (scanf("%d%d", &a, &b) != EOF) {
	//	if (a > 1 && b > 1) {
	//		throw 1;
	//	}
		printf("%.12lf %.12lf\n", (double)gao(a, b), 1 - (double)gao(a, b));
		break;
	}
/*	
	double p;

	scanf("%d%d", &a, &b);
	if (a == 0) {
		p = 1.0 / (b + 1);
	} else if (b == 0) {
		p = 1.0;
	} else {
		p = 0.5;
	}
	printf("%.12lf %.12lf\n", p, 1 - p);
*/
	return 0;
}
