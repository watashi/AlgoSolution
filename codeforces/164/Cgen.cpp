#include <cstdio>
#include <cstdlib>
#include <algorithm>

int main() {
    int n = 1000, m = 50;

    printf("%d %d\n", n, m);
    for (int i = 0; i < n; ++i) {
        printf("%d %d %d\n", 1 + rand() % 1000000, 1 + rand() % 100000, 1 + rand() % 1000000);
    }

    return 0;
}

