#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100100;

int a[MAXN], b[MAXN];

int main() {
    int n, c = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    copy(a, a + n, b);
    sort(b, b + n);
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            ++c;
        }
    }
    puts(c <= 2 ? "YES" : "NO");

    return 0;
}
