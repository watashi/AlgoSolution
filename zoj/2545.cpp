#include <cstdio>
class bigdouble{
private:
    double data_a;
    long data_e;
public:
    void format()
    {
        while(data_a>=10){data_a/=10;data_e++;}
        while(data_a<1){data_a*=10;data_e--;}
    }
    bool operator<(const bigdouble &r) const
    {
        if(data_e==r.data_e) return data_a<r.data_a;
        else return data_e<r.data_e;
    }
    bool operator==(const bigdouble &r) const
    {
        return (data_e==r.data_e&&data_a==r.data_a);
    }
    bool operator<=(const bigdouble &r) const
    {
        return *this<r||*this==r;
    }
    bigdouble operator*(const int &r) const
    {
        bigdouble res;
        res.data_a=data_a*r;
        res.data_e=data_e;
        res.format();
        return res;
    }
    bigdouble operator*(const bigdouble &r) const
    {
        bigdouble res;
        res.data_a=data_a*r.data_a;
        res.data_e=data_e+r.data_e;
        res.format();
        return res;
    }
    bigdouble operator=(const double &r)
    {
        data_a=r;
        data_e=0;
        format();
        return *this;
    }
    bigdouble operator=(const bigdouble &r)
    {
        data_a=r.data_a;
        data_e=r.data_e;
        format();
        return *this;
    }
};
int main()
{
    int i,j,ans[21];
    bigdouble fact,bin;

    fact=1;
    bin=4;
    j=1;
    for(i=0;i<21;i++){
        bin=bin*bin;
        while(fact<=bin) fact=fact*j++;
        ans[i]=j-2;
    }
    while(scanf("%d",&i)!=EOF && i){
        j=(i-1960)/10;
        printf("%d\n",ans[j]);
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2627702 2007-10-01 20:46:01 Accepted 2545 C++ 00:00.05 392K ¤ï¤¿¤·

// 2012-09-07 01:27:34 | Accepted | 2545 | C++ | 20 | 180 | watashi | Source
