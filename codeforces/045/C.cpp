#include <queue>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <utility>
#include <functional>

using namespace std;

typedef pair<int, int> PII;
typedef pair<int, PII> PIJ;

const int MAXN = 200200;

int a[MAXN], p[MAXN], q[MAXN];
bool r[MAXN];
char s[MAXN];

int main() {
	int n;
	vector<PII> ans;
	priority_queue<PIJ, vector<PIJ>, greater<PIJ> > pq;

	scanf("%d", &n);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; ++i) {
		p[i] = i - 1;
		q[i] = i + 1;
		r[i] = true;
		scanf("%d", &a[i]);
		if (i > 1 && s[i - 1] != s[i]) {
			pq.push(make_pair(abs(a[i] - a[i - 1]), make_pair(i - 1, i)));
		}
	}

	while (!pq.empty()) {
		int i = pq.top().second.first;
		int j = pq.top().second.second;
		pq.pop();
		if (r[i] && r[j]) {
			ans.push_back(make_pair(i, j));
			r[i] = r[j] = false;
			i = p[i];
			j = q[j];
			q[i] = j;
			p[j] = i;
			if (r[i] && r[j] && s[i] != s[j]) {
				pq.push(make_pair(abs(a[i] - a[j]), make_pair(i, j)));
			}
		}
	}

	printf("%d\n", (int)ans.size());
	for (int i = 0; i < (int)ans.size(); ++i) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//413337 	Apr 28, 2011 1:35:42 AM 	watashi 	45C - Dancing Lessons 	GNU C++ 	Accepted 	270 ms 	8800 KB 
