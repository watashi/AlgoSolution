#include <iostream>
#include <algorithm>
using namespace std;
class fraction{
private:
    long long numerator;
    long long denominator;//>0!
    inline long long gcd(long long a,long long b)
    {
        if(b==0) return a;
        else return gcd(b,a%b);
    }
    inline fraction format()
    {
        long long c=gcd(denominator,(numerator>=0)?numerator:-numerator);

        denominator/=c;
        numerator/=c;
        return *this;
    }
public:
    fraction()
    {
        this->denominator=1;
        this->numerator=0;
    }
    fraction(const long long &x)
    {
        this->denominator=1;
        this->numerator=x;
    }
    fraction(const long long &num,const long long &den)
    {
        this->denominator=den;
        this->numerator=num;
        format();
    }
    fraction(const fraction &x)
    {
        this->denominator=x.denominator;
        this->numerator=x.numerator;
    }
    inline long long num() const
    {
        return this->numerator;
    }
    inline long long den() const
    {
        return this->denominator;
    }
    inline fraction abs() const
    {
        fraction res=*this;

        if(res.numerator<0) res.numerator=-res.numerator;
        return res;
    }
    inline fraction operator=(const long long &that)
    {
        this->denominator=1;
        this->numerator=that;
        return *this;
    }
    inline fraction operator=(const fraction &that)
    {
        this->denominator=that.denominator;
        this->numerator=that.numerator;
        return *this;
    }
    inline fraction operator+(const fraction &that) const
    {
        fraction res;

        res.denominator=this->denominator*that.denominator;
        res.numerator=this->numerator*that.denominator+this->denominator*that.numerator;
        return res.format();
    }
    inline fraction operator-(const fraction &that) const
    {
        fraction res;

        res.denominator=this->denominator*that.denominator;
        res.numerator=this->numerator*that.denominator-this->denominator*that.numerator;
        return res.format();
    }
    inline bool operator==(const fraction &that) const
    {
        return this->denominator==that.denominator && this->numerator==that.numerator;
    }
    inline bool operator<(const fraction &that) const
    {
        return this->numerator*that.denominator-this->denominator*that.numerator<0;
    }
    inline bool operator>(const fraction &that) const
    {
        return this->numerator*that.denominator-this->denominator*that.numerator>0;
    }
    friend inline istream& operator>>(istream& is,fraction& x)
    {
        cin>>x.numerator>>x.denominator;
        x.format();
        return is;
    }
    friend inline ostream& operator<<(ostream& os,const fraction &x)
    {
        cout<<x.numerator<<"/"<<x.denominator;
        return os;
    }
};
fraction make(const fraction &sou,const long long den)
{
    /*int flag=(sou.num()>=0)?1:-1;
    int num=den*sou.num()/sou.den();*/
    long long num=den*sou.num()/sou.den();
    fraction a(num,den),b(num+1,den);

    return ((a-sou).abs()<(b-sou).abs())?a:b;
}
int main()
{
    bool blank=false;
    fraction tmp,ans,eps;

    while(cin>>ans){
        if(blank) cout<<endl;
        else blank=true;
        for(int i=1;i<=ans.den();i++){
            tmp=make(ans,i);
            if(i==1||(tmp-ans).abs()<eps){
                cout<<tmp<<endl;
                eps=(tmp-ans).abs();
            }
        }
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2655791 2007-10-23 20:00:52 Accepted 1218 C++ 00:00.02 840K ¤ï¤¿¤·

// 2012-09-07 00:42:08 | Accepted | 1218 | C++ | 10 | 188 | watashi | Source
