#include <iostream>

using namespace std;

int main()
{
	int i,ri,m,n;

	cin>>ri;
	for(i=1;i<=ri;i++){
		cin>>m>>n;
		if(m<n) cout<<"NO BRAINS"<<endl;
		else cout<<"MMM BRAINS"<<endl;
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//806308 	3077 	No Brainer 	Accepted 	C++ 	0.012 	2011-05-24 11:45:46
/*
id => 1174152
pid => 3077
pname => No Brainer
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:30:49
*/
