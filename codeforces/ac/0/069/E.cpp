#include <set>
#include <map>
#include <cstdio>
#include <algorithm>

using namespace std;

int a[1 << 20];

int main() {
	int n, m;
	set<int> st;
	map<int, int> mp;

	scanf("%d%d", &n, &m);
	--m;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		// insert
		switch (++mp[a[i]]) {
			case 1:
				st.insert(a[i]);
				break;
			case 2:
				st.erase(a[i]);
				break;
		}
		if (i >= m) {
			if (st.empty()) {
				puts("Nothing");
			} else {
				printf("%d\n", *st.rbegin());
			}
			// erase
			switch (--mp[a[i - m]]) {
				case 0:
					st.erase(a[i - m]);
					break;
				case 1:
					st.insert(a[i - m]);
					break;
			}
		}
	}

	return 0;
}


