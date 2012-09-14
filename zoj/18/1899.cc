#include <map>
#include <cstdio>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;
int main()
{
    char str[1024];
    int blank=0;
    while(gets(str)){
        if(blank) printf("\n");
        else blank=1;
        int n=0;
        map<string ,int > mp;
        do{
            n++;
            string cur(str);
            if(mp.find(cur)==mp.end()){
                mp.insert(make_pair(cur,1));
            }
            else mp[cur]++;
        }while(gets(str)&&*str);
        for(map<string, int >::iterator itr=mp.begin();itr!=mp.end();++itr){
            printf("%s %.4lf\n",itr->first.c_str(),100.0*(double)itr->second/n);
        }
    }
}
//STL 美
//hash ...//
//有机会用C写写 -_-//
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2651841 2007-10-20 16:01:20 Accepted 1899 C++ 00:05.36 960K わたし
/*
Rank Submit time Run time Run memory Language User
1 2007-06-09 04:28:45 00:00.89 948K C++ 9911
*/

// 2012-09-07 01:05:00 | Accepted | 1899 | C++ | 3020 | 180 | watashi | Source
