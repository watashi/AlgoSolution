#include <queue>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 1024;

template<class T>
bool spfa(int n, vector<pair<int, T> > e[], T mind[]) {
	int s;
    queue<int> q;
    vector<int> d(n, 0);
    vector<bool> mark(n, false);
   
	for (int i = 0; i < n; ++i) {
		mind[i] = 0;
		mark[i] = true;
		q.push(i);
	}
    while (!q.empty()) {
        s = q.front();
        mark[s] = false;
        q.pop();
        for (typename vector<pair<int, T> >::const_iterator i =e[s].begin(); i != e[s].end(); ++i) {
            if (mind[i->first] < mind[s] + i->second) {
                mind[i->first] = mind[s] + i->second;
                d[i->first] = d[s] + 1;
                if (d[i->first] >= n) {
                    return false;
                }
                if (!mark[i->first]) {
                    mark[i->first] = true;
                    q.push(i->first);
                }
            }
        }
    }
   
    return true;
}

int d[MAXN];
vector<pair<int, int> > e[MAXN];

int main() {
	int n, m;
	char ch;

	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		scanf(" %c", &ch);
		if (ch == 'L') {
			e[i].push_back(make_pair(i - 1, 1));
		} else if (ch == 'R') {
			e[i - 1].push_back(make_pair(i, 1));
		} else {
			e[i - 1].push_back(make_pair(i, 0));
			e[i].push_back(make_pair(i - 1, 0));
		}
	}
	spfa<int>(n, e, d);
	m = 1 - *min_element(d, d + n);
	for (int i = 0; i < n; ++i) {
		printf("%d ", d[i] + m);
	}

	return 0;
}

