#include <cstdio>

int main() {
    int n = 100000;
    printf("%d 7777777777\n", n);
    for (int i = 0; i < n; ++i) {
        printf("%d%c", 9, i == n - 1 ? '\n' : ' ');
    }
    return 0;
}

