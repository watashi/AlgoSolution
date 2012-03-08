#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	vector<int> w;
	vector<pair<int, int> > v;

	scanf("%d%d", &n, &m);
	w.resize(n);
	v.resize(m);
	for (int i = 0; i < m; ++i) {
		scanf("%d", &v[i].first);
		v[i].second = i + 1;
	}
	sort(v.rbegin(), v.rend());

	fill(w.begin(), w.end(), -1);
	for (int i = 0; i < n; i += 2) {
		for (vector<pair<int, int> >::iterator it = v.begin(); it != v.end(); ++it) {
			if (it->first == 0) {
				continue;
			} else if (it->second == w[(i - 1 + n) % n] || it->second == w[(i + 1) % n]) {
				continue;
			} else {
				w[i] = it->second;
				--it->first;
				break;
			}
		}
	//	printf("[%d] = %d\n", i, w[i]);
	}
	for (int i = 1; i < n; i += 2) {
		for (vector<pair<int, int> >::iterator it = v.begin(); it != v.end(); ++it) {
			if (it->first == 0) {
				continue;
			} else if (it->second == w[(i - 1 + n) % n] || it->second == w[(i + 1) % n]) {
				continue;
			} else {
				w[i] = it->second;
				--it->first;
				break;
			}
		}		
	//	printf("[%d] = %d\n", i, w[i]);
	}
	
	if (count(w.begin(), w.end(), -1) > 0) {
		puts("-1");
	} else {
		for (int i = 0; i < n; ++i) {
			printf("%d%c", w[i], i == n - 1 ? '\n' : ' ');
		}
	}

	return 0;
}

