#include <list>
#include <cstdio>
using namespace std;

const int MAX = 35000;

int main(void)
{
    int ans[3003] = {1, 2};
    list<int> ls;
    for (int i = 3; i < MAX; i += 2)
        ls.push_back(i);
    for (int i = 2; i <= 3000; i++) {
        list<int>::iterator it = ls.begin();
        int d = *it;
        ans[i] = d;
        it = ls.erase(it);
        int t = 1;
        while(it != ls.end()) {
            if(t == d) {
                t = 1;
                it = ls.erase(it);
            }
            else {
                t++;
                it++;
            }
        }
    }
    int input;
    while(scanf("%d", &input) != EOF && input > 0)
        printf("%d\n", ans[input]);
    return 0;
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name

// 2012-09-07 01:09:13 | Accepted | 1978 | C++ | 40 | 444 | watashi | Source
