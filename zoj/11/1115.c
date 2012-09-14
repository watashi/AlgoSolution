/*
#include <stdio.h>
int root(unsigned long num)
{
    int temp,res=0;

    do{
        temp=num%10;
        res+=temp;
        num=num/10;
    }while(num);
    if(res>=10) root(res);
    else return res;
}
int main()
{
    unsigned long in;

    while(scanf("%ld",&in),in>0){
        printf("%d\n",root(in));
    }
}
*/
/* //cannot work when num is too large */

#include <stdio.h>
int main()
{
    char ch;
    int temp,root,num;

    while(1){
    root=0;
    ch=getchar();
    while(ch>='0'&&ch<='9'){
        temp=ch-'0';
        root+=temp;
        ch=getchar();
    }
    if(root==0) break;
    else
        while(root>=10){
            num=root;
            root=0;
            do{
                temp=num%10;
                root+=temp;
                num/=10;
            }while(num);
        }
    printf("%d\n",root);
    }

    return 0;   /* NZEC */
}


/*DONE*/
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2464502 2007-05-26 23:00:21 Accepted 1115 C 00:00.00 388K ¤ï¤¿¤· */

// 2012-09-07 02:56:27 | Accepted | 1115 | C | 0 | 160 | watashi | Source
