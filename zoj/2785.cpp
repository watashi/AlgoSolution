#include <string>
#include <iostream>
using namespace std;
#define SIZE 8000
#define OVER 32000
#define ERROR 0xffff
class operand{
public:
    char mod;
    int num;
    void clear()
    {
        mod='#';
        num=0;
    }
    void get()
    {
        cin>>mod>>num;
        num%=SIZE;
        if(num<0) num+=SIZE;
    }
    bool operator==(const operand &r) const
    {
        return (mod==r.mod&&num==r.num);
    }
};
class instruction{
public:
    string opcode;
    operand A,B;
    void clear()
    {
        opcode="DAT";
        A.clear();
        B.clear();
    }
    void get()
    {
        cin>>opcode;
        A.get();
        B.get();
    }
    bool operator==(const instruction &r) const
    {
        return (opcode==r.opcode&&A==r.A&&B==r.B);
    }
};
class memory{
private:
    instruction mem[SIZE];
    int ip[2];
    inline int format(const int &x) const
    {
        int ret=x%SIZE;
        if(ret<0) return ret+SIZE;
        else return ret;
    }
    inline int immediate(const int &ip,const int &x) const
    {
        return format(x);
    }
    inline int direct(const int &ip,const int &x) const
    {
        return format(ip+x);
    }
    inline int indirect(const int &ip,const int &x) const
    {
        int cur=direct(ip,x);
        return direct(cur,mem[cur].B.num);
    }
    inline int address(const int &ip,const operand &X) const
    {
        switch(X.mod){
        case '#':return immediate(ip,X.num);
        case '$':return direct(ip,X.num);
        case '@':return indirect(ip,X.num);
        default:return ERROR;
        }
    }
    inline int DAT(const int &ip)
    {
        return -1;
    }
    inline int MOV(const int &ip)
    {
        if(mem[ip].A.mod=='#'){
            mem[address(ip,mem[ip].B)].B.num=mem[ip].A.num;
            return format(ip+1);
        }
        else{
            mem[address(ip,mem[ip].B)]=mem[address(ip,mem[ip].A)];
            return format(ip+1);
        }
    }
    inline int ADD(const int &ip)
    {
        if(mem[ip].A.mod=='#'){
            mem[address(ip,mem[ip].B)].B.num+=mem[ip].A.num;
            mem[address(ip,mem[ip].B)].B.num%=SIZE;
            return format(ip+1);
        }
        else{
            mem[address(ip,mem[ip].B)].A.num+=mem[address(ip,mem[ip].A)].A.num;
            mem[address(ip,mem[ip].B)].A.num%=SIZE;
            mem[address(ip,mem[ip].B)].B.num+=mem[address(ip,mem[ip].A)].B.num;
            mem[address(ip,mem[ip].B)].B.num%=SIZE;
            return format(ip+1);
        }
    }
    inline int JMP(const int &ip)
    {
        return address(ip,mem[ip].A);
    }
    inline int JMZ(const int &ip)
    {
        if(mem[address(ip,mem[ip].B)].B.num==0) return address(ip,mem[ip].A);
        else return format(ip+1);
    }
    inline int SLT(const int &ip)
    {
        if(mem[ip].A.mod=='#'){
            return (mem[ip].A.num<mem[address(ip,mem[ip].B)].B.num)?format(ip+2):format(ip+1);
        }
        else{
            return (mem[address(ip,mem[ip].A)].B.num<mem[address(ip,mem[ip].B)].B.num)?format(ip+2):format(ip+1);
        }
    }
    inline int CMP(const int &ip)
    {
        return (mem[address(ip,mem[ip].A)]==mem[address(ip,mem[ip].B)])?format(ip+2):format(ip+1);
    }
public:
    void clear()
    {
        for(int i=0;i<SIZE;i++)
            mem[i].clear();
    }
    void get()
    {
        int m;
        cin>>m>>ip[0];
        ip[0]=format(ip[0]);
        for(int i=0;i<m;i++)
            mem[format(ip[0]+i)].get();
        cin>>m>>ip[1];
        ip[1]=format(ip[1]);
        for(int i=0;i<m;i++)
            mem[format(ip[1]+i)].get();
    }
    int run(const int &ip)
    {
        if(mem[ip].opcode=="DAT") return DAT(ip);
        else if(mem[ip].opcode=="MOV") return MOV(ip);
        else if(mem[ip].opcode=="ADD") return ADD(ip);
        else if(mem[ip].opcode=="JMP") return JMP(ip);
        else if(mem[ip].opcode=="JMZ") return JMZ(ip);
        else if(mem[ip].opcode=="SLT") return SLT(ip);
        else if(mem[ip].opcode=="CMP") return CMP(ip);
        else return ERROR;
    }
    int autorun()
    {
        int i;

        for(i=0;i<OVER;){
            ip[0]=run(ip[0]);
            if(ip[0]==-1) break;
            i++;
            ip[1]=run(ip[1]);
            if(ip[1]==-1) break;
            i++;
        }
        return i;
    }
};
typedef memory MARS;
/*********************************************************************************/
int main()
{
    int re,ret;
    MARS mars;

    cin >> re;
    while(re--){
        mars.clear();
        mars.get();
        ret=mars.autorun();
        if(ret==OVER) cout<<"Programs are tied."<<endl;
        else cout<<"Program #"<<((ret&1)?1:2)<<" is the winner."<<endl;
    }
    return 0;
}
/*********************************************************************************/
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2646020 2007-10-15 20:36:26 Accepted 2785 C++ 00:00.08 1120K ¤ï¤¿¤·

/*
2
3
185
ADD #4 $2
JMP $-1 #0
DAT #0 #-3
5
100
JMP $2 #0
DAT #0 #-1
ADD #5 $-1
MOV $-2 @-2
JMP $-2 #0
1
5524
MOV $0 $1
5
539
JMP $2 #0
DAT #0 #-1
ADD #5 $-1
MOV $-2 @-2
JMP $-2 #0
*/

// 2012-09-07 01:39:44 | Accepted | 2785 | C++ | 20 | 320 | watashi | Source
