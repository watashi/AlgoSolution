#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int INF = 1000000000;

int main() {
	int L, B, F, n, a[128], b[128];
	pair<int, int> p[128];
	vector<pair<int, int> > v;

	scanf("%d%d%d", &L, &F, &B);
	v.push_back(make_pair(-INF, -F));
	v.push_back(make_pair(L + B, INF));
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &a[i], &b[i]);
		if (a[i] == 2) {
			v.erase(find(v.begin(), v.end(), p[b[i]]));
		} else {
			p[i].first = -1;
			for (int j = 1; j < (int)v.size(); ++j) {
				if (v[j - 1].second + F + b[i] + B <= v[j].first) {
					p[i] = make_pair(v[j - 1].second + F, v[j - 1].second + F + b[i]);
					v.push_back(p[i]);
					sort(v.begin(), v.end());
					break;
				}
			}
			printf("%d\n", p[i].first);
		}
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//208611 	Dec 5, 2010 7:50:54 PM 	watashi 	D - Parking Lot 	GNU C++ 	Accepted 	30 ms 	1308 KB 

