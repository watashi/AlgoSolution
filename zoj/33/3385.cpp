#include <stack>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n;
    bool flag;
    long long lv, cur, sum, today;

    while (scanf("%d%lld", &n, &lv) != EOF) {
        cur = 0;
        sum = 0;
        stack<int> s;
        flag = true;
        for (int i = 0; i < n; ++i) {
            scanf("%lld", &today);
            sum += today;
            s.push(i);
            while (flag && !s.empty() && cur < sum) {
                cur += (lv + s.size() - 1) - (i - s.top());
                s.pop();
            }
            if (cur < sum) {
                flag = false;
            }
        }
        while (!s.empty() && (lv + s.size() - 1) > (n - 1 - s.top())) {
            cur += (lv + s.size() - 1) - (n - 1 - s.top());
            s.pop();
        }
        if (!flag) {
            puts("Myon");
        } else {
            printf("%lld\n", cur - sum);
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//1071  2010-07-26 13:39:28     Accepted    1128    C++     420     576     anotherpeg  Source

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//227   2010-08-12 15:24:55     Accepted    yuyuko  C++     320     572     watashi@Zodiac  Source

// 2012-09-07 15:51:22 | Accepted | 3385 | C++ | 270 | 576 | watashi | Source
