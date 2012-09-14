#include <cstdio>
#include <cstdlib>
const int MAXN = 10001;
int T[MAXN];
int h1[MAXN], h2[MAXN];
int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int m, n;
        scanf("%d%d", &m, &n);
        for (int i = 0; i < n; i++)
            T[i] = 0;
        bool flag = true;
        for (int i = 1; i <= m; i++){
            scanf("%d%d", &h1[i], &h2[i]);
            if(flag == false) continue;
            if(T[h1[i]] == 0) T[h1[i]] = i;
            else if(T[h2[i]] == 0) T[h2[i]] = -i;
            else{
                int r = h1[i];
                int d = i;
                while (true){
                    int t = T[r];
                    T[r] = d;
                    d = -t;
                    if (d == 0) break;
                    else r = (d > 0) ? h1[d] : h2[-d];
                    if(d == i && r == h1[i]) {flag = false; break;}
                }
            }
        }
        printf("%s\n", flag ? "successful hashing" : "rehash necessary");
    }
    return 0;
}
//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2708368   2007-12-21 17:05:27     Accepted    2877    C++     00:00.21    512K    ¤ï¤¿¤·

// 2012-09-07 01:44:12 | Accepted | 2877 | C++ | 70 | 296 | watashi | Source
