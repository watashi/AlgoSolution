/*A, A# (A-sharp), B, C, C#, D, D#, E, F, F#, G, and finally G#. */
#include <stdio.h>
int notes=12;
int trans[125];
int main()
{
    char t[4][5];
    int i,j,k,flag,a[3],b[3];

    trans['A']=0;trans['B']=2;trans['C']=3;trans['D']=5;trans['E']=7;trans['F']=8;trans['G']=10;
    trans['a']=0;trans['b']=2;trans['c']=3;trans['d']=5;trans['e']=7;trans['f']=8;trans['g']=10;
    while(scanf("%s%s%s",t[0],t[1],t[2])!=EOF){
        for(i=0;i<3;i++){
            a[i]=trans[t[i][0]];
            switch(t[i][1]){
            case '#':a[i]++;break;
            case 'b':a[i]--;break;
            }
            if(a[i]<0) a[i]+=12;
        }
        for(i=0;i<3;i++)
            for(j=2;j>i;j--)
                if(a[j]<a[j-1]){k=a[j];a[j]=a[j-1];a[j-1]=k;}
        flag=0;
        if(a[0]+7==a[2]){
            if(a[0]+4==a[1]) {flag=1;k=a[0];}
            else if(a[0]+3==a[1]) {flag=-1;k=a[0];}
        }
        else if(a[1]+7==a[0]+12){
            if(a[1]+4==a[2]) {flag=1;k=a[1];}
            else if(a[1]+3==a[2]) {flag=-1;k=a[1];}
        }
        else if(a[2]+7==a[1]+12){
            if(a[2]+4==a[0]+12) {flag=1;k=a[2];}
            else if(a[2]+3==a[0]+12) {flag=-1;k=a[2];}
        }
        for(i='A';i<='G';i++)
            if(trans[i]>k) break;
        t[3][0]=i-1;
        if(trans[i-1]<k){t[3][1]='#';t[3][2]='\0';}
        else t[3][1]='\0';
        printf("%s %s %s is ",t[0],t[1],t[2]);
        if(flag==0) printf("unrecognized.\n");
        else printf("a %s %s chord.\n",t[3],(flag>0)?"Major":"Minor");
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2596722 2007-09-05 01:25:56 Accepted 1274 C 00:00.01 388K ¤ï¤¿¤· */

// 2012-09-07 02:58:29 | Accepted | 1274 | C | 0 | 160 | watashi | Source
