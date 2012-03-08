#include <cmath>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int LIMIT = 1000000;

typedef pair<int, int> PII;
PII p[LIMIT];
vector<PII> v;

inline bool pr(const PII& lhs, const PII& rhs) {
	return atan2(lhs.second, lhs.first) < atan2(rhs.second, rhs.first) - 1e-8;
}

inline int R(const PII& p) {
	return p.first * p.first + p.second * p.second;
}

int main() {
	int n, s, x, y, nx, ny, tx, ty, dx, dy;

	scanf("%d", &n);
	for (int i = 0, ii; (ii = i * i) < LIMIT; ++i) {
		for (int j = i, jj; (jj = i * i + j * j) < LIMIT; ++j) {
			p[jj].first = i;
			p[jj].second = j;
		}
	}

	s = 0;
	for (int i = 0; i < LIMIT && (int)v.size() <= n; ++i) {
		if (p[i].first != 0 || p[i].second != 0) {
			s += R(p[i]);
			v.push_back(p[i]);
		}
	}
	
	reverse(v.begin(), v.end());
	for (vector<PII>::iterator it = v.begin(); it != v.end(); ++it) {
		if ((s - R(*it)) % 2 == 0) {
			v.erase(it);
			break;
		}
	}

	x = y = 0;
	for (vector<PII>::iterator it = v.begin(); it != v.end(); ++it) {
		nx = ny = LIMIT;
		dx = it->first;
		dy = it->second;
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j) {
				for (int k = 0; k < 2; ++k) {
					tx = x + dx;
					ty = y + dy;
					if (abs(tx) + abs(ty) < abs(nx) + abs(ny)) {
						nx = tx;
						ny = ty;
						*it = make_pair(dx, dy);
					}
					dx = -dx;
				}
				dy = -dy;
			}
			swap(dx, dy);
		}
		x = nx;
		y = ny;
	}

	sort(v.begin(), v.end(), pr);
	x = y = 0;
	puts("YES");
	for (vector<PII>::iterator it = v.begin(); it != v.end(); ++it) {
		printf("%d %d\n", x, y, atan2(it->second, it->first));
		x += it->first;
		y += it->second;
	}
	if (x != 0 || y != 0) {
		throw 1;
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//208651 	Dec 5, 2010 8:57:49 PM 	watashi 	G - Emperors Problem 	GNU C++ 	Accepted 	80 ms 	9392 KB 
