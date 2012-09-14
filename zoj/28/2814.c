#include <stdio.h>
#include <string.h>
int main()
{
    int i,j,n,d,sur;
    char ch[80],*p=ch,pair[80][2];

    while(gets(ch),ch[0]!='*'){
        n=strlen(ch);
        sur=1;
        for(d=1;d<n&&sur;d++){
            for(i=d;i<n;i++){
                pair[i][0]=ch[i-d];
                pair[i][1]=ch[i];
            }
            for(i=d;i<n&&sur;i++)
                for(j=i+1;j<n;j++)
                    if(pair[i][0]==pair[j][0]&&pair[i][1]==pair[j][1]){
                        sur=0;
                        break;
                    }
        }
        if(sur) printf("%s is surprising.\n",ch);
        else printf("%s is NOT surprising.\n",ch);
    }

    return 0;   /* NZEC */
}

/*用寻找的方法会更好吗?*/
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2476684 2007-06-02 18:34:45 Accepted 2814 C 00:00.00 388K わたし */

// 2012-09-07 03:13:19 | Accepted | 2814 | C | 0 | 160 | watashi | Source
