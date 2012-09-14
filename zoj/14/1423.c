#include <stdio.h>
int main()
{
    char cc,str[300];
    int i,j,k,v,re;

    scanf("%d",&re);
    getchar();
    while(re--){
        gets(str);
        i=0;
        cc='+';
        while(str[i]){
            if(str[i]=='('){
                j=i;k=1;v=0;
                while(k){
                    j++;
                    if(str[j]=='(') k++;
                    else if(str[j]==')') k--;
                    else if(str[j]>='A'&&str[j]<='Z') v++;
                }
                switch(cc){
                case '+':str[i]=str[j]=' ';break;
                case '-':{
                    if(v<=1) str[i]=str[j]=' ';
                    else {str[i]='[';str[j]=']';}
                    }
                    break;
                }
                cc='+';
            }
            else if(str[i]=='+') cc='+';
            else if(str[i]=='-') cc='-';
            i++;
        }
        i=0;
        while(str[i]){
            switch(str[i]){
            case ' ':break;
            case '[':putchar('(');break;
            case ']':putchar(')');break;
            default:putchar(str[i]);break;
            }
            i++;
        }
        printf("\n");
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2511930 2007-07-08 20:59:52 Accepted 1423 C 00:00.00 388K ¤ï¤¿¤· */

// 2012-09-07 00:49:02 | Accepted | 1423 | C | 0 | 160 | watashi | Source
