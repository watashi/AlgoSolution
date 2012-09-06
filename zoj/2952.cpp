#include <set>
#include <cstdio>
using namespace std;

const long long bound = 1LL << 31;

int main(void)
{
    set<int> st;

    for (long long m = 2; m * m < bound; m++)
        for (long long n = m * m; n < bound; n *= m)
            st.insert((int)n);
    for (set<int>::iterator it = st.begin(); it != st.end(); ++it)
        printf("%d\n", *it);

    return 0;
}

//2814233 2008-03-31 19:50:01 Accepted 2952 C++ 00:00.08 2008K ¤ï¤¿¤·

// 2012-09-07 01:49:37 | Accepted | 2952 | C++ | 30 | 1232 | watashi | Source
