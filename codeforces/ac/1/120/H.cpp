#include <map>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MAXX = 256;
const int MAXY = 100100;

struct Hungary {
	int nx, ny, mx[MAXX], my[MAXY];
	vector<int> e[MAXX];

	bool mark[MAXX];

	void init(int nx, int ny) {
		this->nx = nx;
		this->ny = ny;
		for (int i = 0; i < nx; ++i) {
			e[i].clear();
		}
	}

	void add(int a, int b) {
		e[a].push_back(b);
	}

	bool augment(int i) {
		if (!mark[i]) {
			mark[i] = true;
			for (vector<int>::const_iterator j = e[i].begin(); j != e[i].end(); ++j) {
				if (my[*j] == -1 || augment(my[*j])) {
					mx[i] = *j;
					my[*j] = i;
					return true;
				}
			}
		}
		return false;
	}

	int gao() {
		int ret = 0;
		fill(mx, mx + nx, -1);
		fill(my, my + ny, -1);
		for (int i = 0; i < nx; ++i) {
			fill(mark, mark + nx, false);
			if (augment(i)) {
				++ret;
			}
		}
		return ret;
	}
} h;

vector<string> v;

void gen(const char* s, const string& t) {
	if (*s == '\0') {
		if (t.length() > 0) {
			v.push_back(t);
		}
	} else {
		gen(s + 1, t);
		if (t.length() < 4) {
			gen(s + 1, t + *s);
		}
	}
}

int main() {
#ifndef __WATASHI__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	int n;
	char s[80];
	vector<string> tab;
	map<string, int> mp;

	scanf("%d", &n);
	h.init(n, 0);
	for (int i = 0; i < n; ++i) {
	//	printf("%d\n", i);
		scanf("%s", s);
		v.clear();
		gen(s, "");
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		for (const string& t: v) {
			int j;
			if (mp.count(t) == 0) {
				j = tab.size();
				tab.push_back(t);
				mp[t] = j;
			} else {
				j = mp[t];
			}
			h.add(i, j);
		}
		h.ny = tab.size();
	}
//	puts("GO");
	if (h.gao() != n) {
		puts("-1");
	} else {
		for (int i = 0; i < n; ++i) {
			puts(tab[h.mx[i]].c_str());
		}
	}

	return 0;
}

