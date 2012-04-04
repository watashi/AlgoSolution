#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    static int a[1 << 20];

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    k = max_element(a, a + n) - a;
    a[k] = a[k] == 1 ? 2 : 1;
    sort(a, a + n);
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }

    return 0;
}

