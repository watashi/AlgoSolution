#include <cstdio> // auto fix CE
#include <stdio.h>
typedef struct{
int a[7];
}status;
const status original={31,4,4,4,4,4,4};
const int change='A'+'B';
int doit(const status o)//&o::C++ 00:00.20 440K
{
    int i;
    status t;

    for(i=1;i<=6;i++){
        if(o.a[0]-i<0) break;
        if(o.a[i]==0) continue;
        else{
            t=o;
            t.a[i]--;
            t.a[0]-=i;
            if(doit(t)==0) return 1;
        }
    }
    return 0;
}
int main(){
    char str[30],ch;
    int i;
    status origin;

    while(gets(str)){
        origin=original;
        ch='A';
        for(i=0;str[i];i++){
            ch=change-ch;
            origin.a[str[i]-'0']--;
            origin.a[0]-=str[i]-'0';
        }
        printf("%s %c\n",str,doit(origin)?ch:(change-ch));
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2596327 2007-09-04 20:14:33 Accepted 1827 C 00:00.24 396K わたし
/*
#include <cstdio> // auto fix CE
#include <stdio.h>
typedef struct{
int a[7];
}status;
const status original={31,4,4,4,4,4,4};
const int change='A'+'B';
int doit(status o)
{
    int i;

    for(i=1;i<=6;i++){
        if(o.a[0]-i<0) break;
        if(o.a[i]==0) continue;
        else{
            o.a[i]--;
            o.a[0]-=i;
            if(doit(o)==0) return 1;
            o.a[i]++;
            o.a[0]+=i;
        }
    }
    return 0;
}
int main(){
    char str[30],ch;
    int i;
    status origin;

    while(gets(str)){
        origin=original;
        ch='A';
        for(i=0;str[i];i++){
            ch=change-ch;
            origin.a[str[i]-'0']--;
            origin.a[0]-=str[i]-'0';
        }
        printf("%s %c\n",str,doit(origin)?ch:(change-ch));
    }
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2596335 2007-09-04 20:18:24 Accepted 1827 C 00:00.18 392K わたし
*/

/*
#include <cstdio> // auto fix CE
#include <stdio.h>
typedef struct{
int a[7];
}status;
const status original={31,4,4,4,4,4,4};
const int change='A'+'B';
int doit(const status &o)//cpp
{
    int i;
    status t;

    t=o;
    for(i=1;i<=6;i++){
        if(o.a[0]-i<0) break;
        if(o.a[i]==0) continue;
        else{
            t.a[i]--;
            t.a[0]-=i;
            if(doit(t)==0) return 1;
            t.a[i]++;
            t.a[0]+=i;
        }
    }
    return 0;
}
int main(){
    char str[30],ch;
    int i;
    status origin;

    while(gets(str)){
        origin=original;
        ch='A';
        for(i=0;str[i];i++){
            ch=change-ch;
            origin.a[str[i]-'0']--;
            origin.a[0]-=str[i]-'0';
        }
        printf("%s %c\n",str,doit(origin)?ch:(change-ch));
    }
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2596338 2007-09-04 20:20:22 Accepted 1827 C++ 00:00.19 440K わたし

*/

// 2012-09-07 14:09:11 | Accepted | 1827 | C++ | 80 | 180 | watashi | Source
