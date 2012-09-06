/*
from cc98
 1
  2    数 n,m;
  3    数组 sum[10000]；  //sum[i]表示读取第0~i个数的和，在对m取个余数……
  4    sum[0]=0；
  5    数 答案=0；    //保存有多少个部分序列
  6    数 i 从 1 到 n
  7    {
  8        读取 x；        //就是下一个数，有了部分和数组，原来的数组就不用保留了
  9        sum[i]=sum[i-1]+x；
 10        sum[i]%=m；            //这两步应该很清楚吧……
 11        数 j 从 0 到 i - 1
 12        {
 13            如果 sum[j]==sum[i]   //那么sum[i]-sum[j]代表 从 j 到 i 的和，除m余零
 14             答案+=1；
 15        }
 16    }
 17    输出答案；
 18
 19

好像有O(max(n, m))的吧，遍历一遍，count[i]表示sum[j] % m = i的个数，然后从0到m遍历count[i]，total+=(count[i]*(count[i]-1))/2

1
  2    数 n,m;
  3    数组 sum[10000]；  //sum[i]表示读取第0~i个数的和，在对m取个余数……
  4    数组 count[5000]；  //count[i]到目前为止余数为i的sum个数
  5
  6    填充 count 为零；
  7    sum[0]=0；
  8
  9    数 答案=0；    //保存有多少个部分序列
 10
 11    数 i 从 1 到 n
 12    {
 13        读取 x；        //就是下一个数，有了部分和数组，原来的数组就不用保留了
 14        sum[i]=sum[i-1]+x；
 15        sum[i]%=m；            //这两步应该很清楚吧……
 16        count[sum[i]]+=1；
 17        答案+=count[sum[i]]；
 18    }
 19    输出答案；
 20
 21

*/
#include <stdio.h>
int main()
{
    int i,n,m,x,sum[10002],mod[5001];
    long count;

    while(scanf("%d%d",&n,&m)!=EOF){
        for(i=0;i<m;i++)
            mod[i]=0;
        sum[0]=0;
        mod[0]=1;
        for(i=1;i<=n;i++){
            scanf("%d",&x);
            sum[i]=(sum[i-1]+x)%m;
            mod[sum[i]]++;
        }
        count=0;
        for(i=0;i<m;i++)
            if(mod[i]>1) count+=mod[i]*(mod[i]-1)/2;
        printf("%ld\n",count);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2501930 2007-06-24 16:08:31 Accepted 1569 C 00:00.03 448K わたし */

// 2012-09-07 03:02:26 | Accepted | 1569 | C | 20 | 160 | watashi | Source
