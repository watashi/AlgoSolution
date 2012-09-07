/*
#include <utility> // auto fix CE
#include <cstring> // auto fix CE
#include <utility> // auto fix CE
#include <set>
#include <utility> // auto fix CE
#include <cstring> // auto fix CE
#include <utility> // auto fix CE
#include <map>
#include <utility> // auto fix CE
#include <cstring> // auto fix CE
#include <utility> // auto fix CE
#include <string>
#include <utility> // auto fix CE
#include <cstring> // auto fix CE
#include <utility> // auto fix CE
#include <iostream>
using namespace std;
set<string> st;
map<string,string> mp;
int main()
{
    int ri=0;
    string root;
    while(cin>>root){
        if(ri) cout<<endl;
        int n;
        mp.clear();
        cin>>n;
        while(n--){
            string child,father;
            cin>>child>>father;
            mp.insert(make_pair(child,father));
        }
        int m;
        st.clear();
        cin>>m;
        while(m--){
            string cur;
            cin>>cur;
            st.insert(cur);
        }
        int l;
        cout << "Function " << ++ri << endl;
        cin>>l;
        while(l--){
            string ans;
            cin>>ans;
            while(st.find(ans)==st.end()){
                if(mp.find(ans)==mp.end()){
                    ans="Exception";
                    break;
                }
                else ans=mp[ans];
            }
            cout<<ans<<endl;
        }
    }
}
*/
//TLE
/*
#include <utility> // auto fix CE
#include <cstring> // auto fix CE
#include <utility> // auto fix CE
#include <set>
#include <utility> // auto fix CE
#include <cstring> // auto fix CE
#include <utility> // auto fix CE
#include <map>
#include <utility> // auto fix CE
#include <cstring> // auto fix CE
#include <utility> // auto fix CE
#include <string>
#include <utility> // auto fix CE
#include <cstring> // auto fix CE
#include <utility> // auto fix CE
#include <cstdio>
using namespace std;
set<string> st;
map<string,string> mp;
char buf[512];
int main()
{
    int ri=0;
    while(scanf("%s",buf)!=EOF){
        string root(buf);
        if(ri) putchar('\n');
        int n;
        mp.clear();
        scanf("%d",&n);
        while(n--){
            scanf("%s",buf);
            string child(buf);
            scanf("%s",buf);
            string father(buf);
            mp.insert(make_pair(child,father));
        }
        int m;
        st.clear();
        scanf("%d",&m);
        while(m--){
            scanf("%s",buf);
            st.insert((string)buf);
        }
        int l;
        printf("Function %d\n",++ri);
        scanf("%d",&l);
        while(l--){
            scanf("%s",buf);
            string ans(buf);
            while(st.find(ans)==st.end()){
                if(mp.find(ans)==mp.end()){
                    ans="Exception";
                    break;
                }
                else ans=mp[ans];
            }
            printf("%s\n",ans.c_str());
        }
    }
}
*/
//TLE
#include <utility> // auto fix CE
#include <cstring> // auto fix CE
#include <utility> // auto fix CE
#include <map>
#include <utility> // auto fix CE
#include <cstring> // auto fix CE
#include <utility> // auto fix CE
#include <vector>
#include <utility> // auto fix CE
#include <cstring> // auto fix CE
#include <utility> // auto fix CE
#include <cstdio>
#include <utility> // auto fix CE
#include <cstring> // auto fix CE
#include <utility> // auto fix CE
#include <string>
using namespace std;
char buf[256];
int a[60000];
bool b[60000];
vector<string> vs;
map<string,int> mp;
inline int mapped(const char *p)
{
    string cur(p);
    if(mp.find(cur)==mp.end()){
        mp.insert(make_pair(cur,mp.size()));
        vs.push_back(cur);
        return mp.size()-1;
    }
    else return mp[p];
}
inline int findup(int t)
{
    if(t==-1) return -1;
    else if(b[t]) return t;
    else return a[t]=findup(a[t]);//Â·¾¶Ñ¹Ëõ
}
int main()
{
    int ri=0;
    while(scanf("%s",buf)!=EOF){
        if(ri) printf("\n");
        memset(a,0xff,sizeof(a));
        memset(b,0,sizeof(b));
        mp.clear();
        vs.clear();
        mapped(buf);
        int i,j,k;
        scanf("%d",&k);
        while(k--){
            scanf("%s",buf);
            i=mapped(buf);
            scanf("%s",buf);
            j=mapped(buf);
            a[i]=j;
        }
        scanf("%d",&k);
        while(k--){
            scanf("%s",buf);
            b[mapped(buf)]=true;
        }
        printf("Function %d\n",++ri);
        scanf("%d",&k);
        while(k--){
            scanf("%s",buf);
            i=findup(mapped(buf));
            printf("%s\n",(i==-1)?"Exception":vs[i].c_str());
        }
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2676769 2007-11-15 13:42:15 Accepted 2862 C++ 00:01.62 4080K ¤ï¤¿¤·

// 2012-09-07 14:05:40 | Accepted | 2862 | C++ | 700 | 2716 | watashi | Source
