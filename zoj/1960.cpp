#include <set>
#include <map>
#include <vector>
#include <cstdio>
#include <string>
#include <utility>
#include <cstring>
#include <algorithm>
using namespace std;
class Group
{
private:
    int size;
    set<string> st;
public:
    Group():size(0){}
    void insert(const string &cur)
    {
        size++;
        st.insert(cur);
    }
    void show()
    {
        printf("Group of size %d: ",size);
        for(set<string>::iterator itr=st.begin();itr!=st.end();++itr)
            printf("%s ",itr->c_str());
        printf(".\n");
    }
    bool operator<(const Group &that) const
    {
        if(size==that.size) return *(st.begin())<*(that.st.begin());
        else return size>that.size;
    }
};
vector<Group> vt;
map<string,int> mp;
int main()
{
    set<Group> st;
    char str[64];
    while(scanf("%s",str)!=EOF){
        string cur,tmp;
        cur=(string)str;
        sort(str,str+strlen(str));
        tmp=(string)str;
        int index;
        if(mp.find(tmp)==mp.end()){
            index=mp.size();
            mp.insert(make_pair(tmp,index));
            vt.push_back(Group());
        }
        else index=mp[tmp];
        vt[index].insert(cur);
    }
    sort(vt.begin(),vt.end());
    for(int i=0;i<5&&i<vt.size();i++)
        vt[i].show();
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2684495 2007-11-24 19:24:58 Accepted 1960 C++ 00:00.26 2264K ¤ï¤¿¤·

// 2012-09-07 01:08:30 | Accepted | 1960 | C++ | 90 | 1912 | watashi | Source
