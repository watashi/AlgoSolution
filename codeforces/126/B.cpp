#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

template<typename T>
void extKmpA(int n, T pat[], int a[]) {
	int p = 0, k = 1;
	a[0] = n;
	while (pat[p + 1] == pat[p]) {
		++p;
	}
	a[1] = p;
	for (int i = 2; i < n; ++i) {
		int x = k + a[k] - i, y = a[i - k];
		if (y < x) {
			a[i] = y;
		} else {
			p = max(0, x);
			while (pat[p + i] == pat[p]) {
				++p;
			}
			a[i] = p;
			k = i;
		}
	}
}

char buf[1 << 20];
int a[1 << 20];

int main() {
	int n, m, ans;

	scanf("%s", buf);
	n = strlen(buf);
	extKmpA(n, buf, a);
	m = 0;
	for (int i = 1; i < n; ++i) {
		m = max(m, min(a[i], n - i - 1));
	}
	ans = 0;
	for (int i = 1; i < n; ++i) {
		if (i + a[i] == n && a[i] <= m) {
			ans = max(ans, a[i]);
		}
	}
	if (ans == 0) {
		puts("Just a legend");
	} else {
		buf[ans] = '\0';
		puts(buf);
	}

	return 0;
}

