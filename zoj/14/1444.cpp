#include <map>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
class record{
public:
    char id[33];
    int prob[101];
    int ac,t;
    bool operator<(const record &r) const
    {
        if(ac==r.ac){
            if(t==r.t){
                string a(id),b(r.id);

                for(int i=0;i<a.length();i++)
                    a[i]=toupper(a[i]);
                for(int i=0;i<b.length();i++)
                    b[i]=toupper(b[i]);
                return a<b;
            }
            else return t<r.t;
        }
        else return ac>r.ac;
    }
};
int n,m;
map<string,int> mp;
record team[10001];
int t;char id[33];int prob;char ret[5];
int main()
{
    scanf("%d",&n);
    m=0;
    memset(team,0,sizeof(team));
    while(scanf("%d%s%d%s",&t,id,&prob,ret)!=EOF){
        if(mp.find((string)id)==mp.end()){
            mp.insert(make_pair((string)id,m));
            strcpy(team[m].id,id);
            n=m++;
        }
        else n=mp[(string)id];
        if(team[n].prob[prob]==1) continue;
        else{
            if(*ret=='A'){team[n].t+=t-team[n].prob[prob]*20;team[n].ac++;team[n].prob[prob]=1;}
            else team[n].prob[prob]--;
        }
    }
    sort(team,team+m);
    for(int i=0;i<m;i++){
        if(!team[i].ac) break;
        if(!i||team[i].ac!=team[i-1].ac||team[i].t!=team[i-1].t) printf("%-10d",i+1);
        else printf("%10s"," ");
        printf("%-30s%-10d%d\n",team[i].id,team[i].ac,team[i].t);
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2639769 2007-10-10 21:06:39 Accepted 1444 C++ 00:00.41 5268K ¤ï¤¿¤·

// 2012-09-07 00:49:39 | Accepted | 1444 | C++ | 180 | 4556 | watashi | Source
