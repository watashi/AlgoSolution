#include <stdio.h>
#include <string.h>
void doit(char *a,char *b,int l,int m)
{
    int i,c[62];

    c[l]=c[l-1]=0;
    for(i=l-1;i;i--){
        c[i-1]=0;
        c[i]+=(a[i]-'0')*m;
        c[i-1]+=c[i]/10;
        c[i]%=10;
    }
    c[0]+=(a[0]-'0')*m;
    if(c[0]>10) b[0]='o';
    else{
        for(i=0;i<l;i++)
            b[i]=c[i]+'0';
    }
    b[l]=0;
}
int main()
{
    char a[61],b[66],str[121];
    int i,l;

    while(gets(a)){
        l=strlen(a);
        strcpy(str,a);
        strcat(str,a);
        for(i=1;i<=l;i++){
            doit(a,b,l,i);
            if(!strstr(str,b)) break;
        }
        if(i>l) printf("%s is cyclic\n",a);
        else printf("%s is not cyclic\n",a);
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2500479 2007-06-22 22:44:11 Accepted 1073 C 00:00.00 388K ¤ï¤¿¤· */

// 2012-09-07 00:35:44 | Accepted | 1073 | C | 0 | 160 | watashi | Source
