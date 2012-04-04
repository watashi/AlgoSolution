#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1000000007;

int main() {
	int n, t;
	vector<int> v[128];

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 4; ++j) {
			scanf("%d", &t);
			v[i].push_back(t);
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (v[i][0] < v[j][0] && v[i][1] < v[j][1] && v[i][2] < v[j][2]) {
				v[i][3] = INF;
			}
		}
	}
	printf("%d\n", min_element(v, v + n,
			[](const vector<int>& lhs, const vector<int>& rhs){ return lhs[3] < rhs[3]; }) - v + 1);

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//627270 	Aug 23, 2011 6:00:32 PM 	watashi 	106B - Choosing Laptop 	GNU C++0x 	Accepted 	30 ms 	1400 KB 
