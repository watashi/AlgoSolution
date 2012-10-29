#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 2012;
vector<int> e[MAXN];

int main() {
	int n, m;

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &a, &b);
		--a;
		--b;
		e[a].push_back(b);
		e[b].push_back(a);
	}


	return 0;
}
