#include <cstdlib> // auto fix CE
#include <cstring> // auto fix CE
#include <cmath>
#include <cstdio>
#include <string>
class Vector{
private:
    double x,y,z,mod;
public:
    void get()
    {
        scanf("%lf%lf%lf",&x,&y,&z);
        mod=sqrt(x*x+y*y+z*z);
    }
    double abs() const
    {
        return mod;
    }
    double operator*(const Vector &that) const
    {
        return x*that.x+y*that.y+z*that.z;
    }
};
int main()
{
    bool mark[500];
    Vector s[500],t;
    int i,n;

    while(scanf("%d",&n),n){
        for(i=0;i<n;i++)
            s[i].get();
        memset(mark,0,sizeof(bool)*n);
        int m;
        scanf("%d",&m);
        int ans=0;
        while(m--){
            t.get();
            double it;
            scanf("%lf",&it);
            it=cos(it);
            for(i=0;i<n;i++){
                if(mark[i]) continue;
                double tmp;
                tmp=(s[i]*t)/(s[i].abs()*t.abs());
                if(tmp>=it) {mark[i]=1;ans++;}
            }
        }
        printf("%d\n",ans);
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2611049 2007-09-16 17:43:15 Accepted 2819 C++ 00:00.05 412K わたし

/*
Rank Submit time Run time Run memory Language User
1 2007-03-08 11:45:10 00:00.04 416K C++ Liu
2 2007-08-23 14:23:43 00:00.04 456K C++ terranw
3 2007-07-29 16:26:45 00:00.04 856K C++ Tom Riddle
4 2007-07-30 16:11:00 00:00.05 408K C++ 何以解忧,唯有AC
5 2007-09-16 17:43:15 00:00.05 412K C++ わたし
6 2007-04-30 18:26:05 00:00.05 416K C++ 11
7 2007-07-12 00:11:54 00:00.05 416K C mj
8 2007-04-02 14:52:40 00:00.05 420K C++ Fire
9 2007-03-22 09:39:42 00:00.06 412K C++ SHOIT
10 2007-05-18 16:46:07 00:00.06 412K C++ 9911
11 2007-03-02 08:29:42 00:00.06 416K C++ 这个GMT+8准了...
12 2007-03-28 00:30:54 00:00.06 416K C++ 阿九
13 2007-05-03 16:48:39 00:00.06 416K C++ 杭之翼
14 2007-05-18 02:26:23 00:00.06 416K C Time Limit Exceeded
15 2007-06-07 17:51:19 00:00.06 416K C++ IS
16 2007-03-03 00:28:16 00:00.06 420K C++ 清风
17 2007-03-08 22:03:30 00:00.06 420K C++ katherine
18 2007-03-08 22:04:51 00:00.06 420K C++ KatherineZhang
19 2007-03-29 17:53:56 00:00.06 424K C++ van
20 2007-03-03 02:20:27 00:00.07 412K C++ qiuqiuqiu67
*/

// 2012-09-07 13:36:46 | Accepted | 2819 | C++ | 20 | 180 | watashi | Source
