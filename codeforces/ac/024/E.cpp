#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

#define fst first
#define snd second

const double INF = 1e100;

typedef pair<double, double> PDD;

void gao(vector<pair<double, PDD> >& v) {
	int j = 0;
	for (int i = 1; i < (int)v.size(); ++i) {
		if (v[i].snd.snd <= v[j].snd.snd) {
			continue;
		}
		while ((v[i].fst = (v[j].snd.fst - v[i].snd.fst) / (v[i].snd.snd - v[j].snd.snd)) <= v[j].fst) {
			--j;
		}
		v[++j] = v[i];
	}
	v.resize(j + 1);
}

int main() {
	int n;
	double ans;
	vector<PDD> v;
	vector<pair<double, PDD> > l, r;

	scanf("%d", &n);
	v.resize(n);
	for (int i = 0; i < n; ++i) {
		scanf("%lf%lf", &v[i].fst, &v[i].snd);
	}
//	sort(v.begin(), v.end());

	ans = INF;
	for (int i = 0, j = i; i < n; i = j) {
		l.clear();
		r.clear();
		while (j < n && v[j].snd > 0) {
			l.push_back(make_pair(0, v[j++]));
		}
		while (j < n && v[j].snd < 0) {
			v[j].fst = -v[j].fst;
			v[j].snd = -v[j].snd;
			r.push_back(make_pair(0, v[j++]));
		}
		if (l.empty() || r.empty()) {
			continue;
		}

		reverse(l.begin(), l.end());
		gao(l);
		gao(r);
		for (int x = 0, y = 0; x < (int)l.size() && y < (int)r.size(); ) {
			ans = min(ans, max(max(l[x].fst, r[y].fst),
					-(l[x].snd.fst + r[y].snd.fst) /
					(l[x].snd.snd + r[y].snd.snd)));
			if (y + 1 == (int)r.size() || (x + 1 < (int)l.size() && l[x + 1].fst <= r[y + 1].fst)) {
				++x;
			} else {
				++y;
			}
		}
	}
	if (ans == INF) {
		puts("-1");
	} else {
		printf("%.10lf\n", ans);
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//308990 	Feb 27, 2011 9:53:19 PM 	watashi 	24E - Berland collider 	GNU C++ 	Accepted 	1440 ms 	33800 KB 

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//308997 	Feb 27, 2011 9:56:32 PM 	watashi 	24E - Berland collider 	GNU C++ 	Accepted 	1420 ms 	33800 KB

// 二分亦可，我的算法的复杂度没有二分的lg！
// 但实际更慢！！
