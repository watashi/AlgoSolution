#include <set>
#include <stack>
#include <queue>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1024;
static int curid = 0;
int id[MAXN][MAXN];
char buf[MAXN][MAXN];

struct Node {
	const int x, y;
	vector<Node*> p;
	bool ok[6];
	int how[6][4];
	Node(int x, int y) : x(x), y(y) {
	}
	int getok() const {
		for (int i = 2; i <= 5; ++i) {
			if (ok[i]) {
				return i;
			}
		}
		return -1;
	}
	void gao() {
		vector<int> ok(6, false);
		static int how[2][6][4];
	//	vector<vector<int> > how(6, vector<int>());
		ok[1] = true;
		int from = 0, to = 1;
	//	printf(">> %d, %d\n", x, y);
		for (int i = 0; i < (int)p.size(); ++i) {
			swap(from, to);
	//		printf("> %d, %d: %d\n", x, y, i);
			vector<int> ok0(6, false);
			ok.swap(ok0);
	//		vector<vector<int> > how0(6, vector<int>());
	//		how.swap(how0);
			for (int j = 1; j <= 5; ++j) {
	//			printf("j = %d\n", j);
				if (ok0[j] && p[i]->getok() != -1) {
					ok[j] = true;
					copy(how[from][j], how[from][j] + i, how[to][j]);
					how[to][j][i] = 0;
				//	how[j] = how0[j];
				//	how[j].push_back(0);

				}
				for (int k = 1; !ok[j] && k < j; ++k) {
					if (ok0[j - k] && p[i]->ok[k]) {
						ok[j] = true;
			//			how[j] = how0[j - k];
			//			how[j].push_back(k);
					copy(how[from][j - k], how[from][j - k] + i, how[to][j]);
					how[to][j][i] = k;
					}
				}
			}
		}
		copy(ok.begin(), ok.end(), this->ok);
//		copy(how.begin() + 1, how.end(), this->how + 1);
		for (int i = 1; i <= 5; ++i) {
			if (ok[i]) {
				copy(how[to][i], how[to][i] + p.size(), this->how[i]);	/// <= TLE74 !!!
			//	this->how[i].insert(this->how[i].end(), how[to][i], how[to][i] + p.size());	/// <= 1.5s AC !!!
			}
		}
	}

	void debug(int lv = 0) {
		for (int lvi = 0; lvi < lv; ++lvi) {
			printf("\t");
		}
		printf("(%d, %d) ", x, y);
		for (int i = 1; i <= 5; ++i) {
			putchar(ok[i] ? 'Y' : 'N');
		}
		puts("");
		for (int i = 0; i < (int)p.size(); ++i) {
			p[i]->debug(lv + 1);
		}
	}
};

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

Node* floodfill(int i, int j) {
	Node* p = new Node(i, j);
	queue<Node*> q;
	stack<Node*> s;
	buf[p->x][p->y] = 'x';
	q.push(p);
	s.push(p);
	while (!q.empty()) {
		Node* t = q.front();
		q.pop();
		for (int k = 0; k < 4; ++k) {
			i = t->x + dx[k];
			j = t->y + dy[k];
		//	printf("(%d, %d) -> (%d, %d) ? [%c]\n", t->x, t->y, i, j, buf[i][j]);
			if (buf[i][j] == '.') {
				buf[i][j] = 'x';
				Node* r = new Node(i, j);
				t->p.push_back(r);
				q.push(r);
				s.push(r);
			}
		}
	}
//	p->debug();
//	puts("GAO");
	while (!s.empty()) {
		Node* t = s.top();
		s.pop();
		t->gao();
	}
//	p->debug();
	return p;
}

void dump(Node* p) {
	queue<pair<Node*, pair<int, int> > > q;
	q.push(make_pair(p, make_pair(0, -1)));
	while (!q.empty()) {
		p = q.front().first;
		int s = q.front().second.first;
		int d = q.front().second.second;
		q.pop();
		if (s == 0) {
			s = p->getok();
			d = curid++;
		}
//		printf("(%d, %d) %d %d\n", p->x, p->y, s, d);
		id[p->x][p->y] = d;
		for (int i = 0; i < (int)p->p.size(); ++i) {
			q.push(make_pair(p->p[i], make_pair(p->how[s][i], d)));
		}
	}
}

void color(int i, int j) {
	vector<pair<int, int> > v;
	set<char> s;
	int d = id[i][j];
	id[i][j] = -1;
	v.push_back(make_pair(i, j));
	for (int h = 0; h < (int)v.size(); ++h) {
		i = v[h].first;
		j = v[h].second;
		for (int k = 0; k < 4; ++k) {
			int x = i + dx[k];
			int y = j + dy[k];
			if (id[x][y] == d) {
				id[x][y] = -1;
				v.push_back(make_pair(x, y));
			} else if (isdigit(buf[x][y])) {
				s.insert(buf[x][y]);
			}
		}
	}
	char c;
	for (c = '0'; s.count(c) > 0; ++c) {
	}
	for (int h = 0; h < (int)v.size(); ++h) {
		buf[v[h].first][v[h].second] = c;
	}
}

int main() {
	int r, c;
	vector<Node*> p;

	scanf("%d%d", &r, &c);
	memset(id, 0xff, sizeof(id));
	memset(buf, '\0', sizeof(buf));
	for (int i = 1; i <= r; ++i) {
		scanf("%s", buf[i] + 1);
	}
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			if (buf[i][j] == '.') {
				p.push_back(floodfill(i, j));
			}
		}
	}
//	puts("floodfill");
//	fflush(stdout);
	for (int i = 0; i < (int)p.size(); ++i) {
		if (p[i]->getok() == -1) {
			puts("-1");
			return 0;
		} else {
			dump(p[i]);
		}
	}
//	puts("dump");
//	fflush(stdout);
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			if (id[i][j] != -1) {
				color(i, j);
			}
		}
	}
//	puts("color");
//	fflush(stdout);
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			putchar(buf[i][j]);
		}
		puts("");
	}
	
	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//467645 	May 22, 2011 9:44:13 PM 	watashi 	B - Tetris revisited 	GNU C++ 	Accepted 	1470 ms 	159496 KB 
