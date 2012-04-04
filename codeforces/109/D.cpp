#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

bool islucky(int n) {
	while (n > 0 && (n % 10 == 4 || n % 10 == 7)) {
		n /= 10;
	}
	return n == 0;
}

vector<pair<int, int> > v;
vector<int> p, q;

void swp(int i, int j) {
	if (i != j) {
//		printf("swp %d %d\n", i, j);
		v.push_back(make_pair(i, j));
		swap(q[i], q[j]);
		p[q[i]] = i;
		p[q[j]] = j;
	}
}

int main() {
	int n, s, t, x;
	bool f;

	scanf("%d", &n);
	s = -1;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &x);
		v.push_back(make_pair(x, i));
		if (islucky(x)) {
			s = i;
		}
	}

	sort(v.begin(), v.end());
	p.resize(n);
	q.resize(n);
	f = true;
	for (int i = 0; i < n; ++i) {
		p[i] = v[i].second;
		q[v[i].second] = i;
		if (v[i].second != i) {
			f = false;
		}
	}
//	for (int i = 0; i < n; ++i) {
//		printf("%d ", q[i]);
//	}
//	puts("");

	if (s == -1) {
		puts(f ? "0" : "-1");
	} else {
		v.clear();
		for (int i = 0; i < n; ++i) {
			if (i == q[s]) {
				continue;
			}
			swp(s, i);
			t = p[i];
			swp(i, t);
			s = t;
		}
		printf("%d\n", (int)v.size());
		for (int i = 0; i < (int)v.size(); ++i) {
			printf("%d %d\n", v[i].first + 1, v[i].second + 1);
		}
	}

	return 0;
}

