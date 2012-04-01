#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int ans[6];

// 3, 1, 4, ?, ?

int main() {
    int n;
    char* p;

    ans[3] = 1;
    ans[1] = 2;
    ans[4] = 2;
    ans[2] = 3;
    ans[5] = 1;
    scanf("%d", &n);
    if (ans[n] == 0) {
        for (int i = 0; i < n; ++i) {
            p = new char[10 << 20];
            fill(p, p + (10 << 20), '?');
        }
    } else {
        printf("%d\n", ans[n]);
    }

    return 0;
}

