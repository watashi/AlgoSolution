#include <cstring> // auto fix CE
#include <map>
#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int a,b,c[3],i,flag;
    map<int,int> e;
    vector<pair<int,int> > p;

    while(cin>>a>>b){
        e.clear();
        p.clear();
        if(e.find(a)==e.end()) e.insert(make_pair(a,e.size()));
        if(e.find(b)==e.end()) e.insert(make_pair(b,e.size()));
        p.push_back(make_pair(min(a,b),max(a,b)));
        for(i=1;i<6;i++){
            cin>>a>>b;
            if(e.find(a)==e.end()) e.insert(make_pair(a,e.size()));
            if(e.find(b)==e.end()) e.insert(make_pair(b,e.size()));
            p.push_back(make_pair(min(a,b),max(a,b)));
        }
        sort(p.begin(),p.end());
        memset(c,0,sizeof(c));
        if(e.size()>3) flag=0;
        else{
            flag=1;
            for(i=0;i<6;i++)
                c[e[p[i].first]+e[p[i].second]]++;
            for(i=0;i<3;i++)
                if(c[i]&1) flag=0;
        }
        cout<<(flag?"POSSIBLE":"IMPOSSIBLE")<<endl;
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2627440 2007-10-01 17:12:42 Accepted 2659 C++ 00:00.00 844K ¤ï¤¿¤·

// 2012-09-07 13:36:40 | Accepted | 2659 | C++ | 0 | 188 | watashi | Source
