#include <stdio.h>
#define isempty() (size==0)
#define clear() (size=0)
#define top() (stack[size-1])
#define topIndex() (index[size-1])
#define pop() (--size)
#define push(i,value) (index[size]=i,stack[size]=value,++size)
char str[100001];
char stack[100001];
int index[100001];
int size;
int main()
{
    int i,start,f,begin,end,len;

    while(gets(str)!=NULL){
        begin=end=-1;/*bs myself*/
        start=-1;
        len=0;
        clear();
        for(i=0;str[i];++i){
            switch(str[i]){
            case '(':case '[':
                push(i,str[i]);break;
            case ')':case ']':
                if(!isempty()&&(str[i]==')'&&top()=='('||str[i]==']'&&top()=='[')){
                    pop();
                    if(!isempty()) f=topIndex();
                    else f=start;
                    if(i-f>len){
                        len=i-f;
                        begin=f;
                        end=i;
                    }
                }
                else{
                    start=i;
                    clear();
                }
                break;
            }
        }
        str[end+1]='\0';
        puts(str+begin+1);
        getchar();
        putchar('\n');
    }
}

// 2012-09-07 15:44:34 | Accepted | 2704 | C | 10 | 744 | watashi | Source
