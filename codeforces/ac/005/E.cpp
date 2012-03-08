#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1 << 20;

int a[MAXN], b[MAXN];

int main() {
	int n;
	long long m;
	pair<int, int> p;
	vector<pair<int, int> > s;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	rotate(a, max_element(a, a + n), a + n);
	b[n] = 0;
	for (int i = n - 1; i >= 0; --i) {
		b[i] = max(a[i], b[i + 1]);
	}

	m = 0;
	s.push_back(make_pair(a[0], 1));
	for (int i = 1; i < n; ++i) {
		while (s.back().first < a[i]) {
			m += s.back().second;
			s.pop_back();
		}
		if (s.back().first == a[i]) {
			m += s.back().second;
			p = s.back();
			++p.second;
			s.pop_back();
		} else {
			p = make_pair(a[i], 1);
		}
		if (!s.empty()) {
			++m;
			if (a[i] == b[i] && (s.size() > 1 || s.back().second > 1)) {
				++m;
			}
		}
		s.push_back(p);
	}
	printf("%I64d\n", m);

	return 0;
}

//#  	When  	Who  	Problem  	Lang  	Verdict  	Time  	Memory
//256043 	Jan 21, 2011 11:38:54 AM 	watashi 	5E - Bindian Signalizing 	GNU C++ 	Accepted 	440 ms 	21900 KB 

