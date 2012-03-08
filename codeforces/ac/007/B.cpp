#include <list>
#include <cstdio>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int> PII;
typedef list<PII>::iterator Itr;

int main() {
	char ch;
	int n, m, x, y;
	list<PII> l;
	vector<Itr> v;

	scanf("%d%d", &n, &m);
	l.push_back(PII(m, 0));
	v.push_back(l.end());
	for (int i = 0; i < n; ++i) {
		scanf(" %c%*s%d", &ch, &x);
		if (ch == 'a') {
			y = 0;
			for (Itr i = l.begin(); i != l.end(); ++i) {
				if (y + x <= i->first) {
					printf("%d\n", v.size());
					v.push_back(l.insert(i, make_pair(y, x)));
					break;
				}
				y = i->first + i->second;
			}
			if (y == m) {
				puts("NULL");
			}
		} else if (ch == 'e') {
			if (0 < x && x < (int)v.size() && v[x] != l.end()) {
				l.erase(v[x]);
				v[x] = l.end();
			} else {
				puts("ILLEGAL_ERASE_ARGUMENT");
			}
		} else {
			y = 0;
			for (Itr i = l.begin(); i->first < m; ++i) {
				i->first = y;
				y += i->second;
			}
		}
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//267869 	Jan 30, 2011 6:04:26 PM 	watashi 	7B - Memory Manager 	GNU C++ 	Accepted 	30 ms 	1300 KB 
