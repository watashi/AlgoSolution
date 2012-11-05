#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

template<int MAXN, typename T = int>
struct BIT {
  int n;
  T a[MAXN];

  void init(int n) {
    this->n = n;
    fill(a, a + n + 1, T());
  }

  void add(int i, T v) {
    for (int j = i + 1; j <= n; j = (j | (j - 1)) + 1) {
      a[j] += v;
    }
  }

  // [0, i)
  T sum(int i) const {
    T ret = T();
    for (int j = i; j > 0; j = j & (j - 1)) {
      ret += a[j];
    }
    return ret;
  }

  T get(int i) const {
    return sum(i + 1) - sum(i);
  }

  void set(int i, T v) {
    add(i, v - get(i));
  }
};

// The structure of tree must be static
// The length of edge can be dynamic
// Weighted path length from the root
template<int MAXN, typename T = int>
struct WeightedPathLength {
  int n, m, root;
  int id[MAXN][2];

  BIT<MAXN + MAXN, T> bit;

  const vector<int> *e;

  void dfs_(int v, int p) {
    for (vector<int>::const_iterator it = e[v].begin(); it != e[v].end(); ++it) {
      if (*it != p) {
        id[*it][0] = m++;
        dfs_(*it, v);
        id[*it][1] = m++;
      }
    }
  }

  void init(int n, const vector<int> e[MAXN], int root = 0) {
    this->n = n;
    this->m = 0;
    this->root = root;
    this->e = e;
    dfs_(root, root);
    bit.init(m);
  }

  // weight(v, parent(v))
  void update(int v, T w) {
    bit.set(id[v][0], w);
    bit.set(id[v][1], -w);
  }

  T query(int v) {
    return v == root ? T() : bit.sum(id[v][0] + 1);
  }
};

template<int MAXN, int CHARSET>
struct AhoCorasick {
	int end;
	int fail[MAXN];
	int trie[MAXN][CHARSET];

	void init() {
		fill(trie[0], trie[0] + CHARSET, -1);
		end = 1;
	}

	int add(int m, const int* s) {
		int p = 0;
		for (int i = 0; i < m; ++i) {
			if (trie[p][*s] == -1) {
				fill(trie[end], trie[end] + CHARSET, -1);
				trie[p][*s] = end++;
			}
			p = trie[p][*s];
			++s;
		}
		return p;
	}

	void build() {
		queue<int> bfs;
		fail[0] = 0;
		for (int i = 0; i < CHARSET; ++i) {
			if (trie[0][i] != -1) {
				fail[trie[0][i]] = 0;
				bfs.push(trie[0][i]);
			} else {
				trie[0][i] = 0;
			}
		}
		while (!bfs.empty()) {
			int p = bfs.front();
			bfs.pop();
			for (int i = 0; i < CHARSET; ++i) {
				if (trie[p][i] != -1) {
					fail[trie[p][i]] = trie[fail[p]][i];
					bfs.push(trie[p][i]);
				} else {
					trie[p][i] = trie[fail[p]][i];
				}
			}
		}
	}
};

const int MAXN = 1 << 20;
const int SIGMA = 26;

WeightedPathLength<MAXN> wpl;
AhoCorasick<MAXN, SIGMA> ac;
vector<int> e[MAXN];
char s[MAXN];
int a[MAXN], b[MAXN];

int main() {
  int n, m, t, c;

  scanf("%d%d", &m, &n);
  ac.init();
  for (int i = 0; i < n; ++i) {
    scanf("%s", s);
    c = strlen(s);
    for (int j = 0; j < c; ++j) {
      a[j] = s[j] - 'a';
    }
    b[i] = ac.add(c, a);
  }
  ac.build();

  for (int i = 0; i < ac.end; ++i) {
    e[i].clear();
  }
  for (int i = 1; i < ac.end; ++i) {
    e[ac.fail[i]].push_back(i);
  }
  wpl.init(ac.end, e);
  for (int i = 0; i < n; ++i) {
    wpl.update(b[i], 1);
  }

  for (int i = 0; i < m; ++i) {
    scanf("%s", s);
    sscanf(s + 1, "%d", &t);
    if (s[0] == '+') {
      wpl.update(b[t - 1], 1);
    } else if (s[0] == '-') {
      wpl.update(b[t - 1], 0);
    } else {
      t = 0;
      c = 0;
      for (int i = 1; s[i] != '\0'; ++i) {
        t = ac.trie[t][s[i] - 'a'];
        c += wpl.query(t);
      }
      printf("%d\n", c);
    }
  }

  return 0;
}
