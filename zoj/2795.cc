/*
#include <cstdio> // auto fix CE
#include <stdio.h>
int main()
{
    int i,n,a[100001];

    while(scanf("%d",&n),n){
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(i=1;i<=n;i++){
            if(a[i]==i) continue;
            else if(a[a[i]]==i) continue;
            break;
        }
        if(i<=n) printf("not ambiguous\n");
        else printf("ambiguous\n");
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2598286 2007-09-06 13:48:17 Accepted 2795 C 00:00.26 788K わたし
*/

/*
#include <cstdio> // auto fix CE
#include <stdio.h>
int main()
{
    char ch;
    int i,n,a[100001],*p;

    while(scanf("%d ",&n),n){

//      for(i=1,p=a+1;i<=n;i++,p++){
//          while((ch=getchar())==' ');
//          *p=ch-'0';
//          while((ch=getchar())!=' '&&ch!='\n'){
//              *p*=10;
//              *p+=ch-'0';
//          }
//      }

        for(i=1,p=a+1;i<n;i++,p++){
            while((ch=getchar())==' ');
            *p=ch-'0';
            while((ch=getchar())!=' '){
                *p*=10;
                *p+=ch-'0';
            }
        }
        while((ch=getchar())==' ');
            *p=ch-'0';
        while((ch=getchar())!='\n'){
            *p*=10;
            *p+=ch-'0';
        }//壓扮寂貧涙延晒��
        for(i=1;i<=n;i++){
            if(a[i]==i) continue;
            else if(a[a[i]]==i) continue;
            break;
        }
        if(i<=n) printf("not ambiguous\n");
        else printf("ambiguous\n");
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2598313 2007-09-06 14:06:21 Accepted 2795 C++ 00:00.15 784K わたし
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2598315 2007-09-06 14:07:42 Accepted 2795 C++ 00:00.15 780K わたし
*/

/*
#include <cstdio> // auto fix CE
#include <stdio.h>
int main()
{
    char ch;
    int i,n,a[100001],*p;

    while(scanf("%d ",&n),n){
        for(i=1,p=a+1;i<n;i++,p++){
            while((ch=getchar())==' ');
            *p=ch-'0';
            while((ch=getchar())!=' '){
                *p*=10;
                *p+=ch-'0';
            }
        }
        while((ch=getchar())==' ');
            *p=ch-'0';
        while((ch=getchar())!='\n'){
            *p*=10;
            *p+=ch-'0';
        }
        for(i=1,p=a+1;i<=n;i++,p++)
            if(*p!=i&&a[*p]!=i) break;
        if(i<=n) printf("not ambiguous\n");
        else printf("ambiguous\n");
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2598320 2007-09-06 14:10:22 Accepted 2795 C++ 00:00.14 784K わたし
*/


/*
#include <cstdio> // auto fix CE
#include <stdio.h>
int main()
{
    char ch;
    int i,n,a[100001],*p,flag;

    while(scanf("%d",&n),n){
        getchar();
        flag=0;
        for(i=1,p=a+1;i<=n;i++,p++){
            while((ch=getchar())==' ');
            *p=ch-'0';
            while((ch=getchar())!=' '&&ch!='\n'){
                *p*=10;
                *p+=ch-'0';
            }
            if(*p<i&&a[*p]!=i){
                flag=1;
                while(ch!='\n') ch=getchar();
                break;
            }
        }
        if(flag) printf("not ambiguous\n");
        else printf("ambiguous\n");
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2598339 2007-09-06 14:22:32 Accepted 2795 C++ 00:00.13 788K わたし
*/

/*
Rank Submit time Run time Run memory Language User
1 2007-05-25 23:39:42 00:00.02 1368K C++ 9911
2 2007-09-06 14:22:32 00:00.13 788K C++ わたし
3 2007-02-08 02:52:37 00:00.21 788K C mj
4 2007-03-05 21:11:17 00:00.28 1368K C++ Prinse
5 2007-04-05 19:34:59 00:00.30 792K FPC Media
6 2007-04-05 19:28:56 00:00.31 792K FPC T-mac
7 2007-08-06 11:58:42 00:00.32 788K FPC みいみいのあい
8 2007-03-05 20:38:50 00:00.32 796K FPC tinywolf
*/

/*
#include <cstdio> // auto fix CE
#include <stdio.h>
int main()
{
    char ch,line[500000];
    int i,n,a[100001],*p,flag;

    while(scanf("%d",&n),n){
        getchar();
        flag=0;
        for(i=1,p=a+1;i<=n;i++,p++){
            while((ch=getchar())==' ');
            *p=ch-'0';
            while((ch=getchar())!=' '&&ch!='\n'){
                *p*=10;
                *p+=ch-'0';
            }
            if(*p<i&&a[*p]!=i){
                flag=1;
                if(ch!='\n') gets(line);
                break;
            }
        }
        if(flag) printf("not ambiguous\n");
        else printf("ambiguous\n");
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2598396 2007-09-06 15:30:43 Accepted 2795 C 00:00.10 1760K わたし
*/


//...gets()!!!...0.02s
#include <cstdio> // auto fix CE
#include <stdio.h>
int main()
{
    char line[600000],*c;
    int i,n,a[100001],*p,flag;

    while(scanf("%d",&n),n){
        getchar();
        gets(line);
        c=line;
        flag=0;
        for(i=1,p=a+1;i<=n;i++,p++){
            while(*c==' ') c++;
            *p=*c-'0';
            c++;
            while(*c!=' '&&*c!='\0'){
                *p*=10;
                *p+=*c-'0';
                c++;
            }
            if(*p<i&&a[*p]!=i){
                flag=1;
                break;
            }
        }
        if(flag) printf("not ambiguous\n");
        else printf("ambiguous\n");
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2598403 2007-09-06 15:37:11 Accepted 2795 C 00:00.03 1364K わたし

// 2012-09-07 14:10:58 | Accepted | 2795 | C++ | 10 | 180 | watashi | Source
