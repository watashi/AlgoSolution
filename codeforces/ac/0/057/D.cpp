#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1024;

void rotate(int& r, int& c, char buf[MAXN][MAXN]) {
	static char tmp[MAXN][MAXN];
	for (int i = 0; i < c; ++i) {
		for (int j = 0; j < r; ++j) {
			tmp[i][j] = buf[j][c - 1 - i];
		}
	}
	swap(r, c);
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			buf[i][j] = tmp[i][j];
		}
	}
}

long long gao(int r, int c, char buf[MAXN][MAXN]) {
	static long long top[MAXN][MAXN], left[MAXN][MAXN], cnt[MAXN][MAXN], sum[MAXN][MAXN];
	long long ret = 0, dleft, dcnt, dsum;
	
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cnt[i][j] = buf[i][j] == '.' ? 1 : 0;
			sum[i][j] = 0;
			if (j > 0) {
				cnt[i][j] += cnt[i][j - 1];
				sum[i][j] += sum[i][j - 1] + cnt[i][j - 1];
			}
		}
		for (int j = 0; j < c; ++j) {
			if (i > 0) {
				cnt[i][j] += cnt[i - 1][j];
				sum[i][j] += sum[i - 1][j] + cnt[i - 1][j];
			}
		}
	}

	for (int i = 0; i < r; ++i) {
		dleft = dcnt = dsum = 0;
		for (int j = 0; j < c; ++j) {
			dsum += dcnt;
			if (buf[i][j] == 'X') {
				dleft = j;
				top[i][j] = i + (j == 0 ? 0 : top[i][j - 1]);
				left[i][j] = j + (i == 0 ? 0 : left[i - 1][j]);
			} else {
				++dcnt;
				top[i][j] = i == 0 ? 0 : top[i - 1][j];
				left[i][j] = j == 0 ? 0 : left[i][j - 1];
				ret += sum[i][j] + (top[i][j] + left[i][j]) * 2 - dsum - dleft * 2;
			}
//			printf("[%d][%d] (%lld, %lld, %lld, %lld) -> %lld\n", i, j, top[i][j], left[i][j], cnt[i][j], sum[i][j], ret);
		}
	}

	return ret;
}

int main() {
	int r, c;
	long long sum = 0, num = 0;
	static char buf[MAXN][MAXN];

	scanf("%d%d", &r, &c);
	for (int i = 0; i < r; ++i) {
		scanf("%s", buf[i]);
		num += count(buf[i], buf[i] + c, '.');
	}
	for (int i = 0; i < 4; ++i) {
		rotate(r, c, buf);
		sum += gao(r, c, buf);
		fprintf(stderr, "%lld %lld\n", sum, num);
	}
	printf("%.10lf\n", 1.0 * sum / num / num);

	return 0;
}

