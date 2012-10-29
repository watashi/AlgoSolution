#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, s;
    vector<int> a, b;

    scanf("%d", &n);
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    s = accumulate(a.begin(), a.end(), 0);
    for (int i = 0; i < n; ++i) {
        if (s == a[i] * n) {
            b.push_back(i);
        }
    }
    printf("%d\n", (int)b.size());
    for (int i: b) {
        printf("%d ", i + 1);
    }

    return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//1132992 	Feb 2, 2012 4:14:12 PM 	watashi 	134A - Average Numbers 	GNU C++0x 	Accepted 	160 ms 	3700 KB
