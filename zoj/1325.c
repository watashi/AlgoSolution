#include <stdio.h>
#include <string.h>
static char re[100];
int main()
{
    int p,m,i,j,l;
    char ch[25];


    re['A']='A';re['E']='3';re['H']='H';re['I']='I';re['J']='L';re['L']='J';
    re['M']='M';re['O']='O';re['S']='2';re['T']='T';re['U']='U';re['V']='V';
    re['W']='W';re['X']='X';re['Y']='Y';re['Z']='5';re['1']='1';re['2']='S';
    re['3']='E';re['5']='Z';re['8']='8';
    while(scanf("%s",ch)!=EOF){
        p=m=0;
        l=strlen(ch);
        for(i=0,j=l-1;i<j;i++,j--)
            if(ch[i]!=ch[j]) break;
        if(i>=j) p=1;
        for(i=0,j=l-1;i<=j;i++,j--)
            if(re[ch[i]]!=ch[j]) break;
        if(i>j) m=1;
        printf("%s -- ",ch);
        if(p&&m) printf("is a mirrored palindrome.\n");
        else if(p) printf("is a regular palindrome.\n");
        else if(m) printf("is a mirrored string.\n");
        else printf("is not a palindrome.\n");
        printf("\n");
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2508188 2007-07-03 00:55:48 Accepted 1325 C 00:00.00 392K ¤ï¤¿¤· */

// 2012-09-07 02:59:30 | Accepted | 1325 | C | 0 | 160 | watashi | Source
