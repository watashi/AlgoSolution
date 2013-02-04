#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

template<int MAXX, int MAXY>
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

	bool gao() {
		fill(mx, mx + nx, -1);
		fill(my, my + ny, -1);
		for (int i = 0; i < nx; ++i) {
			fill(mark, mark + nx, false);
			if (!augment(i)) {
				return false;
			}
		}
		return true;
	}
};

const int MAXN = 64;
const int MAXL = 4096;

Hungary<MAXN, MAXN> h;
char sa[MAXL], sb[MAXL];
string a[MAXN], b[MAXN];

bool match(const string& a, const string& b) {
  for (int i = 0; i < (int)a.length() && i < (int)b.length(); ++i) {
    if (a[i] != '?' && b[i] != '?' && a[i] != b[i]) {
      return false;
    }
  }
  return a.length() == b.length();
}

bool gao(int n) {
  h.init(n, n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (match(a[i], b[j])) {
        h.add(i, j);
      }
    }
  }
  return h.gao();
}

int main() {
  int re, n, m;
  string output;

  scanf("%d", &re);
  for (int ri = 1; ri <= re; ++ri) {
    scanf("%d%s%s", &n, sa, sb);
    m = strlen(sa) / n;
    for (int i = 0; i < n; ++i) {
      a[i] = b[i] = "";
      for (int j = i * m; j < (i + 1) * m; ++j) {
        a[i] += sa[j];
        b[i] += sb[j];
      }
    }

    if (!gao(n)) {
      output = "IMPOSSIBLE";
    } else {
      output = "";
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          if (a[i][j] == '?') {
            for (char k = 'a'; k <= 'f'; ++k) {
              a[i][j] = k;
              if (gao(n)) {
                break;
              }
            }
          }
        }
        output += a[i];
      }
    }
    printf("Case #%d: %s\n", ri, output.c_str());
    fflush(stdout);
  }

  return 0;
}

