#include <cstdio>
#include <algorithm>

using namespace std;

const double EPS = 1e-9;
const int MAX_N = 128;
const int MAX_M = 128;
typedef double LPMAT[MAX_M + 1][MAX_M + MAX_N + 1];
typedef double LPRET[MAX_N + 1];

inline bool d_zero(double x) {
    return fabs(x) < EPS;
};

inline bool d_less(double x, double y) {
    return x + EPS < y;
};

/** 线性规划.
 * 求 b1 x1 + b2 x2 + ... + bn xn 在 x1, x2, ..., xn >= 0 时的最大值
 * m 为限制条件方程数, n 为变量数目
 * 限制条件为
 *  a_i1 x1 + a_i2 x2 + ... + a_in xn <= ci (1 <= i <= m, ci >= 0 (!!!))
 * mat 传入系数矩阵
 * mat[0] 表示目标方程, 即 mat[0][1..n] 为 b1 .. bn
 * mat[1..m]表示限制方程, mat[1..m][0] 表示 c1, c2, ... cm
 * 其余 mat[i][j] 表示 a[i][j]
 * 注意函数会改变 mat 的值
 *   i \ j 0    1    2   .... n
 *   0     0   b1   b2   .... bn
 *   1     c1  a11  a12  .... a1n
 *   ............................
 *   m     cm  am1  am2  .... amn
 * 找到解返回 true, ans 返回最大值, ret[1..n] 分别返回 x1..xn 的取值
 * 如果不存在最大值返回 false
 * 不可能无解, 因为 x1 = x2 = ... = xn = 0 必为一组解
 */
bool lp(int m, int n, LPMAT mat, double& ans, LPRET ret) {
    static int p[MAX_M + 1], q[MAX_M + MAX_N + 1];
    static double trial[MAX_M + MAX_N + 1];
    int i, j, k, l, s, h;
    double z, zbuf;

    mat[0][0] = 0;
    for (i = 0; i <= m; i++) {
        for (j = n; j > 0; j--)
            mat[i][j + m] = (i == 0) ? -mat[i][j] : mat[i][j];

        for (j = m; j > 0; j--)
            mat[i][j] = (i == j) ? 1 : 0;

        p[i] = q[i] = i;
    }

    bool flag = true;
    while (flag) {
        flag = false;
        for (j = m + n; j > 0; j--) {
            if (!d_less(mat[0][j], 0))
                continue;
            for (i = 1, l = 0; i <= m; i++) {
                if (!d_less(0, mat[i][j]))
                    continue;
                if (l == 0) {
                    l = i, s = 0;
                } else {
                    for (h = 0; ; h++) {
                        if (h == s)
                            trial[s++] = mat[l][h] / mat[l][j];
                        z = mat[i][h] / mat[i][j];
                        if (trial[h] != z)
                            break;
                    }
                    if (d_less(z, trial[h]))
                        l = i, trial[h] = z, s = h + 1;
                }
            }
            if (l == 0)
                // The maximum is infinite
                return false;

            for (k = 0, z = mat[l][j]; k <= m + n; k++)
                if (!d_zero(mat[l][k]))
                    mat[l][k] = mat[l][k] / z;

            for (i = 0; i <= m; i++) {
                if (i == l)
                    continue;
                for (k = 0, z = mat[i][j]; k <= m + n; k++)
                    mat[i][k] = (k == j || d_zero(zbuf = mat[i][k] - z * mat[l][k])) ?
                            0 : zbuf;
            }
            q[p[l]] = 0, p[l] = j, q[j] = l;
            flag = true;
            break;
        };
    };
    ans = mat[0][0];

    for (i = 1, j = m + 1; j <= m + n; i++, j++)
        ret[i] = (q[j]) ? mat[q[j]][0] : 0;

    /* 此处可用来计算 (u1, u2, ..., um) 其中 ui >= 0, 使得在
     * a1j u1 + a2j u2 + ... + amj um >= bj (1 <= j <= n)
     * 的限制条件下 c1 u1 + c2 u2 + ... + cm um 最大.
     * 当函数返回 false 的时候此处无解. */
    //for (j = 1; j <= m; j++)
    //    u[i] = mat[0][j];

    return true;
}

LPMAT a;
LPRET b;

int main() {
	int n;
	double c, p[128];

	scanf("%d", &n);
	for (int i = 0; i <= n; ++i) {
		scanf("%lf", &p[i]);
	//	if (i > 0) {
	//		p[i] = max(p[i], p[i - 1]);
	//	}
	}
	for (int i = 0; i <= n; ++i) {
		a[0][i + 1] = p[i];
	}
	for (int i = 0; i <= n; ++i) {
		a[1][i + 1] = i;
	}
	for (int i = 0; i <= n; ++i) {
		a[2][i + 1] = 1;
	}
	a[1][0] = 0.5 * n;
	a[2][0] = 1.0;
	if (lp(3, n + 1, a, c, b)) {
//		puts("OK");
	}
//	for (int i = 0; i <= n; ++i) {
//		printf("[%d] = %lf\n", i, b[i]);
//	}
	printf("%.10lf\n", c);

	return 0;
}

