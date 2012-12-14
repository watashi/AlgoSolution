#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double b,n;
	int a;
	
	while(cin>>b>>n,n){
		a=(int)pow(b,1/n);
		a=((b-pow(a,n))<(pow(a+1,n)-b))?a:(a+1);
		cout<<a<<endl;	
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//806320 	3600 	Root of the Problem 	Accepted 	C++ 	0.008 	2011-05-24 11:57:31
/*
id => 1174293
pid => 3600
pname => Root of the Problem
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:50:33
*/
