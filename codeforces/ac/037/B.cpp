#include <queue>
#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

#define F first
#define S second
#define P F.F
#define D F.S

typedef pair<int, int> PII;
typedef pair<PII, int> SC;

int main() {
	int n, m, r, h, d, t;
	SC s[1024];
	vector<PII> a;
	priority_queue<PII> q;

	scanf("%d%d%d", &n, &m, &r);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &s[i].P, &s[i].D);
		s[i].S = i;
	}
	sort(s + 1, s + 1 + n);

	h = m;
	d = 0;
	for (t = 0; t < 9999 && h > 0; ++t) {
		while (n > 0 && h <= m * s[n].P / 100) {
			q.push(PII(s[n].D, s[n].S));
			--n;
		}
		if (!q.empty()) {
			a.push_back(PII(t, q.top().S));
			d += q.top().F;
			q.pop();
		}
		h = min(h - d + r, m);
	}

	if (h > 0) {
		puts("NO");
	} else {
		puts("YES");
		printf("%d %u\n", t, a.size());
		for (typeof(a.begin()) i = a.begin(); i != a.end(); ++i) {
			printf("%d %d\n", i->F, i->S);
		}
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//235955 	Jan 2, 2011 3:39:37 PM 	watashi 	B - Computer Game 	GNU C++ 	Accepted 	30 ms 	1336 KB 
