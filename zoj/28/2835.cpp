// #include <iostream.h> // CE
#include <iostream>

using namespace std;

int main()
{
    int i,j,k,t,n,a[10][10],sum[11],BOOL;

    while(cin>>n,n){
        BOOL=1;
        for(i=0;i<n;i++){
            sum[i]=0;
            for(j=0;j<n;j++){
                cin>>a[i][j];
                sum[i]+=a[i][j];
            }
        }
        sum[n]=sum[n-1];
        for(i=0;i<n;i++)
            for(j=0;j<n;j++){
                t=n*i+j;
                for(k=0;k<t;k++)
                    if(a[k/n][k%n]==a[i][j]){
                        BOOL=0;
                        break;
                    }
            }
        if(BOOL){
            for(j=0;i<n;j++){
                if(sum[j]!=sum[j+1]){
                    BOOL=0;
                    break;
                }
                sum[j]=0;
                for(i=0;i<n;i++)
                    sum[j]+=a[i][j];
                if(sum[j]!=sum[j+1]){
                    BOOL=0;
                    break;
                }
            }
        }
        if(BOOL){
            sum[1]=sum[2]=0;
            for(i=0;i<n;i++){
                sum[1]+=a[i][i];
                sum[2]+=a[i][n-1-i];
            }
            if(sum[0]!=sum[1]||sum[0]!=sum[2]) BOOL=0;
        }
        if(BOOL) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2496933 2007-06-19 12:40:51 Accepted 2835 C++ 00:00.01 844K ¤ï¤¿¤·

// 2012-09-07 04:28:09 | Accepted | 2835 | C++ | 0 | 188 | watashi | Source
