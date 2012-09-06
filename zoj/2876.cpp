#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
inline bool check(const string &a, const string &b)
{
    if(a.length() > b.length()) return false;
    else return b.substr(0, a.length()) == a;
}
int main()
{
    int t;

    scanf("%d", &t);
    while(t--){
        int n;
        string l[10000];
        scanf("%d", &n);
        for (int i = 0; i < n; i++){
            char str[12];
            scanf("%s", str);
            l[i] = (string)str;
        }
        sort(l, l + n);
        bool flag = true;
        for (int i = 1; i < n; i++){
            if (check(l[i - 1], l[i])){
                flag = false;
                break;
            }
        }
        printf("%s\n", flag ? "YES" : "NO");
    }
    return 0;
}
//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2708364   2007-12-21 17:03:08     Accepted    2876    C++     00:00.68    1116K   ¤ï¤¿¤·

// 2012-09-07 01:44:06 | Accepted | 2876 | C++ | 220 | 444 | watashi | Source
