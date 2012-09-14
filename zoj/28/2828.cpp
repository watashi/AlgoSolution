#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int re;
    cin>>re;
    while(re--){
        int n;
        cin>>n;
        string tmp;
        vector<string> dict;
        dict.clear();
        for(int i=0;i<n;i++){
            cin>>tmp;
            dict.push_back(tmp);
        }
        int m;
        cin>>m;
        while(m--){
            int i,j;
            string word,temp;
            cin>>word;
            for(i=0;i<n;i++)
                if(dict[i]==word) break;
            if(i<n){
                cout<<word<<endl;
                continue;
            }
            vector<string> ans;
            ans.clear();
            for(i=1;i<word.length();i++){
                temp=word;
                swap(temp[i-1],temp[i]);
                for(j=0;j<n;j++)
                    if(dict[j]==temp) break;
                if(j<n) ans.push_back(temp);
            }
            if(ans.empty()){
                cout<<word<<endl;
                continue;
            }
            sort(ans.begin(),ans.end());
            vector<string>::iterator itr;
            itr=ans.begin();
            cout<<*itr;
            for(itr++;itr!=ans.end();++itr)
                cout<<","<<*itr;
            cout<<endl;
        }
        if(re) cout<<endl;
    }
}
/*
Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
2591439 2007-09-01 00:35:09 Accepted 2828 C++ 00:00.05 856K ¤ï¤¿¤·
*/

// 2012-09-07 01:41:34 | Accepted | 2828 | C++ | 20 | 188 | watashi | Source
