#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1024;

bool in[MAXN], done[MAXN];
int out[MAXN], cap[MAXN];

int main() {
	int n, m, a, b, c;
	vector<pair<pair<int, int>, int> > ans;
	
	scanf("%d%d", &n, &m);
	fill(in, in + n, false);
	fill(done, done + n, false);
	fill(out, out + n, -1);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d", &a, &b, &c);
		--a;
		--b;
		in[b] = true;
		out[a] = b;
		cap[a] = c;
	}

	for (int i = 0; i < n; ++i) {
		if (out[i] != -1 && !in[i]) {
			int j = i, k = cap[i];
			while (!done[j] && out[j] != -1) {
				done[j] = true;
				k = min(k, cap[j]);
				j = out[j];
			}
			if (out[j] == -1) {
				ans.push_back({{i, j}, k});
			}
		}
	}
	
	printf("%d\n", (int)ans.size());
	for (int i = 0; i < (int)ans.size(); ++i) {
		printf("%d %d %d\n", ans[i].first.first + 1, ans[i].first.second + 1, ans[i].second);
	}

	return 0;
}
