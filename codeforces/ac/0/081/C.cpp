#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool byFirst(const pair<int, int>& lhs, const pair<int, int>& rhs) {
	return lhs.first == rhs.first ? lhs.second < rhs.second : lhs.first > rhs.first;
}

int main() {
	int n, a, b;
	vector<pair<int, int> > v;

	scanf("%d%d%d", &n, &a, &b);
	v.resize(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &v[i].first);
		v[i].second = i;
	}
	if (a < b) {
		sort(v.begin(), v.end(), byFirst);
	} else if (a > b) {
		sort(v.begin(), v.end());
	}
	for (int i = 0; i < a; ++i) {
		v[v[i].second].first = 1;
	}
	for (int i = a; i < n; ++i) {
		v[v[i].second].first = 2;
	}
	for (int i = 0; i < n; ++i) {
		printf("%d%c", v[i].first, i == n - 1 ? '\n' : ' ');
	}

	return 0;
}

