#include <cctype>
#include <cstdio>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    char ch[128],str[1024];
    int ri,n,m;

    ri=0;
    while(scanf("%d%d",&n,&m)!=EOF){
        set<string> word;
        word.clear();
        while(n--){
            scanf("%s ",str);
            word.insert((string)str);
        }
        int cur=0;
        vector<string> ans;
        ans.clear();
        while(m--){
            int i,j;
            int tmp=0;
            gets(str);
            for(i=0;str[i];){
                if(isalpha(str[i])){
                    for(j=0;isalpha(str[i+j]);j++)
                        ch[j]=tolower(str[i+j]);//
                    ch[j]='\0';
                    if(word.find((string)ch)!=word.end()) tmp++;
                    i=i+j;
                }
                i++;
            }
            if(tmp==cur) ans.push_back((string)str);
            else if(tmp>cur){
                cur=tmp;
                ans.clear();
                ans.push_back((string)str);
            }
        }
        printf("Excuse Set #%d\n",++ri);
        for(vector<string>::iterator itr=ans.begin();itr!=ans.end();++itr)
            printf("%s\n",(*itr).c_str());
        printf("\n");
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2630777 2007-10-03 21:30:43 Accepted 1315 C++ 00:00.00 848K ¤ï¤¿¤·

// 2012-09-07 00:45:35 | Accepted | 1315 | C++ | 0 | 180 | watashi | Source
