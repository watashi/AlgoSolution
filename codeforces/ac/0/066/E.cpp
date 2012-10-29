#include <set>
#include <cstdio>
#include <numeric>
#include <algorithm>

using namespace std;

const int MAXN = 200200;

int a[MAXN], b[MAXN], sa[MAXN], sb[MAXN];

int main() {
	int n;
	set<int> ans;
	multiset<int> s;

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &b[i]);
	}
	copy(a + 1, a + n + 1, a + n + 1);
	copy(b + 1, b + n + 1, b + n + 1);

	copy(a + 1, a + n + n + 1, sa + 1);
	copy(b + 1, b + n + n + 1, sb + 1);
	sa[0] = sb[0] = 0;
	partial_sum(sa, sa + n + n + 1, sa);
	partial_sum(sb, sb + n + n + 1, sb);
	s.clear();
	for (int i = 1; i <= n; ++i) {
		s.insert(sa[i] - sb[i]);
	}
	for (int i = 1; i <= n; ++i) {
		if (*s.begin() == sa[i - 1] - sb[i - 1]) {
			ans.insert(i);
		}
		s.erase(s.find(sa[i] - sb[i]));
		s.insert(sa[i + n] - sb[i + n]);
	}

	copy(a + 1, a + n + n + 1, sa + 1);
	copy(b + 1, b + n + n + 1, sb + 1);
	reverse(sa + 1, sa + n + n + 1);
	reverse(sb + 1, sb + n + n + 1);
	rotate(sb + 1, sb + 2, sb + n + n + 1);
	sa[0] = sb[0] = 0;
	partial_sum(sa, sa + n + n + 1, sa);
	partial_sum(sb, sb + n + n + 1, sb);
	s.clear();
	for (int i = 1; i <= n; ++i) {
		s.insert(sa[i] - sb[i]);
	}
	for (int i = 1; i <= n; ++i) {
		if (*s.begin() == sa[i - 1] - sb[i - 1]) {
			ans.insert(n + 1 - i);
		}
		s.erase(s.find(sa[i] - sb[i]));
		s.insert(sa[i + n] - sb[i + n]);
	}

	printf("%d\n", ans.size());
	for (set<int>::const_iterator it = ans.begin(); it != ans.end(); ++it) {
		printf("%d ", *it);
	}

	return 0;
}

