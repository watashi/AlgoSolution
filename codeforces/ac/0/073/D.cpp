#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1 << 20;

struct DisjointSet {
	int p[MAXN], c[MAXN];
	void init(int n) {
		for (int i = 0; i < n; ++i) {
			p[i] = i;
			c[i] = 1;
		}
	}
	int root(int i) {
		return i == p[i] ? i : (p[i] = root(p[i]));
	}
	void setp(int i, int j) {
		i = root(i);
		j = root(j);
		if (i == j) {
			return;
		}
		if (c[i] > c[j]) {
			swap(i, j);
		}
		p[i] = j;
		c[j] += c[i];
	}
} ds;

int main() {
	int n, m, q, s, a, b;
	vector<int> c;

	scanf("%d%d%d", &n, &q, &m);
	ds.init(n);
	for (int i = 0; i < q; ++i) {
		scanf("%d%d", &a, &b);
		ds.setp(a - 1, b - 1);
	}
	for (int i = 0; i < n; ++i) {
		if (ds.root(i) == i) {
			c.push_back(ds.c[i]);
		}
	}
//	for (int i = 0; i < (int)c.size(); ++i) {
//		printf("%d%c", c[i], i == (int)c.size() - 1 ? '\n' : ' ');
//	}

	if (c.size() == 1) {
		puts("0");
	} else if (m == 1) {
		printf("%d\n", max(0, (int)c.size() - 2));
	} else {
		q = count(c.begin(), c.end(), 1);
		c.erase(remove(c.begin(), c.end(), 1), c.end());
		if (c.empty()) {
			q = q - 1;
			s = 1;
		} else {
			s = 0;
			for (int i = 0; i < (int)c.size(); ++i) {
				s += min(c[i], m);
			}
			s -= 2 * ((int)c.size() - 1);
		}
		printf("%d\n", max(0, (q - s + 1) / 2));
	}

	return 0;
}

