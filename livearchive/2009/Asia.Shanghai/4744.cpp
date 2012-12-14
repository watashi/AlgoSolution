#include <cstdio>

struct Mat {
	long long a[2][2];

	Mat() {
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j) {
				a[i][j] = 0;
			}
		}
	}

	long long* operator[](int i) {
		return a[i];
	}

	const long long* operator[](int i) const {
		return a[i];
	}
};

Mat mul(const Mat& lhs, const Mat& rhs, long long mod) {
	Mat ret;
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < 2; ++k) {
				ret[i][j] += lhs[i][k] * rhs[k][j];
			}
			ret[i][j] %= mod;
		}
	}
	return ret;
}

Mat pow(Mat a, long long b, long long mod) {
	Mat ret;
	ret[0][0] = ret[1][1] = 1;
	while (b > 0) {
		if (b % 2 != 0) {
			ret = mul(ret, a, mod);
		}
		a = mul(a, a, mod);
		b >>= 1;
	}
	return ret;
}

long long pow(long long a, long long b, long long mod) {
	long long ret = 1LL;
	while (b > 0) {
		if (b % 2 != 0) {
			ret = ret * a % mod;
		}
		a = a * a % mod;
		b >>= 1;
	}
	return ret;
}

long long phi(long long n) {
	long long m = n;
	for (long long i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			m /= i;
			m *= i - 1;
			do {
				n /= i;
			} while (n % i == 0);
		}
	}
	if (n > 1) {
		m /= n;
		m *= n - 1;
	}
	return m;
}

int main() {
	int re;
	Mat mat;
	long long n, m, l, a, b;

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%lld%lld%lld%lld", &a, &b, &m, &n);
		mat[0][0] = 0;
		mat[0][1] = mat[1][0] = mat[1][1] = 1;
		if (n > 30) {
			l = phi(m);
			mat = pow(mat, n - 1, l);
			mat[0][0] += l;
			mat[0][1] += l;
		} else {
			mat = pow(mat, n - 1, 1000000007);
		}
		a = pow(a, mat[0][0], m);
		b = pow(b, mat[0][1], m);
	//	printf("%lld %lld %lld %lld\n", mat[0][0], mat[0][1]);
		printf("Case #%d: %lld\n", ri, a * b % m);
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//898516 	4744 	Brute-force Algorithm 	Accepted 	C++ 	0.008 	2011-10-05 07:26:47
/*
id => 1174250
pid => 4744
pname => Brute-force Algorithm
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:45:11
*/
