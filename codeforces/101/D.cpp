#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 100100;

vector<pair<int, int> > e[MAXN];

struct Gao {
	long long sum;
	long long cnt;
	long long len;
};

bool operator<(const Gao& lhs, const Gao& rhs) {
	return lhs.len * rhs.cnt < rhs.len * lhs.cnt;
}

Gao gao(int v, int p) {
	Gao ret = {0, 0, 0};
	vector<Gao> todo;
	
	for (auto w: e[v]) {
		if (w.first != p) {
			todo.push_back(gao(w.first, v));
			todo.back().sum += w.second * todo.back().cnt;
			todo.back().len += 2 * w.second;
		}
	}
	sort(todo.begin(), todo.end());
	for (auto i: todo) {
		ret.sum += i.sum + ret.len * i.cnt;
		ret.cnt += i.cnt;
		ret.len += i.len;
	}
	++ret.cnt;

	return ret;
}

int main() {
	int n, a, b, c;
	Gao ans;

	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		scanf("%d%d%d", &a, &b, &c);
		--a;
		--b;
		e[a].push_back(make_pair(b, c));
		e[b].push_back(make_pair(a, c));
	}
	ans = gao(0, -1);
	printf("%.10lf\n", 1.0 * ans.sum / (ans.cnt - 1));

	return 0;
}

