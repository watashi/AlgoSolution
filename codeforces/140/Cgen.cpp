#include <cstdio>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {
    int n = 100000;
    vector<int> v;

    printf("%d\n", n);
    for (int i = 0; i < n; ++i) {
        // printf("%d%c", 100000000 - i, i == n - 1 ? '\n' : ' ');
        v.push_back(i);
    }
    while (v.size() >= 3) {
        v.erase(v.begin() + 2);
        v.erase(v.begin() + 1);
        v.erase(v.begin());
    }
    puts("END");

    return 0;
}
