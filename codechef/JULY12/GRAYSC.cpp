#include <set>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

const int MAXN = 256;

ull a[MAXN];
int main() {
    int n;
    set<ull> st;

    scanf("%d", &n);
    if (n > MAXN) {
        puts("Yes");
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%llu", &a[i]);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (st.count(a[i] ^ a[j]) != 0) {
                puts("Yes");
                return 0;
            }
        }
        for (int j = 0; j < i; ++j) {
            st.insert(a[i] ^ a[j]);
        }
    }
    puts("No");
    return 0;
}

//Correct Answer
//Execution Time: 0.06
