#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1024;

int a[MAXN][MAXN];

int main() {
	int n, m, ans;

	while (scanf("%d%d", &n, &m) != EOF && n > 0) {
		ans = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				scanf("%d", &a[i][j]);
				if (i > 0 && j > 0 && a[i][j] > 0) {
					a[i][j] += min(a[i - 1][j - 1], min(a[i - 1][j], a[i][j - 1]));
				}
				ans = max(ans, a[i][j]);
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//714863  	2011-01-03 16:48:21 	Accepted	2.893	4492	26909	C++	4867 - Maximum Square

/*
id => 1174298
pid => 4867
pname => Maximum Square
status => Accepted
lang => C++
time => 0.552
date => 2012-12-14 17:51:02
*/
