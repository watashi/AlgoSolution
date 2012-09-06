/*
#include <stdio.h>
int main()
{
    static char ascll[128];
    int i;
    char ch,end[11]="ENDOFINPUT";

    for(i=0;i<=127;i++)
        ascll[i]=i;
    for(i=70;i<=90;i++)
        ascll[i]=i-5;
    for(i=65;i<70;i++)
        ascll[i]=i+21;
    for(;;){
        scanf("START\n");
        while((ch=getchar())!='\n'){
            printf("%c",ascll[ch]);
        }
        printf("\n");
        scanf("END\n");
        if(scanf("ENDOFINPUT\n")) break;
    }
}
*/
#include <stdio.h>
int main()
{
    static char ascll[128],message[108];
    int i,n,end=0;
    char ch;

    for(i=0;i<=127;i++)
        ascll[i]=i;
    for(i=70;i<=90;i++)
        ascll[i]=i-5;
    for(i=65;i<70;i++)
        ascll[i]=i+21;
    for(;;){
        ch='?';
        while(1){
            if(ch=='S'){
                if((ch=getchar())=='T')
                if((ch=getchar())=='A')
                if((ch=getchar())=='R')
                if((ch=getchar())=='T')
                break;
            }
            else if(ch=='E'){
                if((ch=getchar())=='N')
                if((ch=getchar())=='D')
                if((ch=getchar())=='O')
                if((ch=getchar())=='F')
                if((ch=getchar())=='I')
                if((ch=getchar())=='N')
                if((ch=getchar())=='P')
                if((ch=getchar())=='U')
                if((ch=getchar())=='T')
                end=1;
                break;
            }
            else ch=getchar();
        }
        if(end) break;
        while((message[0]=getchar())=='\n');
        for(i=1;i<108;i++){
            message[i]=getchar();
            if(message[i]=='D'&&i>1)
                if(message[i-1]=='N'&&message[i-2]=='E')
                    break;
        }
        n=i;
        for(i=0;i<=n-3;i++)
            if(ascll[message[i]]!='\n') printf("%c",ascll[message[i]]);
        printf("\n");
    }

    return 0;   /* NZEC */
}

/*always Presentation Error,at least 10 times*/
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2469493 2007-05-29 12:24:36 Accepted 1392 C 00:00.00 388K ¤ï¤¿¤· */

// 2012-09-07 03:00:43 | Accepted | 1392 | C | 0 | 160 | watashi | Source
