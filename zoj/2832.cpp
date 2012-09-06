#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
string tmp;
vector<string> a;
set<string> b;
int main()
{
    int n;
    bool blank=0;
    while(cin>>n){
        if(blank) cout<<endl;
        else blank=1;
        a.clear();
        b.clear();
        for(int i=0;i<n;i++){
            cin>>tmp;
            a.push_back(tmp);
            int m;
            cin>>m;
            for(int j=0;j<m;j++){
                cin>>tmp;
                b.insert(tmp);
            }
        }
        vector<string>::iterator itr;
        vector<string> ans;
        ans.clear();
        for(itr=a.begin();itr!=a.end();++itr)
            if(b.find(*itr)==b.end()) ans.push_back(*itr);
        sort(ans.begin(),ans.end());
        for(itr=ans.begin();itr!=ans.end();++itr)
            cout<<*itr<<endl;
    }
}
/*
Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
2591490 2007-09-01 03:00:56 Accepted 2832 C++ 00:00.04 860K ¤ï¤¿¤·
*/

// 2012-09-07 01:41:58 | Accepted | 2832 | C++ | 10 | 188 | watashi | Source
