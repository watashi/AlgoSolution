#include <queue>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int re, n, a;
	char buf[1024];

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%s", buf);
		printf("%s", buf);
		scanf("%d", &n);
		printf(" %d\n", (n + 1) / 2);
		
		priority_queue<int> p;
		priority_queue<int, vector<int>, greater<int> > q;

		for (int i = 0; i < n; ++i) {
			scanf("%d", &a);
			if (p.empty() || a > p.top()) {
				q.push(a);
			} else {
				p.push(a);
			}
			while (p.size() > q.size()) {
				q.push(p.top());
				p.pop();
			}
			while (p.size() < q.size()) {
				p.push(q.top());
				q.pop();
			}
			if (i % 2 == 0) {
				printf("%d", p.top());
				if (i % 20 == 18 || i == n - 1) {
					puts("");
				} else {
					putchar(' ');
				}
			}
		}
	}

	return 0;
}
//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//714981  	2011-01-04 06:14:34 	Accepted	0.020	Minimum	26909	C++	4555 - Running Median

/*
id => 1174217
pid => 4555
pname => Running Median
status => Accepted
lang => C++
time => 0.012
date => 2012-12-14 17:40:04
*/
