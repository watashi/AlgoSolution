#include <stdio.h>
char mp[11][11][11];
short q[1001][3];
short d[6][3]={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
int n;
int islegal(int x,int y,int z)
{
	return x>=0&&x<n&&y>=0&&y<n&&z>=0&&z<n&&mp[x][y][z]!='X';
}
int main()
{
	int i,j,k,x,y,z,t,mind;
	int p,head,tail;

	while(scanf("%*s%d ",&n)!=EOF){
		for(k=0;k<n;k++)
			for(j=0;j<n;j++){
				for(i=0;i<n;i++)
					mp[i][j][k]=getchar();
				getchar();
			}
		scanf("%d%d%d",&q[0][0],&q[0][1],&q[0][2]);
		scanf("%d%d%d",&i,&j,&k);
		mp[i][j][k]='E';
		scanf("%*s");
		p=0;mind=0;tail=1;
		while(p<tail){
			head=tail;
			while(p<head){
				if(mp[i=q[p][0]][j=q[p][1]][k=q[p][2]]=='E') break;
				for(t=0;t<6;t++){
					if(islegal(x=i+d[t][0],y=j+d[t][1],z=k+d[t][2])){
						if(mp[x][y][z]=='E'){mind++;break;}
						mp[x][y][z]='X';
						q[tail][0]=x;
						q[tail][1]=y;
						q[tail][2]=z;
						tail++;
					}
				}
				if(t<6) break;
				p++;
			}
			if(p<head) break;
			mind++;
		}
		if(p<tail) printf("%d %d\n",n,mind);
		else printf("NO ROUTE\n");
	}

	return 0;
}
/* # 		Problem 	Verdict 	Language 	Run Time 	Submission Date */
/* 806251 	2311 	Asteroids 	Accepted 	ANSI C 	0.012 	2011-05-24 10:45:01 */
/*
id => 1174375
pid => 2311
pname => Asteroids
status => Accepted
lang => ANSI C
time => 0.006
date => 2012-12-14 18:03:46
*/
