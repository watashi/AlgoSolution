#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 512;
const int MAXM = 10086;

struct Node {
	short x, y;
	bool z;
	Node() { }
	Node(int x, int y, bool z) : x(x), y(y), z(z) { }
};

int pre[MAXN][MAXN][2];
vector<int> e[MAXN];

int main() {
	int n, m, a, b;

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &a, &b);
		e[a].push_back(b);
		e[b].push_back(a);
	}
	
	Node s;
	queue<Node> q;

	q.push(s = Node(1, n, false));
	pre[s.x][s.y][s.z] = -1;
	while (!q.empty()) {
		s = q.front();
		q.pop();
		a = s.x;
		b = s.y;
		s.z = !s.z;
		if (a == b && s.z) {
			continue;
		}
		if (s.z) {
			for (vector<int>::const_iterator i = e[a].begin(); i != e[a].end(); ++i) {
				s.x = *i;
				if (pre[s.x][s.y][s.z] == 0) {
					pre[s.x][s.y][s.z] = a;
					q.push(s);
				}
			}
		} else {
			for (vector<int>::const_iterator i = e[b].begin(); i != e[b].end(); ++i) {
				s.y = *i;
				if (pre[s.x][s.y][s.z] == 0) {
					pre[s.x][s.y][s.z] = b;
					q.push(s);
				}
			}			
		}
	}

	s = Node(n, 1, false);
	if (pre[s.x][s.y][s.z] == 0) {
		puts("-1");
	} else {
		vector<int> ra(1, s.x), rb(1, s.y);
		do {
			if (s.z) {
				ra.push_back(s.x = pre[s.x][s.y][s.z]);
			} else {
				rb.push_back(s.y = pre[s.x][s.y][s.z]);
			}
			s.z = !s.z;
		} while (pre[s.x][s.y][s.z] != -1);
		reverse(ra.begin(), ra.end());
		reverse(rb.begin(), rb.end());

		printf("%d\n", (int)ra.size() - 1);
		for (int i = 0; i < (int)ra.size(); ++i) {
			printf("%d%c", ra[i], i == (int)ra.size() - 1 ? '\n' : ' ');
		}
		for (int i = 0; i < (int)rb.size(); ++i) {
			printf("%d%c", rb[i], i == (int)rb.size() - 1 ? '\n' : ' ');
		}
	}

	return 0;
}

// 复杂度: O(nm)
//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//235056 	Dec 29, 2010 7:32:07 PM 	watashi 	E - Quarrel 	GNU C++ 	Accepted 	160 ms 	6120 KB 

