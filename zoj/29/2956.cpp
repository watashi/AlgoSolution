#include <set>
#include <cstdio>
#include <algorithm>
using namespace std;

pair<int, int> p[4004];
multiset<int> st;

int main(void)
{
    int re, n, ans;

    scanf("%d", &re);
    while(re--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%*d%d%d", &p[i].first, &p[i].second);
        sort(p, p + n);
        st.clear();
        ans = 0;
        for (int i = 0; i < n; i++) {
            st.insert(p[i].second);
            while(*st.begin() < p[i].first)
                st.erase(st.begin());
            ans = max(ans, (int)st.size());
        }
        printf("%d\n", ans);
    }

    return 0;
}
//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2916866   2008-05-15 20:41:58     Accepted    2956    C++     00:00.01    892K    Re:ReJudge

// 2012-09-07 01:50:04 | Accepted | 2956 | C++ | 0 | 212 | watashi | Source
