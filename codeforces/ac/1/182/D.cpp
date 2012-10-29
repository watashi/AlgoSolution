#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 100100;

void extKmp(int n, const char pat[], int a[]) {
	int p = 0, k = 1;
	a[0] = n;
	while (p + 1 < n && pat[p + 1] == pat[p]) {
		++p;
	}
	a[1] = p;
	for (int i = 2; i < n; ++i) {
		int x = k + a[k] - i, y = a[i - k];
		if (y < x) {
			a[i] = y;
		} else {
			p = max(0, x);
			while (p + i < n && pat[p + i] == pat[p]) {
				++p;
			}
			a[i] = p;
			k = i;
		}
	}
}

char s[MAXN], t[MAXN];
int a[MAXN], b[MAXN];

int main() {
    int n, m, ans = 0;

    scanf("%s%s", s, t);
    n = strlen(s);
    m = strlen(t);
    extKmp(n, s, a);
    extKmp(m, t, b);
    a[n] = b[m] = 0;
    for (int i = 1; s[i - 1] == t[i - 1] && i <= n && i <= m; ++i) {
        if (n % i == 0 && m % i == 0 && a[i] == n - i && b[i] == m - i) {
            ++ans;
        }
    }
    printf("%d\n", ans);

    return 0;
}

