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
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2681782 2007-11-21 14:24:47 Accepted 2704 C 00:00.04 976K わたし */
/*
Rank Submit time Run time Run memory Language User
1 2007-05-16 10:00:33 00:00.04 580K C++ 9911
2 2006-11-06 14:39:53 00:00.04 884K C++ xprogrammer
3 2007-11-21 14:24:47 00:00.04 976K C わたし
4 2007-03-01 20:19:00 00:00.05 884K C++ 吴.Woody
5 2007-03-01 20:45:29 00:00.05 884K C++ LoadingTime
6 2006-05-08 12:34:33 00:00.05 976K C++ 疯狂递交！
7 2006-04-26 16:17:35 00:00.05 1264K C++ tmpf
8 2006-04-26 16:27:18 00:00.05 1276K C++ foolman
9 2007-04-28 22:44:59 00:00.05 1372K C++ forever
10 2006-03-26 21:08:39 00:00.05 1468K C++ -_-
11 2006-05-21 12:57:09 00:00.06 876K C++ 一碟小菜^o^ @ZJOU
*/


/*
题目描述
给一个仅由[]()四种字符组成的字符串,找一个配好对的最长子串
比如对")[])([])(]"得到"([])"

注意到以下事实很重要:
考虑位置i的字符'[',假设与之匹配的位置j的']'构成子串"[A]",如果A不是空串,那么它一定是起始于i+1终止于j-1的最长配对串
(A一定是配对串,但A]B肯定不是配对串,对任意的B)
并且,位置i的最长配对串=[A]+位置j+1的最长配对串

所以,我们可以DP
f[n]表示起始于位置n的最长配对串.
如果s[n]='['或'(',那么只需要检查n+1+f[n+1]的字符是否与之匹配.若匹配,再加上f[n+2+f[n+1]]

刘歆
03-26-2006
*/

/*
其实不用那么麻烦，用一个栈扫描一次就搞定了。

确实,用栈是更简单的办法

如果某个字符可以消掉,那么栈顶到该字符一定是已配串
*/

// 2012-09-07 01:35:40 | Accepted | 2704 | C | 20 | 744 | watashi | Source
