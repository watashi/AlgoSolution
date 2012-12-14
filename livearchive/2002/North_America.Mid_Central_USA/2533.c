#include <stdio.h>
#include <string.h> 
#include <math.h>
#define ch_name 10/*lengh of team_name*/
#define num_Q 7/*num of problems*/
int rank[20];
struct imfo{	
	char team[ch_name];
	int time[num_Q];
	int ac;
	int total;
	int g_mean;
}note[20],*p=note;
void getnote(struct imfo *p)
{
	int i;	
	double temp;

	scanf("%s",p->team);
	p->total=p->ac=0;
	temp=0;
	for(i=0;i<num_Q;i++){
		scanf("%d",&p->time[i]);
		p->total+=p->time[i];
		if(p->time[i]){
			p->ac++;
			temp+=log(p->time[i]);
		}
	}	
	if(p->ac==0) p->g_mean=0;
	else p->g_mean=(int)(exp(temp/p->ac)+0.5);
}
void putnote(struct imfo *p)
{
	int i;

	printf(" %-10s",p->team);	
	printf(" %1d",p->ac);
	printf(" %4d",p->total);
	printf(" %3d",p->g_mean);
	for(i=0;i<num_Q;i++)
		printf("%4d",p->time[i]);
	printf("\n");
}
int compare(struct imfo *p,struct imfo *pp)
{
	int k;

	if(p->ac>pp->ac) return 1;
	else if(p->ac<pp->ac) return 0;
	else{
		if(p->total<pp->total) return 1;
		else if(p->total>pp->total) return 0;
		else{
			if(p->g_mean<pp->g_mean) return 1;
			else if(p->g_mean>pp->g_mean) return 0;
			else{
				k=strcmp(p->team,pp->team);
				if(k<0) return 1;
				else return 0;
			}
		}
	}
}
void ranknote(int n)
{
	int i,j,temp;

	for(i=0;i<n;i++)
		rank[i]=i;	
	for(i=0;i<n;++i)
		for(j=n-1;i<j;--j)
			if(compare(p+rank[j],p+rank[j-1])){   /*rank[j-1]¶ÔÓ¦µÄ´ó*/
				temp=rank[j-1];
				rank[j-1]=rank[j];
				rank[j]=temp;
			}
}
int main()
{
	int i,j,n,count;

	count=0;
	while(scanf("%d",&n),n){
		getchar();
		count++;
		for(i=0;i<n;i++){
			getnote(p+i);			
		}
		ranknote(n);
		printf("CONTEST %d\n",count);		
		for(i=0;i<n;i++){
			j=i;
			while(j&&
				note[rank[j]].ac==note[rank[j-1]].ac&&
				note[rank[j]].total==note[rank[j-1]].total&&
				note[rank[j]].g_mean==note[rank[j-1]].g_mean)
				j--;
			printf("%02d",j+1);
			putnote(p+rank[i]);
		}
	}
	return 0;
}

/* # 		Problem 	Verdict 	Language 	Run Time 	Submission Date */
/* 806240 	2533 	Programmer, Rank Thyself 	Accepted 	ANSI C 	0.008 	2011-05-24 10:34:41 */
/*
id => 1174369
pid => 2533
pname => Programmer, Rank Thyself
status => Accepted
lang => ANSI C
time => 0.006
date => 2012-12-14 18:02:58
*/
