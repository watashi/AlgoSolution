// Topological Sort

#include <list>
#include <stack>
#include <cstdio>
#include <algorithm>
using namespace std;

list<int> e[101];
int cnt[101];

int main(void)
{
    int n;
    while(scanf("%d", &n) != EOF && n != -1) {
        for (int i = 1; i <= 100; i++) {
            e[i].clear();
            cnt[i] = 0;
        }
        while(n--) {
            int a, b;
            scanf("%d%d", &a, &b);
            if(a == b) continue;///***so xe***///
            e[b].push_front(a);
            ++cnt[a];
        }
        stack<int> s;
        for (int i = 1; i <= 100; i++)
            if(cnt[i] == 0) s.push(i);
        while(!s.empty()) {
            int a = s.top();
            s.pop();
            for (list<int>::iterator itr = e[a].begin(); itr != e[a].end(); ++itr) {
                int b = *itr;
                --cnt[b];
                if(cnt[b] == 0) s.push(b);
            }
        }
        scanf("%d", &n);
        puts(cnt[n] == 0 ? "Yes" : "No");
    }
    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2746732 2008-02-08 21:07:40 Accepted 2475 C++ 00:00.00 840K わたし
//2746725 2008-02-08 20:58:16 Wrong Answer 2475 C++ 00:00.00 844K わたし
//2746724 2008-02-08 20:55:01 Wrong Answer 2475 C++ 00:00.00 840K わたし

// 2012-09-07 01:23:54 | Accepted | 2475 | C++ | 0 | 180 | watashi | Source
