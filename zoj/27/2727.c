#include <stdio.h>
#include <string.h>
struct bookinfo{
    char name[80];
    int year,price;
}book[100],*order[100],*p=book,*t;
void name(int n)
{
    int i,j;

    for(i=0;i<n-1;i++)
        for(j=n-1;i<j;j--){
            if(strcmp(order[j]->name,order[j-1]->name)<0){t=order[j];order[j]=order[j-1];order[j-1]=t;}
            else if(strcmp(order[j]->name,order[j-1]->name)==0){
                if(order[j]->year<order[j-1]->year){t=order[j];order[j]=order[j-1];order[j-1]=t;}
                else if(order[j]->year==order[j-1]->year){
                    if(order[j]->price<order[j-1]->price){t=order[j];order[j]=order[j-1];order[j-1]=t;}
                }
            }
        }
}
void year(int n)
{
    int i,j;

    for(i=0;i<n;i++)
        for(j=n-1;i<j;j--){
            if(order[j]->year<order[j-1]->year){t=order[j];order[j]=order[j-1];order[j-1]=t;}
            else if(order[j]->year==order[j-1]->year){
                if(strcmp(order[j]->name,order[j-1]->name)<0){t=order[j];order[j]=order[j-1];order[j-1]=t;}
                else if(strcmp(order[j]->name,order[j-1]->name)==0){
                    if(order[j]->price<order[j-1]->price){t=order[j];order[j]=order[j-1];order[j-1]=t;}
                }
            }
        }
}
void price(int n)
{
int i,j;

    for(i=0;i<n;i++)
        for(j=n-1;i<j;j--){
            if(order[j]->price<order[j-1]->price){t=order[j];order[j]=order[j-1];order[j-1]=t;}
            else if(order[j]->price==order[j-1]->price){
                if(strcmp(order[j]->name,order[j-1]->name)<0){t=order[j];order[j]=order[j-1];order[j-1]=t;}
                else if(strcmp(order[j]->name,order[j-1]->name)==0){
                    if(order[j]->year<order[j-1]->year){t=order[j];order[j]=order[j-1];order[j-1]=t;}
                }
            }
        }
}
int main()
{
    int i,n,blank=0;
    char index[10];

    while(scanf("%d",&n),n){
        if(blank) printf("\n");
        else blank=1;
        for(i=0;i<n;i++){
            order[i]=p+i;
            scanf("%s%d%d\n",(p+i)->name,&book[i].year,&book[i].price);
        }
        gets(index);
        if(!strcmp(index,"Name")) name(n);
        else if(!strcmp(index,"Year")) year(n);
        else if(!strcmp(index,"Price")) price(n);
        for(i=0;i<n;i++)
            printf("%s %d %d\n",order[i]->name,order[i]->year,order[i]->price);
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2485025 2007-06-08 14:36:02 Accepted 2727 C 00:00.00 404K ¤ï¤¿¤· */

// 2012-09-07 01:36:29 | Accepted | 2727 | C | 0 | 168 | watashi | Source
