#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1 << 23;

// [ALGO] Algo: Manacher
// [MODULE] Module: Manacher
void manacher(int n, const char s[], int r[]) {
    int m = 0, i = 0, pl = 0;
    while (i < n) {
        if (i > pl && s[i - pl - 1] == s[i]) {
            pl += 2;
            i++;
            continue;
        }
        r[m++] = pl;
        int b = m - 2, e = b - pl, j;
        for (j = b; j > e; j--) {
            int d = j - e - 1;
            if (r[j] >= d) {
                pl = d;
                break;
            }
            r[m++] = min(d, r[j]);
        }
        if (j == e) {
            pl = 1;
            i++;
        }
    }
    r[m++] = pl;
    int b = m - 2, e = b - ((n << 1) + 1 - m);
    for (int i = b; i > e; i--) {
        int d = i - e - 1;
        r[m++] = min(d, r[i]);
    }
}

char s[MAXN];
int r[MAXN];
int d[MAXN];

int main() {
	int n, ans;

	scanf("%s", s);
	n = strlen(s);
	manacher(n, s, r);
	ans = d[0] = 0;
	for (int i = 1; i <= n; ++i) {
		if (r[i] == i) {
			d[i] = d[i / 2] + 1;
		} else {
			d[i] = 0;
		}
		ans += d[i];
	}
	printf("%d\n", ans);

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//267923 	Jan 30, 2011 7:56:50 PM 	watashi 	7D - Palindrome Degree 	GNU C++ 	Accepted 	200 ms 	75200 KB 
