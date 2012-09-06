/*
#include <set>
#include <cstdio>
using namespace std;

int ans[500001];
set<int> st;

int main(void)
{
    ans[0] = 0;
    st.insert(0);
    for (int i = 1; i <= 500000; i++) {
        if(ans[i - 1] > i && st.find(ans[i - 1] - i) == st.end()) ans[i] = ans[i - 1] - i;
        else ans[i] = ans[i - 1] + i;
        st.insert(ans[i]);
    }
    set<int>::iterator itr = st.end();
    printf("%d\n", *--itr);//3012500
    int k;
    while(scanf("%d", &k) != EOF && k != -1)
        printf("%d\n", ans[k]);
}
*/
#include <set>
#include <cstdio>
using namespace std;

int ans[500001];
bool mark[3012503] = {false};

int main(void)
{
    ans[0] = 0;
    mark[0] = true;
    for (int i = 1; i <= 500000; i++) {
        if(ans[i - 1] > i && mark[ans[i - 1] - i] == false) ans[i] = ans[i - 1] - i;
        else ans[i] = ans[i - 1] + i;
        mark[ans[i]] = true;
    }
    int k;
    while(scanf("%d", &k) != EOF && k != -1)
        printf("%d\n", ans[k]);
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2746683 2008-02-08 19:32:04 Accepted 2421 C++ 00:00.01 5288K ¤ï¤¿¤·

// 2012-09-07 01:22:58 | Accepted | 2421 | C++ | 0 | 5076 | watashi | Source
