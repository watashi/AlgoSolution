#include <set>
#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 300300;

template<int N> struct LG2 { static const int VAL = LG2<N / 2>::VAL + 1; };
template<> struct LG2<0> { static const int VAL = -1; };

template<int MAXN, typename T = int>
struct RMQ {
    // static const int MAXL = 32 - __builtin_clz(MAXN - 1);
    static const int MAXL = ::LG2<MAXN - 1>::VAL + 1;

	int n;
	T e[MAXN];
	int rmq[MAXL][MAXN];

    static inline int LG2(int i) { return 31 - __builtin_clz(i); }
	static inline int BIN(int i) { return 1 << i; }

	int cmp(int l, int r) {
		return e[l] <= e[r] ? l : r;
	}

	void init(int n, int e[MAXN]) {
        this->n = n;
        copy(e, e + n, this->e);
		for (int i = 0; i < n; ++i) {
			rmq[0][i] = i;
		}
		for (int i = 0; BIN(i + 1) <= n; ++i) {
			for (int j = 0; j + BIN(i + 1) <= n; ++j) {
				rmq[i + 1][j] = cmp(rmq[i][j], rmq[i][j + BIN(i)]);
			}
		}
	}

	int index(int l, int r) {
		int b = LG2(r - l);
		return cmp(rmq[b][l], rmq[b][r - (1 << b)]);
	}

	T value(int l, int r) {
		return e[index(l, r)];
	}
};

RMQ<MAXN> rmq;

template<typename T>
struct Indexer {
    const T* a;

    Indexer(const T* a): a(a) {
    }

    bool operator()(int lhs, int rhs) const {
        return a[lhs] < a[rhs];
    }
};

template<int MAXN>
struct SuffixArray {
    pair<int, int> suffix[MAXN];
    int sa[MAXN], rank[MAXN], height[MAXN], h[MAXN];

    void init(int n, const char a[MAXN]) {
        sa[0] = 0;
        for (int i = 0; i < n; ++i) {
            rank[i] = a[i];
        }
        for (int m = 1; m < n; m <<= 1) {
            for (int i = 0; i < n; ++i) {
                sa[i] = i;
                suffix[i] = make_pair(rank[i], i + m < n ? rank[i + m] : -1);
            }
            sort(sa, sa + n, Indexer<pair<int, int> >(suffix));
            for (int i = 0; i < n; ++i) {
                if (i == 0 || (suffix[sa[i]] != suffix[sa[i - 1]])) {
                    rank[sa[i]] = i;
                } else {
                    rank[sa[i]] = rank[sa[i - 1]];
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (rank[i] == 0) {
                h[i] = 0;
            } else {
                int x = i, y = sa[rank[i] - 1], z = max(0, h[i - 1] - 1);
                while (x + z < n && y + z < n && a[x + z] == a[y + z]) {
                    ++z;
                }
                h[i] = z;
            }
        }
        for (int i = 0; i < n; ++i) {
            height[i] = h[sa[i]];
        }
    }
};

SuffixArray<MAXN> sa;

char buf[MAXN], op[80];

int main() {
    int n, m, l, r;
    set<pair<int, int> > st;

    scanf("%d%d", &n, &m);
    scanf("%s", buf);
    sa.init(n, buf);
    rmq.init(n, sa.height);

    l = 0;
    r = 1;
    for (int i = 0; i < m; ++i) {
        scanf("%s", op);
        int& t = op[0] == 'L' ? l : r;
        t += op[1] == '+' ? 1 : -1;
        int k = sa.rank[l];
        int lo = 0, hi = k;
        while (lo < hi) {
            int mi = (lo + hi) / 2;
            if (rmq.value(mi + 1, k + 1) >= r - l) {
                hi = mi;
            } else {
                lo = mi + 1;
            }
        }
        st.insert(make_pair(hi, r - l));
    }
    printf("%d\n", (int)st.size());

    return 0;
}

//Run# 	Author 	Problem 	Status 	Lang 	Time 	Memory 	Submission Date
//#486821 	watashi 	E 	: Accepted 	C++ 	00:65 sec 	65464 KB 	Sun Sep 16 17:01:19

//Run# 	Author 	Problem 	Status 	Lang 	Time 	Memory 	Code 	Submission Date
//#489372 	watashi 	2444 	: Accepted 	C++ 	00:65 sec 	45836 KB 	3452 Bytes 	Wed Sep 19 16:05:48

