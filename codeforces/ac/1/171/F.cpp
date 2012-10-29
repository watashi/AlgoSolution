#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1000000;

bool p[MAXN];
vector<int> q;

int rev(int p, int q = 0) {
    return p == 0 ? q : rev(p / 10, q * 10 + p % 10);
}

int main() {
    for (int i = 2; i < MAXN; ++i) {
        if (!p[i]) {
            for (int j = i + i; j < MAXN; j += i) {
                p[j] = true;
            }
        }
    }
    for (int i = 10; i < MAXN; ++i) {
        if (!p[i] && rev(i) != i && !p[rev(i)]) {
            q.push_back(i);
        }
    }
    //printf("%d\n", (int)q.size());
    int n;
    scanf("%d", &n);
    printf("%d\n", q[n - 1]);
    return 0;
}

