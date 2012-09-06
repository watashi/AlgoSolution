#include <stdio.h>
#include <string.h>
int flag;
int w[26][27];
int doit(char *p)
{
    char *pc=p,tmp[1024];
    int res,t,tt;

    res=0;
    while(*pc){
        if(*pc=='('){
            t=1;tt=0;pc++;
            while(t){
                if(*pc=='(') t++;
                else if(*pc==')') t--;
                tmp[tt++]=*(pc++);
            }
            tmp[tt-1]='\0';
            t=doit(tmp);
            if(t<0) return -1;
            tt=0;
            while('0'<=*pc&&*pc<='9'){
                tt*=10;
                tt+=*(pc++)-'0';
            }
            if(tt==0) tt=1;
            res+=t*tt;
        }
        else{
            tt=*(pc++)-'A';
            if('a'<=*pc&&*pc<='z') t=w[tt][*(pc++)-'a'];
            else t=w[tt][26];
            if(t<0) return -1;
            tt=0;
            while('0'<=*pc&&*pc<='9'){
                tt*=10;
                tt+=*(pc++)-'0';
            }
            if(tt==0) tt=1;
            res+=t*tt;
        }
    }
    return res;
}
int main()
{
    char line[1024];
    int i,j,ans;

    for(i=0;i<26;i++)
        for(j=0;j<27;j++)
            w[i][j]=-1;
    while(scanf("%s",line),strcmp(line,"END_OF_FIRST_PART")){
        i=line[0]-'A';
        j=((line[1]!='\0')?(line[1]-'a'):26);
        scanf("%d",&w[i][j]);
    }
    while(scanf("%s",line),strcmp(line,"0")){
        ans=doit(line);
        if(ans<0) printf("UNKNOWN\n");
        else printf("%d\n",ans);
    }
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2595798 2007-09-04 13:59:16 Accepted 1741 C 00:00.01 400K ¤ï¤¿¤· */

// 2012-09-07 00:59:31 | Accepted | 1741 | C | 0 | 160 | watashi | Source
