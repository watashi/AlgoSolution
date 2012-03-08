#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 65536;
char str[MAXN];
int a[MAXN];

int main() {
	int n, m, b;
	long long ans = 0;

	scanf("%s", str);
	n = strlen(str);
	m = count(str, str + n, '?');
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &a[i], &b);
		a[i] -= b;
		ans += b;
	}

	try {
		priority_queue<pair<int, int> > pq;
		m = 0;
		b = 0;
		for (int i = 0; i < n; ++i) {
			if (str[i] == '(') {
				++b;
			} else if (str[i] == ')') {
				--b;
			} else {
				str[i] = ')';
				--b;
				pq.push(make_pair(-a[m++], i));
			}
			while (b < 0) {
				if (pq.empty()) {
					throw 1;
				}
				ans -= pq.top().first;
				str[pq.top().second] = '(';
				pq.pop();
				b += 2;
			}
		}
		if (b != 0) {
			throw 1;
		}
		printf("%I64d\n%s\n", ans, str);
	} catch (...) {
		puts("-1");
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//255720 	Jan 20, 2011 8:47:32 PM 	watashi 	3D - Least cost bracket sequence 	GNU C++ 	Accepted 	60 ms 	2100 KB 
