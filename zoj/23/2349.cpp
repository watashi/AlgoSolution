//是个好题，赞~~****
//Hash~
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
class word{
private:
    int len;
    int alpha[26];
    char str[22];
    int pr;
public:
    int dp;
    bool read()
    {
        if(gets(str)==NULL || str[0]=='\0') return false;
        fill(alpha,alpha+26,0);
        for(len=0;str[len];len++)
            alpha[str[len]-'a']++;
        pr=-1;
        dp=0;
        return true;
    }
    bool operator<(const word &that) const
    {
        if(len<that.len) return true;
        else if(len>that.len) return false;
        else{
            for(int i=0;i<26;i++){
                if(alpha[i]<that.alpha[i]) return true;
                else if(alpha[i]>that.alpha[i]) return false;
            }
            return false;
        }
    }
    bool operator>(const word &that) const
    {
        if(len<that.len) return false;
        else if(len>that.len) return true;
        else{
            for(int i=0;i<26;i++){
                if(alpha[i]<that.alpha[i]) return false;
                else if(alpha[i]>that.alpha[i]) return true;
            }
            return false;
        }
    }
    bool operator==(const word &that) const
    {
        if(len!=that.len) return false;
        for(int i=0;i<26;i++)
            if(alpha[i]!=that.alpha[i]) return false;
        return true;
    }
    void doit(word *lst,int n)
    {
        word cur=*this;
        cur.len--;
        for(int i=0;i<26;i++){
            if(cur.alpha[i]==0) continue;
            cur.alpha[i]--;
            word *p=lower_bound(lst,lst+n,cur);
            if(*p==cur&&p->dp>=dp){
                dp=p->dp+1;
                pr=p-lst;
            }
            cur.alpha[i]++;
        }
    }
    void prt(word* lst)
    {
        if(pr!=-1) lst[pr].prt(lst);
        printf("%s\n",str);
    }
};
word lst[10001];
int main()
{
    int re;
    scanf("%d ",&re);
    while(re--){
        int n=0;
        while(lst[n].read()) n++;
        sort(lst,lst+n);
        int index = 0;
        for(int i=0;i<n;i++){
            lst[i].doit(lst,n);
            if(lst[i].dp>lst[index].dp) index=i;
        }
        lst[index].prt(lst);
        if(re) putchar('\n');
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2683903 2007-11-24 00:43:43 Accepted 2349 C++ 00:00.48 1808K わたし

// 2012-09-07 01:20:18 | Accepted | 2349 | C++ | 190 | 1548 | watashi | Source
