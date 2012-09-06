#include <stdio.h>
int main()
{
    int a[1001],i,n,j,k,t;

    while(scanf("%d",&n),n){
        while(scanf("%d",&a[0]),t=a[0]){
            for(i=j=1;i<n;i++){
                scanf("%d",&a[j]);
                if(a[j]>t) {t=a[j];j++;}
                else t=a[j];
            }
            k=j;
            for(i=1;i<k;i++)
                if(a[i-1]>a[i]) break;
            if(i<k) printf("No\n");
            else printf("Yes\n");
        }
        printf("\n");
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2503256 2007-06-26 12:41:25 Accepted 1259 C 00:00.08 400K gl hf */

/*
发信人: SgHao ( [ focus ] ), 板面: Algorithm
标  题: Re: 如何判断出栈顺序是否合理？
发信站: 飘渺水云间 (Sat Jan 19 13:20:49 2008), 站内信件

每一步都是确定的啊
根据下一个应该出栈的元素，以及该元素当前在堆栈里面还是没有进入堆栈，
可以确定现在要新压入一个元素还是弹出一个元素，或者可以判定不可能。
【 在 watashi (watashi) 的大作中提到: 】
: O(n^3) 555
: how to simulate it?
: 【 在 SgHao ( [ focus ] ) 的大作中提到: 】
: : 这个方法时间复杂度多少？
: : 模拟一把O(N)就搞定了。


--
5
9
101

※ 来源:·飘渺水云间 freecity.cn·[FROM: SgHao]
*/

// 2012-09-07 00:43:21 | Accepted | 1259 | C | 20 | 160 | watashi | Source
