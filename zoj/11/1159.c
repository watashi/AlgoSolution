#include <stdio.h>
static int x[125];
long gett()
{
    char c;
    long num=0;

    while((c=getchar())!='\n'){
        if(c!='-'){
            num*=10;
            num+=x[c];
        }
    }
    return num;
}
void quicksort(int l,int r,int b[])
{
    int i,j,x;

    if(l>=r) return;
    i=l;
    j=r;
    x=b[i];
    while(i!=j){
        while(b[j]>x&&j>i) j--;
        if(i<j){
            b[i]=b[j];
            i++;
        }
        while(b[i]<x&&j>i)i++;
            if(i<j){
            b[j]=b[i];
            j--;
        }
    }
    b[i]=x;
    quicksort(l,j-1,b);
    quicksort(i+1,r,b);
}
int main()
{
    long i,n,a[100001],count;
    int re,j,k,flag;
    char str[80];

    x['0']=0;x['1']=1;
    x['2']=x['A']=x['B']=x['C']=2;
    x['3']=x['D']=x['E']=x['F']=3;
    x['4']=x['G']=x['H']=x['I']=4;
    x['5']=x['J']=x['K']=x['L']=5;
    x['6']=x['M']=x['N']=x['O']=6;
    x['7']=x['P']=x['R']=x['S']=7;
    x['8']=x['T']=x['U']=x['V']=8;
    x['9']=x['W']=x['X']=x['Y']=9;
    scanf("%d ",&re);
    while(re--){
        scanf("%d",&n);
        getchar();
        for(i=0;i<n;i++)
            a[i]=gett();
        /*TLE::
        {a[i]=0;scanf("%s",str);
        for(j=k=0;j<7;k++){if(str[k]=='-') continue;else{a[i]*=10;a[i]+=x[str[k]];j++;}
        }}
        */
        quicksort(0,n-1,a);
        flag=0;
        for(i=1;i<n;i++)
            if(a[i]==a[i-1]){
                printf("%03ld-%04ld ",a[i]/10000,a[i]%10000);
                count=1;
                do{
                    i++;
                    count++;
                }while(i<n&&a[i]==a[i-1]);
                flag=1;
                printf("%d\n",count);
            }
        if(!flag) printf("No duplicates.\n");
        if(re) printf("\n");
    }
}
/*
switch(str[i]){
    case '-':break;
    case '0':num*=10;break;
    case '1':num*=10;num+=1;break;
    case '2':case 'A':case 'B':case 'C':num*=10;num+=2;break;
    case '3':case 'D':case 'E':case 'F':num*=10;num+=3;break;
    case '4':case 'G':case 'H':case 'I':num*=10;num+=4;break;
    case '5':case 'J':case 'K':case 'L':num*=10;num+=5;break;
    case '6':case 'M':case 'N':case 'O':num*=10;num+=6;break;
    case '7':case 'P':case 'R':case 'S':num*=10;num+=7;break;
    case '8':case 'T':case 'U':case 'V':num*=10;num+=8;break;
    case '9':case 'W':case 'X':case 'Y':num*=10;num+=9;break;
*/
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2532364 2007-07-23 23:06:49 Accepted 1159 C 00:00.89 792K ¤ï¤¿¤· */

// 2012-09-07 00:39:23 | Accepted | 1159 | C | 420 | 160 | watashi | Source
