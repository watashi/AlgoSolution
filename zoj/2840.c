#include <stdio.h>
#include <string.h>
int main()
{
    struct file{
        char n[81];
        int l;
    }f[101];
    char s[81],s1[80],s2[80];
    int i,n,m,l1,l2,found,blank=0;

    while(scanf("%d ",&n)!=EOF){
        if(blank) printf("\n");
        else blank=1;
        for(i=0;i<n;i++){
            scanf("%s",f[i].n);
            f[i].l=strlen(f[i].n);
        }
        scanf("%d ",&m);
        while(m--){
            scanf("%s",s);
            i=-1;
            while(s[++i]!='*') s1[i]=s[i];
            s1[i]='\0';
            l1=i;
            do{
                i++;
                s2[i-l1-1]=s[i];
            }while(s[i]!='\0');
            l2=strlen(s2);
            found=0;
            /*
            if(s1[0]=='\0')
            else if(s2[0]=='\0')
            else
            */
            for(i=0;i<n;i++){
                if(f[i].l>=l1+l2&&strstr(f[i].n,s1)==f[i].n&&strstr(f[i].n+f[i].l-l2,s2)==f[i].n+f[i].l-l2){
                    if(found) printf(", ");
                    else found=1;
                    printf("%s",f[i].n);
                }
            }
            if(!found) printf("FILE NOT FOUND");
            printf("\n");
        }
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2504949 2007-06-28 14:11:57 Accepted 2840 C 00:00.00 400K ¤ï¤¿¤· */

// 2012-09-07 03:13:43 | Accepted | 2840 | C | 0 | 160 | watashi | Source
