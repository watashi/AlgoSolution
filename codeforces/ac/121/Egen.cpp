#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {
    int n = 100, m = 200, a, b, c;

    printf("%d %d\n", n, 3 * m);
    for (int i = 0; i < n; ++i) {
        printf("%d ", 1 + rand() % 10);
    }
    puts("");
    for (int i = 0; i < m; ++i) {
        printf("count 1 %d\n", n);
        a = 1 + rand() % n;
        b = 1 + rand() % n;
        c = 1 + rand() % 10;
        printf("add %d %d %d\n", min(a, b), max(a, b), c);
        a = 1 + rand() % n;
        b = 1 + rand() % n;
        printf("count %d %d\n", min(a, b), max(a, b));
    }

    return 0;
}

