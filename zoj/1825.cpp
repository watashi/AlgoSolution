#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string cur;
    vector<string> str;
    while(cin>>cur){str.push_back(cur);}
//  sort(str.begin(),str.end());//ÒÑÖª
    int len;
    set<string> ans;
    vector<string>::iterator itr,tmp;
    for(itr=str.begin();itr!=str.end();++itr){
        for(len=(int)(*itr).length(),tmp=itr+1;tmp!=str.end()&&*itr==(*tmp).substr(0,len);tmp++){
            if(binary_search(str.begin(),str.end(),(*tmp).substr(len))) ans.insert(*tmp);
        }
    }
    for(set<string>::iterator itr=ans.begin();itr!=ans.end();++itr)
        cout<<*itr<<endl;
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2633611 2007-10-05 19:37:13 Accepted 1825 C++ 00:00.27 1396K ¤ï¤¿¤·

// 2012-09-07 01:02:03 | Accepted | 1825 | C++ | 80 | 980 | watashi | Source
