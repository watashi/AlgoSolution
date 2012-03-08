#include <set>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

typedef pair<int, string> PIS;

int main() {
	int n, m, t;
	char buf[80];
	PIS vasya;
	vector<PIS> a;
	multiset<int> b, c;
	multiset<int>::iterator it;

	scanf("%d", &n);
	a.resize(n);
	for (int i = 0; i < n; ++i) {
		scanf("%s%d", buf, &a[i].first);
		a[i].second = buf;
	}
	
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d", &t);
		b.insert(t);
	}
	for (int i = m; i < n; ++i) {
		b.insert(0);
	}
	
	scanf("%s", buf);
	vasya.second = buf;
	for (vector<PIS>::iterator i = a.begin(); i != a.end(); ++i) {
		if (i->second == vasya.second) {
			vasya.first = i->first;
			a.erase(i);
			break;
		}
	}
	sort(a.begin(), a.end());

	t = 1;
	c = b;
	vasya.first += *b.rbegin();
	it = c.end();
	--it;
	c.erase(it);
	for (vector<PIS>::iterator i = a.begin(); i != a.end(); ++i) {
		if (i->second < vasya.second) {
			it = c.lower_bound(vasya.first - i->first);
		} else {
			it = c.upper_bound(vasya.first - i->first);
		}
		if (it != c.begin()) {
			--it;
			c.erase(it);
		} else {
			++t;
		}
	}
	vasya.first -= *b.rbegin();
	printf("%d ", t);

	t = 1;
	c = b;
	vasya.first += *b.begin();
	c.erase(c.begin());
	for (vector<PIS>::iterator i = a.begin(); i != a.end(); ++i) {
		if (i->second < vasya.second) {
			it = c.lower_bound(vasya.first - i->first);
		} else {
			it = c.upper_bound(vasya.first - i->first);
		}
		if (it != c.end()) {
			++t;
			c.erase(it);
		}
	}
	vasya.first -= *b.begin();
	printf("%d\n", t);

	return 0;
}

