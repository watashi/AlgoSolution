#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int MAXN = 100100;
const int INF = 1000000007;
int a[MAXN], b[MAXN], c[MAXN];

struct SkyLine {
	vector<PII> w;

	SkyLine(const vector<int>& v) {
		for (int i: v) {
			while (true) {
				if (w.empty()) {
					w.push_back(make_pair(0, i));
					break;
				} else {
					int j = w.back().second;
					int t = b[i] >= b[j] ? 0 : (b[j] - b[i]) / (a[i] - a[j]) + 1;
					if (t <= w.back().first) {
						w.pop_back();
					} else {
						w.push_back(make_pair(t, i));
						break;
					}
				}
			}
		}
	}

	pair<long long, int> query(int t) const {
		int i = (upper_bound(w.begin(), w.end(), make_pair(t, INF)) - 1)->second;
		return {1LL * a[i] * t + b[i], i};
	}
};

struct SegmentTree {
	const int l, r;
	const SkyLine sl;
	SegmentTree *pl, *pr;
	
	SegmentTree(int l, int r, int i[]) : l(l), r(r), sl(vector<int>(i + l, i + r)), pl(nullptr), pr(nullptr) {
		if (r - l > 1) {
			int m = (l + r) / 2;
			stable_partition(i + l, i + r, [m](int j){return j < m;});
			pl = new SegmentTree(l, m, i);
			pr = new SegmentTree(m, r, i);
		}
	}

	~SegmentTree() {
		delete pl;
		delete pr;
	}

	pair<long long, int> query(int ll, int rr, int t) const {
		if (ll == l && rr == r) {
			return sl.query(t);
		} else {
			int m = (l + r) / 2;
			if (rr <= m) {
				return pl->query(ll, rr, t);
			} else if (m <= ll) {
				return pr->query(ll, rr, t);
			} else {
				return max(pl->query(ll, m, t), pr->query(m, rr, t));
			}
		}
	}
};

int main() {
	int n, m, l, r, t;
	SegmentTree *st = nullptr;

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &b[i], &a[i]);
		c[i] = i;
	}
	sort(c, c + n, [&](int i, int j){return a[i] < a[j] || (a[i] == a[j] && b[i] < b[j]);});

	st = new SegmentTree(0, n, c);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d", &l, &r, &t);
		printf("%d\n", st->query(l - 1, r, t).second + 1);
	}
	delete st;

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//507754 	Jun 22, 2011 5:14:06 PM 	watashi 	91E - Igloo Skyscraper 	GNU C++0x 	Accepted 	970 ms 	29200 KB 
