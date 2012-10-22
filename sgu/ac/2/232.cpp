// SGU232. Infinite Fraction

// O(n)
// 字符串最小表示

#include <cstdio>

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

// [algo] minString
// [module] minString
int maxP(int n, char a[]) {
	int i = 0, j = 1;

	while (i < n && j < n) {
		int k = 0;
		while (k < n && a[i + k] == a[j + k]) {
			++k;
		}
		if (a[i + k] < a[j + k]) {
			i += k + 1;
		} else if (a[i + k] > a[j + k]) {
			j += k + 1;
		} else {	// k == n
			break;
		}
		if (i == j) {
			++j;
		}
	}

	return i < j ? i : j;
}

int main() {
	int n, k;
	char s[150150], buf[300300], ans[150150];

	scanf("%d%d", &n, &k);
	scanf("%s", s);

	int g = gcd(n, k);
	int len = n / gcd(n, k);
	for (int i = 0; i < g; ++i) {
		for (int j = 0, p = i; j < len; ++j, p = (p + k) % n) {
			buf[j] = buf[len + j] = s[p];
		}
		int off = maxP(len, buf);
		for  (int j = 0; j < len; ++j) {
			if (ans[j] < buf[off + j]) {
				while (j < len) {
					ans[j] = buf[off + j];
					++j;
				}
			} else if (ans[j] > buf[off + j]) {
				break;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		s[i] = ans[i % len];
	}
	s[n] = '\0';
	puts(s);

	return 0;
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status:  	Time:  	Memory:
//1078643	19.09.10 16:39	watashi	232 	.CPP_VS	Accepted 	23 ms	507 kb

