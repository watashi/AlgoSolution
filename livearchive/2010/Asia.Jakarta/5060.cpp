#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 1 << 16;

int p[MAXN], q[MAXN];
vector<int> v[MAXN];

int main() {
	int re, n, m;
	vector<int> a, b;

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d%d", &n, &m);
		a.resize(1 << n);
		for (int i = 0; i < (1 << n); ++i) {
			scanf("%d", &p[i]);
			a[i] = i;
			q[i] = p[i];
			v[i].clear();
		}
		while (a.size() > 1) {
			b.clear();
			for (int i = 0; i < (int)a.size(); i += 2) {
				int x = a[i];
				int y = a[i + 1];
				q[x] = min(p[x], q[x] + m);
				q[y] = min(p[y], q[y] + m);
				if (q[x] >= q[y]) {
					q[x] -= q[y];
					b.push_back(x);
					v[x].push_back(y);
				} else {
					q[y] -= q[x];
					b.push_back(y);
					v[y].push_back(x);
				}
			}
			a.swap(b);
		}
		printf("%d\n", a[0] + 1);
		for (int i = 0; i < n; ++i) {
			printf("%d%c", v[a[0]][i] + 1, i == n - 1 ? '\n' : ' ');
		}
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//798546 	5060 	Arm Wrestling Tournament 	Accepted 	C++ 	0.096 	2011-05-13 11:15:51
/*
id => 1174307
pid => 5060
pname => Arm Wrestling Tournament
status => Accepted
lang => C++
time => 0.089
date => 2012-12-14 17:52:12
*/
