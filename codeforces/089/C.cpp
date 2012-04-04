#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
	const int d, x, y;
	Node* p[4];
	
	Node(int d, int x, int y) : d(d), x(x), y(y) {
		for (int i = 0; i < 4; ++i) {
			p[i] = NULL;
		}
	}

	void remove() {
		for (int i = 0; i < 4; ++i) {
			if (p[i] != NULL) {
				p[i]->p[i ^ 1] = p[i ^ 1];
			}
		}
	}
	
	void recover() {
		for (int i = 0; i < 4; ++i) {
			if (p[i] != NULL) {
				p[i]->p[i ^ 1] = this;
			}
		}
	}
};

const char dir[] = "UDLR";

int gao(Node* p) {
	if (p == NULL) {
		return 0;
	} else {
		Node* t = p->p[p->d];
		// printf("%d %d %p %p\n", p->x, p->y, p, t);
		p->remove();
		int ret = gao(t) + 1;
		p->recover();
		return ret;
	}
}

int main() {
	int r, c;
	char ch;
	Node* p;

	scanf("%d%d", &r, &c);
	vector<vector<Node*> > a(r, vector<Node*>(c));
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			scanf(" %c", &ch);
			if (ch != '.') {
				a[i][j] = new Node(find(dir, dir + 4, ch) - dir, i, j);
			} else {
				a[i][j] = NULL;
			}
		}
	}

	for (int i = 0; i < r; ++i) {
		p = NULL;
		for (int j = 0; j < c; ++j) {
			if (a[i][j] != NULL) {
				if (p != NULL) {
					p->p[3] = a[i][j];
				}
				a[i][j]->p[2] = p;
				p = a[i][j];
			}
		}
	}
	for (int j = 0; j < c; ++j) {
		p = NULL;
		for (int i = 0; i < r; ++i) {
			if (a[i][j] != NULL) {
				if (p != NULL) {
					p->p[1] = a[i][j];
				}
				a[i][j]->p[0] = p;
				p = a[i][j];
			}
		}
	}

	int ans = 0, cnt = 0;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (a[i][j] != NULL) {
				int tmp = gao(a[i][j]);
				if (tmp > ans) {
					ans = tmp;
					cnt = 1;
				} else if (tmp == ans) {
					++cnt;
				}
			}
		}
	}
	printf("%d %d\n", ans, cnt);
	
	return 0;
}

