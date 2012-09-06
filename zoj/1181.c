#include <stdio.h>
#include <string.h>
struct dic{
    char ch[12];
    int len;
};
typedef char STR[12];
int mystrcmp(struct dic *p,STR ch)
{
    int i;
    char *pt;

    for(i=0;i<p->len;i++){
        if(pt=strchr(ch,p->ch[i])) *pt='?';
        else break;
    }
    if(i>=p->len) return 1;
    else return 0;
}
int main()
{
    struct dic a[101],*p=a;
    STR ch,str,b[50];
    int i,j,n,index,nb,len;

    i=-1;
    while(scanf("%s",a[++i].ch),strcmp(a[i].ch,"XXXXXX"))
        a[i].len=strlen(a[i].ch);
    n=++i;
    while(scanf("%s",ch),strcmp(ch,"XXXXXX")){
        len=strlen(ch);
        nb=0;
        for(i=0;i<n;i++){
            strcpy(str,ch);
            if(len==(p+i)->len&&mystrcmp(p+i,str)) strcpy(b[nb++],a[i].ch);
        }
        for(i=0;i<nb;i++){
            index=i;
            for(j=i+1;j<nb;j++)
                if(strcmp(b[j],b[index])<0) index=j;
            if(index!=i){
                strcpy(ch,b[index]);
                strcpy(b[index],b[i]);
                strcpy(b[i],ch);
            }
        }
        if(nb){
            for(i=0;i<nb;i++)
                printf("%s\n",b[i]);
        }
        else printf("NOT A VALID WORD\n");
        printf("******\n");
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2502417 2007-06-25 13:31:59 Accepted 1181 C 00:00.00 396K ¤ï¤¿¤· */

// 2012-09-07 02:57:22 | Accepted | 1181 | C | 0 | 160 | watashi | Source
