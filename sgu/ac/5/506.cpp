#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 128128;
const int MAXM = 128;
const int SIGMA = 26;

int main() {
	char a[MAXN], b[MAXM];
	int n, m;
	vector<int> p[SIGMA];
	int q[MAXM];
	long long ans = 0;

	gets(a);
	n = strlen(a);
	for (int i = 0; i < n; ++i) {
		a[i] -= 'a';
	}
	gets(b);
	m = strlen(b);
	for (int i = 0; i < m; ++i) {
		b[i] -= 'a';
	}

	for (int i = 0; i < n; ++i) {
		p[a[i]].push_back(i);
	}
	fill(q, q + m, 0);

	ans = 0;
	for (int i = 0; i < n; ++i) {
		int t = i - 1;
		for (int j = 0; j < m; ++j) {
			const vector<int>& v = p[b[j]];
			if (i > 0 && v[q[j]] > t) {
				break;
			} else {
				while (q[j] < (int)v.size() && v[q[j]] <= t) {
					++q[j];
				}
				t = q[j] < (int)v.size() ? v[q[j]] : n;
			}
		}
		if (t == n) {
			break;
		} else {
			ans += n - p[b[m - 1]][q[m - 1]];
		}
	}
	printf("%lld\n", ans);

	return 0;
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status:  	Time:  	Memory:
//1039539	08.07.10 15:40	watashi	506 	.CPP_VS	Accepted 	313 ms	951 kb

/*
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 128128;
const int MAXM = 128;
const int SIGMA = 26;

int main() {
	char a[MAXN], b[MAXM];
	int n, m;
	vector<int> p[SIGMA];
	int q[MAXM];
	long long ans = 0;

	gets(a);
	n = strlen(a);
	for (int i = 0; i < n; ++i) {
		a[i] -= 'a';
	}
	gets(b);
	m = strlen(b);
	for (int i = 0; i < m; ++i) {
		b[i] -= 'a';
	}

	for (int i = 0; i < n; ++i) {
		p[a[i]].push_back(i);
	}
	fill(q, q + m, 0);

	ans = 0;
	for (int i = 0; i < n; ++i) {
		int t = i - 1;
		for (int j = 0; j < m; ++j) {
			const vector<int>& v = p[b[j]];
			if (i > 0 && v[q[j]] > t) {
				break;
			} else {
				while (q[j] < (int)v.size() && v[q[j]] <= t) {
					++q[j];
				}
				t = q[j] < (int)v.size() ? v[q[j]] : n;
			}
		}
		if (t == n) {
			break;
		} else {
			ans += n - p[SIGMA - 1][q[SIGMA - 1]];
		}
	}
	printf("%lld\n", ans);

	return 0;
}
*/
