//trick多
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <cstdio>
using namespace std;
int main()
{
    int ri = 0;
    int i,j,f,t;

    while(scanf("%d%d",&i,&j)!=EOF && (i!=-1||j!=-1) ){
        if(i==0 && j==0){
            printf("Case %d is a tree.\n",++ri);
            continue;
        }
        map<int,int> mp;
        set<int> root;
        vector<bool> mark;
        vector<vector<int> > node;
        do{
            if(mp.find(i)==mp.end()){
                mp.insert(make_pair(i,f=mp.size()));
                mark.push_back(false);
                node.push_back(vector<int>() );
                root.insert(f);
            }
            else f=mp[i];
            if(mp.find(j)==mp.end()){
                mp.insert(make_pair(j,t=mp.size()));
                mark.push_back(false);
                node.push_back(vector<int>() );
            }
            else t=mp[j];
            node[f].push_back(t);
            if(root.find(t)!=root.end()) root.erase(t);
        }while(scanf("%d%d",&i,&j)!=EOF && (i||j) );
        if(root.size()!=1){
            printf("Case %d is not a tree.\n",++ri);
            continue;
        }
        try{
            f=*root.begin();
            queue<int> q;
            q.push(f);
            mark[f]=true;
            while(!q.empty()){
                f=q.front();
                for(vector<int>::iterator itr=node[f].begin();itr!=node[f].end();++itr){
                    t=*itr;
                    if(mark[t]) throw 1;
                    mark[t]=true;
                    q.push(t);
                }
                q.pop();
            }
            for(vector<bool>::iterator itr=mark.begin();itr!=mark.end();++itr)
                if(*itr==false) throw 1;
        }
        catch(int e)
        {
            printf("Case %d is not a tree.\n",++ri);
            continue;
        }
        printf("Case %d is a tree.\n",++ri);
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2686281 2007-11-26 21:13:13 Accepted 1268 C++ 00:00.00 872K 再做几题改成Fire
//第一次用try~
/*
ZOJ_Fire 事件~

*/

// 2012-09-07 00:43:39 | Accepted | 1268 | C++ | 0 | 180 | watashi | Source
