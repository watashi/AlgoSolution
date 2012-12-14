#include <set>
#include <map>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXR = 120021;
const int MAXC = 30003;

int row[MAXR], left[MAXR], right[MAXR];
set<int> col[MAXC];

const char tag[] = "IJLOSTZ";
char bitmap[7][10][10] = {
	{
		"####",
	},
	{
		"#..",
		"###",
	},
	{
		"..#",
		"###",
	},
	{
		"##",
		"##",
	},
	{
		".##",
		"##.",
	},
	{
		".#.",
		"###",
	},
	{
		"##.",
		".##",
	},
};

void rot(char str[10][10]) {
	static char buf[10][10];
	copy(str[0], str[10], buf[0]);
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			str[i][j] = buf[9 - j][i];
		}
	}
}

map<pair<char, int>, vector<vector<int> > > data;

void init() {
	for (int i = 0; i < 7; ++i) {
		for (int j = 0; j < 360; j += 90) {
			vector<vector<int> > &v = data[make_pair(tag[i], j)];
			int off = 0;
			v.resize(10);
			for (int x = 0; x < 10; ++x) {
				for (int y = 0; y < 10; ++y) {
					if (bitmap[i][x][y] == '#') {
						v[y].push_back(-x);
						off = min(off, -x);
					}
				}
			}
			while (v.back().empty()) {
				v.pop_back();
			}
			reverse(v.begin(), v.end());
			while (v.back().empty()) {
				v.pop_back();
			}
			reverse(v.begin(), v.end());
			for (int x = 0; x < (int)v.size(); ++x) {
				for (int y = 0; y < (int)v[x].size(); ++y) {
					v[x][y] -= off;
				}
			}
			rot(bitmap[i]);
		}
	}
}

const int pts[] = {0, 100, 250, 400, 1000};

int move(int i, int d) {
	for (int j = 0; j < d; ++j) {
		i = right[i];
	}
	for (int j = d; j < 0; ++j) {
		i = left[i];
	}
	return i;
}

int main() {
	int re, m, n, r, c, score;
	vector<int> clr;
	char type;

	init();
	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d%d", &m, &n);
		score = 0;
		for (int i = 0; i < 4 * (n + 1); ++i) {
			row[i] = m;
			left[i] = i - 1;
			right[i] = i + 1;
		}
		for (int i = 0; i < m; ++i) {
			col[i].clear();
			col[i].insert(0);
		}

		for (int k = 0; k < n; ++k) {
			scanf(" %c%d%d", &type, &c, &r);
			const vector<vector<int> >& v = data.find(make_pair(type, r))->second;
			r = -1;
			for (int i = 0; i < (int)v.size(); ++i) {
		//		printf("IN %d %d\n", *col[c + i].rbegin(), *v[i].rbegin());
				r = max(r, move(*col[c + i].rbegin(), 1 - *v[i].rbegin()));
			}
		//	printf("r = %d\n", r);
			clr.clear();
			for (int i = 0; i < (int)v.size(); ++i) {
				for (int j = 0; j < (int)v[i].size(); ++j) {
					int k = move(r, v[i][j]);
					col[c + i].insert(k);
		//			printf("> (%d, %d) %d + %d\n", c + i, k, r, v[i][j]);
					if (--row[k] == 0) {
						clr.push_back(k);
					}
				}
			}
			score += pts[clr.size()];
			for (int i = 0; i < (int)clr.size(); ++i) {
				int k = clr[i];
		//		printf("clear %d!\n", k);
				right[left[k]] = right[k];
				left[right[k]] = left[k];
				for (int j = 0; j < m; ++j) {
					col[j].erase(k);
				}
			}
		}

		for (int i = 0; i < 4 * (n + 1); ++i) {
			row[i] = row[i] == 0 ? 1 : 0;
			if (i > 0) {
				row[i] += row[i - 1];
			}
		}

		printf("Case #%d:\n%d\n", ri, score);
		for (int i = 0; i < m; ++i) {
			printf("%d%c", *col[i].rbegin() - row[*col[i].rbegin()], i == m - 1 ? '\n' : ' ');
		}
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//898521 	4747 	Exciting Time 	Accepted 	C++ 	0.860 	2011-10-05 07:28:16
/*
id => 1174249
pid => 4747
pname => Exciting Time
status => Accepted
lang => C++
time => 1.079
date => 2012-12-14 17:44:57
*/
