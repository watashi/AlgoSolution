#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 100100;
int d[MAXN], mod;
vector<int> e[MAXN];

void gao(int v, int t) {
	if (d[v] == -1) {
		d[v] = t++;
		if (t == mod) {
			t = 0;
		}
		for (vector<int>::const_iterator w = e[v].begin(); w != e[v].end(); ++w) {
			gao(*w, t);
		}
	} else if (d[v] != t) {
		throw t - d[v];
	}
}

int main() {
	int n, m, a, b;
	vector<int> ans;

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &a, &b);
		e[a - 1].push_back(b - 1);
	}

	mod = n + 1;
	fill(d, d + n, -1);
	try {
		gao(0, 0);
	} catch (int ex) {
		a = ex;
	}

	b = 0;
	for (int i = 1; i * i <= a; ++i) {
		if (a % i != 0) {
			continue;
		}
	
		mod = a / i;
		if (b < mod) {
			fill(d, d + n, -1);
			try {
				gao(0, 0);
				b = mod;
				ans.clear();
				for (int i = 0; i < n; ++i) {
					if (d[i] == 0) {
						ans.push_back(i);
					}
				}
			} catch (...) {
			}
		}
	
		mod = i;
		if (b < mod) {
			fill(d, d + n, -1);
			try {
				gao(0, 0);
				b = mod;
				ans.clear();
				for (int i = 0; i < n; ++i) {
					if (d[i] == 0) {
						ans.push_back(i);
					}
				}
			} catch (...) {
			}
		}
	}

	printf("%d\n", b);
	printf("%d\n", (int)ans.size());
	for (vector<int>::const_iterator it = ans.begin(); it != ans.end(); ++it) {
		printf("%d ", *it + 1);
	}
	puts("");

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//396364 	Apr 19, 2011 3:38:05 PM 	watashi 	39I - Tram 	GNU C++ 	Accepted 	160 ms 	7600 KB
