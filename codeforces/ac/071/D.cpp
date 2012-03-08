#include <set>
#include <cstdio>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const string suit[4] = {"C", "D", "H", "S"};
const string rank[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K", "A"};
string a[100][100];
set<string> st;

bool gao(int x, int y) {
	set<char> s, r;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			r.insert(a[x + i][y + j][0]);
			s.insert(a[x + i][y + j][1]);
		}
	}
	return s.size() == 1 || r.size() == 9;
}

int main() {
	int r, c, rj1, cj1, rj2, cj2;
	char buf[100];

	scanf("%d%d", &r, &c);
	rj1 = cj1 = rj2 = cj2 = -1;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 13; ++j) {
			st.insert(rank[j] + suit[i]);
		}
	}
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			scanf("%s", buf);
			a[i][j] = buf;
			st.erase(a[i][j]);
			if (a[i][j] == "J1") {
				rj1 = i;
				cj1 = j;
			} else if (a[i][j] == "J2") {
				rj2 = i;
				cj2 = j;
			}
		}
	}

	// WA38 for st.insert("J1"); ...
	st.insert("@1");
	st.insert("@2");
	for (set<string>::const_iterator j1 = st.begin(); j1 != st.end(); ++j1) {
		if (rj1 != -1) {
			if ((*j1)[0] == '@') {
				continue;
			}
			a[rj1][cj1] = *j1;
		}
		for (set<string>::const_iterator j2 = st.begin(); j2 != st.end(); ++j2) {
			if (j1 == j2) {
				continue;
			}
			if (rj2 != -1) {
				if ((*j2)[0] == '@') {
					continue;
				}
				a[rj2][cj2] = *j2;
			}

			vector<pair<int, int> > ok;
			for (int i = 0; i + 3 <= r; ++i) {
				for (int j = 0; j + 3 <= c; ++j) {
					if (gao(i, j)) {
						ok.push_back(make_pair(i, j));
					}
				}
			}

			for (vector<pair<int, int> >::const_iterator i1 = ok.begin(); i1 != ok.end(); ++i1) {
				for (vector<pair<int, int> >::const_iterator i2 = ok.begin(); i2 != i1; ++i2) {
					if (i1->first + 3 <= i2->first ||
						i2->first + 3 <= i1->first ||
						i1->second + 3 <= i2->second ||
						i2->second + 3 <= i1->second) {
						puts("Solution exists.");
						if (rj1 != -1 && rj2 != -1) {
							printf("Replace J1 with %s and J2 with %s.\n",
								j1->c_str(), j2->c_str());
						} else if (rj1 != -1) {
							printf("Replace J1 with %s.\n", j1->c_str());
						} else if (rj2 != -1) {
							printf("Replace J2 with %s.\n", j2->c_str());
						} else {
							puts("There are no jokers.");
						}
						printf("Put the first square to (%d, %d).\n",
							i2->first + 1, i2->second + 1);
						printf("Put the second square to (%d, %d).\n",
							i1->first + 1, i1->second + 1);
						return 0;
					}
				}
			}
		}
	}
	puts("No solution.");
	return 0;
}

