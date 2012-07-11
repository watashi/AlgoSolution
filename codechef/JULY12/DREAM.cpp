#include <map>
#include <cstdio>

using namespace std;

int main() {
    int n, m, a, c;
    map<int, int> mp;

    scanf("%d%d", &n, &m);
    c = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a);
        if (mp[a] < i) {
            ++c;
            mp[a] = i + m - 1;
        }
    }
    printf("%d\n", c);

    return 0;
}

//Correct Answer
//Execution Time: 4.91
