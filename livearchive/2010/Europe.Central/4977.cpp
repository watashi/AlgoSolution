#include <set>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1 << 20;
int t[MAXN], x[MAXN];

int main() {
	int re, n, m;
	bool flag;
	set<int> todo;
	set<int>::iterator it;

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d%d", &n, &m);
		flag = true;
		todo.clear();
		for (int i = 1; i <= n; ++i) {
			x[i] = 0;
		}
		for (int i = 1; i <= m; ++i) {
			scanf("%d", &t[i]);
			if (!flag) {
				continue;
			}
			if (t[i] == 0) {
				todo.insert(i);
			} else if ((it = todo.lower_bound(x[t[i]])) != todo.end()) {
				t[*it] = -t[i];
				todo.erase(it);
				x[t[i]] = i;
			} else {
				flag = false;
			}
		}
		if (flag) {
			puts("YES");
			flag = false;
			for (int i = 1; i <= m; ++i) {
				if (t[i] <= 0) {
					if (flag) {
						putchar(' ');
					} else {
						flag = true;
					}
					printf("%d", -t[i]);
				}
			}
			puts("");
		} else {
			puts("NO");
		}
	}

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//722952  	2011-01-20 14:56:00 	Accepted	7.584	16040	26909	C++	4977 - Enter The Dragon

/*
id => 1174400
pid => 4977
pname => Enter The Dragon
status => Accepted
lang => C++
time => 0.969
date => 2012-12-14 18:44:50
*/
