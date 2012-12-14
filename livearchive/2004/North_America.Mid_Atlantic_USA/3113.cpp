#include <map>
#include <string>
#include <utility>
#include <iomanip>
#include <iostream>
using namespace std;
#define MAXN 500
#define inf 100e100
map<string,int> mp;
int m,n;
bool mark[MAXN];
double cmp,ans,board[MAXN][MAXN];
int main()
{
	while(cin>>cmp){
		cin>>n;
		mp.clear();
		for(int i=0;i<n;i++){
			string cur;
			cin>>cur;
			mp.insert(make_pair(cur,i));
			mark[i]=false;
			for(int j=0;j<n;j++)
				board[i][j]=inf;
		}
		cin>>m;
		while(m--){
			string cur;
			cin>>cur;
			int f=mp[cur];
			cin>>cur;
			int t=mp[cur];
			double d;
			cin>>d;
			board[f][t]=board[t][f]=d;
		}
		double ans=0;
		mark[0]=true;
		m=n;
		while(--m){
			int i,j,k;
			double w;
			k=-1;
			w=inf;
			for(i=0;i<n;i++){
				if(!mark[i]) continue;
				for(j=0;j<n;j++)
					if(!mark[j]&&(k==-1||board[i][j]<w)){k=j;w=board[i][j];}
			}
			mark[k]=true;
			ans+=w;
		}
		if(ans<=cmp) cout<<"Need "<<setiosflags(ios::showpoint)<<setiosflags(ios::fixed)<<setprecision(1)<<ans<<" miles of cable"<<endl;
		else cout<<"Not enough cable"<<endl;
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//806312 	3113 	Tangled in Cables 	Accepted 	C++ 	0.032 	2011-05-24 11:49:19
/*
id => 1174236
pid => 3113
pname => Tangled in Cables
status => Accepted
lang => C++
time => 0.026
date => 2012-12-14 17:43:00
*/
