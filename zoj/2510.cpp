#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int main()
{
    int i,n,m,a,b;
    vector<pair<int,int> > ring;

    while(scanf("%d",&n)!=EOF){
        ring.clear();
        for(i=0;i<n;i++){
            scanf("%d%d",&a,&b);
            ring.push_back(make_pair(a,b));
        }
        sort(ring.begin(),ring.end());
        for(m=1,i=n-1,a=ring[i].first;i>=0;i--)
            if(ring[i].second<=a){a=ring[i].first;m++;}
        printf("%d\n",n-m);
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2627777 2007-10-01 21:20:49 Accepted 2510 C++ 00:00.11 840K ¤ï¤¿¤·

// 2012-09-07 01:25:50 | Accepted | 2510 | C++ | 30 | 312 | watashi | Source
