#include <cstdio>

const int MAXN = 1 << 20;
const int RLIMIT = 5050;
const int LIMIT = 10000000;

struct DisjointSet {
	int p[MAXN];
	
	void init(int n) {
		for (int i = 1; i <= n; ++i) {
			p[i] = i;
		}
	}

	int root(int i) {
		return p[i] == i ? i : p[i] = root(p[i]);
	}

	bool link(int i, int j) {
		i = root(i);
		j = root(j);
		if (i == j) {
			return false;
		} else {
			p[i] = j;
			return true;
		}
	}
} ds;

int id[LIMIT];

inline int gao(int i, int j) {
	return id[i] > 0 && id[j] > 0 && ds.link(id[i], id[j]) ? 1 : 0;
}

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	int n, a;
	
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a);
		id[a] = i;
	}
	ds.init(n);
	for (int r = 1; r < RLIMIT; ++r) {
		for (int s = r % 2 + 1; s < r; s += 2) {
			if (gcd(r, s) == 1) {
				int x = r * r - s * s;
				int y = 2 * r * s;
				if (x >= LIMIT || y >= LIMIT) {
					continue;
				}
				n -= gao(x, y);
				int z = r * r + s * s;
				if (z < LIMIT) {
					n -= gao(x, z);
					n -= gao(y, z);
				}
			}
		}
	}
	printf("%d\n", n);

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//292351 	Feb 20, 2011 11:53:01 AM 	watashi 	60D - Savior 	GNU C++ 	Accepted 	1080 ms 	44600 KB 
