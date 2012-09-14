#include <cstdio>
#define alpha2int(x) ((x)-'A')
#define alpha2bit(x) (1<<alpha2int(x))
class SET{
private:
    int data;
public:
    SET()
    {
        data=0;
    }
    SET(const SET &that)
    {
        data=that.data;
    }
    SET(const char str[])
    {
        data=0;
        for(int i=1;str[i]!='}';i++)
            data|=alpha2bit(str[i]);
    }
    void init(const char str[])
    {
        SET ret(str);
        *this=ret;
    }
    inline SET operator+(const SET &that) const
    {
        SET ret;

        ret.data=data|that.data;
        return ret;
    }
    inline SET operator+=(const SET &that)
    {
        return *this=*this+that;
    }
    inline SET operator-(const SET &that) const
    {
        SET ret;

        ret.data=data&(~that.data);
        return ret;
    }
    inline SET operator-=(const SET &that)
    {
        return *this=*this-that;
    }
    inline SET operator*(const SET &that) const
    {
        SET ret;

        ret.data=data&that.data;
        return ret;
    }
    inline SET operator*=(const SET &that)
    {
        return *this=*this*that;
    }
    void show() const
    {
        putchar('{');
        for(int i=0;i<26;i++)
            if(data&(1<<i)) putchar('A'+i);
        putchar('}');
    }
};
SET calc(const char str[]);
SET calc2(const char str[]);
SET calc2(const char str[])
{
    SET ret("{ABCDEFGHIJKLMNOPQRSTUVWXYZ}"),cur;
    char op='*',ch[255];
    int i,j,k;

    for(i=0;op;){
        if(str[i]=='('){
            for(j=0,k=1,++i;k;i++){
                if(str[i]=='(') k++;
                else if(str[i]==')') k--;
                ch[j++]=str[i];
            }
            ch[j-1]='\0';
            cur=calc(ch);
        }
        else{
            for(j=0;str[i]!='}';i++)
                ch[j++]=str[i];
            ch[j++]=str[i++];ch[j]='\0';
            cur.init(ch);
        }
        switch(op){
        case '*':ret*=cur;break;
        }
        op=str[i];
        i++;
    }
return ret;
}
SET calc(const char str[])
{
    SET ret("{}"),cur;
    char op='+',ch[255];
    int i,j,k;

    for(i=0;op;){
        for(j=k=0;k||(str[i]&&str[i]!='+'&&str[i]!='-');i++){
            if(str[i]=='(') k++;
            else if(str[i]==')') k--;
            ch[j++]=str[i];
        }
        ch[j]='\0';
        cur=calc2(ch);
        switch(op){
        case '+':ret+=cur;break;
        case '-':ret-=cur;break;
        }
        op=str[i];
        i++;
    }
    return ret;
}
int main()
{
    char str[300];

    while(gets(str)){
        calc(str).show();
        putchar('\n');
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2646539 2007-10-16 12:55:16 Accepted 1958 C++ 00:00.00 432K ¤ï¤¿¤·

// 2012-09-07 01:08:24 | Accepted | 1958 | C++ | 0 | 180 | watashi | Source
