#include <iostream>

using namespace std;

int main()
{
	int i,n,s,t[12]={0},d;//istance

	while(cin>>n,n+1){
		d=0;
		for(i=1;i<=n;i++){
			cin>>s>>t[i];
			d+=s*(t[i]-t[i-1]);
		}
		cout<<d<<" miles\n";
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//806276 	3059 	Speed Limit 	Accepted 	C++ 	0.016 	2011-05-24 11:26:44
/*
id => 1174273
pid => 3059
pname => Speed Limit
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:47:22
*/
