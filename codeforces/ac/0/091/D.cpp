#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100100;

int n, p[MAXN], q[MAXN];

vector<vector<pair<int, int> > > todo[6];

void gao(vector<pair<int, int> >& w) {
	for (int i = 1; i < (int)w.size(); ++i) {
		swap(p[w[i - 1].first], p[w[i].first]);
		swap(w[i - 1].second, w[i].second);
	}
	for (int i = 0; i < (int)w.size(); ++i) {
		q[p[w[i].first]] = w[i].first;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &p[i]);
		q[p[i]] = i;
	}
	for (int i = 1; i <= n; ) {
		if (p[i] == i) {
			++i;
			continue;
		}
		vector<pair<int, int> > w(1, make_pair(i, i));
		for (int j = q[i]; (int)w.size() < 5 && j != i; j = q[j]) {
			w.push_back(make_pair(j, j));
		}
		gao(w);
	//	printf("> ");
	//	for (int i = 1; i <= n; ++i) {
	//		printf("%d ", p[i]);
	//	}
	//	puts("");
		todo[(int)w.size()].push_back(w);
	}
//	for (int i = 1; i <= n; ++i) {
//		if (p[i] != i || q[i] != i) {
//			throw 1;
//		}
//	}
	
	
	todo[5].insert(todo[5].end(), todo[4].begin(), todo[4].end());
	while (!todo[2].empty() && !todo[3].empty()) {
		vector<pair<int, int> > w;
		w.insert(w.end(), todo[2].back().begin(), todo[2].back().end());
		todo[2].pop_back();
		w.insert(w.end(), todo[3].back().begin(), todo[3].back().end());
		todo[3].pop_back();
		todo[5].push_back(w);
	}
	while (todo[3].size() >= 3) {
		vector<pair<int, int> > x = todo[3][todo[3].size() - 1];
		vector<pair<int, int> > y = todo[3][todo[3].size() - 2];
		vector<pair<int, int> > z = todo[3][todo[3].size() - 3];
		todo[3].resize(todo[3].size() - 3);
		x.push_back(y[0]);
		x.push_back(make_pair(y[0].second, y[0].first));
		todo[5].push_back(x);
		z.push_back(make_pair(y[1].first, y[2].first));
		z.push_back(make_pair(y[2].first, y[1].first));
		todo[5].push_back(z);
	}
	todo[5].insert(todo[5].end(), todo[3].begin(), todo[3].end());
	while (!todo[2].empty()) {
		vector<pair<int, int> > w;
		w.insert(w.end(), todo[2].back().begin(), todo[2].back().end());
		todo[2].pop_back();
		if (!todo[2].empty()) {
			w.insert(w.end(), todo[2].back().begin(), todo[2].back().end());
			todo[2].pop_back();
		}
		todo[5].push_back(w);
	}

	printf("%d\n", todo[5].size());
	for (vector<vector<pair<int, int> > >::const_iterator it = todo[5].begin(); it != todo[5].end(); ++it) {
		printf("%d\n", (int)it->size());
		for (vector<pair<int, int> >::const_iterator jt = it->begin(); jt != it->end(); ++jt) {
			printf("%d%c", jt->second, jt == it->end() - 1 ? '\n' : ' ');
		}
		for (vector<pair<int, int> >::const_iterator jt = it->begin(); jt != it->end(); ++jt) {
			printf("%d%c", jt->first, jt == it->end() - 1 ? '\n' : ' ');
		}
	}
	
	return 0;	
}

