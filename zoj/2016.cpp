//判断是否存在欧拉路径~
#include <stdio.h>
#include <string.h>
void dfs(int t, int mark[26], int mp[26][26])
{
    int i;

    mark[t] = 1;
    for(i = 0; i < 26; i++){
        if(mp[t][i] && !mark[i])
            dfs(i, mark, mp);
    }
}
int main()
{
    int re, n, f, t, i;
    char str[1001];
    int in[26], out[26];
    int mark[26], mp[26][26];

    scanf("%d", &re);
    while(re--){
        scanf("%d", &n);
        memset(in, 0, sizeof(in));
        memset(out, 0, sizeof(out));
        memset(mp, 0, sizeof(mp));
        memset(mark, 0, sizeof(mark));
        while(n--){
            scanf("%s",str);
            f = str[0] - 'a';
            t = str[strlen(str) - 1] - 'a';
            mp[f][t] = 1;
            in[f]++;
            out[t]++;
        }
        f = t = -1;
        for(i = 0; i < 26; i++){
            switch(in[i] - out[i]){
                case 0:break;
                case 1:f = (f == -1) ? i : 26;break;
                case -1:t = (t == -1) ? i : 26;break;
                default:f = t = 26;break;
            }
        }
        if(f == -1 && t == -1){
            for(i = 0; i < 26; i++)
                if(in[i] && out[i]) break;
            f = t = i;
        }
        if(f == -1 || t == -1 || f == 26 || t== 26){
            printf("The door cannot be opened.\n");
        }
        else{
            dfs(f, mark, mp);
            for(i = 0; i < 26; i++)
                if(mark[i] == 0 && in[i] + out[i] != 0) break;
            if(i < 26){
                printf("The door cannot be opened.\n");
            }
            else{
                printf("Ordering is possible.\n");
            }
        }
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2703237 2007-12-15 14:04:12 Accepted 2016 C 00:00.40 396K わたし

// 2012-09-07 01:10:27 | Accepted | 2016 | C++ | 110 | 180 | watashi | Source
