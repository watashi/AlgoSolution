#include <map>
#include <queue>
#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

struct Node {
	int s;
	Node* pl;
	Node* pr;
	
	Node() : s(0), pl(NULL), pr(NULL) { }
	~Node() { delete pl; delete pr; }
	Node* getl() { return pl == NULL ? pl = new Node() : pl; }
	Node* getr() { return pr == NULL ? pr = new Node() : pr; }
	
	void add(int l, int r, int i, int v) {
		if (r - l > 1) {
			int m = (l + r) / 2;
			if (i < m) {
				getl()->add(l, m, i, v);
			} else {
				getr()->add(m, r, i, v);
			}
		}
		s += v;
	}

	// [0, i)
	int sum(int l, int r, int i) {
		int m = (l + r) / 2;
		if (s == 0 || r == i) {
			return s;
		} else if (i <= m) {
			return getl()->sum(l, m, i);
		} else {
			return getl()->sum(l, m, m) + getr()->sum(m, r, i);
		}
	}
};

map<int, int> pos, range;
priority_queue<pair<int, int> > todo;

int main() {
	int n, m, x, y, a, b;
	Node *p = new Node();
	map<int, int>::iterator it;

	scanf("%d%d", &n, &m);
	range[1] = n;
	todo.push(make_pair(n - 1, 1));
	for (int i = 0; i < m; ++i) {
		scanf("%d", &x);
		if (x == 0) {
			scanf("%d%d", &x, &y);
			printf("%d\n", p->sum(0, 1 << 30, y + 1) - p->sum(0, 1 << 30, x));
		} else if (pos.count(x) > 0) {
			y = pos[x];
			pos.erase(x);
			p->add(0, 1 << 30, y, -1);
			a = b = y;
			it = range.upper_bound(y);
			if (it != range.begin()) {
				--it;
				if (it->second == y - 1) {
					a = it->first;
					range.erase(it);
				}
			}
			it = range.lower_bound(y);
			if (it != range.end() && it->first == y + 1) {
				b = it->second;
				range.erase(it);
			}
			range[a] = b;
			todo.push(make_pair(b - a, a));
		} else {
			do {
				b = todo.top().first;
				a = todo.top().second;
				b += a;
				todo.pop();
			} while (range.count(a) == 0 || range[a] != b);
			y = (a + b + 1) / 2;
			pos[x] = y;
		//	printf("[%d, %d] => %d\n", a, b, y);
			p->add(0, 1 << 30, y, 1);
			range.erase(a);
			if (a <= y - 1) {
				range[a] = y - 1;
				todo.push(make_pair(y - 1 - a, a));
			}
			if (y + 1 <= b) {
				range[y + 1] = b;
				todo.push(make_pair(b - y - 1, y + 1));
			}
		}
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//413423 	Apr 28, 2011 3:34:15 AM 	watashi 	74D - Hanger 	GNU C++ 	Accepted 	610 ms 	44300 KB
